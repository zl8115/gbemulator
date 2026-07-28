#include "cpu.h"
#include "cpu_state.h"
#include "interrupt_type.h"
#include "mmu.h"
#include "timer.h"

#include <catch2/catch_test_macros.hpp>

namespace {

// `Cpu`'s register/state access is protected so production callers can't poke at internals;
// tests reach it through a subclass instead.
struct TestCpu : gb::Cpu
{
    using gb::Cpu::Cpu;
    using gb::Cpu::GetState;
};

} // namespace

TEST_CASE("Cpu executes NOP and advances the program counter", "[cpu]")
{
    gb::Mmu mmu;
    gb::Timer timer;
    mmu.MapTimer(timer);
    TestCpu cpu(mmu, timer);

    mmu.Write(0x0000, 0x00); // NOP

    auto cycles = cpu.Step();

    CHECK(cpu.GetState().reg.pc == 1);
    CHECK(cycles.cycles == 1);
}

TEST_CASE("Cpu executes LD A,n", "[cpu]")
{
    gb::Mmu mmu;
    gb::Timer timer;
    mmu.MapTimer(timer);
    TestCpu cpu(mmu, timer);

    mmu.Write(0x0000, 0x3E); // LD A, n
    mmu.Write(0x0001, 0x42);

    cpu.Step();

    CHECK(cpu.GetState().reg.a == 0x42);
    CHECK(cpu.GetState().reg.pc == 2);
}

TEST_CASE("Cpu delays IME by one instruction after EI", "[cpu]")
{
    gb::Mmu mmu;
    gb::Timer timer;
    mmu.MapTimer(timer);
    TestCpu cpu(mmu, timer);

    mmu.Write(0x0000, 0xFB); // EI
    mmu.Write(0x0001, 0x00); // NOP

    cpu.Step(); // EI: IME is not enabled by the instruction that sets it...
    CHECK(cpu.GetState().reg.ime == 0);

    cpu.Step(); // ...but takes effect after the next one.
    CHECK(cpu.GetState().reg.ime == 1);
}

TEST_CASE("Cpu services a pending interrupt on the following Step", "[cpu]")
{
    gb::Mmu mmu;
    gb::Timer timer;
    mmu.MapTimer(timer);
    TestCpu cpu(mmu, timer);

    mmu.Write(0x0000, 0x00); // NOP
    mmu.Write(0x0001, 0x00); // NOP

    cpu.GetState().reg.sp = 0xFFFE;
    cpu.GetState().reg.ime = 1;
    mmu.EnableInterrupt<gb::InterruptType::VBLANK>();
    mmu.SetInterruptFlag<gb::InterruptType::VBLANK>();

    cpu.Step(); // Executes the NOP at 0x0000; flags the interrupt as pending for next Step.
    CHECK(cpu.GetState().reg.pc == 1);
    CHECK(cpu.GetState().interruptPending);

    auto cycles = cpu.Step(); // Services the interrupt instead of executing the NOP at 0x0001.
    CHECK(cpu.GetState().reg.pc == 0x40); // VBLANK handler address
    CHECK(cpu.GetState().reg.ime == 0);
    CHECK_FALSE(cpu.GetState().interruptPending);
    CHECK_FALSE(mmu.HasInterrupt<gb::InterruptType::VBLANK>());
    CHECK(cycles.cycles == 5);

    // Return address (0x0001) was pushed onto the stack.
    CHECK(cpu.GetState().reg.sp == 0xFFFC);
    CHECK(mmu.Read(0xFFFC) == 0x01);
    CHECK(mmu.Read(0xFFFD) == 0x00);
}
