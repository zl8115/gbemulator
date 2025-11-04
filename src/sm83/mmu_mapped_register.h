#pragma once

#include "mmu.h"
#include <cstdint>

#include <stdexcept>

template<uint16_t Address>
class MappedByteRegister
{
public:
    MappedByteRegister(Mmu& mmu):
        m_mmu(mmu)
    {}

    uint8_t Read() const { return m_mmu.Read(Address); }
    void Write(uint8_t byte) { return m_mmu.Write(Address, byte); };

private:
    Mmu& m_mmu;
};

template<uint16_t StartAddress, uint16_t Size>
class MappedRegisterRegion
{
public:
    MappedRegisterRegion(Mmu& mmu):
        m_mmu(mmu)
    {}

    uint8_t Read(uint8_t relativeAddress) const
    {
        if (relativeAddress > Size)
        {
            throw std::out_of_range("Accessing relative address outside range");
        }
        return m_mmu.Read(StartAddress + relativeAddress);
    }

    void Write(uint8_t relativeAddress, uint8_t byte)
    {
        if (relativeAddress > Size)
        {
            throw std::out_of_range("Accessing relative address outside range");
        }
        return m_mmu.Write(StartAddress + relativeAddress, byte);
    };

private:
    Mmu& m_mmu;
};
