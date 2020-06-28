#pragma once

#include "SDL2/SDL.h"

namespace Pong
{
    class Ball
    {
    private:
        SDL_Rect rect_;
        SDL_Window *window_;
        SDL_Renderer *renderer_;

        const int SPEED_ = 20;
        const int scale_height_ = 20; // TODO: try to fix this
        float x_ratio_, y_ratio_;           // TODO: try to fix this

    public:
        Ball(SDL_Window *window, SDL_Renderer *renderer);
        void OnWindowResize();
        void Draw();
    };
} // namespace Pong
