#include "sdl_gameboy.h"

int main(int argc, char* argv[])
{
    SdlGb::Gameboy gameboy;
    gameboy.LoadRom("/home/zerongl/cpu_instrs.gb");
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
