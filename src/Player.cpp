#include "Player.h"

namespace Pong
{
    Player::Player(SDL_Window *window, SDL_Renderer *renderer) : window_(window), renderer_(renderer)
    {
    }

    void Player::Draw()
    {
        SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer_, &rect_);
    }


} // namespace Pong
