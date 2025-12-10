#pragma once

#include "cycles.h"
#include "mmu.h"
#include "detail/cpu_registers.h"

namespace detail {

struct CpuState
{
    Mmu& mmu;
    Registers& reg;
    bool branchTaken;   // flag is branch was taken
    MCycles cbOpCodeCycles; // cycles taken if the cb opcode prefix is taken
};

class CpuImpl
{
public:
    CpuImpl(Mmu& mmu);
    MCycles Step();
    MCycles Execute(uint8_t opcode);

    Registers& GetRegister();
    const Registers& GetRegister() const;

private:
    Registers m_reg;
    CpuState m_state;
};

} // namespace detail
