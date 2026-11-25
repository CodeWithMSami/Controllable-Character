#include "Input/GamepadInput.hpp"

GamepadInput::~GamepadInput()
{
    shutdown();
}

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

bool GamepadInput::isDown(SDL_GamepadButton button) const
{
    return current[button];
}

bool GamepadInput::wasDown(SDL_GamepadButton button) const
{
    return previous[button];
}

bool GamepadInput::isPressed(SDL_GamepadButton button) const
{
    return current[button] && !previous[button];
}

bool GamepadInput::isReleased(SDL_GamepadButton button) const
{
    return !current[button] && previous[button];
}

bool GamepadInput::isConnected() const
{
    return gamepad != nullptr;
}

float GamepadInput::getLeftX() const
{
    if(!gamepad)
        return 0.0f;

    Sint16 value = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_LEFTX);

    return value < 0 
        ? static_cast<float>(value) / 32768.0f
        : static_cast<float>(value) / 32767.0f;
}

float GamepadInput::getLeftY() const
{
    if (!gamepad)
        return 0.0f;

    Sint16 value = SDL_GetGamepadAxis(gamepad, SDL_GAMEPAD_AXIS_LEFTY);

    return value < 0
        ? static_cast<float>(value) / 32768.0f
        : static_cast<float>(value) / 32767.0f;
}

void GamepadInput::shutdown()
{
    if (gamepad)
    {
        SDL_CloseGamepad(gamepad);
        gamepad = nullptr;
    }

    current.fill(false);
    previous.fill(false);
}