#include "cpu.h"
#include "mmu.h"
#include "mmu_register_names.h"
#include "timer.h"
#include "detail/cpu_opcode.h"

namespace gb {

Cpu::Cpu(Mmu& mmu, Timer& timer):
    m_disableInterruptHandling(false),
    m_state(mmu, timer),
    m_timer(timer)
{
    m_state.pauseClockFunc = [this]() { m_timer.PauseClock(); };
}

MCycles Cpu::Execute(Reg8 opcode)
{
    return detail::Execute(m_state, opcode);
}

MCycles Cpu::Step()
{
    if (m_state.halted)
        CheckForInterrupts();

    if (m_state.interruptPending)
        return HandleInterrupts();
    else if (m_state.halted)
        return {1};

    auto pc = m_state.reg.pc;
    auto opcode = m_state.mmu.Read(pc);
    if (m_state.haltBug)
    {
        m_state.haltBug = false;

        // Halt Bug: pc failed to increment, so the next byte is read twice.
        // TODO: Handle edge case (halt followed by jmp, or preceded by ei and followed by rst)
        opcode = m_state.mmu.Read(m_state.reg.pc + 1);
    }

    MCycles cycles = Execute(opcode);
    CheckForInterrupts();
    if (m_timer.Step(CCycles{cycles.cycles * 4}))
        m_state.mmu.SetInterruptFlag<InterruptType::TIMER>();
    return cycles;
}

int Cpu::SetEi(int value)
{
    m_state.enableInterruptDelay = value;
    return value;
}

int Cpu::GetEi() const
{
    return m_state.enableInterruptDelay == 1
        ? 1  // Next Step() will set IME
        : 0; // Next Step() does nothing to IME
}

void Cpu::HandleEnableInterrupt()
{
    if (m_state.enableInterruptDelay < 0)
        return;
    else if (m_state.enableInterruptDelay == 0)
        ++m_state.enableInterruptDelay;
    else // enableInterruptDelay >= 1: one extra step has passed, set IME now
    {
        m_state.reg.ime = 1;
        m_state.enableInterruptDelay = -1;
    }
}

void Cpu::CheckForInterrupts()
{
    HandleEnableInterrupt();

    if (m_disableInterruptHandling || !m_state.reg.ime)
        return;

    auto interrupt_enable = m_state.mmu.Read(REG_INTERRUPT_ENABLE);
    auto interrupt_flag   = m_state.mmu.Read(REG_INTERRUPT_FLAG);
    if (!(interrupt_enable & interrupt_flag))
        return;

    m_state.interruptPending = true;
}

MCycles Cpu::HandleInterrupts()
{
    if (!m_state.interruptPending)
        return {0};

    m_state.halted = false;
    m_state.interruptPending = false;
    detail::PushPc(m_state);

    if (HandleInterrupt<InterruptType::VBLANK>())
        return {5};
    if (HandleInterrupt<InterruptType::LCD>())
        return {5};
    if (HandleInterrupt<InterruptType::TIMER>())
        return {5};
    if (HandleInterrupt<InterruptType::SERIAL>())
        return {5};
    if (HandleInterrupt<InterruptType::JOYPAD>())
        return {5};
    return {0};
}

template <InterruptType Type>
consteval Address Cpu::GetInterruptHandlerAddress()
{
    if constexpr (Type == InterruptType::VBLANK)
        return 0x40;
    else if constexpr (Type == InterruptType::LCD)
        return 0x48;
    else if constexpr (Type == InterruptType::TIMER)
        return 0x50;
    else if constexpr (Type == InterruptType::SERIAL)
        return 0x58;
    else if constexpr (Type == InterruptType::JOYPAD)
        return 0x60;
    else
        static_assert(false, "Unsupported InterruptType");
}

template <InterruptType Type>
bool Cpu::HandleInterrupt()
{
    if (!m_state.mmu.HasInterrupt<Type>())
        return false;

    m_state.mmu.UnsetInterruptFlag<Type>();
    m_state.reg.pc = GetInterruptHandlerAddress<Type>();
    m_state.reg.ime = 0;
    return true;
}

} // namespace gb
