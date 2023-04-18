#include <raylib.h>
#include "Level.h"
#include "Utils.h"
#include "UserInterface.h"

int main()
{
    InitWindow(SCREEN_X, SCREEN_Y, WINDOW_TITLE);
    
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
        ClearBackground(BLACK);
        EndDrawing();      
    }
    CloseWindow();  
    level->~Level();
    delete level;

    return 0;
}