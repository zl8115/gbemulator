#pragma once

#include "registers.h"
#include "mmu.h"

#include <stdint.h>
#include <string_view>

class Cpu
{
public:
    void Step();
    void Execute(uint8_t opcode);

    void LoadRomFromFile(std::string_view romPath);

    Registers reg;
    Mmu mmu;
    uint8_t ei = 0;
    uint8_t ime = 0;
    uint8_t ie = 0;
};
