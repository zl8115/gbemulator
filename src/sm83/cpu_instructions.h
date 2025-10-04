#pragma once

#include <stdint.h>

class Cpu;

class CpuInstructions {
public:
    static void Execute(Cpu& cpu, uint8_t opcode);
};
