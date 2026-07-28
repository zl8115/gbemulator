#pragma once

#include "cartridge.h"
#include "cpu.h"
#include "cycles.h"
#include "input.h"
#include "mmu.h"
#include "ppu.h"
#include "timer.h"

#include <string_view>
#include <vector>

namespace gb {

// Ties the core components together: routes Cpu/Timer/Cartridge/Ppu/Input through a
// shared Mmu and drives them once per Step(), mirroring the old (unported) Soc class.
class GbEmulator
{
public:
    GbEmulator();

    MCycles Step();

    void LoadRom(std::vector<uint8_t>&& romData);
    void LoadRomFromFile(std::string_view romPath);

    void RegisterRenderer(IRenderer* pRenderer);

    [[nodiscard]] Input& GetInput() { return m_input; }
    [[nodiscard]] const Ppu& GetPpu() const { return m_ppu; }

    // Exposed for testing/tooling - lets tests peek at or poke arbitrary addresses
    // (registers, RAM) without needing a full CPU-driven scenario.
    [[nodiscard]] Mmu& GetMmu() { return m_mmu; }
    [[nodiscard]] const Mmu& GetMmu() const { return m_mmu; }

private:
    Mmu m_mmu;
    Timer m_timer;
    Cartridge m_cartridge;
    Ppu m_ppu;
    Input m_input;
    Cpu m_cpu;
};

} // namespace gb
