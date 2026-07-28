#include "ppu.h"

#include "detail/palette.h"
#include "mmu_register_names.h"
#include "utils/bitmanip.h"

#include <stdexcept>

namespace gb {

namespace {

const CCycles CLOCKS_PER_HBLANK{204};       // Mode 0
const CCycles CLOCKS_PER_SCANLINE_OAM{80};  // Mode 2
const CCycles CLOCKS_PER_SCANLINE_VRAM{172}; // Mode 3
const CCycles CLOCKS_PER_SCANLINE = CLOCKS_PER_SCANLINE_OAM + CLOCKS_PER_SCANLINE_VRAM + CLOCKS_PER_HBLANK;

constexpr uint16_t OBJECT_ATTRIBUTE_SIZE = 4;

detail::Palette LoadPalette(Reg8 paletteValue)
{
    GbColour c0 = static_cast<GbColour>(paletteValue & 0b00000011);
    GbColour c1 = static_cast<GbColour>((paletteValue & 0b00001100) >> 2);
    GbColour c2 = static_cast<GbColour>((paletteValue & 0b00110000) >> 4);
    GbColour c3 = static_cast<GbColour>((paletteValue & 0b11000000) >> 6);

    return {c0, c1, c2, c3};
}

GbColour GetColourFromTile(const uint16_t tileData, const uint8_t pixelIdx, const detail::Palette& palette)
{
    unsigned short pixel = (utils::CheckBit(utils::Msb(tileData), 7 - pixelIdx) << 1) | (utils::CheckBit(utils::Lsb(tileData), 7 - pixelIdx));
    return palette[pixel];
}

} // namespace

Ppu::Ppu() = default;

void Ppu::Step(CCycles cycles)
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
            uint8_t line = m_ly;

            WriteScanline(line);
            m_ly = ++line;

            m_cycleCounter %= CLOCKS_PER_HBLANK;

            // Line 145 (index 144) is the first line of VBLANK
            if (line == 144)
            {
                SetPpuMode(Mode::VBLANK);
                if (m_vblankInterruptCallback)
                    m_vblankInterruptCallback();
                if (IsMode1IntSelect() && m_lcdInterruptCallback)
                    m_lcdInterruptCallback();
            }
            else
            {
                SetPpuMode(Mode::OAM_SEARCH);
                if (IsMode2IntSelect() && m_lcdInterruptCallback)
                    m_lcdInterruptCallback();
            }
        }
        break;
    }
    case Mode::VBLANK:
    {
        if (m_cycleCounter >= CLOCKS_PER_SCANLINE)
        {
            uint8_t line = m_ly;
            m_ly = ++line;

            m_cycleCounter %= CLOCKS_PER_SCANLINE;

            // Line 155 (index 154) is the last line
            if (line == 154)
            {
                WriteSprites();
                Render();
                m_ly = 0;

                SetPpuMode(Mode::OAM_SEARCH);
                if (IsMode2IntSelect() && m_lcdInterruptCallback)
                    m_lcdInterruptCallback();
            }
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
            if (IsMode0IntSelect() && m_lcdInterruptCallback)
                m_lcdInterruptCallback();

            if (IsLYCIntSelect() && IsLYAndLYCEqual() && m_lcdInterruptCallback)
                m_lcdInterruptCallback();
        }
        break;
    }
    default:
        throw std::runtime_error("Unexpected ppu mode");
    }
}

void Ppu::Render()
{
    if (m_pRenderer)
    {
        m_pRenderer->Render(m_viewBuffer);
    }
}

void Ppu::SetDisplayOn()
{
    utils::SetBitToTrue<0>(m_lcdControl);
    utils::SetBitToTrue<1>(m_lcdControl);
    utils::SetBitToTrue<5>(m_lcdControl);
    utils::SetBitToTrue<7>(m_lcdControl);
}

void Ppu::SetDisplayOff()
{
    utils::SetBitToFalse<0>(m_lcdControl);
    utils::SetBitToFalse<1>(m_lcdControl);
    utils::SetBitToFalse<5>(m_lcdControl);
    utils::SetBitToFalse<7>(m_lcdControl);
}

void Ppu::RegisterRenderer(IRenderer* pRenderer)
{
    m_pRenderer = pRenderer;
}

void Ppu::SetVBlankInterruptCallback(std::function<void()> callback)
{
    m_vblankInterruptCallback = std::move(callback);
}

