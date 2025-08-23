#include "Cpu.h"
#include "CpuOperator.h"
#include "formatters.h"

#include <cstdint>
#include <format>

void Cpu::Execute(uint8_t opcode)
{
    return CpuOperator::Execute(*this, opcode);
}

void Cpu::Execute(
    Instruction inst,
    Registers::Target src,
    Registers::Target dst)
{
    // auto opcode = CpuOperator::ConvertCpuInstruction(inst, src, dst);
    return CpuOperator::Execute(*this, inst, src, dst);
}

void Cpu::Step()
{
    auto opcode = ram[pc];
    // auto next_pc = Execute(opcode);
    // pc = next_pc;
    Execute(opcode);
}

// uint8_t Cpu::Add(uint8_t value)
// {
//     uint8_t new_value = reg.a + value;
//
//     reg.f &= !Registers::Flags::ALL;
//     if (new_value == 0)
//         reg.f |= Registers::Flags::ZERO_FLAG;
//
//     if ((reg.a & 0xF) + (value & 0xF) > 0)
//         reg.f |= Registers::Flags::HALF_CARRY_FLAG;
//
//     if (new_value < reg.a)
//         reg.f |=  Registers::Flags::CARRY_FLAG;
//
//     return new_value;
// }

uint8_t Cpu::ReadFromReg(Registers::Target target)
{
    return reg.Get(target);
}

std::ostream& operator<<(std::ostream& os, Cpu const& cpu)
{
    return os << std::format("PC: {}, Registers: {}", cpu.pc, cpu.reg);
}
