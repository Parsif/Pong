#pragma once
#include "Player.h"

namespace Pong
{
    class HumanPlayer : public Player
    {
    public:
        HumanPlayer(SDL_Window *window, SDL_Renderer *renderer);
        void MoveUp() override;
        void MoveDown() override;
    };
} // namespace Pong
