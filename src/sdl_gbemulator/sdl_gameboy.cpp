#include "sdl_gameboy.h"
#include "irenderer.h"

namespace SdlGb {

Gameboy::Gameboy():
    m_soc(),
    m_renderer()
    // ,m_assetRenderer(128 * TILE_WIDTH_PX, 3 * TILE_HEIGHT_PX)
{
    m_renderer.RegisterGbInput(&m_soc.GetInput());
    m_soc.RegisterRenderer(&m_renderer);
    // m_soc.RegisterAssetRenderer(&m_assetRenderer);
}

void Gameboy::Step()
{
    m_renderer.Step();
    m_soc.Step();
    // FrameBuffer buffer(GAMEBOY_WIDTH, GAMEBOY_HEIGHT);
    // for (int ii = 0; ii < GAMEBOY_HEIGHT - 1; ++ii)
    // {
    //     buffer.SetPixel(ii, ii, Colour::DarkGrey);
    //     buffer.SetPixel(ii, ii, Colour::DarkGrey);
    //     buffer.SetPixel(ii + 1, ii + 1, Colour::LightGrey);
    //     buffer.SetPixel(ii + 1, ii + 1, Colour::LightGrey);
    // }
    // m_renderer.Render(buffer);
}

void Gameboy::LoadRom(std::string_view romPath)
{
    m_soc.LoadRomFromFile(romPath);
}

bool Gameboy::ShouldExit()
{
    return m_renderer.ShouldExit();
}

} // namespace SdlGb
