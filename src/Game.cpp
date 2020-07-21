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
        constexpr uint32_t FPS = 60;
        constexpr uint32_t FRAME_DURATION = 1000 / FPS;
        uint32_t current_frame_time = SDL_GetTicks();
        uint32_t next_frame_time = 0;
        

        while (is_running_)
        {
            if (current_frame_time >= next_frame_time)
            {
                collider_->Collide(player1_, player2_, ball_);
                ball_->Move();
                HandleInput();
                Render();
                Update();
                next_frame_time = current_frame_time + FRAME_DURATION;
            }
            else
            {
                current_frame_time = SDL_GetTicks();
            }
        }
        Shutdown();
    }

    void Game::Render()
    {
        field_->Draw();
        player1_->Draw();
        player2_->Draw();
        ball_->Draw();
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
                    player1_->OnWindowResize();
                    player2_->OnWindowResize();
                    ball_->OnWindowResize();
                }
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.scancode == SDL_SCANCODE_UP)
                {
                    player1_->MoveUp();
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
                {
                    player1_->MoveDown();
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
        window_ = SDL_CreateWindow(window_params_.title, window_params_.x_pos, window_params_.y_pos,
                                   window_params_.min_width, window_params_.min_height, SDL_WINDOW_RESIZABLE);
        if (window_ == nullptr)
        {
            Logger::LogoutError("window creation error");
        }

        SDL_SetWindowMinimumSize(window_, window_params_.min_width, window_params_.min_height);

        renderer_ = SDL_CreateRenderer(window_, -1, 0);
        if (renderer_ == nullptr)
        {
            Logger::LogoutError("Fail to init renderer");
        }

        field_ = std::make_unique<Field>(window_, renderer_);
        player1_ = std::make_unique<HumanPlayer>(window_, renderer_);
        player2_ = std::make_unique<AIPlayer>(window_, renderer_);
        ball_ = std::make_unique<Ball>(window_, renderer_);
        collider_ = std::make_unique<Collider>(window_);

        is_running_ = true;
    }

    void Game::Shutdown() const
    {
        SDL_DestroyWindow(window_);
        SDL_Quit();
    }
} // namespace Pong