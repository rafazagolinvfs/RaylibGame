#include <raylib.h>
#include "Level.h"
#include "Utils.h"
#include "UserInterface.h"

int main()
{
    InitWindow(SCREEN_X, SCREEN_Y, WINDOW_TITLE);
    InitAudioDevice(); // Initialize audio device

    Level* level = new Level();

    /*Example of loading and playing a sound*/
    /*Sound s = LoadSound("resources/sound/arcade.wav");
    PlaySound(s);*/


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