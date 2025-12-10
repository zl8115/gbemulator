#pragma once

#include "mmu_impl.h"
#include <cstdint>

#include <stdexcept>
#include <span>

namespace detail {

class MappedRegister
{
public:
    MappedRegister(MmuImpl& mmu, uint16_t address):
        m_reg(mmu.m_map.at(address)),
        m_address(address)
    {}

    uint8_t Read() const { return m_reg; }
    void Write(uint8_t byte) { m_reg = byte; };

private:
    uint8_t& m_reg;
    const uint16_t m_address;
};

class MappedMemoryBlock
{
public:
    MappedMemoryBlock(MmuImpl& mmu, uint16_t startAddress, uint16_t size):
        m_region(mmu.m_map.begin() + startAddress, mmu.m_map.begin() + startAddress + size),
        m_startAddress(startAddress),
        m_size(size)
    {}

    uint8_t Read(uint8_t relativeAddress) const
    {
        if (relativeAddress > m_size)
        {
            throw std::out_of_range("Accessing relative address outside range");
        }
        return m_region[relativeAddress];
    }

    void Write(uint8_t relativeAddress, uint8_t byte)
    {
        if (relativeAddress > m_size)
        {
            throw std::out_of_range("Accessing relative address outside range");
        }
        m_region[relativeAddress] = byte;
    };

private:
    std::span<uint8_t> m_region;
    const uint16_t m_startAddress;
    const uint16_t m_size;
};

} // namespace detail
