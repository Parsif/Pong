#include "Game.h"
#include <exception>

#include "Logger.h"

namespace Pong
{
    Game::Game() noexcept : field_(sdl_vars_.window, sdl_vars_.renderer), player1_(sdl_vars_.window, sdl_vars_.renderer),
                            player2_(sdl_vars_.window, sdl_vars_.renderer), ball_(sdl_vars_.window, sdl_vars_.renderer),
                            collider_(sdl_vars_.window), is_running_(true)
    {
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
                collider_.Collide(player1_, player2_, ball_);
                ball_.Move();
                player2_.Move(ball_);
                if(collider_.IsGoalScored(ball_, player1_, player2_))
                {
                    Reset();
                }
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
        field_.Draw();
        player1_.Draw();
        player2_.Draw();
        ball_.Draw();
    }

    void Game::Update()
    {
        SDL_RenderPresent(sdl_vars_.renderer);
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
                    field_.OnWindowResize();
                    player1_.OnWindowResize();
                    player2_.OnWindowResize();
                    ball_.OnWindowResize();
                }
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.scancode == SDL_SCANCODE_UP)
                {
                    player1_.MoveUp();
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
                {
                    player1_.MoveDown();
                }
                break;

            default:
                break;
            }
        }
    }

    void Game::Reset()
    {
        player1_.Reset();
        player2_.Reset();
        ball_.Reset();
    }

    void Game::Shutdown() const
    {
    }
} // namespace Pong