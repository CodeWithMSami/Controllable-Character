#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

class Application{
    public:
        bool init();

        void processEvent();
        void update();
        void processRender();

        bool shutdown();

        bool run();
    private:
        bool running = false;

        SDL_Renderer* renderer = nullptr;
        SDL_Window* window = nullptr;
};