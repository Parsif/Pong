#pragma once
#include <iostream>
#include <memory>

#include "SDL2/SDL.h"

#include "SDL_Vars.h"
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
        SDL_Vars sdl_vars_;
        Field field_;
        HumanPlayer player1_;
        AIPlayer player2_;
        Ball ball_;
        Collider collider_;

        bool is_running_ = false;

    private:
        void Update();
        void Render();
        void Reset();
        void Initialize();
        void Shutdown() const;
        void HandleInput();
    

    public:
        Game() noexcept;
        void Run();
    };

} // namespace Pong