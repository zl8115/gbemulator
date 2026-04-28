#pragma once

#include "sdl_helpers.h"

#include <irenderer.h>
#include <SDL3/SDL.h>
#include <memory>

class Input;

class SdlRenderer: public IRenderer
{
public:
    SdlRenderer();
    ~SdlRenderer() override;

    SdlRenderer(SdlRenderer&&) noexcept = delete;
    SdlRenderer& operator=(SdlRenderer&&) noexcept = delete;
    SdlRenderer(const SdlRenderer&) = delete;
    SdlRenderer& operator=(const SdlRenderer&) = delete;

    void Init();
    void RegisterGbInput(Input* pGbInput);
    void Render(const FrameBuffer& buffer) override;
    void Step() override;
    void ProcessEvents();
    bool ShouldExit();

private:
    bool m_shouldExit;
    Input* m_pGbInput;
    std::unique_ptr<SDL_Window, SDLWindowDestroyer> m_pWindow;
    std::unique_ptr<SDL_Renderer, SDLRendererDestroyer> m_pRenderer;
    std::unique_ptr<SDL_Texture, SDLTextureDestroyer> m_pTexture;
};
