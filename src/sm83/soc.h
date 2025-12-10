#pragma once

#include "mmu.h"
#include "cpu.h"
#include "ppu.h"
#include "input.h"
#include "registers.h"
#include "catridge.h"

#include <string_view>

class Soc
{
public:
    Soc();

    MCycles Step();
    Input& GetInput();
    void LoadRomFromFile(std::string_view romPath);
    void RegisterRenderer(IRenderer* pRenderer);

    Mmu m_mmu;
    Registers m_reg;
    Input m_input;
    Cpu m_cpu;
    Ppu m_ppu;
    Catridge m_catridge;
};
