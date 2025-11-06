#pragma once

#include <memory>

namespace detail {
class InputImpl;
} // namespace detail

class Mmu;

enum class GbButton: uint8_t
{
    Up,
    Down,
    Left,
    Right,
    A,
    B,
    Select,
    Start,
};

class Input {
public:
    Input(Mmu& mmu);
    ~Input();

    Input(Input&&) noexcept;
    Input& operator=(Input&&) noexcept;

    Input(const Input&) = delete;
    Input& operator=(const Input&) = delete;

    void ButtonPressed(GbButton button);
    void ButtonReleased(GbButton button);
    void Step();

private:
    std::unique_ptr<detail::InputImpl> m_pImpl;
};
