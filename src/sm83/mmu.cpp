#include "mmu.h"
#include "detail/mmu_impl.h"

#include <utility>

Mmu::Mmu()
    : m_pImpl(std::make_unique<detail::MmuImpl>())
{}

Mmu::~Mmu() = default;
Mmu::Mmu(Mmu&&) noexcept = default;
Mmu& Mmu::operator=(Mmu&&) noexcept = default;

uint8_t Mmu::Read(const uint16_t address) const
{
    return m_pImpl->Read(address);
}

void Mmu::Write(const uint16_t address, uint8_t byte)
{
    return m_pImpl->Write(address, byte);
}

void Mmu::LoadRom(std::vector<uint8_t>&& romData)
{
    return m_pImpl->LoadRom(std::forward<std::vector<uint8_t>>(romData));
}
