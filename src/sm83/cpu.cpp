#include "cpu.h"
#include "cpu_instructions.h"

#include <cstdint>
#include <filesystem>
#include <format>
#include <fstream>

void Cpu::Execute(uint8_t opcode)
{
    return CpuInstructions::Execute(*this, opcode);
}

void Cpu::Step()
{
    auto opcode = mmu.Read(reg.pc);
    Execute(opcode);
}

namespace {

void ValidateRomDataOrThrow(const std::vector<uint8_t>& romData)
{
    // TODO: Validation
}

std::vector<uint8_t> LoadRomData(std::string_view romPath)
{
    std::filesystem::path fp(romPath);
    if (!std::filesystem::exists(fp) || !std::filesystem::is_regular_file(fp))
    {
        auto error_str = std::format("File does not exist: {}", romPath);
        throw std::runtime_error(error_str);
    }

    std::ifstream stream(fp, std::ios::binary|std::ios::ate);
    if (!stream.good())
    {
        auto error_str = std::format("Cannot read file: {}", romPath);
        throw std::runtime_error(error_str);
    }

    std::ifstream::pos_type position = stream.tellg();
    auto file_size = static_cast<size_t>(position);

    std::vector<char> file_contents(file_size);

    stream.seekg(0, std::ios::beg);
    stream.read(&file_contents[0], static_cast<std::streamsize>(position));
    stream.close();

    return std::vector<uint8_t>(file_contents.begin(), file_contents.end());
}

} // namespace

void Cpu::LoadRomFromFile(std::string_view romPath)
{
    auto data = LoadRomData(romPath);
    ValidateRomDataOrThrow(data);
    mmu.LoadRom(std::move(data));
}
