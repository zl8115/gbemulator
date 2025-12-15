#pragma once

inline constexpr unsigned int GAMEBOY_WIDTH = 160;
inline constexpr unsigned int GAMEBOY_HEIGHT = 144;
inline constexpr unsigned int BG_MAP_SIZE = 256;

inline constexpr unsigned int TILES_PER_LINE = 32;
inline constexpr unsigned int TILE_HEIGHT_PX = 8;
inline constexpr unsigned int TILE_WIDTH_PX = 8;

inline constexpr unsigned int TILES_PER_BLOCK = 64;
inline constexpr unsigned int BLOCKS = 6;
inline constexpr unsigned int BYTES_PER_TILE = 16;

class FrameBuffer;

class IRenderer
{
public:
    virtual ~IRenderer() = default;
    virtual void Step() {};
    virtual void Render(const FrameBuffer& buffer) = 0;
};
