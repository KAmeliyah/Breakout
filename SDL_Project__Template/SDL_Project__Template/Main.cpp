#include <SDL.h>
#include <iostream>



int main(int argc, char* argv[])
{
	
	//set frame rate
	const int FPS = 60;
	//set the frame time
	const int frameDelay = 1000 / FPS;
	
	bool running = true;

	SDL_Window* window{ nullptr };
	SDL_Renderer* rend{ nullptr };
	SDL_Event e;

	Uint32 frameStart;
	int frameTime;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "Failed to initialise SDL: " << SDL_GetError() << std::endl;
		return -1;

	}

	window = SDL_CreateWindow("Play Screen", 100, 100, 300, 300, 0);

	if (window == nullptr)
	{
		std::cout << "Failed to initialise window" << std::endl;
		return -1;
	}

	rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (rend == nullptr)
	{
		std::cout << "Failed to initalise renderer" << std::endl;
		return -1;
	}

	SDL_RenderSetLogicalSize(rend, 300, 300);

	

	//game loop
	while (running)
	{
		frameStart = SDL_GetTicks();

		//on mouse click close window

		SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);

		SDL_RenderClear(rend);

		SDL_RenderPresent(rend);

		

		//frame rate control
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}



	}

	SDL_Quit();

	
	return 0;
}