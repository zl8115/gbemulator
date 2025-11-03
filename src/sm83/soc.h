#pragma once

#include "mmu.h"
#include "registers.h"
#include "cpu.h"
#include "ppu.h"

#include <string_view>

class Soc
{
public:
    Soc();

    int Step();
    void LoadRomFromFile(std::string_view romPath);

    Mmu m_mmu;
    Registers m_reg;
    Cpu m_cpu;
    Ppu m_ppu;
};
