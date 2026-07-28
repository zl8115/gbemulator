#pragma once

#include "frame_buffer.h"
#include "irenderer.h"
#include "types.h"

#include <array>
#include <cstdint>
#include <functional>

namespace gb {

class Ppu
{
public:
    enum class Mode
    {
        HBLANK = 0,
        VBLANK,
        OAM_SEARCH,
        PIXEL_TRANSFER,
    };

    // This map area points to different areas for Window, BG, BGAndWindow
    enum class TileMapAreaType
    {
        ZERO,
        ONE,
    };

    enum class ObjectSizeType
    {
        SMALL, // 8x8
        LONG,  // 8x16
    };

    Ppu();

    void Step(CCycles cycles);
    void RegisterRenderer(IRenderer* pRenderer);

    void SetDisplayOn();
    void SetDisplayOff();
    [[nodiscard]] bool IsDisplayOn() const;

    // Invoked when the PPU raises the VBLANK / LCD (STAT) interrupt, e.g. to let the
    // Mmu set the corresponding interrupt flag. Mirrors Timer::SetOverflowCallback.
    void SetVBlankInterruptCallback(std::function<void()> callback);
    void SetLcdInterruptCallback(std::function<void()> callback);

    [[nodiscard]] const FrameBuffer& GetViewBuffer() const { return m_viewBuffer; }

    [[nodiscard]] Reg8 Read(const Address address) const;
    void Write(const Address address, Reg8 byte);

private:
    // LCD Control checks
    [[nodiscard]] TileMapAreaType GetWindowTileMapAreaType() const;      // bit 6
    [[nodiscard]] bool IsWindowEnabled() const;                         // bit 5
    [[nodiscard]] TileMapAreaType GetBGAndWindowTileMapAreaType() const; // bit 4
    [[nodiscard]] ObjectSizeType ObjectSize() const;                    // bit 2
    [[nodiscard]] bool IsObjectEnabled() const;                         // bit 1
    [[nodiscard]] bool IsBGAndWindowEnabled() const;                    // bit 0

    // LCD Status checks
    [[nodiscard]] bool IsLYCIntSelect() const;   // bit 6
    [[nodiscard]] bool IsMode2IntSelect() const; // bit 5
    [[nodiscard]] bool IsMode1IntSelect() const; // bit 4
    [[nodiscard]] bool IsMode0IntSelect() const; // bit 3
    bool IsLYAndLYCEqual();                      // bit 2 (also updates STAT bit 2 as a side effect)
    [[nodiscard]] Mode GetPpuMode() const;       // bit 1 & 0
    void SetPpuMode(Mode mode);                  // bit 1 & 0

    void Render();
    void WriteScanline(uint8_t line);
    void WriteSprites();

    void DrawBGLine(uint8_t line);
    void DrawWindowLine(uint8_t line);
    void DrawSprite(uint8_t spriteId);
    [[nodiscard]] uint16_t GetObjTile(uint8_t tileId, uint8_t tileHeight) const;
    [[nodiscard]] uint16_t GetBGOrWindowTile(uint8_t tileId, uint8_t tileHeight) const;
    [[nodiscard]] uint16_t GetTileWord(std::size_t lowerBase, std::size_t upperBase, uint8_t tileId, uint8_t tileHeight) const;

    IRenderer* m_pRenderer = nullptr;
    CCycles m_cycleCounter{0};
    std::function<void()> m_vblankInterruptCallback;
    std::function<void()> m_lcdInterruptCallback;

    std::array<Reg8, 0x2000> m_vram{};
    std::array<Reg8, 0xA0> m_oam{};

    Reg8 m_lcdControl = 0;
    Reg8 m_lcdStatus = 0;
    Reg8 m_scx = 0;
    Reg8 m_scy = 0;
    Reg8 m_ly = 0;
    Reg8 m_lyc = 0;
    Reg8 m_bgPalette = 0;
    Reg8 m_objPalette0 = 0;
    Reg8 m_objPalette1 = 0;
    Reg8 m_windowPosY = 0;
    Reg8 m_windowPosX = 0;

    FrameBuffer m_viewBuffer{GAMEBOY_WIDTH, GAMEBOY_HEIGHT};
};

} // namespace gb
