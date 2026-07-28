#pragma once

#include "../cpu_state.h"

namespace gb {
namespace detail {

MCycles Execute(CpuState& state, Reg8 opcode);

void PushPc(CpuState& state);

} // namespace detail
} // namespace gb
