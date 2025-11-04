#include "ppu.h"
#include "mmu.h"
#include "util_bitmanip.h"

#include <stdexcept>

static const CCycles CLOCKS_PER_HBLANK = 204; /* Mode 0 */
static const CCycles CLOCKS_PER_SCANLINE_OAM = 80; /* Mode 2 */
static const CCycles CLOCKS_PER_SCANLINE_VRAM = 172; /* Mode 3 */
static const CCycles CLOCKS_PER_SCANLINE = (CLOCKS_PER_SCANLINE_OAM + CLOCKS_PER_SCANLINE_VRAM + CLOCKS_PER_HBLANK);

static const CCycles CLOCKS_PER_VBLANK = 4560; /* Mode 1 */
static const CCycles SCANLINES_PER_FRAME = 144;
static const CCycles CLOCKS_PER_FRAME = (CLOCKS_PER_SCANLINE * SCANLINES_PER_FRAME) + CLOCKS_PER_VBLANK;

Ppu::Ppu(Mmu& mmu):
    m_mmu(mmu),
    m_mode(Ppu::Mode::HBLANK),
    m_cycleCounter(0),
    m_register_lcdControl(m_mmu.At(0xFF40)),
    m_register_lcdStatus(m_mmu.At(0xFF41)),
    m_register_lcdYCoord(m_mmu.At(0xFF44)),
    m_register_lcdLYCompare(m_mmu.At(0xFF45))
{}

void Ppu::Step(CCycles cycles)
{
    switch (m_mode)
    {
        case Mode::HBLANK:
        {
            // TODO
            break;
        }
        case Mode::VBLANK:
        {
            // TODO
            break;
        }
        case Mode::OAM_SEARCH:
        {
            // TODO
            break;
        }
        case Mode::PIXEL_TRANSFER:
        {
            // TODO
            break;
        }
        default:
            throw std::runtime_error("Unexpected ppu mode");
    }
}

/*     ************** LCD Control Checks *************     */
bool Ppu::IsDisplayOn() const
{
    return CheckBit<7>(m_register_lcdControl);
}

Ppu::TileMapAreaType Ppu::GetWindowTileMapAreaType() const
{
    return CheckBit<6>(m_register_lcdControl) ?
        Ppu::TileMapAreaType::ONE :
        Ppu::TileMapAreaType::ZERO;
}

bool Ppu::IsWindowEnabled() const 
{
    return CheckBit<5>(m_register_lcdControl);
}

Ppu::TileMapAreaType Ppu::GetBGAndWindowTileMapAreaType() const
{
    return CheckBit<4>(m_register_lcdControl) ?
        Ppu::TileMapAreaType::ONE :
        Ppu::TileMapAreaType::ZERO;
}

Ppu::TileMapAreaType Ppu::GetBGTileMapAreaType() const
{
    return CheckBit<3>(m_register_lcdControl) ?
        Ppu::TileMapAreaType::ONE :
        Ppu::TileMapAreaType::ZERO;
}

Ppu::ObjectSizeType Ppu::ObjectSize() const
{
    return CheckBit<2>(m_register_lcdControl) ?
    Ppu::ObjectSizeType::LONG :
    Ppu::ObjectSizeType::SMALL;
}

bool Ppu::IsObjectEnabled() const
{
    return CheckBit<1>(m_register_lcdControl);
}

bool Ppu::IsBGAndWindowEnabled() const
{
    return CheckBit<0>(m_register_lcdControl);
}

/*     ************** LCD Status Checks *************     */
bool Ppu::IsLYCIntSelect() const
{
    return CheckBit<6>(m_register_lcdStatus);
}

bool Ppu::IsMode2IntSelect() const
{
    return CheckBit<5>(m_register_lcdStatus);
}

bool Ppu::IsMode1IntSelect() const
{
    return CheckBit<4>(m_register_lcdStatus);
}

bool Ppu::IsMode0IntSelect() const
{
    return CheckBit<3>(m_register_lcdStatus);
}

bool Ppu::IsLYAndLYCEqual() const
{
    return CheckBit<2>(m_register_lcdStatus);
}

Ppu::Mode Ppu::GetPpuMode() const
{
    unsigned short ppuMode = m_register_lcdStatus & 0x11;
    return static_cast<Ppu::Mode>(ppuMode);
}
