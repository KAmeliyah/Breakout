#pragma once

#include <SDL.h>
#include <iostream>
#include <vector>
#include "GameLevel.h"
#include "Paddle.h"
#include "Ball.h"


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

	int height{ 0 };
	int width{ 0 };

	SDL_Window* window{ nullptr };
	SDL_Renderer* rend{ nullptr };
	SDL_Event e;

	bool running = true;

	//all the levels
	std::vector <GameLevel> levels;

	Paddle* player{ nullptr };
	Ball* ball{ nullptr };
	

public:

	int Init();

	void HandleEvents();

	void Update();

	void Render();

	void Clear();

	void ChangeLevel();

	void SetRunning(bool _running);

	bool GetRunning();


};

