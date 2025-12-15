#include "cpu.h"
#include "detail/cpu/cpu_impl.h"

#include <cstdint>

Cpu::Cpu(Mmu& mmu):
    m_pImpl(std::make_unique<detail::CpuImpl>(mmu))
{}

Cpu::~Cpu() = default;
Cpu::Cpu(Cpu&&) noexcept = default;
Cpu& Cpu::operator=(Cpu&&) noexcept = default;

MCycles Cpu::Execute(uint8_t opcode)
{
    return m_pImpl->Execute(opcode);
}

MCycles Cpu::Step()
{
    return m_pImpl->Step();
}
