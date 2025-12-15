#include "detail/video/ppu_impl.h"

#include "bitmanip.h"
#include "detail/register_names.h"
#include "detail/video/palette.h"
#include "detail/memory/mmu_impl.h"
#include "frame_buffer.h"
#include "irenderer.h"
#include "detail/impl_helper.h"

#include <cstdint>
#include <stdexcept>

static const CCycles CLOCKS_PER_HBLANK = 204; /* Mode 0 */
static const CCycles CLOCKS_PER_SCANLINE_OAM = 80; /* Mode 2 */
static const CCycles CLOCKS_PER_SCANLINE_VRAM = 172; /* Mode 3 */
static const CCycles CLOCKS_PER_SCANLINE = (CLOCKS_PER_SCANLINE_OAM + CLOCKS_PER_SCANLINE_VRAM + CLOCKS_PER_HBLANK);

static const CCycles CLOCKS_PER_VBLANK = 4560; /* Mode 1 */
static const CCycles SCANLINES_PER_FRAME = 144;
static const CCycles CLOCKS_PER_FRAME = (CLOCKS_PER_SCANLINE * SCANLINES_PER_FRAME) + CLOCKS_PER_VBLANK;

static const uint16_t SPRITE_BYTES = 4;

namespace {

detail::Palette LoadPalette(detail::MappedRegister& reg)
{
    uint8_t paletteValue = reg.Read();
    GbColour c0 = static_cast<GbColour>((paletteValue & 0b00000011));
    GbColour c1 = static_cast<GbColour>((paletteValue & 0b00001100) >> 2);
    GbColour c2 = static_cast<GbColour>((paletteValue & 0b00110000) >> 4);
    GbColour c3 = static_cast<GbColour>((paletteValue & 0b11000000) >> 6);

    return {c0, c1, c2, c3};
}

inline uint16_t GetTileWord(detail::MappedMemoryBlock& lowerBlock, detail::MappedMemoryBlock& upperBlock, uint8_t tileId, uint8_t tileHeight)
{
    // Each tile is 16 bytes, 2 bytes per row
    uint16_t address = ((tileId % 128) * BYTES_PER_TILE) + (tileHeight * 2);
    if (tileId > 127)
    {
        return ToWord(upperBlock.Read(address + 1), upperBlock.Read(address));
    }
    return ToWord(lowerBlock.Read(address + 1), lowerBlock.Read(address));
}

inline GbColour GetColourFromTile(const uint16_t tileData, const uint8_t pixelIdx, const detail::Palette& palette)
{
    unsigned short pixel = CheckBit(Msb(tileData), pixelIdx) << 1 | CheckBit(Lsb(tileData), pixelIdx);
    return palette[pixel];
}

} // namespace

