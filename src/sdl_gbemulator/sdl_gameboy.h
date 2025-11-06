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
    bool ShouldExit();

private:
    Soc m_soc;
    SdlRenderer m_renderer;
};

} // namespace SdlGb
