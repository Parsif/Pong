#pragma once
#include <iostream>
#include <memory>

#include "SDL2/SDL.h"

#include "Field.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "Ball.h"

namespace Pong
{

    class Game
    {
    private:
        struct WindowParams
        {
            const char *title = "Pong";
            int min_width = 480;
            int min_height = 480;
            int x_pos = 200;
            int y_pos = 200;
        };

        SDL_Window *window_;
        SDL_Surface *surface_;
        WindowParams window_params_;
        SDL_Renderer *renderer_;
        std::unique_ptr<Field> field_;
        std::unique_ptr<HumanPlayer> human_player_;
        std::unique_ptr<AIPlayer> ai_player_;
        std::unique_ptr<Ball> ball_;


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