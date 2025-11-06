#pragma once

#include <soc.h>
#include <input.h>
#include <sdl_renderer.h>

namespace SdlGb {

class Gameboy
{
public:
    Gameboy();
    void Step();
    void LoadRom(std::string_view romPath);
    bool ShouldExit();

private:
    Soc m_soc;
    SdlRenderer m_renderer;
};

} // namespace SdlGb
