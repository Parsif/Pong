#pragma once
#include "SDL2/SDL.h"

namespace Pong
{
    class Field
    {
    private:
        SDL_Window *window_;
        SDL_Renderer *renderer_;
        SDL_Rect separotor_line_rect_;

    private:
        void DrawSepLine();
        void DrawBackground();

    public:
        Field(SDL_Window *window, SDL_Renderer *renderer);
        void OnWindowResize();
        void Draw();
    };
} // namespace Pong
