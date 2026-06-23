#pragma once

#include "types.h"

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
    CCycles m_leftoverCounterCycles;

public:
    Timer();

    bool Step(CCycles cycles);
    void PauseClock();
    void ResumeClock();

    [[nodiscard]] Reg8 Read(const Address address) const;
    void Write(const Address address, Reg8 byte);

private:
    bool HandleDividerRegisterWrite(Reg8 value);
    bool HandleTimerControlWrite(Reg8 value);
    CCycles GetIncrementFrequency();
};

} // namespace gb
