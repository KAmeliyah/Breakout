#include "Game.h"

int Game::Init()
{
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

}

void Game::HandleEvents()
{
}

void Game::Update()
{
}

void Game::Render()
{
}

void Game::Clear()
{
	SDL_Quit();
}

void Game::SetRunning(bool _running)
{
	running = _running;
}

bool Game::GetRunning()
{
	return running;
}
