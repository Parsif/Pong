#pragma once

#include "SDL2/SDL.h"

namespace Pong
{
    class Player
    {
    public:
        void Draw();
        virtual void MoveUp() = 0;
        virtual void MoveDown() = 0;
        virtual void OnWindowResize() = 0;

    protected:
        Player(SDL_Window *window, SDL_Renderer *renderer);
        virtual void SetRect() = 0;

    protected:
        SDL_Rect rect_;
        SDL_Window *window_;
        SDL_Renderer *renderer_;
        const int SPEED_ = 20;
    };

} // namespace Pong
