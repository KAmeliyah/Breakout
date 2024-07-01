#pragma once

#include <SDL.h>
#include <iostream>
class Game
{
private:

	SDL_Window* window{ nullptr };
	SDL_Renderer* rend{ nullptr };
	SDL_Event e;

	bool running = true;

public:

	int Init();

	void HandleEvents();

	void Update();

	void Render();

	void Clear();

	void SetRunning(bool _running);

	bool GetRunning();


};

