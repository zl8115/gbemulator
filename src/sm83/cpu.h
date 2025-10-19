#pragma once

#include <stdint.h>
#include "registers.h"
#include "mmu.h"

class Cpu
{
public:
    void Step();
    void Execute(uint8_t opcode);

    Registers reg;
    Mmu mmu;
    uint8_t ei = 0;
    uint8_t ime = 0;
    uint8_t ie = 0;
};
