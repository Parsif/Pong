#include "Logger.h"

#include <exception>
#include <iostream>

#include "SDL2/SDL.h"

namespace Pong
{
    void Logger::LogoutError(const char *error_message)
    {
        std::cerr << error_message << '\n';
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, SDL_GetError());
        throw std::exception();
    }
} // namespace Pong