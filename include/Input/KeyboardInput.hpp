#pragma once

#include <SDL3/SDL.h>
#include <array>

class KeyboardInput
{
    private:
        std::array<bool, SDL_SCANCODE_COUNT> current{};
        std::array<bool, SDL_SCANCODE_COUNT> previous{};

    public:
        void beginFrame();

        bool isDown(SDL_Scancode key) const;
        bool wasDown(SDL_Scancode key) const;

        bool isPressed(SDL_Scancode key) const;
        bool isReleased(SDL_Scancode key) const;
};