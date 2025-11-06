#include "sdl_gameboy.h"

int main(int argc, char* argv[])
{
    SdlGb::Gameboy gameboy;
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
