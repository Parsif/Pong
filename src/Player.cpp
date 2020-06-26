#include "Player.h"

namespace Pong
{
    Player::Player(SDL_Window *window, SDL_Renderer *renderer) : window_(window), renderer_(renderer)
    {
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
