#include "cpu.h"
#include "cpu_instructions.h"

#include <cstdint>

void Cpu::Execute(uint8_t opcode)
{
    return CpuInstructions::Execute(*this, opcode);
}

void Cpu::Step()
{
    auto opcode = ram[pc];
    Execute(opcode);
}
