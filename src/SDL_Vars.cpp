#include "SDL_Vars.h"
#include "Logger.h"

namespace Pong
{
    SDL_Vars::SDL_Vars() noexcept
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            Logger::LogoutError("SDL init error");
        }
        window = SDL_CreateWindow(window_params_.title, window_params_.x_pos, window_params_.y_pos,
                                   window_params_.min_width, window_params_.min_height, SDL_WINDOW_RESIZABLE);
        if (window == nullptr)
        {
            Logger::LogoutError("Window creation error");
        }

        SDL_SetWindowMinimumSize(window, window_params_.min_width, window_params_.min_height);

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer == nullptr)
        {
            Logger::LogoutError("Fail to init renderer");
        }
    }

    SDL_Vars::~SDL_Vars()
    {
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
} // namespace Pong
