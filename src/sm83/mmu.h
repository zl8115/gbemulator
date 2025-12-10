#pragma once

#include "bitmanip.h"

#include <cstdint>
#include <memory>

namespace detail {
class MmuImpl;
class ImplHelper;
} // namespace detail

class Mmu {
public:
    friend class detail::ImplHelper;

    Mmu();
    ~Mmu();

    Mmu(Mmu&&) noexcept;
    Mmu& operator=(Mmu&&) noexcept;

    Mmu(const Mmu&) = delete;
    Mmu& operator=(const Mmu&) = delete;

    enum class InterruptType
    {
        VBLANK = 0,
        LCD,
        TIMER,
        SERIAL,
        JOYPAD,
    };

    uint8_t Read(const uint16_t address) const;
    void Write(const uint16_t address, uint8_t byte);

    template <InterruptType Type>
    void EnableInterrupt()
    {
        uint8_t value = Read(0xFFFF);
        SetBitTo<static_cast<std::size_t>(Type), true>(value);
        Write(0xFFFF, value);
    }

    template <Mmu::InterruptType Type>
    void DisableInterrupt()
    {
        uint8_t value = Read(0xFFFF);
        SetBitTo<static_cast<std::size_t>(Type), false>(value);
        Write(0xFFFF, value);
    }

    template <Mmu::InterruptType Type>
    void SetInterruptFlag()
    {
        uint8_t value = Read(0xFF0F);
        SetBitTo<static_cast<std::size_t>(Type), true>(value);
        Write(0xFFFF, value);
    }

    template <Mmu::InterruptType Type>
    void UnsetInterruptFlag()
    {
        uint8_t value = Read(0xFF0F);
        SetBitTo<static_cast<std::size_t>(Type), false>(value);
        Write(0xFFFF, value);
    }

    uint8_t ei = 0;
    uint8_t ime = 0;
    uint8_t ie = 0;

private:
    std::unique_ptr<detail::MmuImpl> m_pImpl;
};
