#pragma once
#include "Player.h"

namespace Pong
{
    class HumanPlayer : public Player
    {
    public:
        HumanPlayer(SDL_Window *window, SDL_Renderer *renderer);

    private:
        void Move() override;
    };
} // namespace Pong
