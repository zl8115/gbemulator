#pragma once

#include "cycles.h"
#include "mmu.h"
#include "detail/mmu_mapped_memory.h"

namespace detail {

class Timer
{
public:
    Timer(Mmu& mmu);
    void Step(CCycles cycles);
    void PauseClock();
    void ResumeClock();

private:
    bool HandleDividerRegisterWrite(uint8_t value);
    bool HandleTimerControlWrite(uint8_t value);
    MCycles GetIncrementFrequency();

    bool m_pauseClock;
    uint8_t m_dividerClock;
    Mmu& m_mmu;
    CCycles m_leftoverCounterCycles;

    MappedRegister m_dividerRegister;
    MappedRegister m_timerCounter;
    MappedRegister m_timerModulo;
    MappedRegister m_timerControl;
};

} // namespace detail
