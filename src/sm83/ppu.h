#pragma once

#include "cycles.h"

#include <cstdint>

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


private:
    Mmu& m_mmu;
    Mode m_mode;
    CCycles m_cycleCounter;
    uint8_t& m_register_lcdControl;
    uint8_t& m_register_lcdStatus;
    uint8_t& m_register_lcdYCoord;
    uint8_t& m_register_lcdLYCompare;
};
