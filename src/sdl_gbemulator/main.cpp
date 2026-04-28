#include "sdl_gameboy.h"

#include <detail/impl_helper.h>
#include <detail/cpu/cpu_impl.h>
#include "detail/cpu/registers.h"
#include "detail/logger.h"

int main(int argc, char* argv[])
{
    SdlGb::Gameboy gameboy;
    gameboy.LoadRom("/home/zerongl/cpu_instrs.gb");
    // gameboy.LoadRom("/home/zerongl/bgbtest.gb");
    const detail::CpuImpl& cpu = detail::ImplHelper::ExtractImpl(gameboy.m_soc.m_cpu);
    const detail::Registers& reg = cpu.GetRegister();

    while(true)
    {
        gameboy.Step();
        if (gameboy.ShouldExit())
        {
            break;
        }
    }
    return 0;
}
