#include "Input/KeyboardInput.hpp"

void KeyboardInput::beginFrame()
{
    previous = current;
    current.fill(false);

    int count;

    const bool* state = SDL_GetKeyboardState(&count);

    for (int i = 0; i < count && i < SDL_SCANCODE_COUNT; i++)
    {
        current[i] = state[i];
    }
}

bool KeyboardInput::isDown(SDL_Scancode key) const
{
    return current[key];
}

bool KeyboardInput::wasDown(SDL_Scancode key) const
{
    return previous[key];
}

bool KeyboardInput::isPressed(SDL_Scancode key) const
{
    return current[key] && !previous[key];
}

bool KeyboardInput::isReleased(SDL_Scancode key) const
{
    return !current[key] && previous[key];
}