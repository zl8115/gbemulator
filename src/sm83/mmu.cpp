#include "mmu.h"
#include "bootrom.h"

#include <iterator>
#include <memory.h>

Mmu::Mmu()
{
    memset(&m_ram, 0, std::size(m_ram));
    // memcpy(&m_ram, bootDMG.data(), std::size(bootDMG));
}

uint8_t Mmu::Read(const uint16_t& address) const
{
    return m_ram[address];
}

void Mmu::Write(const uint16_t& address, uint8_t byte)
{
    // if (address > std::size(bootDMG))
    //     m_ram[address] = byte;
    m_ram[address] = byte;
}

void Mmu::LoadRom(std::vector<uint8_t>&& romData)
{
    m_rom = std::forward<std::vector<uint8_t>>(romData);
}
