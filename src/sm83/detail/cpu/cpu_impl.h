#pragma once

#include "cycles.h"
#include "mmu.h"
#include "detail/cpu/timer.h"
#include "detail/cpu/registers.h"
#include <cstdint>

namespace detail {

struct CpuState
{
    bool halted;
    bool haltBug;
    bool interruptPending;  // flag an interrupt is pending
    bool branchTaken;       // flag is branch was taken
    int enableInterruptDelay; // indicator field to delay setting IME
    MCycles cbOpCodeCycles; // cycles taken if the cb opcode prefix is taken
    Mmu& mmu;
    Registers& reg;
};

class CpuImpl
{
public:
    CpuImpl(Mmu& mmu);
    MCycles Step();
    MCycles Execute(uint8_t opcode);

    // Test Helpers
    Registers& GetRegister();
    const Registers& GetRegister() const;
    int GetEi() const;
    void SetEi(int value);
    void EnableTestMode();

private:
    void HandleEnableInterrupt();
    void CheckForInterrupts();
    MCycles HandleInterrupts();

    template <Mmu::InterruptType Type>
    consteval uint16_t GetInterruptHandlerAddress()
    {
        if constexpr (Type == Mmu::InterruptType::VBLANK)
        {
            return 0x40;
        }
        else if constexpr (Type == Mmu::InterruptType::LCD)
        {
            return 0x48;
        }
        else if constexpr (Type == Mmu::InterruptType::TIMER)
        {
            return 0x50;
        }
        else if constexpr (Type == Mmu::InterruptType::SERIAL)
        {
            return 0x58;
        }
        else if constexpr (Type == Mmu::InterruptType::JOYPAD)
        {
            return 0x60;
        }
        else
        {
            static_assert(false, "Unsupported InterruptType");
        }
    }

    template <Mmu::InterruptType Type>
    bool HandleInterrupt()
    {
        if (!m_state.mmu.HasInterrupt<Type>())
            return false;

        m_state.mmu.UnsetInterruptFlag<Type>();
        m_state.reg.pc = GetInterruptHandlerAddress<Type>();
        m_state.reg.ime = 0;
        return true;
    }

    bool m_disableInterruptHandling;
    CpuState m_state;
    Registers m_reg;
    Timer m_timer;
};

} // namespace detail
