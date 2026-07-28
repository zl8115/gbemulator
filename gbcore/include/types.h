#pragma once
#include <cstdint>
#include "cycles.h"

namespace gb {

using Byte    = std::uint8_t;
using SByte   = std::int8_t;
using Word    = std::uint16_t;

using Reg8    = Byte;
using Reg16   = Word;
using Address = Word;

using CCycles = Cycles<ClockTag>;
using MCycles = Cycles<MachineTag>;

} // namespace gb
