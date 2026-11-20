#pragma once

#include <SDL3/SDL.h>
#include <array>

class GamepadInput
{
    private:
        std::array<bool, SDL_GAMEPAD_BUTTON_COUNT> current{};
        std::array<bool, SDL_GAMEPAD_BUTTON_COUNT> previous{};

        SDL_Gamepad* gamepad = nullptr;

    public:
        ~GamepadInput();

        void beginFrame();
        void handleEvent(const SDL_Event& event);

        bool isDown(SDL_GamepadButton button) const;
        bool wasDown(SDL_GamepadButton button) const;

        bool isPressed(SDL_GamepadButton button) const;
        bool isReleased(SDL_GamepadButton button) const;

        bool isConnected() const;

        float getLeftX() const;
        float getLeftY() const;

        void shutdown() const;
};