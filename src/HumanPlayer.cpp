#include "HumanPlayer.h"

#include <iostream>

namespace Pong
{
    HumanPlayer::HumanPlayer(SDL_Window *window, SDL_Renderer *renderer) : Player(window, renderer, true)
    {
    }

    void HumanPlayer::MoveUp()
    {
        int window_width, window_height;
        SDL_GetWindowSize(window_, &window_width, &window_height);
        if (rect_.y - SPEED_ >= 0)
        {
            rect_.y -= SPEED_;
        }

        y_ratio_ = rect_.y / static_cast<float>(window_height);
    }

    void HumanPlayer::MoveDown()
    {
        int window_width, window_height;
        SDL_GetWindowSize(window_, &window_width, &window_height);
        if (rect_.y + rect_.h + SPEED_ <= window_height)
        {
            rect_.y += SPEED_;
        }

        y_ratio_ = rect_.y / static_cast<float>(window_height);
    }

} // namespace Pong
