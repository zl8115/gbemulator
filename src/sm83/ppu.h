#pragma once

#include "cycles.h"
#include "irenderer.h"

#include <memory>

class Mmu;

namespace detail {
    class PpuImpl;
} // namespace detail

class Ppu
{
public:
    Ppu(Mmu& mmu);
    ~Ppu();

    Ppu(Ppu&&) noexcept;
    Ppu& operator=(Ppu&&) noexcept;

    Ppu(const Ppu&) = delete;
    Ppu& operator=(const Ppu&) = delete;

    void Step(CCycles cycles);
    void RegisterRenderer(IRenderer* pRenderer);

    void SetDisplayOn();
    void SetDisplayOff();

    bool IsDisplayOn() const;

    std::unique_ptr<detail::PpuImpl> m_pImpl;
};
