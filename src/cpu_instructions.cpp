#include "cpu.h"
#include "cpu_instructions.h"

#include <functional>

namespace {

void Noop(Cpu& cpu)
{
    ++cpu.reg.pc;
}

} // namespace

std::function<void(Cpu&)> s_Instructions[0x100] = {
    // 0x0X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0x1X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0x2X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0x3X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0x4X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0x5X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0x6X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0x7X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0x8X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0x9X
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0xaX
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0xbX
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0xcX
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0xdX
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0xeX
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
    // 0xfX
    ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop, ::Noop,
};

void CpuInstructions::Execute(Cpu& cpu, uint8_t opcode)
{
    s_Instructions[opcode](cpu);
}
