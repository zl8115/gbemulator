#pragma once

#include <cstdint>

template <std::size_t Bit>
bool CheckBit(const uint8_t value)
{
    return (value & (1 << Bit)) != 0;
}

template <std::size_t Bit>
void SetBitToTrue(uint8_t& value)
{
    value |= (1 << Bit);
}

template <std::size_t Bit>
void SetBitToFalse(uint8_t& value)
{
    value &= ~(1 << Bit);
}

template <std::size_t Bit, bool BitValue>
void SetBitTo(uint8_t& value)
{
    if constexpr (BitValue)
    {
        SetBitToTrue<Bit>(value);
    }
    else
    {
        SetBitToFalse<Bit>(value);
    }
}

template <std::size_t Bit>
void SetBitTo(uint8_t& value, bool bitValue)
{
    if (bitValue)
    {
        SetBitToTrue<Bit>(value);
    }
    else
    {
        SetBitToFalse<Bit>(value);
    }
}
