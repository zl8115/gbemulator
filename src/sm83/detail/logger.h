#pragma once

#include <string_view>

class FrameBuffer;
class Mmu;

namespace detail {
class CpuImpl;
class MmuImpl;
}

namespace GbStateLogger {
    void SetLogDir(std::string_view dirPath);
    void UnsetLogDir();
    void Log(const FrameBuffer& cpu);
    void LogState(const detail::CpuImpl& cpu);
    void LogState(const Mmu& mmu);
}; // namespace
