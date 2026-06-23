# gbemulator
A toy GameBoy (SM83) Emulator project to explore hardware architecture of the original Game Boy (DMG-01).

Also serves as a toy project for various other technology like SDL3 and CPM.cmake.

## Getting Started

### Prerequisites
- A C++23 compliant compiler - currently targeting Clang 16+
- CMake 3.25+

### Build
The project uses a standard CMake workflow:

```bash
mkdir build
cd build
cmake .. --preset release-gcc-linux
cmake . --preset release-gcc-linux
```

## References
- [Pan Docs](https://gbdev.io/pandocs/): The comprehensive Game Boy technical reference.
