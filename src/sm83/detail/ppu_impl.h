#pragma once

#include "cycles.h"
#include "mmu.h"
#include "mmu_mapped_register.h"
#include "frame_buffer.h"
#include "irenderer.h"

#include <cstdint>
#include <array>

namespace detail {

class Pallete 
{
public:
    Pallete():
        m_colours({Colour::White, Colour::LightGrey, Colour::DarkGrey, Colour::Black})
    {}

    Pallete(Colour c0, Colour c1, Colour c2, Colour c3):
        m_colours({c0, c1, c2, c3})
    {}

    const Colour& operator[] (unsigned short index) const
    {
        return m_colours[index];
    }

private:
    std::array<Colour, 4> m_colours;
};

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

    void Step(CCycles cycles);
    void Render() const;
    void RegisterRenderer(IRenderer* pRenderer);
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

        MappedRegisterBlock vram_tileDataBlock0;
        MappedRegisterBlock vram_tileDataBlock1;
        MappedRegisterBlock vram_tileDataBlock2;
        MappedRegisterBlock vram_tileMapBlock0;
        MappedRegisterBlock vram_tileMapBlock1;
        MappedRegisterBlock oam;
        MappedByteRegister lcdControl;
        MappedByteRegister lcdStatus;
        MappedByteRegister viewScrollX;
        MappedByteRegister viewScrollY;
        MappedByteRegister lcdYCoord;
        MappedByteRegister lcdLYCompare;
        MappedByteRegister dmaStartAddress;
        MappedByteRegister bgPallete;
        MappedByteRegister spritePalette0;
        MappedByteRegister spritePalette1;
        MappedByteRegister windowPosY;
        MappedByteRegister windowPosX;
    };

    void WriteScanline(uint8_t line);
    void WriteSprites();

    void DrawBGLine(uint8_t line);
    void DrawWindowLine(uint8_t line);
    uint16_t GetObjTile(uint8_t tileId);
    uint16_t GetBGOrWindowTile(uint8_t tileId);

    IRenderer* m_pRenderer;
    Mmu& m_mmu;
    CCycles m_cycleCounter;
    MappedRegisters m_reg;
    FrameBuffer m_viewBuffer;
};

} // namespace detail
