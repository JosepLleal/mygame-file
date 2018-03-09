
#include "SDL/include/SDL.h"
#include "SDL_Image/include/SDL_image.h"



#pragma comment(lib, "SDL/libx86/SDL2.lib")
#pragma comment(lib, "SDL/libx86/SDL2main.lib")
#pragma comment(lib, "SDL_Image/libx86/SDL2_image.lib")



int main(int argc, char* argv[]) {
		
	
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Surface *surface;
	SDL_Texture *backround;
	SDL_Texture *ship;
	SDL_Window *window = SDL_CreateWindow("Homework", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

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
	bullet.x = 1000;
	bullet.y = 0;
	

	SDL_Event event;
	
	bool isRunning = true;
	bool up = false;
	bool down = false;
	bool left = false;
	bool right = false;
	bool space = false;

	
	IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG);
	//backround
	surface = IMG_Load("space.png");
	backround = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("spaceship.png");
	ship = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);




	

	while (isRunning) {

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				isRunning = false;
			}
			

			//moving square
			else if (event.type == SDL_KEYDOWN)
			{
				
				if (event.key.keysym.sym == SDLK_UP)
				{
					up = true;

				}
				if (event.key.keysym.sym == SDLK_DOWN)
				{
					down = true;
				}
				if (event.key.keysym.sym == SDLK_LEFT)
				{
					left = true;
				}
				if (event.key.keysym.sym == SDLK_RIGHT)
				{
					right = true;
				}
				if (event.key.keysym.sym == SDLK_SPACE)
				{
					space = true;
				}
				
				
			}
			
				
			else if (event.type == SDL_KEYUP)
			{
				if (event.key.keysym.sym == SDLK_UP)
				{
					up = false;
				}
				if (event.key.keysym.sym == SDLK_DOWN)
				{
					down = false;
				}
				if (event.key.keysym.sym == SDLK_LEFT)
				{
					left = false;
				}
				if (event.key.keysym.sym == SDLK_RIGHT)
				{
					right = false;
				}
				if (event.key.keysym.sym == SDLK_SPACE)
				{
					space = false;
				}
			}
		}

		if (up == true)
		{
			rect.y -= 1;

		}

		if (down == true)
		{
			rect.y += 1;
		}

		if (left == true)
		{
			rect.x -= 1;
		}

		if (right == true)
		{
			rect.x += 1;
		}
		if (space == true)
		{
			bullet.x = rect.x + 100;
			bullet.y = rect.y + 60;

		}

		bullet.x+=3;
		
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



		
		//SDL_SetRenderDrawColor(renderer, 0, 150, 255, 255);
		//SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, backround, NULL, NULL);
		SDL_RenderCopy(renderer, ship, NULL, &rect);

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderFillRect(renderer, &bullet);

		//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		//SDL_RenderFillRect(renderer, &rect);

		
		SDL_RenderPresent(renderer);
		
		SDL_Delay(1);

	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
	
	
	return 0;
}

