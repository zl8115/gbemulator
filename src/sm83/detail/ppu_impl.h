#pragma once

#include "cycles.h"
#include "mmu.h"
#include "mmu_mapped_register.h"
#include "frame_buffer.h"
#include "irenderer.h"

#include <cstdint>

namespace detail {

class PpuImpl
{
public:
    PpuImpl(Mmu& mmu);

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

    bool ShouldRender();
    void Step(CCycles cycles);
    const FrameBuffer& GetViewBuffer() const;

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

        MappedByteRegister<0xFF40> lcdControl;
        MappedByteRegister<0xFF41> lcdStatus;
        MappedByteRegister<0xFF42> viewScrollX;
        MappedByteRegister<0xFF43> viewScrollY;
        MappedByteRegister<0xFF44> lcdYCoord;
        MappedByteRegister<0xFF45> lcdLYCompare;
        MappedByteRegister<0xFF46> dmaStartAddress;
        MappedByteRegister<0xFF47> bgPallete;
        MappedByteRegister<0xFF48> spritePalette0;
        MappedByteRegister<0xFF49> spritePalette1;
        MappedByteRegister<0xFF4A> windowPosY;
        MappedByteRegister<0xFF4B> windowPosX;
        MappedRegisterRegion<0x8000, 0x2000> vram;
        MappedRegisterRegion<0xFE00, 0x00A0> oam;
    };

    void WriteScanline(uint8_t line);
    void WriteSprites();

    bool m_shouldRender;
    Mmu& m_mmu;
    CCycles m_cycleCounter;
    MappedRegisters m_reg;

    FrameBuffer m_viewBuffer;
    FrameBuffer m_mapBuffer;
};

class PpuDrawer
{

};

} // namespace detail
