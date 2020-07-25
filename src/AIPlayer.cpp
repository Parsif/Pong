#include "AIPlayer.h"

#include <random>

namespace Pong
{
    AIPlayer::AIPlayer(SDL_Window *window, SDL_Renderer *renderer) : Player(window, renderer, false)
    {
    }

    void AIPlayer::Move(SDL_Rect ball_rect)
    {
        int ball_y_center = ball_rect.y + ball_rect.h / 2;
        int player_y_center = rect_.y + rect_.h / 2;
    }

} // namespace Pong
