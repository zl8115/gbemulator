#pragma once

#include <stdint.h>

class Cpu;

class CpuInstructions {
public:
    static int Execute(Cpu& cpu, uint8_t opcode);
};
