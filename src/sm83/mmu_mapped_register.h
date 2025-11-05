#pragma once

#include "mmu.h"
#include <cstdint>

#include <stdexcept>

class MappedByteRegister
{
public:
    MappedByteRegister(Mmu& mmu, uint16_t address):
        m_mmu(mmu),
        m_address(address)
    {}

    uint8_t Read() const { return m_mmu.Read(m_address); }
    void Write(uint8_t byte) { return m_mmu.Write(m_address, byte); };

private:
    Mmu& m_mmu;
    const uint16_t m_address;
};

class MappedRegisterBlock
{
public:
    MappedRegisterBlock(Mmu& mmu, uint16_t startAddress, uint16_t size):
        m_mmu(mmu),
        m_startAddress(startAddress),
        m_size(size)
    {}

    uint8_t Read(uint8_t relativeAddress) const
    {
        if (relativeAddress > m_size)
        {
            throw std::out_of_range("Accessing relative address outside range");
        }
        return m_mmu.Read(m_startAddress + relativeAddress);
    }

    void Write(uint8_t relativeAddress, uint8_t byte)
    {
        if (relativeAddress > m_size)
        {
            throw std::out_of_range("Accessing relative address outside range");
        }
        return m_mmu.Write(m_startAddress + relativeAddress, byte);
    };

private:
    Mmu& m_mmu;
    const uint16_t m_startAddress;
    const uint16_t m_size;
};
