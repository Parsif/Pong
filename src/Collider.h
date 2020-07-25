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
        void BallPlayerColiission(std::unique_ptr<Player> &player, std::unique_ptr<Ball> &ball);


    public:
        Collider(SDL_Window *window);
        void Collide(std::unique_ptr<Player> &player1, std::unique_ptr<Player> &player2, std::unique_ptr<Ball> &ball);
        bool IsGoalScored(std::unique_ptr<Ball> &ball);
    };

} // namespace Pong