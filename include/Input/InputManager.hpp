#pragma once

#include <SDL3/SDL.h>

#include "Input/InputAction.hpp"
#include "Input/KeyboardInput.hpp"
#include "Input/MouseInput.hpp"
#include "Input/GamepadInput.hpp"
#include "Input/InputMapping.hpp"

class InputManager
{
    private:
        KeyboardInput keyboard;
        MouseInput mouse;
        GamepadInput gamepad;

        InputMapping mapping;

        bool BindingDown(const InputBinding& binding, bool previous) const;

    public:
        InputManager();
        ~InputManager();

        void beginFrame();
        void handleEvent(const SDL_Event& event);

        ButtonState getActionState(InputAction action) const;

        bool isActionDown(InputAction action) const;
        bool isActionPressed(InputAction action) const;
        bool isActionReleased(InputAction action) const;

        bool isGamepadConnected() const;

        float getAxis(InputAction positive, InputAction negative) const;

        float getLeftStickX() const;
        float getLeftStickY() const;

        float getMouseX() const;
        float getMouseY() const;

        void shutdown();

};