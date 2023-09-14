#include "raylib.h"

int main(void)
{
	const int screenwidth=1200;
 	const int screenheight=800;
	
	InitWindow(screenwidth,screenheight,"HELLO WORLD WINDOW");
	SetTargetFPS(60);

	while(!WindowShouldClose()) //main game loop
	{
		BeginDrawing(); 
			ClearBackground(BLACK);
			DrawText("HARE KRISHNA",screenwidth/2,screenwidth/2,20,WHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
