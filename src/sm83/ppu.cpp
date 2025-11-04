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
    if (m_pImpl->ShouldRender())
    {
        Render();
    }
}

void Ppu::RegisterRenderer(std::shared_ptr<IRenderer> pRenderer)
{
    m_renderer = pRenderer;
}

void Ppu::Render() const
{
    if (m_renderer)
    {
        m_renderer->Render(m_pImpl->GetViewBuffer());
    }
}
