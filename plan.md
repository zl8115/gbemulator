# Refactoring Plan: src/sm83 → gbcore

## What this refactoring is doing

Extracting the emulator core into a standalone `gbcore` static library with a clean public API, replacing `src/sm83/`. Key changes:

- Everything moves into the `gb::` namespace (old code was in the root namespace or `detail::`)
- The pImpl pattern is dropped for both `Cpu` and `Mmu`; implementation goes directly into `.cpp` files
- `Timer` becomes standalone (owns its own registers as `Reg8` members) instead of holding `MappedRegister` references into Mmu's internals; Mmu delegates IO register reads/writes to Timer via `MapTimer(Timer&)`
- `CpuImpl` + `Cpu` wrapper collapses into a single `Cpu` class; opcode dispatch moves to `gbcore/src/detail/cpu_opcode.cpp`
- `CpuState` is now a public struct in `gbcore/include/cpu_state.h`

---

## Current state

### Done (staged)

| File | Status |
|------|--------|
| All `gbcore/include/` headers | Complete |
| `gbcore/src/detail/cpu_opcode.cpp` | Complete — port of opcode dispatch table + CB prefix table |
| `gbcore/src/detail/cpu_opcode_cycles.cpp` | Complete — port of cycle tables |
| Root `CMakeLists.txt` | Updated to point at `gbcore/` |
| `CMakePresets.json` | Updated with new preset names and ASAN/UBSAN on debug |
| `cmake/dependencies.cmake` | Catch2, nlohmann_json, SDL3 already declared |

### Incomplete / Bugs

#### 1. `gbcore/src/cpu.cpp` — bugs

- `HandleEnableInterrupt()` calls itself recursively (should call the EI-delay logic from `CpuImpl::HandleEnableInterrupt` in the old code)
- `CheckForInterrupts()` is empty — needs to call `HandleEnableInterrupt()` then check `REG_INTERRUPT_ENABLE & REG_INTERRUPT_FLAG`
- `SetEi()` is a stub returning `1` with a TODO — old implementation did the EI delay state machine
- `Step()` does not call `Timer::Step(cycles)` after `Execute(opcode)` — the old `CpuImpl::Step` did this

Reference: `src/sm83/detail/cpu/cpu_impl.cpp` lines 1047–1165

#### 2. `gbcore/src/mmu.cpp` — empty

The file is completely empty. Needs the full memory-bus implementation. The new `gb::Mmu` class has no pImpl and no internal member storage declared in the header, so storage (ROM banks, VRAM, working RAM, echo RAM, OAM, IO registers, high RAM) must be added as private members of `Mmu` in the header or defined directly in the `.cpp`.

Steps:
- Add private memory storage to `gbcore/include/mmu.h` (fixed-size arrays for each region matching the old `MmuImpl` layout)
- Port `Read(address)` and `Write(address, byte)` routing from `src/sm83/detail/memory/mmu_impl.cpp`
- Implement `MapTimer(Timer& timer)` — store a pointer/reference to Timer and delegate timer register reads/writes (`0xFF04`–`0xFF07`) to `Timer::Read` / `Timer::Write`
- Port DMA transfer logic
- Drop boot-ROM mapping control (`MappedRegister m_bootRomReg`) and test mode — or port them if still needed

#### 3. `gbcore/src/timer.cpp` — empty

Three blank lines only. Port from `src/sm83/detail/cpu/timer.cpp`.

Key difference: old Timer used `MappedRegister` (references into Mmu's storage); new Timer owns `regDivider`, `regCounter`, `regModulo`, `regControl` as `Reg8` members (declared `protected` in the header) and has its own `Read(address)` / `Write(address, byte)` methods. Mmu calls these when accesses hit the timer register range.

Port `Step()`, `PauseClock()`, `ResumeClock()`, `HandleDividerRegisterWrite()`, `HandleTimerControlWrite()`, `GetIncrementFrequency()`.

The old `Timer::Step` called `m_mmu.SetInterruptFlag<Mmu::InterruptType::TIMER>()` on overflow. In the new design the timer doesn't hold a Mmu reference — needs a callback or the caller (Cpu::Step) to check and fire the interrupt after Timer::Step returns. Decide and implement.

#### 4. `gbcore/tests/` — no source files

`gbcore/tests/CMakeLists.txt` declares an executable from `src/test_cpu.cpp` and `src/test_timer.cpp`, but neither file exists. The `tests/src/` directory doesn't exist.

- Create `gbcore/tests/src/test_cpu.cpp` — CPU unit tests (use `gb::Cpu`, `gb::Mmu`, `gb::Timer`; port tests from `src/sm83/test/tester.cpp` or write new Catch2 tests)
- Create `gbcore/tests/src/test_timer.cpp` — Timer unit tests

#### 5. `gbcore/CMakeLists.txt` — tests not hooked up

`add_subdirectory(tests)` is missing (other subdirectories are commented out). Add it and link Catch2.

```cmake
add_subdirectory(tests)
```

The `gbcore/tests/CMakeLists.txt` already links `Catch2::Catch2WithMain` — just needs `catch_discover_tests(gbtest)` wired up.

---

## Components not yet ported

These still live in `src/sm83/` and are referenced by commented-out lines in `gbcore/CMakeLists.txt`. They are out of scope for the current WIP but will need to be done before the old `src/` tree can be deleted:

| Old location | New location | Notes |
|---|---|---|
| `src/sm83/catridge.*` + `detail/catridge/` | `gbcore/src/catridge.cpp` etc. | MBC1 logic already fixed per recent commits |
| `src/sm83/ppu.*` + `detail/video/` | `gbcore/src/ppu.cpp` etc. | |
| `src/sm83/input.*` + `detail/input/` | `gbcore/src/input.cpp` etc. | |
| `src/sm83/soc.*` | `gbcore/src/soc.cpp` | Wires Cpu, Mmu, Ppu, Input, Catridge together |
| `src/sm83/frame_buffer.*` | `gbcore/src/frame_buffer.cpp` | |
| `src/sm83/detail/logger.*` | `gbcore/src/detail/logger.cpp` | |
| `src/sdl_gbemulator/` | unchanged or move | SDL frontend — update includes to gbcore |
| `src/sdl_renderer/` | unchanged | SDL renderer, no emulator core deps |
| `src/soc_inspector/` | unchanged | Update if it includes sm83 headers |

---

## Suggested order of work

1. Fix `gbcore/src/cpu.cpp` — correct the infinite recursion, implement `CheckForInterrupts`, implement `SetEi` EI-delay state machine, call `Timer::Step` from `Step()`
2. Implement `gbcore/src/timer.cpp` — port Step/clock logic; decide on interrupt signalling (callback vs. return value)
3. Implement `gbcore/src/mmu.cpp` — add memory storage to header, port routing, implement `MapTimer`
4. Wire up `gbcore/CMakeLists.txt` to include tests
5. Create test source files and make them build
6. Port Catridge, Ppu, Input, Soc in any order
7. Update SDL frontend includes
8. Delete `src/sm83/` once everything builds and tests pass
