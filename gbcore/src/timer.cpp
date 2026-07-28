#include "timer.h"

#include "mmu_register_names.h"
#include "utils/bitmanip.h"

namespace gb {

namespace {
constexpr std::size_t TIMER_ENABLE_BIT = 2;
}

Timer::Timer():
    regDivider(0),
    regCounter(0),
    regModulo(0),
    regControl(0),
    m_pauseClock(false),
    m_dividerClock(0),
    m_leftoverCounterCycles(0)
{}

void Timer::Step(CCycles cycles)
{
    if (m_pauseClock)
        return;

    unsigned int dividerTotal = m_dividerClock + cycles.cycles;
    regDivider += static_cast<Reg8>(dividerTotal / 256);
    m_dividerClock = static_cast<Reg8>(dividerTotal % 256);

    if (!utils::CheckBit<TIMER_ENABLE_BIT>(regControl))
        return;

    m_leftoverCounterCycles += cycles;
    CCycles incrementFrequency = GetIncrementFrequency().as<ClockTag>();
    while (m_leftoverCounterCycles >= incrementFrequency)
    {
        m_leftoverCounterCycles -= incrementFrequency;
        ++regCounter;
        if (regCounter == 0)
        {
            regCounter = regModulo;
            if (m_overflowCallback)
                m_overflowCallback();
        }
    }
}

void Timer::PauseClock()
{
    m_pauseClock = true;
}

void Timer::ResumeClock()
{
    m_pauseClock = false;
}

void Timer::SetOverflowCallback(std::function<void()> callback)
{
    m_overflowCallback = std::move(callback);
}

Reg8 Timer::Read(const Address address) const
{
    switch (address)
    {
    case REG_DIVIDER_REGISTER: return regDivider;
    case REG_TIMER_COUNTER:    return regCounter;
    case REG_TIMER_MODULO:     return regModulo;
    case REG_TIMER_CONTROL:    return regControl;
    default:                   return 0xFF;
    }
}

void Timer::Write(const Address address, Reg8 byte)
{
    switch (address)
    {
    case REG_DIVIDER_REGISTER:
        HandleDividerRegisterWrite(byte);
        break;
    case REG_TIMER_COUNTER:
        regCounter = byte;
        break;
    case REG_TIMER_MODULO:
        regModulo = byte;
        break;
    case REG_TIMER_CONTROL:
        HandleTimerControlWrite(byte);
        break;
    default:
        break;
    }
}

bool Timer::HandleDividerRegisterWrite(Reg8 value)
{
    regDivider = 0;
    m_dividerClock = 0;
    return true;
}

bool Timer::HandleTimerControlWrite(Reg8 value)
{
    regControl = value & 0x07;
    return true;
}

MCycles Timer::GetIncrementFrequency()
{
    switch (regControl & 0b11)
    {
    case 0: return {256};
    case 1: return {4};
    case 2: return {16};
    case 3: return {64};
    }
    return {0};
}

} // namespace gb
