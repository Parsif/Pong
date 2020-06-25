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
        field_->Draw();
        human_player_->Draw();
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
                    field_->OnWindowResize();
                    human_player_->OnWindowResize();
                }
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.scancode == SDL_SCANCODE_UP)
                {
                    human_player_->Move(HumanPlayer::MoveSpeed::UP);
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
                {
                    human_player_->Move(HumanPlayer::MoveSpeed::DOWN);
                }
                break;

            // case SDL_KEYUP:
            //     human_player_->Move(HumanPlayer::MoveSpeed::STAY);
            //     break;

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
        window_ = SDL_CreateWindow(window_params_.title, window_params_.x_pos, window_params_.y_pos,
                                   window_params_.width, window_params_.height, SDL_WINDOW_RESIZABLE);
        if (window_ == nullptr)
        {
            Logger::LogoutError("window creation error");
        }

        renderer_ = SDL_CreateRenderer(window_, -1, 0);
        if (renderer_ == nullptr)
        {
            Logger::LogoutError("Fail to init renderer");
        }

        field_ = std::make_unique<Field>(window_, renderer_);
        human_player_ = std::make_unique<HumanPlayer>(window_, renderer_);
        is_running_ = true;
    }

    void Game::Shutdown() const
    {
        SDL_DestroyWindow(window_);
        SDL_Quit();
    }
} // namespace Pong