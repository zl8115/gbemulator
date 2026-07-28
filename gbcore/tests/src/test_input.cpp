#include "input.h"

#include <catch2/catch_test_macros.hpp>

// NOTE: the ported logic sets a button's bit to 1 when pressed (see Input::Step). Real Game
// Boy hardware is active-low (0 = pressed) for these bits, so this is inverted from real
// hardware polarity - preserved as-is from the original implementation, see plan.md.

TEST_CASE("Input reports no buttons pressed when dpad is selected", "[input]")
{
    gb::Input input;
    input.Write(0xFF00, 0b00100000); // select dpad (bit 4 low), buttons deselected (bit 5 high)

    input.Step();

    CHECK((input.Read(0xFF00) & 0x0F) == 0x00);
}

TEST_CASE("Input reflects pressed dpad buttons", "[input]")
{
    gb::Input input;
    input.ButtonPressed(gb::GbButton::Right);
    input.ButtonPressed(gb::GbButton::Down);
    input.Write(0xFF00, 0b00100000); // select dpad

    input.Step();

    gb::Reg8 value = input.Read(0xFF00);
    CHECK((value & 0x01) != 0); // Right pressed
    CHECK((value & 0x02) == 0); // Left not pressed
    CHECK((value & 0x04) == 0); // Up not pressed
    CHECK((value & 0x08) != 0); // Down pressed
}

TEST_CASE("Input reflects pressed action buttons when buttons group is selected", "[input]")
{
    gb::Input input;
    input.ButtonPressed(gb::GbButton::A);
    input.ButtonPressed(gb::GbButton::Start);
    input.Write(0xFF00, 0b00010000); // select buttons group

    input.Step();

    gb::Reg8 value = input.Read(0xFF00);
    CHECK((value & 0x01) != 0); // A pressed
    CHECK((value & 0x02) == 0); // B not pressed
    CHECK((value & 0x04) == 0); // Select not pressed
    CHECK((value & 0x08) != 0); // Start pressed
}

TEST_CASE("Input releasing a button clears its bit again", "[input]")
{
    gb::Input input;
    input.ButtonPressed(gb::GbButton::A);
    input.Write(0xFF00, 0b00010000);
    input.Step();
    REQUIRE((input.Read(0xFF00) & 0x01) != 0);

    input.ButtonReleased(gb::GbButton::A);
    input.Step();

    CHECK((input.Read(0xFF00) & 0x01) == 0);
}
