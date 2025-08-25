#include "Cpu.h"
#include "CpuOperator.h"
#include "formatters.h"

#include <cstdint>
#include <format>

void Cpu::Execute(uint8_t opcode)
{
    return CpuOperator::Execute(*this, opcode);
}

void Cpu::Step()
{
    auto opcode = ram[pc];
    Execute(opcode);
}

std::ostream& operator<<(std::ostream& os, Cpu const& cpu)
{
    return os << std::format("PC: {}, Registers: {}", cpu.pc, cpu.reg);
}
