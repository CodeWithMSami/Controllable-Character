#include "Input/GamepadInput.hpp"

void GamepadInput::handleEvent(const SDL_Event& event)
{
    if (event.type == SDL_EVENT_GAMEPAD_ADDED && !gamepad)
    {
        gamepad = SDL_OpenGamepad(event.gdevice.which);

        if (!gamepad)
        {
            SDL_Log("Gamepad opening failed: %s", SDL_GetError());
        }
    }
    
    if (event.type == SDL_EVENT_GAMEPAD_REMOVED && SDL_GetGamepadID(gamepad) == event.gdevice.which)
    {
        shutdown();
    }
}


void GamepadInput::beginFrame()
{
    previous = current;

    current.fill(false);

    if (!gamepad)
        return;
    
    for (int i{}; i<SDL_GAMEPAD_BUTTON_COUNT; i++)
    {
        current[i] = SDL_GetGamepadButton(gamepad, static_cast<SDL_GamepadButton>(i));
    }
}