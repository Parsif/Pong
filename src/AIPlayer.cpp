#include "AIPlayer.h"

namespace Pong
{
    AIPlayer::AIPlayer(SDL_Window *window, SDL_Renderer *renderer) : Player(window, renderer)
    {
        SetRect();
    }

    void AIPlayer::MoveDown()
    {
    }

    void AIPlayer::MoveUp()
    {
    }

    void AIPlayer::OnWindowResize()
    {
        SetRect();
    }

    void AIPlayer::SetRect()
    {
        int window_width, window_height;
        SDL_GetWindowSize(window_, &window_width, &window_height);

        constexpr int scale_width = 100, scale_height = 5;
        rect_.h = window_height / scale_height;
        rect_.w = window_width / scale_width;
        rect_.x = window_width - window_width * 0.1 - rect_.w;       // TODO: fix magic number
        rect_.y = window_height * 2 / scale_height; // TODO: fix magic number
    }
} // namespace Pong
