#include "sdl_helpers.h"

#include <irenderer.h>
#include <SDL3/SDL.h>
#include <memory>

class AssetRenderer: public IRenderer
{
public:
    AssetRenderer(std::size_t height, std::size_t width);
    ~AssetRenderer() override;

    AssetRenderer(AssetRenderer&&) noexcept = delete;
    AssetRenderer& operator=(AssetRenderer&&) noexcept = delete;
    AssetRenderer(const AssetRenderer&) = delete;
    AssetRenderer& operator=(const AssetRenderer&) = delete;

    void Step() override {} // Do Nothing
    void RescaleWindow(const FrameBuffer& buffer);
    void Render(const FrameBuffer& buffer) override;

private:
    const std::string m_titleName;
    std::size_t m_height;
    std::size_t m_width;
    std::size_t m_scaledHeight;
    std::size_t m_scaledWidth;
    std::unique_ptr<SDL_Window, SDLWindowDestroyer> m_pWindow;
    std::unique_ptr<SDL_Renderer, SDLRendererDestroyer> m_pRenderer;
    std::unique_ptr<SDL_Texture, SDLTextureDestroyer> m_pTexture;
};
