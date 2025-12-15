#pragma once

#include "gb_colour.h"

#include <vector>

class FrameBuffer {
public:
    FrameBuffer(unsigned int width, unsigned int height);

    void SetPixel(unsigned int x, unsigned int y, GbColour colour);
    GbColour GetPixel(unsigned int x, unsigned int y) const;

    void Reset();
    unsigned int GetWidth() const { return m_width; }
    unsigned int GetHeight() const { return m_height; }
    const std::vector<GbColour>& GetBuffer() const;

private:
    std::size_t GetPixelIndex(unsigned int x, unsigned int y) const;

    unsigned int m_width;
    unsigned int m_height;
    std::vector<GbColour> m_buffer;
};
