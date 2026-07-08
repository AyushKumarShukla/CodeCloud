#include<SDL2/SDL.h>
#include<stdbool.h>
#include<math.h>

//Screen parameters
#define WIDTH 900
#define HEIGHT 900

//Color definitions
//              AARRGGBB
#define CRED 	0x00ff0000
#define CBLACK 	0x00000000
#define CWHITE	0x00ffffff
#define CCYAN	0x00395555
#define CRED   	0x00ff0000
#define CGREEN 	0x0000ff00
//Map parameters
#define MAP_HEIGHT 5
#define MAP_WIDTH 5

//Player parameters
#define PLAYER_HEIGHT 20
#define PLAYER_WIDTH 20
#define ARROW_HEAD_DIMENSION 5
#define INITIAL_PLAYER_DIRECTION 45 //degrees
#define FOV_ANGLE 60.0 //degrees

//Geometric parameters
#define DEFAULT_LINE_LENGTH 100

//Helper macros
#define DEG2RAD M_PI/180


int map[MAP_HEIGHT][MAP_WIDTH] = {

	{0, 0, 1, 1, 1},
	{0, 0, 0, 0, 1},
	{1, 1, 1, 0, 1},
	{1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1}

};

typedef struct{
	double value;
}Angle;

typedef struct{
	double x;
	double y;
}Point;

typedef struct{
	Point pos;
	double w;
	double h;
	Angle dir;
}Player;

Player player = {{0, 0}, PLAYER_WIDTH, PLAYER_HEIGHT, {INITIAL_PLAYER_DIRECTION}};


void DrawMapGrid(SDL_Surface *surface){
	
	double cell_width = WIDTH/MAP_WIDTH;
	double cell_height = HEIGHT/MAP_HEIGHT;

	for(int i=0;i<MAP_HEIGHT;i++)
		for(int j=0;j<MAP_WIDTH;j++){
			SDL_Rect cell = {j*cell_width,i*cell_height,cell_width,cell_height};
			SDL_FillRect(surface,&cell,map[i][j] == 0 ? CBLACK:CCYAN);
		}
}

int DrawPlayer(SDL_Surface *surface){
	SDL_Rect player_rect = {player.pos.x, player.pos.y, player.w, player.h};
	return SDL_FillRect(surface, &player_rect, CRED);
}

void DrawArrowHead(SDL_Surface *surface, Point start, Angle dir, Uint32 color){
	double x2,y2;
	x2 = start.x + DEFAULT_LINE_LENGTH * cos(dir.value * DEG2RAD);
	y2 = start.y + DEFAULT_LINE_LENGTH * sin(dir.value * DEG2RAD);
	SDL_Rect arrow_head = {x2, y2, ARROW_HEAD_DIMENSION, ARROW_HEAD_DIMENSION};
	SDL_FillRect(surface, &arrow_head, color);
}

void DrawPlayerFOV(SDL_Surface *surface){
	Angle left_fov= {player.dir.value - (FOV_ANGLE/2.0)};
	Angle right_fov = {player.dir.value + (FOV_ANGLE/2.0)};
	DrawArrowHead(surface, player.pos, left_fov, CGREEN);
	DrawArrowHead(surface, player.pos, right_fov, CGREEN);

}
bool app_running = true;
int main(int argc, char* argv[]){
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window *mainwin 
		= SDL_CreateWindow("RayTracer",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,0);
	
	SDL_Surface *mainwin_surface
		= SDL_GetWindowSurface(mainwin);
	
	SDL_Event event;
	while(app_running){
		while(SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_QUIT:
					app_running=false;
			}
		}

		// ---------------------------------------------------
		//Flush the surface buffer
		SDL_FillRect(mainwin_surface,NULL,CBLACK);
		
		//Draw the actual map from the map 2D array
		DrawMapGrid(mainwin_surface);
	
		//Draw player : Body and Direction Head
		{
			if(DrawPlayer(mainwin_surface) < 0){
				printf("Failed to draw player\n");
				printf("%s",SDL_GetError());
			}
			DrawArrowHead(mainwin_surface, player.pos, player.dir, CGREEN);
			DrawPlayerFOV(mainwin_surface);
		}

		//Add player movement + rotation

	
		SDL_UpdateWindowSurface(mainwin);
		SDL_Delay(10);	
	}
		
	return 0;
}
