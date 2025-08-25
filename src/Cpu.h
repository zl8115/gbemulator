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

    friend std::ostream& operator<<(std::ostream&, Cpu const& cpu);
    friend class CpuOperator;

public:
    bool ime = true;
    uint16_t pc; // Program Counter
    uint16_t sp; // ???
    Registers reg;
    // MemoryBus m_bus;
    uint8_t ram[0xFFFF];
};
