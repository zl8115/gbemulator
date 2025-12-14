#pragma once

#include "mmu.h"
#include "cpu.h"
#include "ppu.h"
#include "input.h"
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

    void EnableUnitTestMode(); // Disables all mapped registry actions (e.g. timer and dma control)

    Mmu m_mmu;
    Input m_input;
    Cpu m_cpu;
    Ppu m_ppu;
    Catridge m_catridge;
};
