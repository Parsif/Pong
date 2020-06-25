#pragma once
#include "Player.h"

namespace Pong
{
    class AIPlayer : public Player
    {
    public:
        AIPlayer(SDL_Window *window, SDL_Renderer *renderer);

    private:
        void MakeDecision();
        void Move(MoveSpeed move_speed) override;
    }

} // namespace Pong
