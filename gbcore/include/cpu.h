#pragma once

#include "types.h"
#include "cpu_state.h"
#include "interrupt_type.h"

namespace gb {

class Mmu;
class Timer;

class Cpu
{
private:
    bool m_disableInterruptHandling;
    CpuState m_state;
    Timer& m_timer;

public:
    explicit Cpu(Mmu& mmu, Timer& timer);

    Cpu(const Cpu&) = delete;
    Cpu& operator=(const Cpu&) = delete;
    Cpu(Cpu&&) noexcept = delete;
    Cpu& operator=(Cpu&&) noexcept = delete;

    MCycles Step();

protected:
    int SetEi(int value);
    MCycles Execute(Reg8 opcode);

    [[nodiscard]] int GetEi() const;
    [[nodiscard]] CpuState& GetState() { return m_state; }
    [[nodiscard]] const CpuState& GetState() const { return m_state; }

private:
    void HandleEnableInterrupt();
    void CheckForInterrupts();

    [[nodiscard]] MCycles HandleInterrupts();
    template <InterruptType Type>
    [[nodiscard]] static consteval Address GetInterruptHandlerAddress();
    template <InterruptType Type>
    [[nodiscard]] bool HandleInterrupt();
};

} // namespace gb
