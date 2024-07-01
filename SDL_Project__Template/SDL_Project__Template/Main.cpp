#include <SDL.h>
#include <iostream>
#include "Game.h"



int main(int argc, char* argv[])
{
	
	//set frame rate
	const int FPS = 60;
	//set the frame time
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	Game* game{ nullptr };
	game = new Game;
	
	game->Init();

	//game loop
	while (game->GetRunning())
	{
		frameStart = SDL_GetTicks();

		game->HandleEvents();
		game->Update();
		game->Render();
		

		//frame rate control
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

	}
	
	game->Clear();
	

	
	return 0;
}