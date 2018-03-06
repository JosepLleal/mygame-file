
#include "SDL/include/SDL.h"
#include "SDL_Image/include/SDL_image.h"



#pragma comment(lib, "SDL/libx86/SDL2.lib")
#pragma comment(lib, "SDL/libx86/SDL2main.lib")
#pragma comment(lib, "SDL_Image/libx86/SDL2_image.lib")


int main(int argc, char* argv[]) {
		
	

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow("Homework", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	

	//Creating square
	SDL_Rect rect;
	rect.w = 120;
	rect.h = 120;
	rect.x = 440;
	rect.y = 340;

	//Creating bullet
	SDL_Rect bullet;
	bullet.w = 50;
	bullet.h = 5;
	



	
	bool isRunning = true;
	SDL_Event event;
	
			
	while (isRunning) {

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				isRunning = false;
			}
			//moving square
			switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					rect.x -= 10;
					break;
				case SDLK_RIGHT:
					rect.x += 10;
					break;
				case SDLK_UP:
					rect.y -= 10;
					break;
				case SDLK_DOWN:
					rect.y += 10;
					break;
				//shooting bullet
				case SDLK_SPACE:
					bullet.x = rect.x+120;
					bullet.y = rect.y+60;
					break;
				}
				
				
			}
		}

		bullet.x++;
		bullet.x++;
		bullet.x++;

		//limits of movement
		if (rect.x < 0) {
			rect.x = 0;
		}
		else if (rect.x > 1000 - rect.w) {
			rect.x = 1000 - rect.w;
		}
		if (rect.y < 0) {
			rect.y = 0;
		}
		else if (rect.y > 800 -rect.h) {
			rect.y = 800 - rect.h;
		}

		//Refreshing color of square
		SDL_SetRenderDrawColor(renderer, 0, 150, 255, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(renderer, &bullet);

		

		SDL_RenderPresent(renderer);
		//Reducing speed
		SDL_Delay(3);

	}
	

	return 0;
}

