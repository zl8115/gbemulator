#pragma once

#include "input_buttons.h"

#include <memory>

namespace detail {
class InputImpl;
} // namespace detail

class Mmu;

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