void Ppu::SetLcdInterruptCallback(std::function<void()> callback)
{
    m_lcdInterruptCallback = std::move(callback);
}

/*     ************** LCD Control Checks *************     */
bool Ppu::IsDisplayOn() const
{
    return utils::CheckBit<7>(m_lcdControl);
}

Ppu::TileMapAreaType Ppu::GetWindowTileMapAreaType() const
{
    return utils::CheckBit<6>(m_lcdControl) ? TileMapAreaType::ONE : TileMapAreaType::ZERO;
}

bool Ppu::IsWindowEnabled() const
{
    return utils::CheckBit<5>(m_lcdControl);
}

Ppu::TileMapAreaType Ppu::GetBGAndWindowTileMapAreaType() const
{
    return utils::CheckBit<4>(m_lcdControl) ? TileMapAreaType::ZERO : TileMapAreaType::ONE;
}

Ppu::ObjectSizeType Ppu::ObjectSize() const
{
    return utils::CheckBit<2>(m_lcdControl) ? ObjectSizeType::LONG : ObjectSizeType::SMALL;
}

bool Ppu::IsObjectEnabled() const
{
    return utils::CheckBit<1>(m_lcdControl);
}

bool Ppu::IsBGAndWindowEnabled() const
{
    return utils::CheckBit<0>(m_lcdControl);
}

/*     ************** LCD Status Checks *************     */
bool Ppu::IsLYCIntSelect() const
{
    return utils::CheckBit<6>(m_lcdStatus);
}

bool Ppu::IsMode2IntSelect() const
{
    return utils::CheckBit<5>(m_lcdStatus);
}

bool Ppu::IsMode1IntSelect() const
{
    return utils::CheckBit<4>(m_lcdStatus);
}

bool Ppu::IsMode0IntSelect() const
{
    return utils::CheckBit<3>(m_lcdStatus);
}

bool Ppu::IsLYAndLYCEqual()
{
    utils::SetBitTo<2>(m_lcdStatus, m_ly == m_lyc);
    return utils::CheckBit<2>(m_lcdStatus);
}

Ppu::Mode Ppu::GetPpuMode() const
{
    unsigned short ppuMode = m_lcdStatus & 0b11;
    return static_cast<Mode>(ppuMode);
}

void Ppu::SetPpuMode(Mode mode)
{
    short v_mode = static_cast<short>(mode);
    utils::SetBitTo<0>(m_lcdStatus, v_mode & 0b01);
    utils::SetBitTo<1>(m_lcdStatus, v_mode & 0b10);
}

Reg8 Ppu::Read(const Address address) const
{
    if (address >= REGION_VRAM_START && address <= REGION_VRAM_END)
        return m_vram[address - REGION_VRAM_START];

    if (address >= REGION_OAM_START && address <= REGION_OAM_END)
        return m_oam[address - REGION_OAM_START];

    switch (address)
    {
    case REG_LCD_CONTROL:       return m_lcdControl;
    case REG_LCD_STATUS:        return m_lcdStatus;
    case REG_LCD_VIEW_SCROLL_Y: return m_scy;
    case REG_LCD_VIEW_SCROLL_X: return m_scx;
    case REG_LCD_Y_COORDINATE:  return m_ly;
    case REG_LCD_LY_COMPARE:    return m_lyc;
    case REG_BG_PALETTE:        return m_bgPalette;
    case REG_SPRITE_PALETTE_0:  return m_objPalette0;
    case REG_SPRITE_PALETTE_1:  return m_objPalette1;
    case REG_WINDOW_POS_Y:      return m_windowPosY;
    case REG_WINDOW_POS_X:      return m_windowPosX;
    default:                    return 0xFF;
    }
}

void Ppu::Write(const Address address, Reg8 byte)
{
    if (address >= REGION_VRAM_START && address <= REGION_VRAM_END)
    {
        m_vram[address - REGION_VRAM_START] = byte;
        return;
    }

    if (address >= REGION_OAM_START && address <= REGION_OAM_END)
    {
        m_oam[address - REGION_OAM_START] = byte;
        return;
    }

    switch (address)
    {
    case REG_LCD_CONTROL:       m_lcdControl = byte; break;
    case REG_LCD_STATUS:        m_lcdStatus = byte; break;
    case REG_LCD_VIEW_SCROLL_Y: m_scy = byte; break;
    case REG_LCD_VIEW_SCROLL_X: m_scx = byte; break;
    case REG_LCD_Y_COORDINATE:  m_ly = byte; break;
    case REG_LCD_LY_COMPARE:    m_lyc = byte; break;
    case REG_BG_PALETTE:        m_bgPalette = byte; break;
    case REG_SPRITE_PALETTE_0:  m_objPalette0 = byte; break;
    case REG_SPRITE_PALETTE_1:  m_objPalette1 = byte; break;
    case REG_WINDOW_POS_Y:      m_windowPosY = byte; break;
    case REG_WINDOW_POS_X:      m_windowPosX = byte; break;
    default: break;
    }
}

