#include "asset_renderer.h"
#include "sdl_helpers.h"

#include <irenderer.h>
#include <frame_buffer.h>

#include <format>

AssetRenderer::AssetRenderer(std::size_t height, std::size_t width):
    m_height(height),
    m_width(width),
    m_scaledHeight(height * PIXEL_SIZE),
    m_scaledWidth(width * PIXEL_SIZE),
    m_pWindow(nullptr),
    m_pRenderer(nullptr),
    m_pTexture(nullptr)
{
    SdlHelpers::InitSdl();
    m_pWindow.reset(SDL_CreateWindow(
        m_titleName.c_str(),
        m_scaledWidth,
        m_scaledHeight,
        SDL_WINDOW_OPENGL));
    if (!m_pWindow)
    {
        throw std::runtime_error(std::format("Failed to create window: {}", SDL_GetError()));
    }

    m_pRenderer.reset(SDL_CreateRenderer(m_pWindow.get(), nullptr));
    if (!m_pRenderer)
    {
        throw std::runtime_error(std::format("Failed to create renderer: {}", SDL_GetError()));
    }

    m_pTexture.reset(SDL_CreateTexture(
        m_pRenderer.get(),
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        m_scaledWidth,
        m_scaledHeight
    ));
    if (!m_pTexture)
    {
        throw std::runtime_error(std::format("Failed to create texture: {}", SDL_GetError()));
    }
}

AssetRenderer::~AssetRenderer()
{
    SdlHelpers::QuitSdl();
}

void AssetRenderer::RescaleWindow(const FrameBuffer& buffer)
{
    if (buffer.GetWidth() == m_width && buffer.GetHeight() == m_height)
        return;

    m_width = buffer.GetWidth();
    m_scaledWidth = m_width * PIXEL_SIZE;
    m_height = buffer.GetHeight();
    m_scaledHeight = m_height * PIXEL_SIZE;

    SDL_SetWindowSize(m_pWindow.get(), m_scaledWidth, m_scaledHeight);
    SDL_SyncWindow(m_pWindow.get());
}

void AssetRenderer::Render(const FrameBuffer& buffer)
{
    RescaleWindow(buffer);
    SDL_RenderClear(m_pRenderer.get());

    void* pPixels;
    int pitch;
    SDL_LockTexture(m_pTexture.get(), nullptr, &pPixels, &pitch);

    uint32_t* pixels = static_cast<uint32_t*>(pPixels);
    SetPixels(pixels, buffer);
    SDL_UnlockTexture(m_pTexture.get());

    SDL_RenderTexture(m_pRenderer.get(), m_pTexture.get(), nullptr, nullptr);
    SDL_RenderPresent(m_pRenderer.get());
}
