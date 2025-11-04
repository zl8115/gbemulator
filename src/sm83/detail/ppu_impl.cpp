#include "ppu.h"
#include "ppu_impl.h"
#include "mmu.h"
#include "frame_buffer.h"
#include "irenderer.h"
#include "util_bitmanip.h"

#include <cstdint>
#include <stdexcept>

static const CCycles CLOCKS_PER_HBLANK = 204; /* Mode 0 */
static const CCycles CLOCKS_PER_SCANLINE_OAM = 80; /* Mode 2 */
static const CCycles CLOCKS_PER_SCANLINE_VRAM = 172; /* Mode 3 */
static const CCycles CLOCKS_PER_SCANLINE = (CLOCKS_PER_SCANLINE_OAM + CLOCKS_PER_SCANLINE_VRAM + CLOCKS_PER_HBLANK);

static const CCycles CLOCKS_PER_VBLANK = 4560; /* Mode 1 */
static const CCycles SCANLINES_PER_FRAME = 144;
static const CCycles CLOCKS_PER_FRAME = (CLOCKS_PER_SCANLINE * SCANLINES_PER_FRAME) + CLOCKS_PER_VBLANK;

constexpr uint GAMEBOY_WIDTH = 160;
constexpr uint GAMEBOY_HEIGHT = 144;
constexpr uint BG_MAP_SIZE = 256;

namespace detail {

PpuImpl::MappedRegisters::MappedRegisters(Mmu& mmu):
    lcdControl     (mmu),
    lcdStatus      (mmu),
    viewScrollX    (mmu),
    viewScrollY    (mmu),
    lcdYCoord      (mmu),
    lcdLYCompare   (mmu),
    dmaStartAddress(mmu),
    bgPallete      (mmu),
    spritePalette0 (mmu),
    spritePalette1 (mmu),
    windowPosY     (mmu),
    windowPosX     (mmu),
    vram           (mmu),
    oam            (mmu)
{}

PpuImpl::PpuImpl(Mmu& mmu):
    m_mmu(mmu),
    m_reg(mmu),
    m_cycleCounter(0),
    m_viewBuffer(GAMEBOY_WIDTH, GAMEBOY_HEIGHT),
    m_mapBuffer(BG_MAP_SIZE, BG_MAP_SIZE)
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
    SetBitTo<0>(value, v_mode & 0x1);
    SetBitTo<1>(value, v_mode & 0x10);
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
        // TODO
        // DrawBGLine(line);

        if (IsWindowEnabled())
        {
            // TODO
            // DrawWindowLine(line);
        }
    }
}

void PpuImpl::WriteSprites()
{
    // TODO
}

} // namespace detail
