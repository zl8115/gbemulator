#include "ppu.h"
#include "detail/ppu_impl.h"

Ppu::Ppu(Mmu& mmu):
    m_pImpl(std::make_unique<detail::PpuImpl>(mmu))
{}
Ppu::~Ppu() = default;
Ppu::Ppu(Ppu&&) noexcept = default;
Ppu& Ppu::operator=(Ppu&&) noexcept = default;

void Ppu::Step(CCycles cycles)
{
    m_pImpl->Step(cycles);
}

void Ppu::RegisterRenderer(IRenderer* pRenderer)
{
    m_pImpl->RegisterRenderer(pRenderer);
}
