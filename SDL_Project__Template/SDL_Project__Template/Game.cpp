#include "Game.h"

int Game::Init()
{
	state = GAME_ACTIVE;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "Failed to initialise SDL: " << SDL_GetError() << std::endl;
		return -1;

	}

	window = SDL_CreateWindow("Play Screen", 450, 50, 600, 750, 0);

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

	SDL_GetWindowSize(window, &width, &height);
	SDL_RenderSetLogicalSize(rend, 600, 750);
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);

	player = new Paddle("./Sprites/Paddle.bmp",250,675,0,rend);
	ball = new Ball("./Sprites/Ball.bmp", 250, 625, 0, rend);


	return 0;

}

void Game::HandleEvents()
{
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
			case SDL_QUIT:
			SetRunning(false);
			break;

			default:
				break;

		}
			
	}
}

void Game::Update()
{
	player->Update(rend);
	ball->Update(rend);
}

void Game::Render()
{
	SDL_RenderClear(rend);

	player->Render(rend);
	ball->Render(rend);
	SDL_RenderPresent(rend);
}

void Game::Clear()
{
	SDL_Quit();
}

void Game::ChangeLevel()
{
}

void Game::SetRunning(bool _running)
{
	running = _running;
}

bool Game::GetRunning()
{
	return running;
}
