#pragma once

#include "SDL2/SDL.h"

namespace Pong
{
    class Player
    {
    private:
    public:
        virtual void Draw() = 0;
    };
} // namespace Pong
