#pragma once

#include <cstdint>
#include <array>

#include "bitmanip.h"

namespace detail {

template<std::size_t N>
using MemoryBlock = std::array<uint8_t, N>;

class MappedRegister
{
public:
    MappedRegister(uint8_t& reg):
        m_reg(reg)
    {}

    uint8_t Read() const { return m_reg; }
    virtual void Write(uint8_t byte) { m_reg = byte; };

    template <std::size_t Bit>
    bool CheckBit()
    {
        return ::CheckBit<Bit>(Read());
    }

    template <std::size_t Bit>
    void SetBitTo(bool bitValue)
    {
        ::SetBitTo<Bit>(m_reg, bitValue);
    }

    template <std::size_t Bit>
    void SetBitToTrue(bool bitValue)
    {
        ::SetBitToTrue<Bit>(m_reg);
    }

    template <std::size_t Bit>
    void SetBitToFalse(bool bitValue)
    {
        ::SetBitToFalse<Bit>(m_reg);
    }

private:
    uint8_t& m_reg;
};

} // namespace detail
