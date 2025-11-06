#include "input.h"
#include "mmu.h"
#include "detail/input_impl.h"

Input::Input(Mmu& mmu):
    m_pImpl(std::make_unique<detail::InputImpl>(mmu))
{}

Input::~Input() = default;

void Input::ButtonPressed(GbButton button)
{
    m_pImpl->ButtonPressed(button);
}

void Input::ButtonReleased(GbButton button)
{
    m_pImpl->ButtonReleased(button);
}

void Input::Step()
{
    m_pImpl->WriteInput();
}
