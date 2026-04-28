#include <detail/impl_helper.h>
#include <detail/logger.h>
#include <detail/cpu/cpu_impl.h>
#include <soc.h>

int main(int argc, char* argv[])
{
    // Instantiate the Gameboy System on Chip (SoC)
    Soc soc;
    soc.LoadRomFromFile("/home/zerongl/cpu_instrs.gb");

    // Extract detail implementations for conditional check
    const detail::CpuImpl& cpu = detail::ImplHelper::ExtractImpl(soc.m_cpu);
    const detail::Registers& cpuReg = cpu.GetRegister();

    // Run until the bootrom is done
    // while(cpuReg.pc <= 256)
    while(true)
    {
        // if (cpuReg.pc == 0x100)
        // {
        //     // Set log directory
        //     GbStateLogger::SetLogDir("/home/zerongl/src/gbemulator-worktree/sm83logs/");
        // }
        soc.Step();
    }
    return 0;
}
