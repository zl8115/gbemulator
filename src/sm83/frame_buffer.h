#pragma once

#include <vector>

enum class Colour {
    White,
    LightGrey,
    DarkGrey,
    Black,
};

class FrameBuffer {
public:
    FrameBuffer(unsigned int width, unsigned int height);

    void SetPixel(unsigned int x, unsigned int y, Colour color);
    Colour GetPixel(unsigned int x, unsigned int y) const;

    void Reset();
    unsigned int GetWidth() const;
    unsigned int GetHeight() const;
    const std::vector<Colour>& GetBuffer() const;

private:
    std::size_t GetPixelIndex(unsigned int x, unsigned int y) const;

    unsigned int m_width;
    unsigned int m_height;
    std::vector<Colour> m_buffer;
};
