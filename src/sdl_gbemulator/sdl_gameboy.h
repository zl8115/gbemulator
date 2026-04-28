#pragma once

#include <soc.h>
#include <input.h>
#include <sdl_renderer.h>
#include <asset_renderer.h>

namespace SdlGb {

class Gameboy
{
public:
    Gameboy();
    void Step();
    void LoadRom(std::string_view romPath);
    bool ShouldExit();

    Soc m_soc;

private:
    SdlRenderer m_renderer;
    // AssetRenderer m_assetRenderer;
};

} // namespace SdlGb
