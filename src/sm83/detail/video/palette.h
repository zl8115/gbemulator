#include "gb_colour.h"

#include <array>

namespace detail {

class Palette
{
public:
    Palette():
        m_colours({GbColour::White, GbColour::LightGrey, GbColour::DarkGrey, GbColour::Black})
    {}

    Palette(GbColour c0, GbColour c1, GbColour c2, GbColour c3):
        m_colours({c0, c1, c2, c3})
    {}

    const GbColour& operator[] (unsigned short index) const
    {
        return m_colours[index];
    }

private:
    std::array<GbColour, 4> m_colours;
};

} // namespace detail
