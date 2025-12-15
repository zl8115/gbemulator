#include "detail/cpu/timer.h"

#include "detail/impl_helper.h"
#include "detail/memory/mmu_impl.h"
#include "detail/register_names.h"
#include "mmu.h"

namespace detail {

Timer::Timer(Mmu& mmu):
    m_pauseClock(false),
    m_dividerClock(0),
    m_mmu(mmu),
    m_leftoverCounterCycles(0),
    m_dividerRegister(ImplHelper::ExtractImpl(mmu).GetMappedRegister(REG_DIVIDER_REGISTER)),
    m_timerCounter(ImplHelper::ExtractImpl(mmu).GetMappedRegister(REG_TIMER_COUNTER)),
    m_timerModulo(ImplHelper::ExtractImpl(mmu).GetMappedRegister(REG_TIMER_MODULO)),
    m_timerControl(ImplHelper::ExtractImpl(mmu).GetMappedRegister(REG_TIMER_CONTROL))
{}

bool Timer::HandleDividerRegisterWrite(uint8_t value)
{
    m_dividerRegister.Write(0);
    return false;
}

MCycles Timer::GetIncrementFrequency()
{
    auto clockSelect = m_mmu.Read(REG_TIMER_CONTROL) & 0b11;
    switch (clockSelect)
    {
    case 0:
        return {256};
    case 1:
        return {4};
    case 2:
        return {16};
    case 3:
        return {64};
    }
    return {0};
}

void Timer::Step(CCycles cycles)
{
    if (m_pauseClock)
        return;

    // Increment Divider Clock
    if (m_dividerClock == m_dividerRegister.Read())
    {
        m_dividerRegister.Write(m_dividerRegister.Read() + cycles.cycles);
    }
    else // Write divider register has occured, so we reset divider to 0
    {
        m_dividerRegister.Write(0);
    }

    // Increment Timer Counter
    m_leftoverCounterCycles += cycles;

    auto originalTimerCounter = m_timerCounter.Read();
    CCycles incrementFrequency = GetIncrementFrequency();
    while (m_leftoverCounterCycles > incrementFrequency)
    {
        m_timerCounter.Write(m_timerCounter.Read() + 1);
        m_leftoverCounterCycles -= incrementFrequency;
    }

    // Check if Timer Counter has overflowed
    if (m_timerCounter.Read() < originalTimerCounter)
    {
        m_timerCounter.Write(m_timerModulo.Read());
        m_mmu.SetInterruptFlag<Mmu::InterruptType::TIMER>();
    }
}

void Timer::PauseClock()
{
    m_dividerRegister.Write(0);
    m_pauseClock = true;
}

void Timer::ResumeClock()
{
    m_pauseClock = false;
}

} // namespace detail