/*     ************** Private Methods *************     */
void Ppu::WriteScanline(uint8_t line)
{
    if (!IsDisplayOn())
        return;

    if (IsBGAndWindowEnabled())
    {
        DrawBGLine(line);

        if (IsWindowEnabled())
        {
            DrawWindowLine(line);
        }
    }
}

void Ppu::WriteSprites()
{
    if (!IsDisplayOn() || !IsObjectEnabled())
        return;

    for (int ii = 0; ii < 40; ++ii)
    {
        DrawSprite(ii);
    }
}

void Ppu::DrawBGLine(uint8_t line)
{
    detail::Palette palette = LoadPalette(m_bgPalette);

    const bool UseTileMap0 = GetBGAndWindowTileMapAreaType() == TileMapAreaType::ZERO;
    std::size_t tileMapBase = UseTileMap0 ? 0x1800 : 0x1C00;

    // The pixel coord relative to the View Port
    unsigned int renderY = line;

    // The absolute pixel coord to the Background
    unsigned int backgroundY = (renderY + m_scy) % BG_MAP_SIZE;

    // Translate the pixel coord to Tiles coord
    // The Tile coord and pixel coord relative to the Tile
    unsigned int tileY = backgroundY / TILE_HEIGHT_PX;
    unsigned int tilePixelY = backgroundY % TILE_HEIGHT_PX;

    for (unsigned int renderX = 0; renderX < GAMEBOY_WIDTH; ++renderX)
    {
        // Do the same coord translations but for the X coords
        unsigned int mapX = (renderX + m_scx) % BG_MAP_SIZE;
        unsigned int bgMapX = mapX % BG_MAP_SIZE;

        unsigned int tileX = bgMapX / TILE_WIDTH_PX;
        unsigned int tilePixelX = bgMapX % TILE_WIDTH_PX;

        // Translate the Tile coord's into the relative index (address)
        unsigned int tileIdx = tileY * TILES_PER_LINE + tileX;

        // Lookup the Tile ID from the selected Tile Map
        uint8_t tileId = m_vram[tileMapBase + tileIdx];

        // Load the Tile Data of the Tile ID
        uint16_t tile = GetBGOrWindowTile(tileId, tilePixelY);

        // Read and set the Colour of the Tile Data for the current pixel
        GbColour pixelColour = GetColourFromTile(tile, tilePixelX, palette);
        m_viewBuffer.SetPixel(renderX, renderY, pixelColour);
    }
}

void Ppu::DrawWindowLine(uint8_t line)
{
    detail::Palette palette = LoadPalette(m_bgPalette);
    const bool UseTileMap0 = GetWindowTileMapAreaType() == TileMapAreaType::ZERO;
    std::size_t tileMapBase = UseTileMap0 ? 0x1800 : 0x1C00;

    // N.B. Window is NOT the same as View Port. "Window" in this context refers
    // to the layer being rendered above the background. Whose position is
    // relative to the "View Port" - the render screen.

    // The pixel coord relative to the View Port
    unsigned int renderY = line;

    // Shift the pixel coord relative to the Window Position (offset)
    unsigned int windowY = renderY - m_windowPosY;
    if (windowY >= GAMEBOY_HEIGHT)
        return;

    // Translate the pixel coord to Tiles coord
    // The Tile coord and pixel coord relative to the Tile
    unsigned int tileY = windowY / TILE_HEIGHT_PX;
    unsigned int tilePixelY = windowY % TILE_HEIGHT_PX;

    for (unsigned int renderX = 0; renderX < GAMEBOY_WIDTH; ++renderX)
    {
        // Do the same coord translations but for the X coords
        // But also account for the 7 pixels offset it has.
        // Known: underflows (wraps to a huge value) when windowPosX < 7 and renderX is
        // small — preserved from the original, which had its bounds check commented out
        // here too. See plan.md.
        unsigned int windowX = renderX + m_windowPosX - 7;

        unsigned int tileX = windowX / TILE_WIDTH_PX;
        unsigned int tilePixelX = windowX % TILE_WIDTH_PX;

        // Translate the Tile coord's into the relative index (address)
        unsigned int tileIdx = (tileY * TILES_PER_LINE) + tileX;

        // Lookup the Tile ID from the selected Tile Map
        uint8_t tileId = m_vram[tileMapBase + tileIdx];

        // Load the Tile Data of the Tile ID
        uint16_t tile = GetBGOrWindowTile(tileId, tilePixelY);

        // Read and set the Colour of the Tile Data for the current pixel
        GbColour pixelColour = GetColourFromTile(tile, tilePixelX, palette);
        m_viewBuffer.SetPixel(renderX, renderY, pixelColour);
    }
}

