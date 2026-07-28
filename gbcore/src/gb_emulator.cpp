#include "gb_emulator.h"

#include <filesystem>
#include <format>
#include <fstream>

namespace gb {

namespace {

std::vector<uint8_t> LoadRomData(std::string_view romPath)
{
    std::filesystem::path fp(romPath);
    if (!std::filesystem::exists(fp) || !std::filesystem::is_regular_file(fp))
    {
        throw std::runtime_error(std::format("File does not exist: {}", romPath));
    }

    std::ifstream stream(fp, std::ios::binary | std::ios::ate);
    if (!stream.good())
    {
        throw std::runtime_error(std::format("Cannot read file: {}", romPath));
    }

    std::ifstream::pos_type position = stream.tellg();
    auto fileSize = static_cast<std::size_t>(position);

    std::vector<char> fileContents(fileSize);

    stream.seekg(0, std::ios::beg);
    stream.read(fileContents.data(), static_cast<std::streamsize>(position));
    stream.close();

    return std::vector<uint8_t>(fileContents.begin(), fileContents.end());
}

} // namespace

GbEmulator::GbEmulator():
    m_mmu(),
    m_timer(),
    m_cartridge(),
    m_ppu(),
    m_input(),
    m_cpu(m_mmu, m_timer)
{
    m_mmu.MapTimer(m_timer);
    m_mmu.MapCartridge(m_cartridge);
    m_mmu.MapPpu(m_ppu);
    m_mmu.MapInput(m_input);
}

MCycles GbEmulator::Step()
{
    MCycles cpuCycles = m_cpu.Step();
    CCycles clockCycles = cpuCycles.as<ClockTag>();

    m_timer.Step(clockCycles);
    m_ppu.Step(clockCycles);
    m_input.Step();

    return cpuCycles;
}

void GbEmulator::LoadRom(std::vector<uint8_t>&& romData)
{
    m_cartridge.LoadRom(std::move(romData));
}

void GbEmulator::LoadRomFromFile(std::string_view romPath)
{
    m_cartridge.LoadRom(LoadRomData(romPath));
}

void GbEmulator::RegisterRenderer(IRenderer* pRenderer)
{
    m_ppu.RegisterRenderer(pRenderer);
}

} // namespace gb
