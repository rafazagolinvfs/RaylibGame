#include <raylib.h>
#include "Level.h"

#define TILE_SIZE 10
#define SCREEN_X 450   
#define SCREEN_Y 700

int main()
{
    InitWindow(SCREEN_X, SCREEN_Y, "raylib [core] example - basic window");

    SetTargetFPS(60);              

    Level* level = new Level();


    // Main game loop
    while (!WindowShouldClose())
    {
        //Update world
        if (level)
        {
            level->Update();
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();      
    }
    CloseWindow();  
    level->~Level();
    delete level;

    return 0;
}