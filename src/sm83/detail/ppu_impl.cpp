#include "ppu.h"
#include "ppu_impl.h"
#include "mmu.h"
#include "frame_buffer.h"
#include "irenderer.h"
#include "util_bitmanip.h"
#include "mmu_reg_names.h"

#include <cstdint>
#include <stdexcept>

static const CCycles CLOCKS_PER_HBLANK = 204; /* Mode 0 */
static const CCycles CLOCKS_PER_SCANLINE_OAM = 80; /* Mode 2 */
static const CCycles CLOCKS_PER_SCANLINE_VRAM = 172; /* Mode 3 */
static const CCycles CLOCKS_PER_SCANLINE = (CLOCKS_PER_SCANLINE_OAM + CLOCKS_PER_SCANLINE_VRAM + CLOCKS_PER_HBLANK);

static const CCycles CLOCKS_PER_VBLANK = 4560; /* Mode 1 */
static const CCycles SCANLINES_PER_FRAME = 144;
static const CCycles CLOCKS_PER_FRAME = (CLOCKS_PER_SCANLINE * SCANLINES_PER_FRAME) + CLOCKS_PER_VBLANK;

namespace {

detail::Pallete LoadPallete(MappedByteRegister& reg)
{
    uint8_t palleteValue = reg.Read();
    Colour c0 = static_cast<Colour>((palleteValue & 0b00000011));
    Colour c1 = static_cast<Colour>((palleteValue & 0b00001100) >> 2);
    Colour c2 = static_cast<Colour>((palleteValue & 0b00110000) >> 4);
    Colour c3 = static_cast<Colour>((palleteValue & 0b11000000) >> 6);

    return {c0, c1, c2, c3};
}

inline uint16_t GetTileWord(MappedRegisterBlock& lowerBlock, MappedRegisterBlock& upperBlock, uint8_t tileId)
{
    // Each tile is 2 bytes, so to get the right relative address, we multiply the index by 2
    uint16_t address = 0;
    if (tileId > 127)
    {
        address = tileId * 2;
        return ToWord(lowerBlock.Read(address + 1), lowerBlock.Read(address));
    }
    address = (tileId - 127) * 2;
    return ToWord(upperBlock.Read(address + 1), upperBlock.Read(address));
}

inline Colour GetColourFromTile(const uint16_t tileData, const uint8_t pixelIdx, const detail::Pallete& pallete)
{
    unsigned short pixel = CheckBit(Msb(tileData), pixelIdx) >> 1 | CheckBit(Lsb(tileData), pixelIdx);
    return pallete[pixel];
}

} // namespace
namespace detail {

PpuImpl::MappedRegisters::MappedRegisters(Mmu& mmu):
    vram_tileDataBlock0 (mmu, 0x8000, 0x0800),
    vram_tileDataBlock1 (mmu, 0x8800, 0x0800),
    vram_tileDataBlock2 (mmu, 0x9000, 0x0800),
    vram_tileMapBlock0  (mmu, 0x9800, 0x0400),
    vram_tileMapBlock1  (mmu, 0x9C00, 0x0400),
    oam                 (mmu, 0xFE00, 0x00A0),
    lcdControl          (mmu, 0xFF40),
    lcdStatus           (mmu, 0xFF41),
    viewScrollX         (mmu, 0xFF42),
    viewScrollY         (mmu, 0xFF43),
    lcdYCoord           (mmu, 0xFF44),
    lcdLYCompare        (mmu, 0xFF45),
    dmaStartAddress     (mmu, 0xFF46),
    bgPallete           (mmu, 0xFF47),
    spritePalette0      (mmu, 0xFF48),
    spritePalette1      (mmu, 0xFF49),
    windowPosY          (mmu, 0xFF4A),
    windowPosX          (mmu, 0xFF4B)
{}

PpuImpl::PpuImpl(Mmu& mmu):
    m_mmu(mmu),
    m_reg(mmu),
    m_cycleCounter(0),
    m_viewBuffer(GAMEBOY_WIDTH, GAMEBOY_HEIGHT)
{}

bool PpuImpl::ShouldRender()
{
    return m_shouldRender;
}

void PpuImpl::Step(CCycles cycles)
{
    m_shouldRender = false;
    switch (GetPpuMode())
    {
        case Mode::HBLANK:
        {
            if (m_cycleCounter >= CLOCKS_PER_HBLANK)
            {
                uint8_t line = m_reg.lcdYCoord.Read();

                WriteScanline(line);
                m_reg.lcdYCoord.Write(++line);

                m_cycleCounter %= CLOCKS_PER_HBLANK;

                /* Line 145 (index 144) is the first line of VBLANK */
                if (line == 144)
                {
                    SetPpuMode(Mode::VBLANK);
                    m_mmu.UnsetInterruptFlag<Mmu::InterruptType::VBLANK>();
                }
                else
                {
                    SetPpuMode(Mode::OAM_SEARCH);
                }
            }
            break;
        }
        case Mode::VBLANK:
        {
            if (m_cycleCounter >= CLOCKS_PER_SCANLINE)
            {
                uint8_t line = m_reg.lcdYCoord.Read();
                m_reg.lcdYCoord.Write(++line);

                m_cycleCounter %= CLOCKS_PER_SCANLINE;

                /* Line 155 (index 154) is the last line */
                if (line == 154)
                {
                    WriteSprites();
                    m_shouldRender = true;
                    m_viewBuffer.Reset();
                    m_reg.lcdYCoord.Write(0);

                    SetPpuMode(Mode::OAM_SEARCH);
                };
            }
            break;
        }
        case Mode::OAM_SEARCH:
        {
            if (m_cycleCounter >= CLOCKS_PER_SCANLINE_OAM)
            {
                m_cycleCounter %= CLOCKS_PER_SCANLINE_OAM;
                SetPpuMode(Mode::PIXEL_TRANSFER);
            }
            break;
        }
        case Mode::PIXEL_TRANSFER:
        {
            if (m_cycleCounter >= CLOCKS_PER_SCANLINE_VRAM)
            {
                m_cycleCounter %= CLOCKS_PER_SCANLINE_VRAM;
                SetPpuMode(Mode::HBLANK);
                if (IsMode0IntSelect())
                {
                    m_mmu.EnableInterrupt<Mmu::InterruptType::VBLANK>();
                }

                if (IsLYCIntSelect() && IsLYAndLYCEqual())
                {
                    m_mmu.SetInterruptFlag<Mmu::InterruptType::VBLANK>();
                }
            }
            break;
        }
        default:
            throw std::runtime_error("Unexpected ppu mode");
    }
}

const FrameBuffer& PpuImpl::GetViewBuffer() const
{
    return m_viewBuffer;
}

/*     ************** LCD Control Checks *************     */
bool PpuImpl::IsDisplayOn() const
{
    return CheckBit<7>(m_reg.lcdControl.Read());
}

PpuImpl::TileMapAreaType PpuImpl::GetWindowTileMapAreaType() const
{
    return CheckBit<6>(m_reg.lcdControl.Read()) ?
        PpuImpl::TileMapAreaType::ONE :
        PpuImpl::TileMapAreaType::ZERO;
}

bool PpuImpl::IsWindowEnabled() const 
{
    return CheckBit<5>(m_reg.lcdControl.Read());
}

PpuImpl::TileMapAreaType PpuImpl::GetBGAndWindowTileMapAreaType() const
{
    return CheckBit<4>(m_reg.lcdControl.Read()) ?
        PpuImpl::TileMapAreaType::ONE :
        PpuImpl::TileMapAreaType::ZERO;
}

PpuImpl::TileMapAreaType PpuImpl::GetBGTileMapAreaType() const
{
    return CheckBit<3>(m_reg.lcdControl.Read()) ?
        PpuImpl::TileMapAreaType::ONE :
        PpuImpl::TileMapAreaType::ZERO;
}

PpuImpl::ObjectSizeType PpuImpl::ObjectSize() const
{
    return CheckBit<2>(m_reg.lcdControl.Read()) ?
    PpuImpl::ObjectSizeType::LONG :
    PpuImpl::ObjectSizeType::SMALL;
}

bool PpuImpl::IsObjectEnabled() const
{
    return CheckBit<1>(m_reg.lcdControl.Read());
}

bool PpuImpl::IsBGAndWindowEnabled() const
{
    return CheckBit<0>(m_reg.lcdControl.Read());
}

/*     ************** LCD Status Checks *************     */
bool PpuImpl::IsLYCIntSelect() const
{
    return CheckBit<6>(m_reg.lcdStatus.Read());
}

bool PpuImpl::IsMode2IntSelect() const
{
    return CheckBit<5>(m_reg.lcdStatus.Read());
}

bool PpuImpl::IsMode1IntSelect() const
{
    return CheckBit<4>(m_reg.lcdStatus.Read());
}

bool PpuImpl::IsMode0IntSelect() const
{
    return CheckBit<3>(m_reg.lcdStatus.Read());
}

bool PpuImpl::IsLYAndLYCEqual() const
{
    return CheckBit<2>(m_reg.lcdStatus.Read());
}

PpuImpl::Mode PpuImpl::GetPpuMode() const
{
    unsigned short ppuMode = m_reg.lcdStatus.Read() & 0b11;
    return static_cast<PpuImpl::Mode>(ppuMode);
}

void PpuImpl::SetPpuMode(PpuImpl::Mode mode)
{
    short v_mode = static_cast<short>(mode);
    auto value = m_reg.lcdStatus.Read();
    SetBitTo<0>(value, v_mode & 0b01);
    SetBitTo<1>(value, v_mode & 0b10);
    m_reg.lcdStatus.Write(value);
}

/*     ************** Private Methods *************     */
void PpuImpl::WriteScanline(uint8_t line)
{
    if (!IsDisplayOn())
    {
        return;
    }

    if (IsBGAndWindowEnabled())
    {
        DrawBGLine(line);

        if (IsWindowEnabled())
        {
            DrawWindowLine(line);
        }
    }
}

void PpuImpl::WriteSprites()
{
    // TODO: Do
}

void PpuImpl::DrawBGLine(uint8_t line)
{
    Pallete pallete = ::LoadPallete(m_reg.bgPallete);
    uint screenY = line;

    uint scrolledY = screenY + m_reg.viewScrollY.Read();
    uint bgMapY = scrolledY % BG_MAP_SIZE;
    uint tileY = bgMapY / TILE_HEIGHT_PX;
    uint tilePixelY = bgMapY % TILE_HEIGHT_PX;

    const bool UseTileMap0 = GetBGAndWindowTileMapAreaType() == TileMapAreaType::ZERO;
    MappedRegisterBlock& tileMap = UseTileMap0
                                    ? m_reg.vram_tileMapBlock0
                                    : m_reg.vram_tileMapBlock1;

    for (uint screenX = 0; screenX < GAMEBOY_WIDTH; screenX++)
    {
        /* Work out the position of the pixel in the framebuffer */
        uint scrolledX = screenX + m_reg.viewScrollX.Read();

        /* Work out the index of the pixel in the full background map */
        uint bgMapX = scrolledX % BG_MAP_SIZE;

        /* Work out which tile of the bg_map this pixel is in, and the index of that tile
         * in the array of all tiles */
        uint tileX = bgMapX / TILE_WIDTH_PX;

        /* Work out which specific (x,y) inside that tile we're going to render */
        uint tilePixelX = bgMapX % TILE_WIDTH_PX;

        /* Work out the address of the tile ID from the tile map */
        uint tileIdx = tileY * TILES_PER_LINE + tileX;

        /* Grab the ID of the tile we'll get data from in the tile map */
        uint8_t tileId = tileMap.Read(tileIdx);

        /* Calculate the offset from the start of the tile data memory where
         * the data for our tile lives */
        uint16_t tile = GetBGOrWindowTile(tileId);
        Colour pixelColour = GetColourFromTile(tile, tilePixelX, pallete);

        m_viewBuffer.SetPixel(screenX, screenY, pixelColour);
    }
}

void PpuImpl::DrawWindowLine(uint8_t line)
{
    uint screenY = line;
    uint scrolledY = screenY - m_reg.windowPosY.Read();
    if (scrolledY >= GAMEBOY_HEIGHT)
    {
        return;
    }

    uint bgMapY = scrolledY % BG_MAP_SIZE;
    uint tileY = bgMapY / TILE_HEIGHT_PX;
    uint tilePixelY = bgMapY % TILE_HEIGHT_PX;

    Pallete pallete = ::LoadPallete(m_reg.bgPallete);
    const bool UseTileMap0 = GetBGAndWindowTileMapAreaType() == TileMapAreaType::ZERO;
    MappedRegisterBlock& tileMap = UseTileMap0
                                    ? m_reg.vram_tileMapBlock0
                                    : m_reg.vram_tileMapBlock1;

    for (uint screenX = 0; screenX < GAMEBOY_WIDTH; screenX++)
    {
        /* Work out the position of the pixel in the framebuffer */
        uint scrolledX = screenX + m_reg.windowPosX.Read() - 7;

        /* Work out which tile of the bg_map this pixel is in, and the index of that tile
         * in the array of all tiles */
        uint tileX = scrolledX / TILE_WIDTH_PX;

        /* Work out which specific (x,y) inside that tile we're going to render */
        uint tilePixelX = scrolledX % TILE_WIDTH_PX;

        /* Work out the address of the tile ID from the tile map */
        uint tileIdx = tileY * TILES_PER_LINE + tileX;

        /* Grab the ID of the tile we'll get data from in the tile map */
        uint8_t tileId = tileMap.Read(tileIdx);

        /* Calculate the offset from the start of the tile data memory where
         * the data for our tile lives */
        uint16_t tile = GetBGOrWindowTile(tileId);
        Colour pixelColour = GetColourFromTile(tile, tilePixelX, pallete);

        m_viewBuffer.SetPixel(screenX, screenY, pixelColour);
    }
}

// TODO: Deduplicate
uint16_t PpuImpl::GetObjTile(uint8_t tileId)
{
    auto& lowerBlock = m_reg.vram_tileDataBlock0;
    auto& upperBlock = m_reg.vram_tileDataBlock1;

    return ::GetTileWord(lowerBlock, upperBlock, tileId);
}

uint16_t PpuImpl::GetBGOrWindowTile(uint8_t tileId)
{
    auto type = GetBGAndWindowTileMapAreaType();
    auto& lowerBlock = (type == TileMapAreaType::ZERO)
                ? m_reg.vram_tileDataBlock0
                : m_reg.vram_tileDataBlock2;
    auto& upperBlock = m_reg.vram_tileDataBlock1;

    return ::GetTileWord(lowerBlock, upperBlock, tileId);
}

} // namespace detail

