#include "mmu.h"

#include <iterator>
#include <memory.h>

Mmu::Mmu()
{
    memset(&m_ram, 0, std::size(m_ram));
}

uint8_t Mmu::Read(const uint16_t& address) const
{
    return m_ram[address];
}


void Mmu::Write(const uint16_t& address, uint8_t byte)
{
    m_ram[address] = byte;
}
