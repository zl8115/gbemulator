#pragma once

#include "cycles.h"
#include "cpu_instructions.h"
#include "mmu.h"
#include "registers.h"

#include <stdint.h>

class Cpu
{
public:
    Cpu(Mmu& mmu, Registers& reg);

    MCycles Step();
    MCycles Execute(uint8_t opcode);

private:
    Registers& m_reg;
    Mmu& m_mmu;
    CpuInstructions m_inst;
};
