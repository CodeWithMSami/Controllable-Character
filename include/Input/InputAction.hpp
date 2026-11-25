#pragma once 

enum class InputAction
{
    MoveUp,
    MoveDown,
    MoveLeft,
    MoveRight,
    Jump,
    Fire
};

struct ButtonState
{
    bool down = false;
    bool pressed = false;
    bool released = false;
};
