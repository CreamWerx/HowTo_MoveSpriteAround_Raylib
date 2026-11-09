#include <iostream>
#include <raylib.h>
#include "GameTypes.hpp"
#include "Game.hpp"

//Types::Point Game::CenterScreenP = { 0, 0 };


int main()
{
    Game game;

    InitWindow(game.screenWidth, game.screenHeight, "New Gamw");
    SetTargetFPS(30);
    game.Setup();


    while (!WindowShouldClose())
    {
        if (!game.paused && !game.gameOver) 
        { 
            game.Update(); 
            game.ProcessEvents(); 
        }

        BeginDrawing();

        ClearBackground(DARKBLUE);

        if (!game.gameOver)
        {
            game.DrawMain();
        }
        else
        {
            game.DrawGameOver();
        }

        EndDrawing();
    }
    CloseWindow();
}

