#include "Player.h"

namespace Pong
{
    Player::Player(SDL_Window *window, SDL_Renderer *renderer) : window_(window), renderer_(renderer)
    {
        SetRect();
    }

    void Player::Draw()
    {
        SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer_, &rect_);
    }

    void Player::OnWindowResize()
    {
        SetRect();
    }

    void Player::SetRect()
    {
        int window_width, window_height;
        SDL_GetWindowSize(window_, &window_width, &window_height);

        constexpr int scale_width = 100, scale_height = 5;
        rect_.h = window_height / scale_height;
        rect_.w = window_width / scale_width;
        rect_.x = window_width / 7 - rect_.w;       // TODO: fix magic number
        rect_.y = window_height * 2 / scale_height; // TODO: fix magic number
    }
} // namespace Pong
