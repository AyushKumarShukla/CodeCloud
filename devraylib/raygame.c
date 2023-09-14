#include<raylib.h>
int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib Window");

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}

