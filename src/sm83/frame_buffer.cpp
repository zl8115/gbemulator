#include "frame_buffer.h"

#include <algorithm>

FrameBuffer::FrameBuffer(unsigned int width, unsigned int height)
    : m_buffer(width * height, Color::White)
{}

void FrameBuffer::SetPixel(unsigned int x, unsigned int y, Color color)
{
    auto index = GetPixelIndex(x, y);
    m_buffer.at(index) = color;
}

Color FrameBuffer::GetPixel(unsigned int x, unsigned int y) const
{
    auto index = GetPixelIndex(x, y);
    return m_buffer.at(index);
}

void FrameBuffer::Reset()
{
    std::fill(m_buffer.begin(), m_buffer.end(), Color::White);
}

std::size_t FrameBuffer::GetPixelIndex(unsigned int x, unsigned int y) const
{
    return (y * m_width) + x;
}
