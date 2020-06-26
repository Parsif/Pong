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
        void OnWindowResize();

    protected:
        Player(SDL_Window *window, SDL_Renderer *renderer);

    protected:
        SDL_Rect rect_;
        SDL_Window *window_;
        SDL_Renderer *renderer_;

        const int SPEED_ = 20;
        const int scale_width_ = 100, scale_height_ = 5;
        float y_ratio, x_ratio; // TODO: try to fix this
    };

} // namespace Pong
