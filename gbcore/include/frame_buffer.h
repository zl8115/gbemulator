#pragma once

#include "gb_colour.h"

#include <vector>

namespace gb {

class FrameBuffer
{
public:
    FrameBuffer(unsigned int width, unsigned int height);

    void SetPixel(unsigned int x, unsigned int y, GbColour colour);
    [[nodiscard]] GbColour GetPixel(unsigned int x, unsigned int y) const;

    void Reset();
    [[nodiscard]] unsigned int GetWidth() const { return m_width; }
    [[nodiscard]] unsigned int GetHeight() const { return m_height; }
    [[nodiscard]] const std::vector<GbColour>& GetBuffer() const;

private:
    [[nodiscard]] std::size_t GetPixelIndex(unsigned int x, unsigned int y) const;

    unsigned int m_width;
    unsigned int m_height;
    std::vector<GbColour> m_buffer;
};

} // namespace gb
