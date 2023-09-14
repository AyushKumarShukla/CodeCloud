#include "raylib.h"

int main(void)
{
	int screenwidth,screenheight;
	screenwidth=1000;
	screenheight=800;
	InitWindow(screenwidth,screenheight,"Move Ball");
	SetTargetFPS(60);
	Vector2 ballpos={-100.0f,-100.0f};
	Color ballcolor=BLACK;
	int radius=50;
	while(!WindowShouldClose())
	{
		ballpos=GetMousePosition();
			if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) ballcolor=RED;
			else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) ballcolor=GREEN;
		BeginDrawing();
			ClearBackground(WHITE);
			DrawText("Move Ball With Mouse, Click To Change Color",10,10,10,BLUE);
			DrawCircleV(ballpos,radius,ballcolor);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