namespace detail {

PpuImpl::MappedRegisters::MappedRegisters(PpuImpl& ppu, MmuImpl& mmu):
    vram_tileDataBlock0 (ppu.m_vram, 0x0000, 0x0800),
    vram_tileDataBlock1 (ppu.m_vram, 0x0800, 0x0800),
    vram_tileDataBlock2 (ppu.m_vram, 0x1000, 0x0800),
    vram_tileMapBlock0  (ppu.m_vram, 0x1800, 0x0400),
    vram_tileMapBlock1  (ppu.m_vram, 0x1C00, 0x0400),
    oam                 (ppu.m_oam,  0x0000, 0x00A0),
    lcdControl          (mmu.GetMappedRegister(REG_LCD_CONTROL)),
    lcdStatus           (mmu.GetMappedRegister(REG_LCD_STATUS)),
    viewScrollX         (mmu.GetMappedRegister(REG_LCD_VIEW_SCROLL_X)),
    viewScrollY         (mmu.GetMappedRegister(REG_LCD_VIEW_SCROLL_Y)),
    lcdYCoord           (mmu.GetMappedRegister(REG_LCD_Y_COORDINATE)),
    lcdLYCompare        (mmu.GetMappedRegister(REG_LCD_LY_COMPARE)),
    dmaStartAddress     (mmu.GetMappedRegister(REG_DMA_TRANSFER_ADDRESS)),
    bgPalette           (mmu.GetMappedRegister(REG_BG_PALETTE)),
    spritePalette0      (mmu.GetMappedRegister(REG_SPRITE_PALETTE_0)),
    spritePalette1      (mmu.GetMappedRegister(REG_SPRITE_PALETTE_1)),
    windowPosY          (mmu.GetMappedRegister(REG_WINDOW_POS_Y)),
    windowPosX          (mmu.GetMappedRegister(REG_WINDOW_POS_X))
{}

PpuImpl::PpuImpl(Mmu& mmu):
    m_pRenderer(nullptr),
    m_mmu(mmu),
    m_reg(*this, ImplHelper::ExtractImpl(mmu)),
    m_cycleCounter(0),
    m_vram(),
    m_oam(),
    m_pMappedVram(std::make_unique<MappedMemoryBlock>(m_vram, 0, m_vram.size())),
    m_pMappedOam(std::make_unique<MappedMemoryBlock>(m_oam, 0, m_oam.size())),
    m_viewBuffer(GAMEBOY_WIDTH, GAMEBOY_HEIGHT)
{
    ImplHelper::ExtractImpl(mmu).MapMemory(*this);
}

void PpuImpl::Step(CCycles cycles)
{
    m_cycleCounter += cycles;
    if (m_pRenderer)
    {
        m_pRenderer->Step();
    }

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
                    m_mmu.SetInterruptFlag<Mmu::InterruptType::VBLANK>();
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
                    Render();
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

void PpuImpl::Render() const
{
    if (m_pRenderer)
    {
        m_pRenderer->Render(m_viewBuffer);
    }
}

void PpuImpl::SetDisplayOn()
{
    auto value = m_reg.lcdControl.Read();
    SetBitToTrue<0>(value);
    SetBitToTrue<1>(value);
    SetBitToTrue<5>(value);
    SetBitToTrue<7>(value);
    m_reg.lcdControl.Write(value);
}

void PpuImpl::SetDisplayOff()
{
    auto value = m_reg.lcdControl.Read();
    SetBitToFalse<0>(value);
    SetBitToFalse<1>(value);
    SetBitToFalse<5>(value);
    SetBitToFalse<7>(value);
    m_reg.lcdControl.Write(value);
}

void PpuImpl::RegisterRenderer(IRenderer* pRenderer)
{
    m_pRenderer = pRenderer;
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

bool PpuImpl::IsLYAndLYCEqual()
{
    m_reg.lcdStatus.SetBitTo<2>(m_reg.lcdYCoord.Read() == m_reg.lcdLYCompare.Read());
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

WeakMappedMemoryBlock PpuImpl::GetMemoryVram() const
{
    return WeakMappedMemoryBlock(m_pMappedVram);
}

WeakMappedMemoryBlock PpuImpl::GetMemoryOam() const
{
    return WeakMappedMemoryBlock(m_pMappedOam);
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
    if (!IsDisplayOn() || !IsObjectEnabled())
    {
        return;
    }

    for (int ii = 0; ii < 40; ++ii)
    {
        DrawSprite(ii);
    }
}

void PpuImpl::DrawBGLine(uint8_t line)
{
    Palette palette = ::LoadPalette(m_reg.bgPalette);
    unsigned int screenY = line;

    unsigned int scrolledY = screenY + m_reg.viewScrollY.Read();
    unsigned int bgMapY = scrolledY % BG_MAP_SIZE;
    unsigned int tileY = bgMapY / TILE_HEIGHT_PX;
    unsigned int tilePixelY = bgMapY % TILE_HEIGHT_PX;

    const bool UseTileMap0 = GetBGAndWindowTileMapAreaType() == TileMapAreaType::ZERO;
    MappedMemoryBlock& tileMap = UseTileMap0
                                    ? m_reg.vram_tileMapBlock0
                                    : m_reg.vram_tileMapBlock1;

    for (unsigned int screenX = 0; screenX < GAMEBOY_WIDTH; screenX++)
    {
        /* Work out the position of the pixel in the framebuffer */
        unsigned int scrolledX = screenX + m_reg.viewScrollX.Read();

        /* Work out the index of the pixel in the full background map */
        unsigned int bgMapX = scrolledX % BG_MAP_SIZE;

        /* Work out which tile of the bg_map this pixel is in, and the index of that tile
         * in the array of all tiles */
        unsigned int tileX = bgMapX / TILE_WIDTH_PX;

        /* Work out which specific (x,y) inside that tile we're going to render */
        unsigned int tilePixelX = bgMapX % TILE_WIDTH_PX;

        /* Work out the address of the tile ID from the tile map */
        unsigned int tileIdx = tileY * TILES_PER_LINE + tileX;

        /* Grab the ID of the tile we'll get data from in the tile map */
        uint8_t tileId = tileMap.Read(tileIdx);

        /* Calculate the offset from the start of the tile data memory where
         * the data for our tile lives */
        uint16_t tile = GetBGOrWindowTile(tileId, tilePixelY);
        GbColour pixelColour = GetColourFromTile(tile, tilePixelX, palette);

        m_viewBuffer.SetPixel(screenX, screenY, pixelColour);
    }
}

void PpuImpl::DrawWindowLine(uint8_t line)
{
    unsigned int screenY = line;
    unsigned int windowY = screenY - m_reg.windowPosY.Read();
    if (windowY >= GAMEBOY_HEIGHT)
        return;

    unsigned int tileY = windowY / TILE_HEIGHT_PX;
    unsigned int tilePixelY = windowY % TILE_HEIGHT_PX;

    Palette palette = ::LoadPalette(m_reg.bgPalette);
    const bool UseTileMap0 = GetBGAndWindowTileMapAreaType() == TileMapAreaType::ZERO;
    MappedMemoryBlock& tileMap = UseTileMap0
                                    ? m_reg.vram_tileMapBlock0
                                    : m_reg.vram_tileMapBlock1;

    for (unsigned int screenX = 0; screenX < GAMEBOY_WIDTH; screenX++)
    {
        /* Work out the position of the pixel in the framebuffer */
        unsigned int scrolledX = screenX + m_reg.windowPosX.Read() - 7;
        if (scrolledX >= GAMEBOY_WIDTH)
            return;

        /* Work out which tile of the bg_map this pixel is in, and the index of that tile
         * in the array of all tiles */
        unsigned int tileX = scrolledX / TILE_WIDTH_PX;
        unsigned int tilePixelX = scrolledX % TILE_WIDTH_PX;

        /* Work out the address of the tile ID from the tile map */
        unsigned int tileIdx = (tileY * TILES_PER_LINE) + tileX;

        /* Grab the ID of the tile we'll get data from in the tile map */
        uint8_t tileId = tileMap.Read(tileIdx);

        /* Calculate the offset from the start of the tile data memory where
         * the data for our tile lives */
        uint16_t tile = GetBGOrWindowTile(tileId, tilePixelY);
        GbColour pixelColour = GetColourFromTile(tile, tilePixelX, palette);

        m_viewBuffer.SetPixel(screenX, screenY, pixelColour);
    }
}

void PpuImpl::DrawSprite(uint8_t spriteId)
{
    // Load Object Attribute
    uint16_t oamAddress = spriteId * SPRITE_BYTES;

    // Directly read from oam since we have access
    uint8_t spriteY = m_oam.at(oamAddress);
    uint8_t spriteX = m_oam.at(oamAddress + 1);

    // Skip if the sprite is offscreen
    if (spriteY == 0 || spriteY >= 160) { return; }
    if (spriteX == 0 || spriteX >= 168) { return; }

    uint8_t tileIdx = m_oam.at(oamAddress + 2);
    bool largePixelMode = CheckBit<4>(m_reg.lcdControl.Read());

    uint8_t spriteFlags = m_oam.at(oamAddress + 3);
    if (largePixelMode)
    {
        // In Large Pixel mode (8x16), 
        SetBitToFalse<0>(tileIdx);
    }

    /* Bits 0-3 are used only for CGB */
    bool usePalette1 = CheckBit<4>(spriteFlags);
    bool flipX = CheckBit<5>(spriteFlags);
    bool flipY = CheckBit<6>(spriteFlags);
    bool priorityFlag = CheckBit<7>(spriteFlags);

    Palette palette = usePalette1
        ? LoadPalette(m_reg.spritePalette1)
        : LoadPalette(m_reg.spritePalette0);

    int startY = spriteY - 16;
    int startX = spriteX - 8;

    uint16_t maxTileOffset = (largePixelMode) ? 2 : 1;
    for (uint16_t tileOffset = 0; tileOffset < maxTileOffset; ++tileOffset)
    {
        startY += tileOffset * TILE_HEIGHT_PX;

        for (uint16_t y = 0; y < TILE_HEIGHT_PX; y++)
        {
            uint16_t tileData = GetObjTile(tileIdx + tileOffset, y);
            for (uint16_t x = 0; x < TILE_WIDTH_PX; x++)
            {
                uint16_t maybe_flipped_y = !flipY
                    ? y
                    : TILE_HEIGHT_PX - y - 1;

                uint16_t maybe_flipped_x = !flipX
                    ? x
                    : TILE_WIDTH_PX - x - 1;

                int screenX = startX + x;
                if (screenX < 0 || screenX >= GAMEBOY_WIDTH) { continue; }

                int screenY = startY + y;
                if (screenY < 0 || screenY >= GAMEBOY_HEIGHT) { continue; }

                GbColour colour = GetColourFromTile(tileData, x, palette);

                // Color 0 is transparent
                if (colour == GbColour::White) { continue; }

                auto existingPixel = m_viewBuffer.GetPixel(x, y);
                if (priorityFlag && existingPixel != GbColour::White) { continue; }

                m_viewBuffer.SetPixel(screenX, screenY, colour);
            }
        }
    }
}

// TODO: Deduplicate
uint16_t PpuImpl::GetObjTile(uint8_t tileId, uint8_t tileHeight)
{
    auto& lowerBlock = m_reg.vram_tileDataBlock0;
    auto& upperBlock = m_reg.vram_tileDataBlock1;

    return ::GetTileWord(lowerBlock, upperBlock, tileId, tileHeight);
}

uint16_t PpuImpl::GetBGOrWindowTile(uint8_t tileId, uint8_t tileHeight)
{
    auto type = GetBGAndWindowTileMapAreaType();
    auto& lowerBlock = (type == TileMapAreaType::ZERO)
                ? m_reg.vram_tileDataBlock0
                : m_reg.vram_tileDataBlock2;
    auto& upperBlock = m_reg.vram_tileDataBlock1;

    return ::GetTileWord(lowerBlock, upperBlock, tileId, tileHeight);
}

} // namespace detail

