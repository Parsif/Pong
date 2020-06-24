#pragma once

#include "SDL2/SDL.h"

namespace Pong
{
    class Player
    {
    public:
        void Draw();
        void OnWindowResize();

    protected:
        Player(SDL_Window *window, SDL_Renderer *renderer);
        SDL_Rect rect_;
        SDL_Window *window_;
        SDL_Renderer *renderer_;

        virtual void Move() = 0;
        void InitPosSize();
    };

} // namespace Pong
