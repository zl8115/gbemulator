#pragma once

#include "util_bitmanip.h"

#include <cstdint>
#include <vector>
#include <array>

class Mmu {
public:
    Mmu();

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
    void LoadRom(std::vector<uint8_t>&& romData);

    uint8_t& At(uint16_t address);
    uint8_t const& At(uint16_t address) const;

    template <InterruptType Type>
    void EnableInterrupt()
    {
        uint8_t& reg = At(0xFFFF);
        SetBitTo<static_cast<std::size_t>(Type), true>(reg);
    }

    template <Mmu::InterruptType Type>
    void DisableInterrupt()
    {
        uint8_t& reg = At(0xFFFF);
        SetBitTo<static_cast<std::size_t>(Type), false>(reg);
    }

    template <Mmu::InterruptType Type>
    void SetInterruptFlag()
    {
        uint8_t& reg = At(0xFF0F);
        SetBitTo<static_cast<std::size_t>(Type), true>(reg);
    }

    template <Mmu::InterruptType Type>
    void UnsetInterruptFlag()
    {
        uint8_t& reg = At(0xFF0F);
        SetBitTo<static_cast<std::size_t>(Type), false>(reg);
    }

    uint8_t ei = 0;
    uint8_t ime = 0;
    uint8_t ie = 0;

    // Iterator like access
    auto begin() { return m_ram.begin(); }
    auto end()   { return m_ram.end(); }

private:
    std::vector<uint8_t> m_rom;
    std::array<uint8_t, 0x10000> m_ram;
};
