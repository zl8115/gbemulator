#include "ppu.h"
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

Ppu::MappedRegisters::MappedRegisters(Mmu& mmu):
    lcdControl     (mmu.At(0xFF40)),
    lcdStatus      (mmu.At(0xFF41)),
    viewScrollX    (mmu.At(0xFF42)),
    viewScrollY    (mmu.At(0xFF43)),
    lcdYCoord      (mmu.At(0xFF44)),
    lcdLYCompare   (mmu.At(0xFF45)),
    dmaStartAddress(mmu.At(0xFF46)),
    bgPallete      (mmu.At(0xFF47)),
    spritePalette0 (mmu.At(0xFF48)),
    spritePalette1 (mmu.At(0xFF49)),
    windowPosY     (mmu.At(0xFF4A)),
    windowPosX     (mmu.At(0xFF4B))
{}

Ppu::Ppu(Mmu& mmu):
    m_mmu(mmu),
    m_reg(mmu),
    m_cycleCounter(0),
    m_viewBuffer(GAMEBOY_WIDTH, GAMEBOY_HEIGHT),
    m_mapBuffer(BG_MAP_SIZE, BG_MAP_SIZE),
    m_vram(std::next(mmu.begin(), 0x8000), std::next(mmu.begin(), 0xA000))
{}

void Ppu::Step(CCycles cycles)
{
    switch (GetPpuMode())
    {
        case Mode::HBLANK:
        {
            if (m_cycleCounter >= CLOCKS_PER_HBLANK)
            {
                WriteScanline(m_reg.lcdYCoord);
                ++m_reg.lcdYCoord;

                m_cycleCounter %= CLOCKS_PER_HBLANK;

                /* Line 145 (index 144) is the first line of VBLANK */
                if (m_reg.lcdYCoord == 144)
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
                ++m_reg.lcdYCoord;

                m_cycleCounter %= CLOCKS_PER_SCANLINE;

                /* Line 155 (index 154) is the last line */
                if (m_reg.lcdYCoord == 154) {
                    WriteSprites();
                    Render();
                    m_viewBuffer.Reset();
                    m_reg.lcdYCoord = 0;

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

void Ppu::RegisterRenderer(std::shared_ptr<IRenderer> pRenderer)
{
    m_renderer = pRenderer;
}

/*     ************** LCD Control Checks *************     */
bool Ppu::IsDisplayOn() const
{
    return CheckBit<7>(m_reg.lcdControl);
}

Ppu::TileMapAreaType Ppu::GetWindowTileMapAreaType() const
{
    return CheckBit<6>(m_reg.lcdControl) ?
        Ppu::TileMapAreaType::ONE :
        Ppu::TileMapAreaType::ZERO;
}

bool Ppu::IsWindowEnabled() const 
{
    return CheckBit<5>(m_reg.lcdControl);
}

Ppu::TileMapAreaType Ppu::GetBGAndWindowTileMapAreaType() const
{
    return CheckBit<4>(m_reg.lcdControl) ?
        Ppu::TileMapAreaType::ONE :
        Ppu::TileMapAreaType::ZERO;
}

Ppu::TileMapAreaType Ppu::GetBGTileMapAreaType() const
{
    return CheckBit<3>(m_reg.lcdControl) ?
        Ppu::TileMapAreaType::ONE :
        Ppu::TileMapAreaType::ZERO;
}

Ppu::ObjectSizeType Ppu::ObjectSize() const
{
    return CheckBit<2>(m_reg.lcdControl) ?
    Ppu::ObjectSizeType::LONG :
    Ppu::ObjectSizeType::SMALL;
}

bool Ppu::IsObjectEnabled() const
{
    return CheckBit<1>(m_reg.lcdControl);
}

bool Ppu::IsBGAndWindowEnabled() const
{
    return CheckBit<0>(m_reg.lcdControl);
}

/*     ************** LCD Status Checks *************     */
bool Ppu::IsLYCIntSelect() const
{
    return CheckBit<6>(m_reg.lcdStatus);
}

bool Ppu::IsMode2IntSelect() const
{
    return CheckBit<5>(m_reg.lcdStatus);
}

bool Ppu::IsMode1IntSelect() const
{
    return CheckBit<4>(m_reg.lcdStatus);
}

bool Ppu::IsMode0IntSelect() const
{
    return CheckBit<3>(m_reg.lcdStatus);
}

bool Ppu::IsLYAndLYCEqual() const
{
    return CheckBit<2>(m_reg.lcdStatus);
}

Ppu::Mode Ppu::GetPpuMode() const
{
    unsigned short ppuMode = m_reg.lcdStatus & 0x11;
    return static_cast<Ppu::Mode>(ppuMode);
}

void Ppu::SetPpuMode(Ppu::Mode mode)
{
    short v_mode = static_cast<short>(mode);
    SetBitTo<0>(m_reg.lcdStatus, v_mode & 0x1);
    SetBitTo<1>(m_reg.lcdStatus, v_mode & 0x10);
}

/*     ************** Private Methods *************     */
void Ppu::Render()
{
    if (m_renderer)
    {
        m_renderer->Render(m_viewBuffer);
    }
}

void Ppu::WriteScanline(uint8_t line)
{
    // TODO
}

void Ppu::WriteSprites()
{
    // TODO
}
