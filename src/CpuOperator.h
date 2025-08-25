#pragma once
#include "Cpu.h"

class CpuOperator {
public:
    static void Execute(Cpu& cpu, uint8_t opcode);
};
