#pragma once

#include "SDL2/SDL.h"

namespace Pong
{
    class Player
    {
    public:
        enum MoveSpeed
        {
            UP = -20,
            DOWN = 20,
            STAY = 0
        };
        void Draw();
        void OnWindowResize();
        virtual void Move(MoveSpeed move_speed) = 0;

    protected:
        Player(SDL_Window *window, SDL_Renderer *renderer);
        void InitPosSize();

    protected:
        SDL_Rect rect_;
        SDL_Window *window_;
        SDL_Renderer *renderer_;
    };

} // namespace Pong
