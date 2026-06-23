#pragma once

#include "../types.h"

namespace gb {
namespace detail {

extern MCycles s_OpCodeCycles[0x100];
extern MCycles s_CbOpcodeCycles[0x100];
extern MCycles s_ConditionalOpCodeCycles[0x100];

} // namespace detail
} // namespace gb
