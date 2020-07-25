#pragma once

#include "SDL2/SDL.h"
#include <memory>
#include "Player.h"
#include "Ball.h"

namespace Pong
{
    class Collider
    {
    private:
        SDL_Window *window_;

    private:
        void BallPlayerColiission(const Player &player, Ball &ball);


    public:
        Collider(SDL_Window *window);
        void Collide(const Player &player1, const Player &player2, Ball &ball);
        bool IsGoalScored(const Ball &ball);
    };

} // namespace Pong