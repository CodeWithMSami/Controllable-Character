#include "Input/MouseInput.hpp"

void MouseInput::beginFrame()
{
    previous = current;

    current.fill(false);

    SDL_MouseButtonFlags state = SDL_GetMouseState(&x, &y);

    for (Uint8 i = SDL_BUTTON_LEFT; i <= SDL_BUTTON_X2; ++i)
    {
        current[i] = (state & SDL_BUTTON_MASK(i)) != 0;
    }
}

bool MouseInput::isDown(Uint8 button) const
{
    return button < current.size() && current[button];
}

bool MouseInput::wasDown(Uint8 button) const
{
    return button < previous.size() && previous[button];
}

bool MouseInput::isPressed(Uint8 button) const
{
    return isDown(button) && !previous[button];
}

bool MouseInput::isReleased(Uint8 button) const
{
    return !isDown(button) && previous[button];
}

float MouseInput::getX() const
{
    return x;
}

float MouseInput::getY() const
{
    return y;
}