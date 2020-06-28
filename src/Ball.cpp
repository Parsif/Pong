#include "Ball.h"

#include <iostream>

namespace Pong
{
    Ball::Ball(SDL_Window *window, SDL_Renderer *renderer) : window_(window), renderer_(renderer)
    {
        int window_width, window_height;
        SDL_GetWindowSize(window_, &window_width, &window_height);

        rect_.w = rect_.h = window_height / scale_height_;
        rect_.x = window_width / 2 - (rect_.w / 2);
        rect_.y = window_height / 2 - (rect_.h / 2);

        x_ratio_ = rect_.x / static_cast<float>(window_width);
        y_ratio_ = rect_.y / static_cast<float>(window_height);
    }

    void Ball::OnWindowResize()
    {
        int window_width, window_height;
        SDL_GetWindowSize(window_, &window_width, &window_height);

        rect_.w = rect_.h = window_height / scale_height_; // this is a problem

        rect_.x = window_width * x_ratio_;  // TODO: fix magic number
        rect_.y = window_height * y_ratio_; // TODO: fix magic number
        std::cout << window_height / scale_height_ << '\n';
    }

    void Ball::Draw()
    {
        SDL_SetRenderDrawColor(renderer_, 155, 0, 155, 255);
        SDL_RenderFillRect(renderer_, &rect_);
    }
} // namespace Pong