void Ppu::DrawSprite(uint8_t spriteId)
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
    const bool LargePixelMode = utils::CheckBit<4>(m_lcdControl);
    if (LargePixelMode)
    {
        // In Large Pixel mode (8x16), the tileIdx byte specifies the
        // index of the first (top) tile of the object
        utils::SetBitToFalse<0>(tileIdx);
    }

    // Load Object Flags
    uint8_t spriteFlags = m_oam.at(oamAddress + 3);

    // Bits 0-3 are used only for CGB
    const bool UsePalette1 = utils::CheckBit<4>(spriteFlags);
    const bool FlipX = utils::CheckBit<5>(spriteFlags);
    const bool FlipY = utils::CheckBit<6>(spriteFlags);
    const bool PriorityFlag = utils::CheckBit<7>(spriteFlags);

    detail::Palette palette = UsePalette1
        ? LoadPalette(m_objPalette1)
        : LoadPalette(m_objPalette0);

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
                // Known bug (preserved, see plan.md): FlipX/FlipY are computed but
                // never actually used below — sprite X/Y flip has no effect.
                uint16_t maybe_flipped_y = !FlipY
                    ? y
                    : TILE_HEIGHT_PX - y - 1;

                uint16_t maybe_flipped_x = !FlipX
                    ? x
                    : TILE_WIDTH_PX - x - 1;

                int pixelX = renderX + x;
                if (pixelX < 0 || pixelX >= static_cast<int>(GAMEBOY_WIDTH)) { continue; }

                int pixelY = renderY + y;
                if (pixelY < 0 || pixelY >= static_cast<int>(GAMEBOY_HEIGHT)) { continue; }

                GbColour colour = GetColourFromTile(tileData, x, palette);

                // Color 0 is transparent
                if (colour == GbColour::White) { continue; }

                // Known bug (preserved, see plan.md): this reads back the tile-local (x, y)
                // instead of the destination (pixelX, pixelY), so the OBJ-vs-BG priority
                // check below is comparing against the wrong pixel almost every time.
                auto existingPixel = m_viewBuffer.GetPixel(x, y);
                if (PriorityFlag && existingPixel != GbColour::White) { continue; }

                m_viewBuffer.SetPixel(pixelX, pixelY, colour);
            }
        }
    }
}

uint16_t Ppu::GetTileWord(std::size_t lowerBase, std::size_t upperBase, uint8_t tileId, uint8_t tileHeight) const
{
    // Each tile is 16 bytes, 2 bytes per row
    uint16_t address = ((tileId % 128) * BYTES_PER_TILE) + (tileHeight * 2);
    if (tileId > 127)
    {
        return utils::ToWord(m_vram[upperBase + address + 1], m_vram[upperBase + address]);
    }
    return utils::ToWord(m_vram[lowerBase + address + 1], m_vram[lowerBase + address]);
}

uint16_t Ppu::GetObjTile(uint8_t tileId, uint8_t tileHeight) const
{
    return GetTileWord(0x0000, 0x0800, tileId, tileHeight);
}

uint16_t Ppu::GetBGOrWindowTile(uint8_t tileId, uint8_t tileHeight) const
{
    auto type = GetBGAndWindowTileMapAreaType();
    std::size_t lowerBase = (type == TileMapAreaType::ZERO) ? 0x0000 : 0x1000;
    return GetTileWord(lowerBase, 0x0800, tileId, tileHeight);
}

} // namespace gb
