#pragma once
#include "Cpu.h"

class CpuOperator {
public:
    static void Execute(Cpu& cpu, Cpu::Instruction inst, Registers::Target src, Registers::Target dst);
    static void Execute(Cpu& cpu, uint8_t opcode);
    // static uint8_t ExecutePrefixed(Cpu& cpu, uint8_t opcode);

    // static uint8_t ConvertCpuInstruction(Cpu::Instruction inst, Registers::Target src, Registers::Target dst);
    // static std::tuple<Cpu::Instruction, Registers::Target, Registers::Target> TranslateOpCode(Cpu& cpu, uint8_t opcode);

private:
    static void Noop(Cpu& cpu);

    static void Add(Cpu& cpu, Registers::Target target, uint8_t value);
    static void Load(Cpu& cpu, Registers::Target src, Registers::Target dst);
    // static uint8_t Jump(Cpu& cpu, Registers::Target src, Registers::Target dst);
};
