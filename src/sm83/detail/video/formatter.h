#include <format>

#include "frame_buffer.h"

template<>
struct std::formatter<FrameBuffer>: std::formatter<std::string>
{
    auto format(const FrameBuffer& obj, std::format_context& ctx) const
    {
        std::string temp;
        temp.reserve(obj.GetWidth() * obj.GetHeight());

        std::size_t offset;
        for (int y = 0; y < obj.GetHeight(); ++y)
        {
            std::format_to(std::back_inserter(temp), "{:04} | ", y);
            offset = y * obj.GetWidth();
            for (int x = 0; x < obj.GetWidth(); ++x)
            {
                std::format_to(std::back_inserter(temp), " {}", static_cast<uint8_t>(obj.GetPixel(x, y)));
            }
            temp.push_back('\n');
        }

        return formatter<string>::format(std::format(
            "{}",
            temp
        ), ctx);
    }
};
