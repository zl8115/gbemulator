#pragma once

#include <SDL3/SDL.h>
#include <irenderer.h>

enum class GbColour;
class FrameBuffer;

namespace SdlHelpers {

void InitSdl();
void QuitSdl();

} // namespace SdlHelpers

constexpr unsigned int PIXEL_SIZE = 1;

uint32_t GetARGBColour(GbColour colour);
unsigned int GetPixelIndex(unsigned int x, unsigned int y, const unsigned int FrameWidth);
void SetPixels(uint32_t* pPixels, const FrameBuffer& buffer);

struct SDLRendererDestroyer
{
    void operator()(SDL_Renderer* ptr)
    {
        SDL_DestroyRenderer(ptr);
    }
};

struct SDLTextureDestroyer
{
    void operator()(SDL_Texture* ptr)
    {
        SDL_DestroyTexture(ptr);
    }
};

struct SDLWindowDestroyer
{
    void operator()(SDL_Window* ptr)
    {
        SDL_DestroyWindow(ptr);
    }
};
