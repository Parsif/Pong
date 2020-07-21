#pragma once

#include "SDL2/SDL.h"
#include <memory>

namespace Pong
{
    class Ball
    {
    private:
        SDL_Rect rect_;
        SDL_Window *window_;
        SDL_Renderer *renderer_;

        const int scale_size_ = 50; // TODO: try to fix this
        float x_ratio_, y_ratio_;   // TODO: try to fix this

    public:
        Ball(SDL_Window *window, SDL_Renderer *renderer);
        void OnWindowResize();
        void Draw();
        void Move();
        SDL_Rect GetRect() const;

    public:
        int velocity_x_ = 0; // should be scaled on risize
        int velocity_y_ = 0;
    };
} // namespace Pong
