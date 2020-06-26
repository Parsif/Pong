#include "HumanPlayer.h"

#include <iostream>

namespace Pong
{
    HumanPlayer::HumanPlayer(SDL_Window *window, SDL_Renderer *renderer) : Player(window, renderer)
    {
        int window_width, window_height;
        SDL_GetWindowSize(window_, &window_width, &window_height);

        rect_.h = window_height / scale_height_;
        rect_.w = window_width / scale_width_;
        rect_.x = window_width - window_width * 0.9; // TODO: fix magic number
        rect_.y = window_height * 2 / scale_height_;  // TODO: fix magic number

        x_ratio = rect_.x / static_cast<float>(window_width);
        y_ratio = rect_.y / static_cast<float>(window_height);
    }

    void HumanPlayer::MoveUp()
    {
        int window_width, window_height;
        SDL_GetWindowSize(window_, &window_width, &window_height);
        if (rect_.y - SPEED_ >= 0)
        {
            rect_.y -= SPEED_;
        }

        y_ratio = rect_.y / static_cast<float>(window_height);
    }

    void HumanPlayer::MoveDown()
    {
        int window_width, window_height;
        SDL_GetWindowSize(window_, &window_width, &window_height);
        if (rect_.y + rect_.h + SPEED_ <= window_height)
        {
            rect_.y += SPEED_;
        }

        y_ratio = rect_.y / static_cast<float>(window_height);
    }


   
} // namespace Pong
