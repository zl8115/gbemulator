#pragma once

#include "types.h"

#include <functional>

namespace gb {

class Timer
{
protected:
    Reg8 regDivider;
    Reg8 regCounter;
    Reg8 regModulo;
    Reg8 regControl;

private:
    bool m_pauseClock;
    Reg8 m_dividerClock;
    CCycles m_leftoverCounterCycles;
    std::function<void()> m_overflowCallback;

public:
    Timer();

    void Step(CCycles cycles);
    void PauseClock();
    void ResumeClock();

    // Invoked when the timer counter (TIMA) overflows, e.g. to let the Mmu raise the TIMER interrupt.
    void SetOverflowCallback(std::function<void()> callback);

    [[nodiscard]] Reg8 Read(const Address address) const;
    void Write(const Address address, Reg8 byte);

private:
    bool HandleDividerRegisterWrite(Reg8 value);
    bool HandleTimerControlWrite(Reg8 value);
    MCycles GetIncrementFrequency();
};

} // namespace gb
