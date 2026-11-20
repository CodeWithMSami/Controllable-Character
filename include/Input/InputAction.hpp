#pragma once 

enum class InputAction
{
    MoveUp,
    MoveDown,
    MoveLeft,
    MoveRight,
    Jump,
    Fire,
    Pause
};

struct ButtonState
{
    bool down = false;
    bool pressed = false;
    bool released = false;
};
