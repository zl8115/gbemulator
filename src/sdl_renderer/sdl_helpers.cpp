#include "sdl_helpers.h"

#include <frame_buffer.h>

#include <format>

static bool s_SDLInitialized = false;
static int s_SDLCreated = 0;

namespace SdlHelpers {

void InitSdl()
{
    ++s_SDLCreated;
    if (!s_SDLInitialized)
    {
        s_SDLInitialized = SDL_Init(SDL_INIT_VIDEO);
    }
    if (!s_SDLInitialized)
    {
        throw std::runtime_error(std::format("Failed to initialise SDL: {}", SDL_GetError()));
    }
}

void QuitSdl()
{
    --s_SDLCreated;
    if (s_SDLCreated == 0)
    {
        SDL_Quit();
    }
}

} // namespace SdlHelpers

uint32_t GetARGBColour(GbColour colour)
{
    switch (colour)
    {
        case GbColour::White:
            return 0xFFFFFFFF;
        case GbColour::LightGrey:
            return 0xFFAAAAAA;
        case GbColour::DarkGrey:
            return 0xFF555555;
        case GbColour::Black:
            return 0xFF000000;
    }
    throw std::runtime_error(std::format("Unable to translate colour for GbColour {}", static_cast<unsigned short>(colour)));
};

unsigned int GetPixelIndex(unsigned int x, unsigned int y, const unsigned int FrameWidth)
{
    unsigned int heightOffset = FrameWidth * PIXEL_SIZE * y;
    unsigned int widthOffset = PIXEL_SIZE * x;
    return heightOffset + widthOffset;
}

namespace
{

void SetRenderPixel(uint32_t* pPixels, unsigned int x,  unsigned int y, uint32_t pixel, const unsigned int FrameWidth)
{
    const unsigned int PixelsPerLine = FrameWidth * PIXEL_SIZE;
    unsigned int heightOffset = PixelsPerLine * PIXEL_SIZE * y;
    unsigned int widthOffset = PIXEL_SIZE * x;
    for (int h = 0; h < PIXEL_SIZE; ++h)
    {
        unsigned int heightIndex = heightOffset + (h * PixelsPerLine);
        for (int w = 0; w < PIXEL_SIZE; ++w)
        {
            unsigned int pixelIndex = heightIndex + widthOffset + w;
            pPixels[pixelIndex] = pixel;
        }
    }
}

} // namespace

void SetPixels(uint32_t* pPixels, const FrameBuffer& buffer)
{
    for (unsigned int y = 0; y < buffer.GetHeight(); y++)
    {
        for (unsigned int x = 0; x < buffer.GetWidth(); x++)
        {
            GbColour colour = buffer.GetPixel(x, y);
            uint32_t argbColour = GetARGBColour(colour);
            ::SetRenderPixel(pPixels, x, y, argbColour, buffer.GetWidth());
        }
    }
}
