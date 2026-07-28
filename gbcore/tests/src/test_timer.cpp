#include "timer.h"

#include "mmu_register_names.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Timer divider increments every 256 cycles", "[timer]")
{
    gb::Timer timer;

    timer.Step(gb::CCycles{255});
    CHECK(timer.Read(REG_DIVIDER_REGISTER) == 0);

    timer.Step(gb::CCycles{1});
    CHECK(timer.Read(REG_DIVIDER_REGISTER) == 1);
}

TEST_CASE("Writing the divider register resets it", "[timer]")
{
    gb::Timer timer;
    timer.Step(gb::CCycles{256});
    REQUIRE(timer.Read(REG_DIVIDER_REGISTER) == 1);

    timer.Write(REG_DIVIDER_REGISTER, 0x99);
    CHECK(timer.Read(REG_DIVIDER_REGISTER) == 0);
}

TEST_CASE("Timer counter does not increment while disabled", "[timer]")
{
    gb::Timer timer;
    timer.Write(REG_TIMER_CONTROL, 0x00); // disabled

    timer.Step(gb::CCycles{1000});
    CHECK(timer.Read(REG_TIMER_COUNTER) == 0);
}

TEST_CASE("Timer counter increments at the configured frequency", "[timer]")
{
    gb::Timer timer;
    timer.Write(REG_TIMER_CONTROL, 0x05); // enabled, clock select 01 -> every 16 cycles

    timer.Step(gb::CCycles{15});
    CHECK(timer.Read(REG_TIMER_COUNTER) == 0);

    timer.Step(gb::CCycles{1});
    CHECK(timer.Read(REG_TIMER_COUNTER) == 1);
}

TEST_CASE("Timer counter overflow reloads modulo and fires the overflow callback", "[timer]")
{
    gb::Timer timer;
    bool overflowed = false;
    timer.SetOverflowCallback([&overflowed] { overflowed = true; });

    timer.Write(REG_TIMER_MODULO, 0x10);
    timer.Write(REG_TIMER_CONTROL, 0x05); // enabled, every 16 cycles
    timer.Write(REG_TIMER_COUNTER, 0xFF);

    timer.Step(gb::CCycles{16});

    CHECK(overflowed);
    CHECK(timer.Read(REG_TIMER_COUNTER) == 0x10);
}
