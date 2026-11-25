#include "Input/InputManager.hpp"

InputManager::InputManager()
{
    mapping.addKeyboard(InputAction::MoveUp, SDL_SCANCODE_UP);
    mapping.addKeyboard(InputAction::MoveDown, SDL_SCANCODE_DOWN);
    mapping.addKeyboard(InputAction::MoveLeft, SDL_SCANCODE_LEFT);
    mapping.addKeyboard(InputAction::MoveRight, SDL_SCANCODE_RIGHT);

    mapping.addKeyboard(InputAction::MoveUp, SDL_SCANCODE_W);
    mapping.addKeyboard(InputAction::MoveDown, SDL_SCANCODE_S);
    mapping.addKeyboard(InputAction::MoveLeft, SDL_SCANCODE_A);
    mapping.addKeyboard(InputAction::MoveRight, SDL_SCANCODE_D);

    mapping.addKeyboard(InputAction::Jump, SDL_SCANCODE_SPACE);
    mapping.addKeyboard(InputAction::Fire, SDL_SCANCODE_LCTRL);

    mapping.addMouse(InputAction::Fire, SDL_BUTTON_LEFT);

    mapping.addGamepad(InputAction::MoveUp, SDL_GAMEPAD_BUTTON_DPAD_UP);
    mapping.addGamepad(InputAction::MoveDown, SDL_GAMEPAD_BUTTON_DPAD_DOWN);
    mapping.addGamepad(InputAction::MoveLeft, SDL_GAMEPAD_BUTTON_DPAD_LEFT);
    mapping.addGamepad(InputAction::MoveRight, SDL_GAMEPAD_BUTTON_DPAD_RIGHT);

    mapping.addGamepad(InputAction::Jump, SDL_GAMEPAD_BUTTON_SOUTH);
    mapping.addGamepad(InputAction::Fire, SDL_GAMEPAD_BUTTON_LEFT_SHOULDER);
}

void InputManager::beginFrame()
{
    keyboard.beginFrame();
    mouse.beginFrame();
    gamepad.beginFrame();
}

void InputManager::handleEvent(const SDL_Event& event)
{
    gamepad.handleEvent(event);
}

bool InputManager::BindingDown(const InputBinding& binding, bool previous) const
{
    switch (binding.device)
    {
    case InputDevice::Keyboard:
        {
            SDL_Scancode key = static_cast<SDL_Scancode>(binding.code);

            return previous
                ? keyboard.wasDown(key)
                : keyboard.isDown(key);
        }
    case InputDevice::Mouse:
        {
            Uint8 button = static_cast<Uint8>(binding.code);

            return previous
                ? mouse.wasDown(button)
                : mouse.isDown(button);
        }
    case InputDevice::Gamepad:
        {
            SDL_GamepadButton button = static_cast<SDL_GamepadButton>(binding.code);

            return previous
                ? gamepad.wasDown(button)
                : gamepad.isDown(button);
        }
    }

    return false;
}

ButtonState InputManager::getActionState(InputAction action) const
{
    bool currentDown{};
    bool previousDown{};

    for (const InputBinding& binding: mapping.getBindngs())
    {
        if (binding.action != action)
            continue;

        currentDown |= BindingDown(binding, false);
        previousDown |= BindingDown(binding, true);
    }

    return {
        .down = currentDown,
        .pressed = currentDown && !previousDown,
        .released = !currentDown && previousDown
    };
}

bool InputManager::isActionDown(InputAction action) const
{
    return getActionState(action).down;
}

bool InputManager::isActionPressed(InputAction action) const
{
    return getActionState(action).pressed;
}

bool InputManager::isActionReleased(InputAction action) const
{
    return getActionState(action).released;
}

bool InputManager::isGamepadConnected() const
{
    return gamepad.isConnected();
}

float InputManager::getAxis(InputAction positive, InputAction negative) const
{
    return static_cast<float>(isActionDown(positive)) - static_cast<float>(isActionDown(negative));
}

float InputManager::getLeftStickX() const
{
    return gamepad.getLeftX();
}

float InputManager::getLeftStickY() const
{
    return gamepad.getLeftY();
}

float InputManager::getMouseX() const
{
    return mouse.getX();
}

void InputManager::shutdown()
{
    gamepad.shutdown();
}

InputManager::~InputManager()
{
    this->shutdown();
}