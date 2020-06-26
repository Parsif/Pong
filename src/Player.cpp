#include "Player.h"

namespace Pong
{
    Player::Player(SDL_Window *window, SDL_Renderer *renderer, bool located_left) : window_(window), renderer_(renderer)
    {
        int window_width, window_height;
        SDL_GetWindowSize(window_, &window_width, &window_height);

        rect_.h = window_height / scale_height_;
        rect_.w = window_width / scale_width_;
        rect_.y = window_height * 2 / scale_height_; // TODO: fix magic number
        if (located_left)
        {
            rect_.x = window_width - window_width * 0.9; // TODO: fix magic number
        }
        else
        {
            rect_.x = window_width - window_width * 0.1 - rect_.w; // TODO: fix magic number
        }

        x_ratio = rect_.x / static_cast<float>(window_width);
        y_ratio = rect_.y / static_cast<float>(window_height);
    }

    void Player::Draw()
    {
        SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer_, &rect_);
    }

    void Player::OnWindowResize()
    {
        int window_width, window_height;
        SDL_GetWindowSize(window_, &window_width, &window_height);

        rect_.h = window_height / scale_height_;
        rect_.w = window_width / scale_width_;

        rect_.x = window_width * x_ratio;  // TODO: fix magic number
        rect_.y = window_height * y_ratio; // TODO: fix magic number
    }

} // namespace Pong
