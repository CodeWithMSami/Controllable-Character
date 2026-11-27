#pragma once

#include <SDL3/SDL.h>

#include "Input/InputManager.hpp"

class Application
{
public:
    bool init();

    void processEvent();
    void update();
    void processRender();

    void shutdown();

    int run();

private:
    bool running = false;

    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;

    InputManager input;

    SDL_FRect player{
        450.0f,
        350.0f,
        50.0f,
        50.0f};

    float speed{250.0f};

    Uint64 currentTime{0};
    Uint64 previousTime{0};

    float deltaTime{0.0f};
};