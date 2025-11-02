#pragma once

#include "registers.h"
#include "mmu.h"

#include <stdint.h>
#include <string_view>

// Some internal state to make CPU cycles easier to manage
struct CpuDetails
{
    bool branchTaken;
    int cbInstructionCycles;
};

class Cpu
{
public:
    int Step();
    int Execute(uint8_t opcode);

    void LoadRomFromFile(std::string_view romPath);

    uint8_t ei = 0;
    uint8_t ime = 0;
    uint8_t ie = 0;
    Registers reg;
    Mmu mmu;
    CpuDetails details;
};
