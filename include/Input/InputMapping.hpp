#pragma once

#include <SDL3/SDL.h>
#include <vector>

#include "Input/InputAction.hpp"

enum class InputDevice
{
    Keyboard,
    Mouse,
    Gamepad
};

struct InputBinding
{
    InputAction action;
    InputDevice device;
    int code;
};

class InputMapping
{
private:
    std::vector<InputBinding> bindings;

public:
    void addKeyboard(InputAction action, SDL_Scancode key);
    void addMouse(InputAction action, Uint8 button);
    void addGamepad(InputAction action, SDL_GamepadButton button);

    const std::vector<InputBinding>& getBindngs() const;
};