#pragma once

#include "cycles.h"
#include "registers.h"
#include "mmu.h"

#include <stdint.h>

struct CpuState
{
    Mmu& mmu;
    Registers& reg;
    bool branchTaken;   // flag is branch was taken
    MCycles cbOpCodeCycles; // cycles taken if the cb opcode prefix is taken
};

class CpuInstructions
{
public:
    CpuInstructions(Mmu& mmu, Registers& reg);
    MCycles Execute(uint8_t opcode);

private:
    CpuState m_state;
};
