#pragma once

#include <SDL.h>
#include <iostream>
#include <vector>
#include "GameLevel.h"

enum GameState
{
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

class Game
{
private:

	GameState state;

	unsigned int height{ 0 };
	unsigned int width{ 0 };

	SDL_Window* window{ nullptr };
	SDL_Renderer* rend{ nullptr };
	SDL_Event e;

	bool running = true;

	//all the levels
	std::vector <GameLevel> levels;

public:

	int Init();

	void HandleEvents();

	void Update();

	void Render();

	void Clear();

	void SetRunning(bool _running);

	bool GetRunning();


};

