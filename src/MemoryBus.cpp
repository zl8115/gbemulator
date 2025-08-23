#include "MemoryBus.h"

MemoryBus::MemoryBus()
{
    memset(m_memory, 0, sizeof(m_memory));
}

uint8_t MemoryBus::ReadByte(uint16_t address)
{
    return m_memory[address];
}

