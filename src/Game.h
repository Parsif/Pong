#pragma once
#include <iostream>
#include <memory>

#include "SDL2/SDL.h"

#include "Field.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "Ball.h"
#include "Collider.h"

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
        std::unique_ptr<Player> player1_;
        std::unique_ptr<Player> player2_;
        std::unique_ptr<Ball> ball_;
        std::unique_ptr<Collider> collider_;


        bool is_running_ = false;

    private:
        void Update();
        void Render();
        void Initialize();
        void Shutdown() const;
        void HandleInput();
    

    public:
        Game() noexcept;
        void Run();
    };

} // namespace Pong