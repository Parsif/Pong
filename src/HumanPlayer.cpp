#include "HumanPlayer.h"

#include <iostream>

namespace Pong
{
    HumanPlayer::HumanPlayer(SDL_Window *window, SDL_Renderer *renderer) : Player(window, renderer)
    {
    }

    void HumanPlayer::Move(MoveSpeed move_speed)
    {
        int window_width, window_height;
        SDL_GetWindowSize(window_, &window_width, &window_height);
        if (rect_.y + rect_.h + move_speed  >= window_height && move_speed == MoveSpeed::DOWN ||
            rect_.y + move_speed <= 0 && move_speed == MoveSpeed::UP)
        {
            return;
        }

        
        rect_.y += move_speed;
    }
} // namespace Pong
