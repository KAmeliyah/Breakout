#pragma once

#include <SDL.h>
#include <iostream>
#include <vector>
#include "GameLevel.h"
#include "Paddle.h"
#include "Ball.h"
#include "Text.h"
#include <SDL_mixer.h>


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
	std::vector < const char* > fileNames;
	std::vector <GameLevel> levels;

	Paddle* player{ nullptr };
	Ball* ball{ nullptr };

	Mix_Chunk* hitSFX{ nullptr };
	
	
	TTF_Font* font{ nullptr };
	Text* score{ nullptr };


public:

	int Init();

	void HandleEvents();

	void Update();

	void Render();

	void Clear();

	void SetRunning(bool _running);

	bool GetRunning();


};

