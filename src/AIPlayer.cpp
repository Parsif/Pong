#include "AIPlayer.h"

#include <random>
#include <iostream>

namespace Pong
{
    AIPlayer::AIPlayer(SDL_Window *window, SDL_Renderer *renderer) : Player(window, renderer, false)
    {
    }

    void AIPlayer::Move(const Ball &ball)
    {
        int window_width, window_height;
        SDL_GetWindowSize(window_, &window_width, &window_height);

        auto ball_rect = ball.GetRect();
        int ball_y_center = ball_rect.y + ball_rect.h / 2;
        int player_y_center = rect_.y + rect_.h / 2;

        if (ball_y_center > player_y_center && ball.velocity_y > 0 && rect_.y + rect_.h <= window_height)
        {
            rect_.y += VELOCITY_;
        }
        else if (ball_y_center < player_y_center && ball.velocity_y < 0 && rect_.y > 0)
        {
            rect_.y -= VELOCITY_;
        }
    }

} // namespace Pong
