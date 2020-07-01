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

        int velocity_x_ = 0;
        int velocity_y_ = 0;
        const int scale_height_ = 20; // TODO: try to fix this
        float x_ratio_, y_ratio_;     // TODO: try to fix this

    private:
        void CheckColission();
        void ApplyColission();


    public:
        Ball(SDL_Window *window, SDL_Renderer *renderer);
        void OnWindowResize();
        void Draw();
        void Move();
        auto GetRect() const;
    };
} // namespace Pong
