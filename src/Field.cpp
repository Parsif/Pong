#include "Field.h"
#include "Logger.h"

#include <iostream>
namespace Pong
{

    Field::Field(SDL_Window *window, SDL_Renderer *renderer) : window_(window), renderer_(renderer)
    {
    }

    Field::~Field()
    {
        SDL_DestroyRenderer(renderer_);
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
        SDL_Rect separotor_line_rect;
        SDL_GetWindowSize(window_, &separotor_line_rect.w, &separotor_line_rect.h);
        separotor_line_rect.x = separotor_line_rect.w / 2 - (separotor_line_rect.w / 40);
        separotor_line_rect.y = 0;
        separotor_line_rect.w /= 40;
        SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer_, &separotor_line_rect);
    }

} // namespace Pong
