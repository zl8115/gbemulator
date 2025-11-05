#pragma once

#include <cstdint>

inline bool CheckBit(const uint8_t value, uint8_t bit)
{
    return (value & (1 << bit)) != 0;
}

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

inline uint16_t ToWord(uint8_t hibyte, uint8_t lobyte)
{
    return (hibyte << 8) | lobyte;
}

inline uint8_t Lsb(uint16_t word)
{
    return static_cast<uint8_t>(word & 0xFF);
}

inline uint8_t Msb(uint16_t word)
{
    return word >> 8;
}
