#include <format>

#include "mmu.h"
#include "detail/impl_helper.h"
#include "detail/memory/mapped_memory_block.h"
#include "detail/memory/mmu_impl.h"

template<std::size_t N>
struct std::formatter<std::span<const uint8_t, N>>: std::formatter<std::string>
{
    auto format(const std::span<const uint8_t, N>& obj, std::format_context& ctx) const
    {
        constexpr std::size_t NO_OF_DATA_PER_LINE = 16;
        constexpr std::size_t noOfLines = N / NO_OF_DATA_PER_LINE;
        constexpr std::size_t lastLineData = N % NO_OF_DATA_PER_LINE;
        constexpr std::size_t strSizePerData = N * 5;
        constexpr std::size_t prefixSize = (noOfLines + lastLineData) * 9;

        std::string temp;
        temp.reserve((noOfLines * NO_OF_DATA_PER_LINE + lastLineData) * strSizePerData);

        std::size_t ii = 0;
        std::size_t offset = 0;
        for (ii = 0; ii < noOfLines; ++ii)
        {
            offset = ii * NO_OF_DATA_PER_LINE;
            std::format_to(std::back_inserter(temp), "0x{:04X} | ", offset);
            for (std::size_t jj = 0; jj < NO_OF_DATA_PER_LINE; ++jj)
            {
                std::format_to(std::back_inserter(temp), " 0x{:02X}", obj[offset + jj]);
            }
            temp.push_back('\n');
        }

        if constexpr (lastLineData != 0)
        {
            std::format_to(std::back_inserter(temp), "0x{:04X} | ", offset + NO_OF_DATA_PER_LINE);
            offset = N - lastLineData;
        }

        for (std::size_t ii = 0; ii < lastLineData; ++ii)
        {
            std::format_to(std::back_inserter(temp), " 0x{:02X}", obj[offset + ii]);
        }

        return formatter<string>::format(std::format(
            "{}",
            temp
        ), ctx);
    }
};

template<std::size_t N>
struct std::formatter<std::span<uint8_t, N>>: std::formatter<std::string>
{
    auto format(const std::span<uint8_t, N>& obj, std::format_context& ctx) const
    {
        const std::span<const uint8_t,N> span(obj);
        return formatter<string>::format(std::format(
            "{}",
            span
        ), ctx);
    }
};

template<std::size_t N>
struct std::formatter<detail::MemoryBlock<N>>: std::formatter<std::string>
{
    template<class FormatContext>
    typename FormatContext::iterator format(const detail::MemoryBlock<N>& obj, FormatContext& ctx) const
    {
        const std::span<const uint8_t,N> span(obj);
        return formatter<string>::format(std::format(
            "{}",
            span
        ), ctx);
    }
};

template<std::size_t N>
struct std::formatter<detail::MappedMemoryBlock<N>>: std::formatter<std::string>
{
    auto format(const detail::MappedMemoryBlock<N>& obj, std::format_context& ctx) const
    {
        return formatter<string>::format(std::format(
            "{}",
            obj.GetSpan()
        ), ctx);
    }
};

template<std::size_t N>
struct std::formatter<detail::WeakMappedMemoryBlock<N>>: std::formatter<std::string>
{
    auto format(const detail::WeakMappedMemoryBlock<N>& obj, std::format_context& ctx) const
    {
        return formatter<string>::format(std::format(
            "{}",
            *obj.get()
        ), ctx);
    }
};

template<>
struct std::formatter<detail::MmuImpl>: std::formatter<std::string>
{
    auto format(const detail::MmuImpl& obj, std::format_context& ctx) const
    {
        return formatter<string>::format(std::format(
            "MmuImpl:\n------\n"
            "RomBankA      (0x0000 - 0x3FFF):\n{}------\n"
            "RomBankB      (0x4000 - 0x7FFF):\n{}------\n"
            "VideoRam      (0x8000 - 0x9FFF):\n{}------\n"
            "ExternalRam   (0xA000 - 0xBFFF):\n{}------\n"
            "WorkingRam    (0xC000 - 0xDFFF):\n{}------\n"
            "EchoRam       (0xE000 - 0xFDFF):\n{}------\n"
            "ObjectAttribs (0xFE00 - 0xFE9F):\n{}------\n"
            "Unusable      (0xFEA0 - 0xFEFF):\n{}------\n"
            "IORegisters   (0xFF00 - 0xFF7F):\n{}------\n"
            "HighRam + IE  (0xFF80 - 0xFFFE + 0xFFFF):\n{}\n",
            obj.GetRomBankA(),
            obj.GetRomBankB(),
            obj.GetVideoRam(),
            obj.GetExternalRam(),
            obj.GetWorkingRam(),
            obj.GetEchoRam(),
            obj.GetObjectAttributeMemory(),
            obj.GetNotUsable(),
            obj.GetInput(),
            obj.GetHighRam()
        ), ctx);
    }
};

template<>
struct std::formatter<Mmu>: std::formatter<std::string> 
{
    auto format(const Mmu& obj, std::format_context& ctx) const
    {
        return formatter<string>::format(
            std::format("{}", detail::ImplHelper::ExtractImpl(obj)) , ctx);
    }
};
