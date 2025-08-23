#pragma once

#include "Cpu.h"
#include <tuple>

uint8_t ConvertCpuInstruction(std::tuple<Cpu::Instruction, Registers::Target, Registers::Target> instructionSet);
uint8_t ConvertCpuInstruction(Cpu::Instruction inst, Registers::Target src, Registers::Target dst);

std::tuple<Cpu::Instruction, Registers::Target, Registers::Target> TranslateOpCode(uint8_t opcode);
