#pragma once

#include "SDL2/SDL.h"

namespace Pong
{
    class Player
    {
    public:
        void Draw();
        void OnWindowResize();
        SDL_Rect GetRect() const;

    protected:
        Player(SDL_Window *window, SDL_Renderer *renderer, bool located_left);

    protected:
        SDL_Rect rect_;
        SDL_Window *window_;
        SDL_Renderer *renderer_;

        const int VELOCITY_ = 20;
        const int scale_width_ = 100, scale_height_ = 5; // TODO: try to fix this
        float y_ratio_, x_ratio_; // TODO: try to fix this
    };

} // namespace Pong 
