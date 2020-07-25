#pragma once

#include "SDL2/SDL.h"

namespace Pong
{
    class SDL_Vars
    {
    private:
       struct WindowParams
        {
            const char *title = "Pong";
            int min_width = 480;
            int min_height = 480;
            int x_pos = 200;
            int y_pos = 200;
        };
        WindowParams window_params_;
    public:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Vars() noexcept;
        ~SDL_Vars();
    };
} // namespace Pong
