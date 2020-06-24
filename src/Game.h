#pragma once
#include <iostream>
#include <memory>

#include "SDL2/SDL.h"

#include "Field.h"
#include "HumanPlayer.h"

namespace Pong
{

    class Game
    {
    private:
        struct WindowParams
        {
            const char *title = "Pong";
            int width = 480;
            int height = 480;
            int x_pos = 200;
            int y_pos = 200;
        };

        SDL_Window *window_;
        SDL_Surface *surface_;
        WindowParams window_params_;
        SDL_Renderer *renderer_;
        std::unique_ptr<Field> field_;
        std::unique_ptr<HumanPlayer> human_player_;
        bool is_running_ = false;

    public:
        Game() noexcept;
        void Run();
        void Render();
        void Initialize();
        void Shutdown() const;
        void HandleInput();
        void Update();
    };

} // namespace Pong