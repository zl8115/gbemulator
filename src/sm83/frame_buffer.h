#pragma once

#include <vector>

enum class Color {
    White,
    LightGray,
    DarkGray,
    Black,
};

class FrameBuffer {
public:
    FrameBuffer(unsigned int width, unsigned int height);

    void SetPixel(unsigned int x, unsigned int y, Color color);
    Color GetPixel(unsigned int x, unsigned int y) const;

    void Reset();

private:
    std::size_t GetPixelIndex(unsigned int x, unsigned int y) const;

    unsigned int m_width;
    unsigned int m_height;
    std::vector<Color> m_buffer;
};
