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
            Update();
        }
        Shutdown();
    }

    void Game::Render()
    {
        field->Draw();
    }

    void Game::Update()
    {
        SDL_RenderPresent(renderer_);
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

            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_RESIZED)
                {
                }

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
        window_ = SDL_CreateWindow(window_params.title, window_params.x_pos, window_params.y_pos,
                                   window_params.width, window_params.height, SDL_WINDOW_RESIZABLE);
        if (window_ == nullptr)
        {
            Logger::LogoutError("window creation error");
        }

        renderer_ = SDL_CreateRenderer(window_, -1, 0);
        if (renderer_ == nullptr)
        {
            Logger::LogoutError("Fail to init renderer");
        }

        field = new Field(window_, renderer_);
        is_running_ = true;
    }

    void Game::Shutdown() const
    {

        SDL_DestroyWindow(window_);
        SDL_Quit();
    }
} // namespace Pong