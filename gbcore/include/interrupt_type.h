#pragma once

namespace gb {

enum class InterruptType
{
    VBLANK = 0,
    LCD,
    TIMER,
    SERIAL,
    JOYPAD,
};

} // namespace gb
