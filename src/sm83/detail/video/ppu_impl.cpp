#include "detail/video/ppu_impl.h"

#include "bitmanip.h"
#include "frame_buffer.h"
#include "irenderer.h"
#include "detail/impl_helper.h"
#include "detail/register_names.h"
#include "detail/logger.h"
#include "detail/video/palette.h"
#include "detail/memory/mmu_impl.h"
#include "detail/memory/formatter.h"

#include <cstdint>
#include <stdexcept>

static const CCycles CLOCKS_PER_HBLANK = 204; /* Mode 0 */
static const CCycles CLOCKS_PER_SCANLINE_OAM = 80; /* Mode 2 */
static const CCycles CLOCKS_PER_SCANLINE_VRAM = 172; /* Mode 3 */
static const CCycles CLOCKS_PER_SCANLINE = (CLOCKS_PER_SCANLINE_OAM + CLOCKS_PER_SCANLINE_VRAM + CLOCKS_PER_HBLANK);

static const CCycles CLOCKS_PER_VBLANK = 4560; /* Mode 1 */
static const CCycles SCANLINES_PER_FRAME = 144;
static const CCycles CLOCKS_PER_FRAME = (CLOCKS_PER_SCANLINE * SCANLINES_PER_FRAME) + CLOCKS_PER_VBLANK;

static const uint16_t OBJECT_ATTRIBUTE_SIZE = 4;

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

inline uint16_t GetTileWord(detail::MappedMemoryBlock<0x800>& lowerBlock, detail::MappedMemoryBlock<0x800>& upperBlock, uint8_t tileId, uint8_t tileHeight)
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
    unsigned short pixel = (CheckBit(Msb(tileData), 7 - pixelIdx) << 1) | (CheckBit(Lsb(tileData), 7 - pixelIdx));
    return palette[pixel];
}

} // namespace

