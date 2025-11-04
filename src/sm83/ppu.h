#pragma once

#include "cycles.h"
#include "frame_buffer.h"
#include "irenderer.h"

#include <cstdint>
#include <memory>
#include <span>

class Mmu;

class Ppu
{
public:
    Ppu(Mmu& mmu);

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

    void Step(CCycles cycles);
    void RegisterRenderer(std::shared_ptr<IRenderer> pRenderer);

    // LCD Control Checks
    bool            IsDisplayOn()                   const; // bit 7
    TileMapAreaType GetWindowTileMapAreaType()      const; // bit 6
    bool            IsWindowEnabled()               const; // bit 5
    TileMapAreaType GetBGAndWindowTileMapAreaType() const; // bit 4
    TileMapAreaType GetBGTileMapAreaType()          const; // bit 3
    ObjectSizeType  ObjectSize()                    const; // bit 2
    bool            IsObjectEnabled()               const; // bit 1
    bool            IsBGAndWindowEnabled()          const; // bit 0

    // LCD Status Checks
    bool            IsLYCIntSelect()                const; // bit 6
    bool            IsMode2IntSelect()              const; // bit 5
    bool            IsMode1IntSelect()              const; // bit 4
    bool            IsMode0IntSelect()              const; // bit 3
    bool            IsLYAndLYCEqual()               const; // bit 2
    Mode            GetPpuMode()                    const; // bit 1 & 0

    void            SetPpuMode(Mode mode);                 // bit 1 & 0

private:
    struct MappedRegisters
    {
        MappedRegisters(Mmu& mmu);

        uint8_t& lcdControl;
        uint8_t& lcdStatus;
        uint8_t& viewScrollX;
        uint8_t& viewScrollY;
        uint8_t& lcdYCoord;
        uint8_t& lcdLYCompare;
        uint8_t& dmaStartAddress;
        uint8_t& bgPallete;
        uint8_t& spritePalette0;
        uint8_t& spritePalette1;
        uint8_t& windowPosY;
        uint8_t& windowPosX;
    };

    void WriteScanline(uint8_t line);
    void WriteSprites();
    void Render();

    Mmu& m_mmu;
    MappedRegisters m_reg;

    std::shared_ptr<IRenderer> m_renderer;
    CCycles m_cycleCounter;
    FrameBuffer m_viewBuffer;
    FrameBuffer m_mapBuffer;
    std::span<uint8_t, 0x2000> m_vram;
};
