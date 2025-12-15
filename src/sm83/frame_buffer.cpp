#include "frame_buffer.h"

#include <algorithm>

FrameBuffer::FrameBuffer(unsigned int width, unsigned int height):
    m_width(width),
    m_height(height),
    m_buffer(width * height, GbColour::White)
{}

void FrameBuffer::SetPixel(unsigned int x, unsigned int y, GbColour color)
{
    auto index = GetPixelIndex(x, y);
    m_buffer.at(index) = color;
}

GbColour FrameBuffer::GetPixel(unsigned int x, unsigned int y) const
{
    auto index = GetPixelIndex(x, y);
    return m_buffer.at(index);
}

void FrameBuffer::Reset()
{
    std::fill(m_buffer.begin(), m_buffer.end(), GbColour::Black);
}

std::size_t FrameBuffer::GetPixelIndex(unsigned int x, unsigned int y) const
{
    return (y * m_width) + x;
}
