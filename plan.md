# Known issues / bugs carried over from the src/sm83 → gbcore port

This tracks bugs found while porting `Cartridge`, `Ppu`, `Input`, and the `GbEmulator`
glue from the old `src/sm83/` tree into `gbcore`. Per instruction, these were **preserved,
not silently fixed** — the ported code behaves the same as the original, bug for bug. Each
entry below is something you may want to review and decide whether/how to fix.

Cpu, Mmu, and Timer were ported in an earlier pass; their known issue (`Cpu::SetEi`) is
listed here too for completeness.

## Cartridge / MBC1

1. **Advanced banking mode's upper ROM bank bits never apply.**
   `gbcore/src/cartridge.cpp:49` — `bank |= m_ramBankSelect & 0x3 << 6;`. Due to operator
   precedence, `<<` binds tighter than `&`, so this evaluates as `m_ramBankSelect & (0x3 << 6)`
   (`m_ramBankSelect & 0xC0`), not `(m_ramBankSelect & 0x3) << 6`. Since `m_ramBankSelect` is
   always masked to 2 bits before storage, the result is always 0 — the upper ROM bank bits
   in MBC1 "advanced" banking mode never take effect. Games relying on banking-mode-1 ROM
   bank switching (>512KB ROMs) would read the wrong bank. Covered by the test
   `"Cartridge advanced banking mode's upper ROM bank bits never apply"` in
   `gbcore/tests/src/test_cartridge.cpp`, which pins the current (buggy) behavior.

2. **No ROM/RAM size masking against the cartridge header.**
   `gbcore/src/cartridge.cpp:14-15` (`m_romSize`/`m_ramSize` are parsed from the header but
   never used to bound-check or mask the bank-select registers). A cartridge could select a
   bank number beyond what it actually has, reading whatever happens to be there. External
   RAM in the new code is sized as a fixed 4-bank (32KB) buffer specifically so this can't
   cause out-of-bounds access — but it doesn't validate the *declared* size either.

3. **No ROM header/checksum validation.** The original had a `ValidateRom()` stub
   (`// TODO: Validation`) that was never implemented; the port doesn't add any either.
   Malformed ROMs won't be rejected up front.

4. **Uncertain external RAM design (changed during this port, not silently preserved).**
   The original's external-RAM banking was entangled with its `MappedMemoryBlock`
   re-pointing mechanism, including an apparent bug where RAM-bank offsets were computed
   using the ROM bank size (0x4000) instead of the RAM bank size (0x2000), and RAM-bank
   switches ended up re-aliasing into the ROM buffer rather than a dedicated RAM buffer
   (the original author's own comment doubted this code: *"I don't actually know what to do
   with this"*). Since this pass replaces that whole indirection mechanism (see the
   Mmu/architecture note below), external RAM in `gbcore/include/cartridge.h` is instead a
   straightforward dedicated 4-bank buffer with correct 0x2000-byte bank arithmetic. This is
   a deliberate behavior change, flagged here rather than hidden, since faithfully
   reproducing the old aliasing bug would have meant deliberately re-introducing the very
   indirection pattern this pass removed.

## PPU / rendering

5. **Sprite X/Y flip is computed but never applied.**
   `gbcore/src/ppu.cpp:471-478` (`DrawSprite`) — `maybe_flipped_x`/`maybe_flipped_y` are
   computed from the sprite's flip flags but the tile fetch (`GetObjTile(tileIdx + tileOffset, y)`)
   and colour lookup (`GetColourFromTile(tileData, x, palette)`) both use the raw, un-flipped
   `x`/`y` instead. Flipped sprites render as if they weren't flipped.

6. **Sprite-vs-background priority check reads the wrong pixel.**
   `gbcore/src/ppu.cpp:495-496` — `m_viewBuffer.GetPixel(x, y)` uses the tile-local loop
   counters (0-7) instead of the actual destination framebuffer coordinates
   (`pixelX`, `pixelY`) used everywhere else in the same function. The OBJ-vs-BG priority
   check (`PriorityFlag && existingPixel != White`) is therefore comparing against the wrong
   pixel almost every frame, making sprite priority effectively broken/inconsistent.

7. **Window-position underflow.**
   `gbcore/src/ppu.cpp:401` — `unsigned int windowX = renderX + m_windowPosX - 7;` underflows
   (wraps to a huge value) whenever `windowPosX < 7` and `renderX` is small. The original had
   a bounds check commented out at this exact spot; the port doesn't add one either, so the
   underflowed `tileIdx` can read from an unexpected VRAM offset.

## Input

8. **Pressed-button bits are inverted from real hardware polarity.**
   `gbcore/src/input.cpp:37-59` (`Input::Step`) — sets a button's bit to **1** when pressed
   (`utils::SetBitTo<N>(m_reg, m_pressedX)`). Real Game Boy joypad hardware is active-low:
   0 = pressed, 1 = released. This was already the case in the original `InputImpl::WriteInput`
   and is preserved as-is. As written, any real game reading the joypad register would see
   every button's pressed/released state backwards. This was found empirically while writing
   `gbcore/tests/src/test_input.cpp` (the tests assert the actual, inverted behavior — not
   real hardware polarity) rather than during the original code read-through, so it wasn't in
   the initial survey of known issues.

## Cpu (from the earlier Cpu/Mmu/Timer port, still open)

9. **`Cpu::SetEi` is unimplemented.** `gbcore/include/cpu.h:30`, `gbcore/src/cpu.cpp:44-48` —
   still a `// TODO: Do` stub returning a constant. Nothing currently calls it, so it hasn't
   surfaced as a functional gap yet.

## Out of scope this pass (not bugs, just not done)

- The SDL app layer (`src/sdl_renderer`, `src/sdl_gbemulator`, `src/soc_inspector`) was not
  touched or ported — it remains orphaned from the build (see below). It has its own known
  issue worth remembering if/when it's revived: the old `SdlRenderer`'s key-up handling
  called `ButtonPressed` instead of `ButtonReleased`, so released keys never cleared.
- `AssetRenderer` (a secondary/debug tile-view renderer) and `soc_inspector` (a bare
  `while(true)` debugging harness with commented-out breakpoint scaffolding) were both
  abandoned-looking in the original and were intentionally not ported — dropped rather than
  carried over as dead code, per your choice when this pass was scoped.
- The whole legacy `src/` tree has been orphaned from the build since the Cpu/Mmu/Timer pass
  (root `CMakeLists.txt` no longer has `add_subdirectory(src)`, and old files still expect
  headers that were moved into `gbcore`). It was already unbuildable before this pass and
  remains so; nothing here changes that.

## Architecture note (not a bug)

The old `Mmu` aliased memory between itself and owning components (Ppu/Cartridge) via
`MappedMemoryBlock`/`MappedRegister` — `std::weak_ptr`-wrapped views with virtual `Write()`
for side effects and `.lock()`-and-throw on every access. This pass replaces that entirely:
`Cartridge`, `Ppu`, and `Input` each own their own state and expose `Read(Address)`/
`Write(Address, Reg8)`, and `Mmu::Read`/`Write` (`gbcore/src/mmu.cpp`) special-case address
ranges and delegate via plain non-owning pointers set through `MapCartridge`/`MapPpu`/
`MapInput` — the same pattern already used for `Timer`. Every component is now constructible
and testable standalone, without a full `Mmu`/`GbEmulator` wired up (see the `test_*.cpp`
files under `gbcore/tests/src/`).
