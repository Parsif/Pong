#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

namespace Pong
{

    class FileManager
    {
    private:
    public:
        FileManager();
        static SDL_Texture *LoadPngImg(const char *image);
    };

} // namespace Pong