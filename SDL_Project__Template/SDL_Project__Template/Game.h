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
	GAME_TITLE,
	GAME_ACTIVE,
	GAME_PAUSE,
	GAME_WIN,
	GAME_LOSE
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

	SDL_Texture* titleScreen;
	SDL_Rect titleSRect;
	SDL_Rect titleDRect;

	SDL_Texture* pause;
	SDL_Rect pauseSRect;
	SDL_Rect pauseDRect;

	SDL_Texture* m_WinScreen;
	SDL_Rect m_WinSRect;
	SDL_Rect m_WinDRect;

	SDL_Texture* m_LoseScreen;
	SDL_Rect m_LoseSRect;
	SDL_Rect m_LoseDRect;



public:

	int Init();

	void HandleEvents();

	void Update();

	void Render();

	void Clear();

	void SetRunning(bool _running);

	bool GetRunning();


};

