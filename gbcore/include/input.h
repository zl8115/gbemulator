#pragma once

#include "gb_button.h"
#include "types.h"

namespace gb {

class Input
{
public:
    Input() = default;

    void ButtonPressed(GbButton button);
    void ButtonReleased(GbButton button);

    // Re-derives the joypad register's input lines (bits 0-3) from the currently
    // pressed buttons and whichever group (dpad/buttons) the game last selected.
    void Step();

    [[nodiscard]] Reg8 Read(const Address address) const;
    void Write(const Address address, Reg8 byte);

private:
    bool m_pressedUp = false;
    bool m_pressedDown = false;
    bool m_pressedLeft = false;
    bool m_pressedRight = false;
    bool m_pressedA = false;
    bool m_pressedB = false;
    bool m_pressedSelect = false;
    bool m_pressedStart = false;

    Reg8 m_reg = 0xFF;
};

} // namespace gb
