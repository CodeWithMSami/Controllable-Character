#include <cmath>

#include "Application/Application.hpp"

bool Application::init()
{
    SDL_SetAppMetadata(
        "Controllable Character",
        "1.0.0",
        "app.netlify.codewithmsami"
    );

    if(!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD))
    {
        SDL_Log("Init Failed: %s", SDL_GetError());
        return false;
    }

    if (!SDL_CreateWindowAndRenderer(
        "Controll Section",
        800,
        600,
        SDL_WINDOW_RESIZABLE,
        &window,
        &renderer
    ))
    {
        SDL_Log("Window & Renderer creation Failed: %s", SDL_GetError());
        SDL_Quit();
        return false;
    }

    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    previousTime = SDL_GetPerformanceCounter();

    this->running = true;

    return running;
}

void Application::processEvent()
{
    SDL_Event event{};

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT || (event.type == SDL_EVENT_KEY_DOWN && event.key.scancode == SDL_SCANCODE_ESCAPE))
        {
            this->running = false;
        }
        input.handleEvent(event);
    }
    input.beginFrame();
}

void Application::update()
{
    currentTime = SDL_GetPerformanceCounter();

    deltaTime = static_cast<float>(currentTime - previousTime) / static_cast<float>(SDL_GetPerformanceFrequency());

    previousTime = currentTime;

    deltaTime = SDL_min(deltaTime, 0.05f);

    float x = input.getAxis(InputAction::MoveRight, InputAction::MoveLeft);

    float y = input.getAxis(InputAction::MoveDown, InputAction::MoveUp);

    x += input.getLeftStickX();
    y += input.getLeftStickY();

    float length = std::sqrt(x*x + y*y);

    if (length > 1.0f)
    {
        x /= length;
        y /= length;
    }

    player.x += x * speed * deltaTime;
    player.y += y * speed * deltaTime;

    if (input.isActionPressed(InputAction::Jump))
    {
        SDL_Log("Jump!");
    }
    if (input.isActionPressed(InputAction::Fire))
    {
        SDL_Log("Fire!");
    }
}

void Application::processRender()
{
    SDL_SetRenderDrawColor(renderer, 25, 25, 35, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 50, 180, 255, 255);
    SDL_RenderFillRect(renderer, &player);

    SDL_RenderPresent(renderer);
}

void Application::shutdown()
{
    input.shutdown();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    renderer = nullptr;
    window = nullptr;

    SDL_Quit();
}

int Application::run()
{
    if (!init())
    {
        shutdown();
        return 1;
    }

    while (running)
    {
        processEvent();
        update();
        processRender();
    }

    shutdown();

    return 0;
}