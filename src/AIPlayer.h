#pragma once
#include "Player.h"

namespace Pong
{
    class AIPlayer : public Player
    {
    public:
        AIPlayer(SDL_Window *window, SDL_Renderer *renderer);
        void Move(const SDL_Rect &&ball_rect);
    };

} // namespace Pong
