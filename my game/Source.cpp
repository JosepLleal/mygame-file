#include "SDL/include/SDL.h"

#pragma comment(lib, "SDL/libx86/SDL2.lib")
#pragma comment(lib, "SDL/libx86/SDL2main.lib")


int main(int argc, char* argv[]) {

	

		SDL_Init(SDL_INIT_EVERYTHING);

		SDL_Window *window = SDL_CreateWindow("Homework", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
		SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

		SDL_SetRenderDrawColor(renderer, 0, 150, 255, 255);
		SDL_RenderClear(renderer);

		//Creating square
		SDL_Rect rect;
		rect.w = 120;
		rect.h = 120;
		rect.x = 440;
		rect.y = 340;

		int a = 1; 
		int b = 1;

			
	while (true) {
		//Refreshing color of square
		SDL_SetRenderDrawColor(renderer, 0, 150, 255, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);

		//Square bounding
		if (rect.x >= 1000 - 120) {
			a=-1;
		}
		else if (rect.y >=800 - 120) {
			b=-1;
		}
		else if (rect.x <= 0) {
			a = 1;
		}
		else if (rect.y <= 0) {
			b = 1;
		}

		rect.x += a;
		rect.y += b;
	
		SDL_RenderPresent(renderer);
		//Reducing speed
		SDL_Delay(2);
	}
	

	return 0;
}

