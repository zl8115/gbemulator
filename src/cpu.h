#pragma once

#include <stdint.h>
#include "registers.h"

class Cpu
{
public:
    void Step();
    void Execute(uint8_t opcode);

public:
    Registers reg;
    uint8_t ime = 0;
    uint8_t ram[0xFFFF];
};
