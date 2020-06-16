#include "Game.h"
#include <exception>

#include "Logger.h"

namespace Pong
{
    Game::Game() noexcept
    {
        Initialize();
    }

    void Game::Run()
    {
        while (is_running_)
        {
            HandleInput();
            Render();
        }
        Shutdown();
    }

    void Game::Render()
    {
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

    void Game::HandleInput()
    {
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                is_running_ = false;
                break;

            default:
                break;
            }
        }
    }

    void Game::Initialize()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            Logger::LogoutError("SDL init error");
        }
        window = SDL_CreateWindow(window_params.title, window_params.x_pos, window_params.y_pos, window_params.width, window_params.height, 0);

        if (window == nullptr)
        {
            Logger::LogoutError("window creation error");
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer == nullptr)
        {
            Logger::LogoutError("Renderer creation error");
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        is_running_ = true;
    }

    void Game::Shutdown() const
    {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }
} // namespace Pong