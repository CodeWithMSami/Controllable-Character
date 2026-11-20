#pragma once

#include <SDL3/SDL.h>
#include <array>

class MouseInput
{
    private:
        std::array<bool, 6> current{};
        std::array<bool, 6> previous{};

        float x;
        float y;
    public:

        void beginFrame();

        bool isDown(Uint8 button) const;
        bool wasDown(Uint8 button) const;

        bool isPressed(Uint8 button) const;
        bool isReleased(Uint8 button) const;

        float getX() const;
        float getY() const;
};
