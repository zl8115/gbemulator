#include "sdl_gameboy.h"
#include "irenderer.h"
#include "frame_buffer.h"

namespace SdlGb {

Gameboy::Gameboy():
    m_soc(),
    m_renderer()
{
    m_renderer.RegisterGbInput(&m_soc.GetInput());
    m_soc.RegisterRenderer(&m_renderer);
}

void Gameboy::Step()
{
    m_soc.Step();
    // FrameBuffer fb(GAMEBOY_WIDTH, GAMEBOY_HEIGHT);
    // m_renderer.Render(fb);
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
