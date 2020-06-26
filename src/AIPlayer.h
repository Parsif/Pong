#pragma once
#include "Player.h"

namespace Pong
{
    class AIPlayer : public Player
    {
    public:
        AIPlayer(SDL_Window *window, SDL_Renderer *renderer);
        void MoveUp() override;
        void MoveDown() override;

    private:
        void MakeDecision();
    };

} // namespace Pong
