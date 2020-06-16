#include <iostream>

#include "Game.h"

int main(int argc, char *argv[])
{
    try
    {
        Pong::Game game;
        game.Run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}