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

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) != 0)
	{
		std::cout << "Failed to open audio:" << Mix_GetError();
		return -1;
	}

	
	if (TTF_Init() < 0)
	{
		std::cout << "Error initialising SDL_ttf" << TTF_GetError() << std::endl;
		return -1;
	}

	SDL_GetWindowSize(window, &width, &height);
	SDL_RenderSetLogicalSize(rend, 600, 750);
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);

	fileNames.push_back("Level1.txt");
	fileNames.push_back("Level2.txt");
	fileNames.push_back("test.txt");
	fileNames.push_back("test2.txt");

	GameLevel level1;
	level1.LoadLevel(fileNames[1]);
	level1.InitLevel(rend);
	levels.push_back(level1);
	
	GameLevel level2;
	level2.LoadLevel(fileNames[0]);
	level2.InitLevel(rend);
	levels.push_back(level2);

	
	hitSFX = Mix_LoadWAV("./Sounds/hit.wav");

	if (!hitSFX)
	{
		std::cout << "Failed to load SFX: " << Mix_GetError() << std::endl;
	}

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


	if (levels.empty())
	{
		std::cout << "You win" << std::endl;
		SetRunning(false);

	}
	else
	{
		if (!ball->GetAlive())
		{
			SetRunning(false);
			std::cout << "You lost" << std::endl;
		}
		player->Update(rend);
		ball->Update(rend);
		levels.back().Update(ball, hitSFX);

		SDL_Rect collision;

		bool pColl = SDL_IntersectRect(player->GetRect(), ball->GetRect(), &collision);

		if (pColl)
		{
			ball->Reverse(player->GetRect());
			Mix_PlayChannel(-1, hitSFX, 0);
		}

		if (levels.back().GetCompleted())
		{
			levels.pop_back();
			ball->Reset();
		}
	}

	
	


}

void Game::Render()
{
	SDL_RenderClear(rend);

	player->Render(rend);
	ball->Render(rend);

	if (!levels.empty())
	{
		levels.back().Render(rend);
	}
	


	SDL_RenderPresent(rend);
}

void Game::Clear()
{
	Mix_FreeChunk(hitSFX);
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
