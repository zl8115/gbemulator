#include "detail/logger.h"

#include "cpu.h"
#include "frame_buffer.h"
#include "mmu.h"
#include "detail/impl_helper.h"
#include "detail/cpu/cpu_impl.h"
#include "detail/cpu/formatter.h"
#include "detail/memory/mmu_impl.h"
#include "detail/memory/formatter.h"
#include "detail/video/formatter.h"

#include <filesystem>
#include <optional>
#include <print>
#include <fstream>
#include <stdexcept>

constexpr char CpuFileFormat[] = "cpu_{:05}.log";
constexpr char MmuFileFormat[] = "mmu_{:05}.log";
constexpr char VideoFileFormat[] = "frame_{:05}.log";

static std::optional<std::filesystem::path> gLogDir = std::nullopt;
static std::size_t gCpuStateCount = 0;
static std::size_t gMmuStateCount = 0;
static std::size_t gVideoStateCount = 0;

namespace GbStateLogger {

void SetLogDir(std::string_view dirPath)
{
    std::filesystem::path dp(dirPath);
    if (!std::filesystem::exists(dp))
    {
        throw std::runtime_error(std::format("{} does not exist.", std::string(dp)));
    }
    if (!std::filesystem::is_directory(dp))
    {
        throw std::runtime_error(std::format("{} is not a directory.", std::string(dp)));
    }
    gLogDir = dp;
}

void UnsetLogDir()
{
    gLogDir = std::nullopt;
}

void Log(const FrameBuffer& frameBuffer)
{
    if (!gLogDir)
        return;

    auto outFilePath = gLogDir.value() / std::format(VideoFileFormat, gVideoStateCount++);
    std::ofstream ostream(outFilePath, std::ios_base::out | std::ios_base::trunc);
    std::print(ostream, "{}", frameBuffer);
}

void LogState(const Mmu& mmu)
{
    if (!gLogDir)
        return;

    auto outFilePath = gLogDir.value() / std::format(MmuFileFormat, gMmuStateCount++);
    std::ofstream ostream(outFilePath, std::ios_base::out | std::ios_base::trunc);
    std::print(ostream, "{}", mmu);
}

void LogState(const detail::MmuImpl& mmu)
{
    return;
    if (!gLogDir)
        return;

    auto outFilePath = gLogDir.value() / std::format(MmuFileFormat, gMmuStateCount++);
    std::ofstream ostream(outFilePath, std::ios_base::out | std::ios_base::trunc);
    std::print(ostream, "{}", mmu);
}

void LogState(const detail::CpuImpl& cpu)
{
    return;
    if (!gLogDir)
        return;

    auto outFilePath = gLogDir.value() / std::format(CpuFileFormat, gCpuStateCount++);
    std::ofstream ostream(outFilePath, std::ios_base::out | std::ios_base::trunc);
    std::print(ostream, "{}", cpu);

    // Then also log Mmu for convenience
    LogState(detail::ImplHelper::ExtractImpl(cpu.GetState().mmu));
}


} // namespace GbStateLogger
