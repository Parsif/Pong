#pragma once
#include <iostream>

#include "SDL2/SDL.h"

namespace Pong
{

    struct WindowParams
    {
        const char *title = "Pong";
        int width = 480;
        int height = 480;
        int x_pos = 200;
        int y_pos = 200;
    };

    class Game
    {
    private:
        SDL_Window *window;
        SDL_Surface *surface;
        SDL_Renderer *renderer;
        WindowParams window_params;
        bool is_running_ = false;

    public:
        Game() noexcept;
        void Run();
        void Render();
        void Initialize();
        void Shutdown() const;
        void HandleInput();
    };

} // namespace Pong