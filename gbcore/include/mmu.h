#pragma once

#include "types.h"
#include "interrupt_type.h"
#include "utils/bitmanip.h"

namespace gb {

using namespace gb::utils;

class Timer;

class Mmu {
public:
    Mmu()
    {}

    Mmu(Mmu&&) noexcept = delete;
    Mmu& operator=(Mmu&&) noexcept = delete;
    Mmu(const Mmu&) = delete;
    Mmu& operator=(const Mmu&) = delete;

    Reg8 Read(const Address address) const;
    void Write(const Address address, Reg8 byte);

    template <InterruptType Type>
    void EnableInterrupt()
    {
        uint8_t value = Read(0xFFFF);
        SetBitToTrue<static_cast<std::size_t>(Type)>(value);
        Write(0xFFFF, value);
    }

    template <InterruptType Type>
    void DisableInterrupt()
    {
        uint8_t value = Read(0xFFFF);
        SetBitToFalse<static_cast<std::size_t>(Type)>(value);
        Write(0xFFFF, value);
    }

    template <InterruptType Type>
    void SetInterruptFlag()
    {
        uint8_t value = Read(0xFF0F);
        SetBitToTrue<static_cast<std::size_t>(Type)>(value);
        Write(0xFF0F, value);
    }

    template <InterruptType Type>
    void UnsetInterruptFlag()
    {
        uint8_t value = Read(0xFF0F);
        SetBitToFalse<static_cast<std::size_t>(Type)>(value);
        Write(0xFF0F, value);
    }

    template <InterruptType Type>
    bool HasInterrupt()
    {
        uint8_t value = Read(0xFF0F) & Read(0xFFFF);
        return CheckBit<static_cast<std::size_t>(Type)>(value);
    }

    void MapTimer(Timer& timer);
};

} // namespace gb
