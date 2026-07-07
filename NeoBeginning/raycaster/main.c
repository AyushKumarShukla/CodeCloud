#include<SDL2/SDL.h>
#include<stdbool.h>
#define WIDTH 900
#define HEIGHT 600
#define CWHITE 0xffffffff
#define CBLACK 0x00000000
#define RECT_WIDTH 100
#define RECT_HEIGHT 100
bool app_running = true;
int main(int argc, char* argv[]){
	SDL_Init(SDL_INIT_VIDEO);
	
	SDL_Window *mainwin 
		= SDL_CreateWindow("RayTracer",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,0);
	
	SDL_Surface *mainwin_surface
		= SDL_GetWindowSurface(mainwin);
	
	SDL_Event event;
	int counter = 0;
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
		SDL_Rect rect = {WIDTH/2,HEIGHT/2,RECT_WIDTH+counter++,RECT_HEIGHT+counter};
		SDL_FillRect(mainwin_surface, &rect,CWHITE);
		SDL_UpdateWindowSurface(mainwin);
		SDL_Delay(10);	
	}
		
	return 0;
}
