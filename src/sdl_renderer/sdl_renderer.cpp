#include "sdl_renderer.h"

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <irenderer.h>
#include <input.h>
#include <frame_buffer.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_oldnames.h>

#include <cstdint>
#include <format>

static bool s_SDLInitialized = false;
static int s_SDLCreated = 0;

constexpr unsigned int PIXEL_SIZE = 2;
constexpr unsigned int RENDER_WIDTH = GAMEBOY_WIDTH * PIXEL_SIZE;
constexpr unsigned int RENDER_HEIGHT = GAMEBOY_HEIGHT * PIXEL_SIZE;

namespace {

uint32_t GetARGBColour(Colour colour)
{
    switch (colour)
    {
        case Colour::White:
            return 0xFFFFFFFF;
        case Colour::LightGrey:
            return 0xFFAAAAAA;
        case Colour::DarkGrey:
            return 0xFF555555;
        case Colour::Black:
            return 0xFF000000;
    }
    throw std::runtime_error(std::format("Unable to translate colour for Colour {}", static_cast<unsigned short>(colour)));
};

void SetRenderPixel(uint32_t* pPixels, uint x, uint y, uint32_t pixel)
{
    unsigned int heightOffset = RENDER_WIDTH * PIXEL_SIZE * y;
    unsigned int widthOffset = PIXEL_SIZE * x;
    for (int h = 0; h < PIXEL_SIZE; ++h)
    {
        unsigned int heightIndex = heightOffset + (h * RENDER_WIDTH);
        for (int w = 0; w < PIXEL_SIZE; ++w)
        {
            unsigned int pixelIndex = heightIndex + widthOffset + w;
            pPixels[pixelIndex] = pixel;
        }
    }
}

void SetRenderPixels(uint32_t* pPixels, const FrameBuffer& buffer)
{
    for (unsigned int y = 0; y < GAMEBOY_HEIGHT; y++)
    {
        for (unsigned int x = 0; x < GAMEBOY_WIDTH; x++)
        {
            Colour colour = buffer.GetPixel(x, y);
            uint32_t argbColour = ::GetARGBColour(colour);
            ::SetRenderPixel(pPixels, x, y, argbColour);
        }
    }
}

} // namespace

SdlRenderer::SdlRenderer():
    m_shouldExit(false),
    m_pGbInput(nullptr),
    m_pWindow(nullptr),
    m_pRenderer(nullptr),
    m_pTexture(nullptr)
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

    m_pWindow.reset(SDL_CreateWindow(
        "gbemu",
        RENDER_WIDTH,
        RENDER_HEIGHT,
        SDL_WINDOW_OPENGL));
    if (!m_pWindow)
    {
        throw std::runtime_error(std::format("Failed to create window: {}", SDL_GetError()));
    }

    // m_pRenderer.reset(SDL_CreateRenderer(m_pWindow.get(), -1, SDL_RENDERER_VSYNC_DISABLED));
    m_pRenderer.reset(SDL_CreateRenderer(m_pWindow.get(), nullptr));
    if (!m_pRenderer)
    {
        throw std::runtime_error(std::format("Failed to create renderer: {}", SDL_GetError()));
    }

    m_pTexture.reset(SDL_CreateTexture(
        m_pRenderer.get(),
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        RENDER_WIDTH,
        RENDER_HEIGHT
    ));
    if (!m_pTexture)
    {
        throw std::runtime_error(std::format("Failed to create texture: {}", SDL_GetError()));
    }
}

SdlRenderer::~SdlRenderer()
{
    if (--s_SDLCreated <= 0)
    {
        SDL_Quit();
    }
}

void SdlRenderer::Render(const FrameBuffer& buffer) 
{
    ProcessEvents();
    if (m_pGbInput)
    {
        m_pGbInput->Step();
    }

    SDL_RenderClear(m_pRenderer.get());

    void* pPixels;
    int pitch;
    SDL_LockTexture(m_pTexture.get(), nullptr, &pPixels, &pitch);

    uint32_t* pixels = static_cast<uint32_t*>(pPixels);
    ::SetRenderPixels(pixels, buffer);
    SDL_UnlockTexture(m_pTexture.get());

    SDL_RenderTexture(m_pRenderer.get(), m_pTexture.get(), nullptr, nullptr);
    SDL_RenderPresent(m_pRenderer.get());
}

void SdlRenderer::Step()
{
}

std::optional<GbButton> GetGbButton(int keyCode)
{
    switch (keyCode)
    {
        case SDLK_UP: return GbButton::Up;
        case SDLK_DOWN: return GbButton::Down;
        case SDLK_LEFT: return GbButton::Left;
        case SDLK_RIGHT: return GbButton::Right;
        case SDLK_X: return GbButton::A;
        case SDLK_Z: return GbButton::B;
        case SDLK_BACKSPACE: return GbButton::Select;
        case SDLK_RETURN: return GbButton::Start;
        default: return std::nullopt;
    }
}

void SdlRenderer::ProcessEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_EVENT_KEY_DOWN:
            {
                if (event.key.repeat == true)
                {
                    break;
                }
                if (auto button = GetGbButton(event.key.key); m_pGbInput && button)
                {
                    m_pGbInput->ButtonPressed(button.value());
                }
                break;
            }
            case SDL_EVENT_KEY_UP:
            {
                if (event.key.repeat == true)
                {
                    break;
                }
                if (auto button = GetGbButton(event.key.key); m_pGbInput && button)
                {
                    m_pGbInput->ButtonPressed(button.value());
                }
                break;
            }
            case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
            case SDL_EVENT_QUIT:
            {
                m_shouldExit = true;
                break;
            }
        }
    }
}

void SdlRenderer::RegisterGbInput(Input* pGbInput)
{
    m_pGbInput = pGbInput;
}

bool SdlRenderer::ShouldExit()
{
    return m_shouldExit;
}
