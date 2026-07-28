#pragma once
#include "types.h"
#include "cpu_registers.h"

#include <functional>

namespace gb {

class Mmu;
class Timer;

struct CpuState
{
    bool halted;
    bool haltBug;
    bool interruptPending;    // flag an interrupt is pending
    bool branchTaken;         // flag is branch was taken
    int enableInterruptDelay; // indicator field to delay setting IME
    MCycles cbOpCodeCycles;   // cycles taken if the cb opcode prefix is taken
    Registers reg;
    std::function<void()> pauseClockFunc;
    Mmu& mmu;

    CpuState(Mmu& mmu, Timer& timer):
        halted(false),
        haltBug(false),
        interruptPending(false),
        branchTaken(false),
        enableInterruptDelay(0),
        cbOpCodeCycles(0),
        reg(),
        pauseClockFunc({}),
        mmu(mmu)
    {}
};

} // namespace gb