namespace detail {

PpuImpl::MappedMemory::MappedMemory(PpuImpl& ppu, MmuImpl& mmu):
    vram_tileDataBlock0 (ppu.m_vram, 0x0000),
    vram_tileDataBlock1 (ppu.m_vram, 0x0800),
    vram_tileDataBlock2 (ppu.m_vram, 0x1000),
    vram_tileMapBlock0  (ppu.m_vram, 0x1800),
    vram_tileMapBlock1  (ppu.m_vram, 0x1C00),
    oam                 (ppu.m_oam,  0x0000),
    lcdControl          (mmu.GetMappedRegister(REG_LCD_CONTROL)),
    lcdStatus           (mmu.GetMappedRegister(REG_LCD_STATUS)),
    viewScrollX         (mmu.GetMappedRegister(REG_LCD_VIEW_SCROLL_X)),
    viewScrollY         (mmu.GetMappedRegister(REG_LCD_VIEW_SCROLL_Y)),
    lcdYCoord           (mmu.GetMappedRegister(REG_LCD_Y_COORDINATE)),
    lcdLYCompare        (mmu.GetMappedRegister(REG_LCD_LY_COMPARE)),
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
    m_pMappedVram(std::make_unique<MappedMemoryBlock<0x2000>>(m_vram, 0)),
    m_pMappedOam(std::make_unique<MappedMemoryBlock<0xA0>>(m_oam, 0)),
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
                    if (IsMode1IntSelect())
                    {
                        m_mmu.SetInterruptFlag<Mmu::InterruptType::LCD>();
                    }
                }
                else
                {
                    SetPpuMode(Mode::OAM_SEARCH);
                    if (IsMode2IntSelect())
                    {
                        m_mmu.SetInterruptFlag<Mmu::InterruptType::LCD>();
                    }
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
                    m_reg.lcdYCoord.Write(0);

                    SetPpuMode(Mode::OAM_SEARCH);
                    if (IsMode2IntSelect())
                    {
                        m_mmu.SetInterruptFlag<Mmu::InterruptType::LCD>();
                    }
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
                    m_mmu.SetInterruptFlag<Mmu::InterruptType::LCD>();
                }

                if (IsLYCIntSelect() && IsLYAndLYCEqual())
                {
                    m_mmu.SetInterruptFlag<Mmu::InterruptType::LCD>();
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
        GbStateLogger::Log(m_viewBuffer);
        GbStateLogger::LogState(m_mmu);
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
        PpuImpl::TileMapAreaType::ZERO :
        PpuImpl::TileMapAreaType::ONE;
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

WeakMappedMemoryBlock<0x2000> PpuImpl::GetMemoryVram() const
{
    return WeakMappedMemoryBlock<0x2000>(m_pMappedVram);
}

WeakMappedMemoryBlock<0xA0> PpuImpl::GetMemoryOam() const
{
    return WeakMappedMemoryBlock<0xA0>(m_pMappedOam);
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

    const bool UseTileMap0 = GetBGAndWindowTileMapAreaType() == TileMapAreaType::ZERO;
    MappedMemoryBlock<0x400>& tileMap = UseTileMap0
                                    ? m_reg.vram_tileMapBlock0
                                    : m_reg.vram_tileMapBlock1;

    // The pixel coord relative to the View Port
    unsigned int renderY = line;

    // The absolute pixel coord to the Background
    unsigned int backgroundY = (renderY + m_reg.viewScrollY.Read()) % BG_MAP_SIZE; 

    // Translate the pixel coord to Tiles coord
    // The Tile coord and pixel coord relative to the Tile
    unsigned int tileY = backgroundY / TILE_HEIGHT_PX;
    unsigned int tilePixelY = backgroundY % TILE_HEIGHT_PX;

    for (unsigned int renderX = 0; renderX < GAMEBOY_WIDTH; ++renderX)
    {
        // Do the same coord translations but for the X coords
        unsigned int mapX = (renderX + m_reg.viewScrollX.Read()) % BG_MAP_SIZE;
        unsigned int bgMapX = mapX % BG_MAP_SIZE;

        unsigned int tileX = bgMapX / TILE_WIDTH_PX;
        unsigned int tilePixelX = bgMapX % TILE_WIDTH_PX;

        // Translate the Tile coord's into the relative index (address)
        unsigned int tileIdx = tileY * TILES_PER_LINE + tileX;

        // Lookup the Tile ID from the selected Tile Map
        uint8_t tileId = tileMap.Read(tileIdx);

        // Load the Tile Data of the Tile ID
        uint16_t tile = GetBGOrWindowTile(tileId, tilePixelY);

        // Read and set the Colour of the Tile Data for the current pixel
        GbColour pixelColour = GetColourFromTile(tile, tilePixelX, palette);
        m_viewBuffer.SetPixel(renderX, renderY, pixelColour);
    }
}

void PpuImpl::DrawWindowLine(uint8_t line)
{
    Palette palette = ::LoadPalette(m_reg.bgPalette);
    const bool UseTileMap0 = GetWindowTileMapAreaType() == TileMapAreaType::ZERO;
    MappedMemoryBlock<0x400>& tileMap = UseTileMap0
                                    ? m_reg.vram_tileMapBlock0
                                    : m_reg.vram_tileMapBlock1;

    // N.B. Window is NOT the same as View Port. "Window" in this context refers
    // to the layer being rendered above the background. Whose position is 
    // relative to the "View Port" - the render screen.

    // The pixel coord relative to the View Port
    unsigned int renderY = line;

    // Shift the pixel coord relative to the Window Position (offset)
    unsigned int windowY = renderY - m_reg.windowPosY.Read();
    if (windowY >= GAMEBOY_HEIGHT)
        return;

    // Translate the pixel coord to Tiles coord
    // The Tile coord and pixel coord relative to the Tile
    unsigned int tileY = windowY / TILE_HEIGHT_PX;
    unsigned int tilePixelY = windowY % TILE_HEIGHT_PX;

    for (unsigned int renderX = 0; renderX < GAMEBOY_WIDTH; ++renderX)
    {
        // Do the same coord translations but for the X coords
        // But also account for the 7 pixels offset it has
        unsigned int windowX = renderX + m_reg.windowPosX.Read() - 7;
        // if (scrolledX >= GAMEBOY_WIDTH)
        //     return;

        unsigned int tileX = windowX / TILE_WIDTH_PX;
        unsigned int tilePixelX = windowX % TILE_WIDTH_PX;

        // TODO: Deduplicate with BG
        // Translate the Tile coord's into the relative index (address)
        unsigned int tileIdx = (tileY * TILES_PER_LINE) + tileX;

        // Lookup the Tile ID from the selected Tile Map
        uint8_t tileId = tileMap.Read(tileIdx);

        // Load the Tile Data of the Tile ID
        uint16_t tile = GetBGOrWindowTile(tileId, tilePixelY);

        // Read and set the Colour of the Tile Data for the current pixel
        GbColour pixelColour = GetColourFromTile(tile, tilePixelX, palette);
        m_viewBuffer.SetPixel(renderX, renderY, pixelColour);
    }
}

void PpuImpl::DrawSprite(uint8_t spriteId)
{
    // Load Object Coords
    uint16_t oamAddress = spriteId * OBJECT_ATTRIBUTE_SIZE;
    uint8_t mapY = m_oam.at(oamAddress);
    uint8_t mapX = m_oam.at(oamAddress + 1);

    // Skip if the sprite is offscreen
    if (mapY == 0 || mapY >= 160) { return; }
    if (mapX == 0 || mapX >= 168) { return; }

    // Load Object Tile Index
    uint8_t tileIdx = m_oam.at(oamAddress + 2);
    const bool LargePixelMode = CheckBit<4>(m_reg.lcdControl.Read());
    if (LargePixelMode)
    {
        // In Large Pixel mode (8x16), the tileIdx byte specifies the
        // index of the first (top) tile of the object
        SetBitToFalse<0>(tileIdx);
    }

    // Load Object Flags
    uint8_t spriteFlags = m_oam.at(oamAddress + 3);

    // Bits 0-3 are used only for CGB
    const bool UsePalette1 = CheckBit<4>(spriteFlags);
    const bool FlipX = CheckBit<5>(spriteFlags);
    const bool FlipY = CheckBit<6>(spriteFlags);
    const bool PriorityFlag = CheckBit<7>(spriteFlags);

    Palette palette = UsePalette1
        ? LoadPalette(m_reg.spritePalette1)
        : LoadPalette(m_reg.spritePalette0);

    // "Start" pixel coords (top-left) of the Object
    int renderY = mapY - 16;
    int renderX = mapX - 8;

    // Iterate twice in Large Pixel Mode (16x8)
    uint16_t maxTileOffset = (LargePixelMode) ? 2 : 1;
    for (uint16_t tileOffset = 0; tileOffset < maxTileOffset; ++tileOffset)
    {
        // Offset the "Start" coord in Large Pixel Mode
        renderY += tileOffset * TILE_HEIGHT_PX;

        for (uint16_t y = 0; y < TILE_HEIGHT_PX; ++y)
        {
            uint16_t tileData = GetObjTile(tileIdx + tileOffset, y);
            for (uint16_t x = 0; x < TILE_WIDTH_PX; ++x)
            {
                uint16_t maybe_flipped_y = !FlipY
                    ? y
                    : TILE_HEIGHT_PX - y - 1;

                uint16_t maybe_flipped_x = !FlipX
                    ? x
                    : TILE_WIDTH_PX - x - 1;

                int pixelX = renderX + x;
                if (pixelX < 0 || pixelX >= GAMEBOY_WIDTH) { continue; }

                int pixelY = renderY + y;
                if (pixelY < 0 || pixelY >= GAMEBOY_HEIGHT) { continue; }

                GbColour colour = GetColourFromTile(tileData, x, palette);

                // Color 0 is transparent
                if (colour == GbColour::White) { continue; }

                auto existingPixel = m_viewBuffer.GetPixel(x, y);
                if (PriorityFlag && existingPixel != GbColour::White) { continue; }

                m_viewBuffer.SetPixel(pixelX, pixelY, colour);
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
