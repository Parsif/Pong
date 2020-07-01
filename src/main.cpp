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

//TODO:
// 1: Fix ball onResize
// 2: Draw and move ball;
// 3: Add collision feature
// 4: Fix field class