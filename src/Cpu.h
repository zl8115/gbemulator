#pragma once

#include <stdint.h>
#include <ostream>

#include "Registers.h"
#include "MemoryBus.h"

class Cpu
{
public:
    enum Instruction: uint8_t
    {
        INVALID = 0,

        LOAD,
        LOADH,

        ADD,
        INC,
        DEC,
        JR,
        RLC,
        RLCA,
        RRA,
        RRCA,
        RLA,
        DAA,

        // Misc Instructions
        NOOP,
        STOP,
        HALT,
        DI,
        EI,
    };

    void Step();
    void Execute(uint8_t opcode);
    // More of a convenience testing function
    void Execute(Instruction inst,
                    Registers::Target src = Registers::Target::NONE,
                    Registers::Target dst = Registers::Target::NONE);

    friend std::ostream& operator<<(std::ostream&, Cpu const& cpu);
    friend class CpuOperator;

public:
    uint8_t ReadFromReg(Registers::Target target);
    uint8_t ExecutePrefixed(uint8_t opcode);

    uint16_t pc; // Program Counter
    uint16_t sp; // Program Counter
    Registers reg;
    // MemoryBus m_bus;
    uint8_t ram[0xFFFF];
};
