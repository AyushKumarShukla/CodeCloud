#include "raylib.h"

int main(void)
{
	const int screenwidth=550;
 	const int screenheight=500;
	float delta;	
	InitWindow(screenwidth,screenheight,"MOVE BALL");
	SetTargetFPS(60);
	Vector2 ballpos= {(float)screenwidth/2 , (float)screenheight/2};
	while(!WindowShouldClose()) //main game loop
	{
		delta=2.0f;
		if(IsKeyDown(KEY_RIGHT))
			ballpos.x += delta;
		if(IsKeyDown(KEY_LEFT))
			ballpos.x -= delta;
		if(IsKeyDown(KEY_UP))
			ballpos.y -= delta;
		if(IsKeyDown(KEY_DOWN))
			ballpos.y += delta;
		BeginDrawing(); 
			ClearBackground(BLACK);
			DrawText("Move The Ball With Arrow Keys",10,10,10,WHITE);
			DrawCircleV(ballpos,10,RED);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
