#include "Input/InputMapping.hpp"

void InputMapping::addKeyboard(InputAction action, SDL_Scancode key)
{
    bindings.push_back({
        action,
        InputDevice::Keyboard,
        static_cast<int>(key)
    });
}

void InputMapping::addMouse(InputAction action, Uint8 button)
{
    bindings.push_back({
        action,
        InputDevice::Mouse,
        static_cast<int>(button)
    });
}

void InputMapping::addGamepad(InputAction action, SDL_GamepadButton button)
{
    bindings.push_back({
        action,
        InputDevice::Gamepad,
        static_cast<int>(button)
    });
}

const std::vector<InputBinding>& InputMapping::getBindings() const
{
    return bindings;
}