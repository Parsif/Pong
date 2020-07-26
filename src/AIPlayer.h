#pragma once
#include "Player.h"
#include "Ball.h"

namespace Pong
{
    class AIPlayer : public Player
    {
    public:
        AIPlayer(SDL_Window *window, SDL_Renderer *renderer);
        void Move(const Ball &ball);
    };

} // namespace Pong
