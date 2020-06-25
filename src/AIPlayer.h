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
        void OnWindowResize() override;

    private:
        void MakeDecision();
        void SetRect() override;
    };

} // namespace Pong
