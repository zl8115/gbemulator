#include "mmu.h"
#include "bootrom.h"

#include <iterator>
#include <memory.h>

Mmu::Mmu()
{
    memset(m_ram.data(), 0, std::size(m_ram));
    memcpy(m_ram.data(), bootDMG.data(), std::size(bootDMG));
}

uint8_t Mmu::Read(const uint16_t address) const
{
    return m_ram.at(address);
}

void Mmu::Write(const uint16_t address, uint8_t byte)
{
    m_ram.at(address) = byte;
}

uint8_t& Mmu::At(uint16_t address)
{
    return m_ram.at(address);
}

uint8_t const& Mmu::At(uint16_t address) const
{
    return m_ram.at(address);
};

void Mmu::LoadRom(std::vector<uint8_t>&& romData)
{
    m_rom = std::forward<std::vector<uint8_t>>(romData);
    if (m_rom.at(0x0147) != static_cast<uint8_t>(MapperChip::ROM_ONLY))
    {
        throw std::runtime_error("Unsupported ROM with mapper chip type.");
    }

    if (m_rom.size() > 32768)
    {
        throw std::runtime_error("ROM (Only) is too large.");
    }

    memcpy(m_ram.data(), m_rom.data(), std::size(m_rom));
    memcpy(m_ram.data(), bootDMG.data(), std::size(bootDMG));
}
