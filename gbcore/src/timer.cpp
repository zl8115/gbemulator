#include "timer.h"
#include "mmu_register_names.h"

namespace gb {

Timer::Timer():
    regDivider(0),
    regCounter(0),
    regModulo(0),
    regControl(0),
    m_pauseClock(false),
    m_leftoverCounterCycles(0)
{}

bool Timer::Step(CCycles cycles)
{
    if (m_pauseClock)
        return false;

    // Divider increments every clock cycle regardless of timer enable.
    // regDivider is a free-running uint8_t counter; natural overflow is correct.
    regDivider += static_cast<Reg8>(cycles.cycles);

    // Timer counter only runs when bit 2 of TAC is set.
    if (!(regControl & 0x04))
        return false;

    m_leftoverCounterCycles += cycles;

    auto originalCounter = regCounter;
    CCycles freq = GetIncrementFrequency();
    while (m_leftoverCounterCycles > freq)
    {
        ++regCounter;
        m_leftoverCounterCycles -= freq;
    }

    if (regCounter < originalCounter)
    {
        regCounter = regModulo;
        return true;
    }
    return false;
}

void Timer::PauseClock()
{
    regDivider = 0;
    m_pauseClock = true;
}

void Timer::ResumeClock()
{
    m_pauseClock = false;
}

Reg8 Timer::Read(const Address address) const
{
    switch (address)
    {
    case REG_DIVIDER_REGISTER: return regDivider;
    case REG_TIMER_COUNTER:    return regCounter;
    case REG_TIMER_MODULO:     return regModulo;
    case REG_TIMER_CONTROL:    return regControl;
    default:                   return 0;
    }
}

void Timer::Write(const Address address, Reg8 byte)
{
    switch (address)
    {
    case REG_DIVIDER_REGISTER: HandleDividerRegisterWrite(byte); break;
    case REG_TIMER_COUNTER:    regCounter = byte; break;
    case REG_TIMER_MODULO:     regModulo  = byte; break;
    case REG_TIMER_CONTROL:    HandleTimerControlWrite(byte); break;
    }
}

bool Timer::HandleDividerRegisterWrite(Reg8 /*value*/)
{
    // Any write to DIV resets it to 0; the written value is ignored.
    regDivider = 0;
    return false;
}

bool Timer::HandleTimerControlWrite(Reg8 value)
{
    regControl = value;
    return false;
}

CCycles Timer::GetIncrementFrequency()
{
    // Clock cycles per timer counter increment (GB clock = 4194304 Hz)
    switch (regControl & 0b11)
    {
    case 0: return {1024}; // 4096 Hz
    case 1: return {16};   // 262144 Hz
    case 2: return {64};   // 65536 Hz
    case 3: return {256};  // 16384 Hz
    }
    return {1024};
}

} // namespace gb
