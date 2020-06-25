#include "Field.h"
#include "Logger.h"

#include <iostream>
namespace Pong
{

    Field::Field(SDL_Window *window, SDL_Renderer *renderer) : window_(window), renderer_(renderer)
    {
        OnWindowResize(); // fix this call
    }

    void Field::Draw()
    {
        DrawBackground();
        DrawSepLine();
    }

    void Field::DrawBackground()
    {
        SDL_SetRenderDrawColor(renderer_, 24, 24, 24, 255);
        SDL_RenderClear(renderer_);
    }

    void Field::DrawSepLine()
    {
        SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer_, &separotor_line_rect_);
    }

    void Field::OnWindowResize()
    {
        constexpr int scale_width = 100;
        int window_width, window_height;
        SDL_GetWindowSize(window_, &window_width, &window_height);

        separotor_line_rect_.h = window_height;
        separotor_line_rect_.w = window_width / scale_width;
        separotor_line_rect_.x = window_width / 2 - separotor_line_rect_.w;
        separotor_line_rect_.y = 0;
    }

} // namespace Pong
