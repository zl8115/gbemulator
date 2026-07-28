# gbemulator
A toy GameBoy (SM83) Emulator project to explore hardware architecture of the original Game Boy (DMG-01).

Also serves as a toy project for various other technology like SDL3 and CPM.cmake.

## Getting Started

### Prerequisites
- A C++23 compliant compiler - currently targeting Clang 16+
- CMake 3.25+

### Build
The project uses CMake presets:

```bash
cmake --preset release-gcc-linux
cmake --build --preset release-gcc-linux
```

Available presets: `debug-gcc-linux`, `release-gcc-linux`, `debug-msvc-windows`, `release-msvc-windows`.

### Test
Run the test suite via CTest:

```bash
ctest --preset release-gcc-linux --output-on-failure
```

Or run the test binary directly (it's a Catch2 executable, so standard Catch2 CLI flags apply, e.g. `--list-tests` or a tag like `"[timer]"`):

```bash
./build/release-gcc-linux/gbcore/tests/gbtest
```

## References
- [Pan Docs](https://gbdev.io/pandocs/): The comprehensive Game Boy technical reference.
