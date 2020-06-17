#pragma once
#include <iostream>

#include "SDL2/SDL.h"

#include "Field.h"

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
        SDL_Window *window_;
        SDL_Surface *surface;
        WindowParams window_params;
        SDL_Renderer *renderer_;
        Field *field;
        bool is_running_ = false;

    public:
        Game() noexcept;
        void Run();
        void Render();
        void Initialize();
        void Shutdown() const;
        void HandleInput();
        void Update();
    };

} // namespace Pong