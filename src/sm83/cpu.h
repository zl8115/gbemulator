#pragma once

#include "cycles.h"
#include <stdint.h>

#include <memory>

class Mmu;

namespace detail {
    class CpuImpl;
    class ImplHelper;
} // namespace detail

class Cpu
{
public:
    friend class detail::ImplHelper;

    Cpu(Mmu& mmu);
    ~Cpu();

    Cpu(Cpu&&) noexcept;
    Cpu& operator=(Cpu&&) noexcept;

    Cpu(const Cpu&) = delete;
    Cpu& operator=(const Cpu&) = delete;

    MCycles Step();
    MCycles Execute(uint8_t opcode);

private:
    std::unique_ptr<detail::CpuImpl> m_pImpl;
};
