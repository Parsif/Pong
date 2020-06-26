#include "AIPlayer.h"

namespace Pong
{
    AIPlayer::AIPlayer(SDL_Window *window, SDL_Renderer *renderer) : Player(window, renderer)
    {
        int window_width, window_height;
        SDL_GetWindowSize(window_, &window_width, &window_height);

        rect_.h = window_height / scale_height_;
        rect_.w = window_width / scale_width_;
        rect_.x = window_width - window_width * 0.1 - rect_.w; // TODO: fix magic number
        rect_.y = window_height * 2 / scale_height_;

        x_ratio = rect_.x / static_cast<float>(window_width);
        y_ratio = rect_.y / static_cast<float>(window_height);
    }

    void AIPlayer::MoveDown()
    {
    }

    void AIPlayer::MoveUp()
    {
    }

    

} // namespace Pong
