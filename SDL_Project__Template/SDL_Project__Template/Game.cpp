#include "Game.h"

int Game::Init()
{
	state = GAME_TITLE;

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
	fileNames.push_back("Level3.txt");
	fileNames.push_back("Level4.txt");

	GameLevel level1;
	level1.LoadLevel(fileNames[0]);
	level1.InitLevel(rend);

	GameLevel level2;
	level2.LoadLevel(fileNames[1]);
	level2.InitLevel(rend);

	GameLevel level3;
	level3.LoadLevel(fileNames[2]);
	level3.InitLevel(rend);

	GameLevel level4;
	level4.LoadLevel(fileNames[3]);
	level4.InitLevel(rend);


	levels.push_back(level4);
	levels.push_back(level3);
	levels.push_back(level2);
	levels.push_back(level1);

	hitSFX = Mix_LoadWAV("./Sounds/hit.wav");

	if (!hitSFX)
	{
		std::cout << "Failed to load SFX: " << Mix_GetError() << std::endl;
	}

	font = TTF_OpenFont("Anton.ttf", 36);
	if (!font)
	{
		std::cout << "Failed to open font " << TTF_GetError() << std::endl;
		return -1;
	}

	SDL_Surface* surface = SDL_LoadBMP("./Sprites/Title.bmp");
	if (surface == nullptr)
	{
		std::cout << "Failed to load title screen " << SDL_GetError() << std::endl;
		return -1;
	}
	titleScreen = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	SDL_QueryTexture(titleScreen, 0, 0, &titleSRect.w, &titleSRect.h);
	titleSRect.x = 0;
	titleSRect.y = 0;

	titleDRect.w = titleSRect.w;
	titleDRect.h = titleSRect.h;

	surface = SDL_LoadBMP("./Sprites/Pause.bmp");
	if (surface == nullptr)
	{
		std::cout << "Failed to load pause screen " << SDL_GetError() << std::endl;
		return -1;
	}
	pause = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	SDL_QueryTexture(pause, 0, 0, &pauseSRect.w, &pauseSRect.h);
	pauseSRect.x = 0;
	pauseSRect.y = 0;

	pauseDRect.w = pauseSRect.w;
	pauseDRect.h = pauseSRect.h;

	surface = SDL_LoadBMP("./Sprites/Win.bmp");
	if (surface == nullptr)
	{
		std::cout << "Failed to load win screen " << SDL_GetError() << std::endl;
		return -1;
	}
	m_WinScreen = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	SDL_QueryTexture(m_WinScreen, 0, 0, &m_WinSRect.w, &m_WinSRect.h);
	m_WinSRect.x = 0;
	m_WinSRect.y = 0;

	m_WinDRect.w = m_WinSRect.w;
	m_WinDRect.h = m_WinSRect.h;

	surface = SDL_LoadBMP("./Sprites/Lose.bmp");
	if (surface == nullptr)
	{
		std::cout << "Failed to load lose screen " << SDL_GetError() << std::endl;
		return -1;
	}
	m_LoseScreen = SDL_CreateTextureFromSurface(rend, surface);

	SDL_FreeSurface(surface);
	SDL_QueryTexture(m_LoseScreen, 0, 0, &m_LoseSRect.w, &m_LoseSRect.h);
	m_LoseSRect.x = 0;
	m_LoseDRect.y = 0;

	m_LoseDRect.w = m_LoseSRect.w;
	m_LoseDRect.h = m_LoseSRect.h;

	score = new Text(0, rend, font, 0, 0);

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

			case SDL_MOUSEBUTTONDOWN:
				switch (e.button.button)
				{
					case SDL_BUTTON_LEFT:
						if (state == GAME_TITLE)
						{
							
							state = GAME_ACTIVE;
						}
						if (state == GAME_WIN || state == GAME_LOSE)
						{
							SetRunning(false);
						}
						break;

					default:
						break;
				}

			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						if (state == GAME_ACTIVE)
						{
							state = GAME_PAUSE;
						}
						else if (state == GAME_PAUSE)
						{
							state = GAME_ACTIVE;
						}
						break;
					default:
						break;

				}
			default:
				break;	
		}
			
	}
}

void Game::Update()
{

	if (state == GAME_ACTIVE)
	{
		if (levels.empty())
		{
			state = GAME_WIN;

			

		}
		else
		{
			if (!ball->GetAlive())
			{
				state = GAME_LOSE;

				
				
			}
			player->Update(rend);
			ball->Update(rend);
			levels.back().Update(ball, hitSFX,score);

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

	
		score->Update();
	}
	


}

void Game::Render()
{
	SDL_RenderClear(rend);

	if (state == GAME_TITLE)
	{

		SDL_RenderCopy(rend, titleScreen, NULL, NULL);
	}
	else if (state == GAME_PAUSE)
	{
		SDL_RenderCopy(rend, pause, NULL, NULL);
	}
	else if (state == GAME_WIN)
	{
		SDL_RenderCopy(rend, m_WinScreen, NULL, NULL);
	}
	else if (state == GAME_LOSE)
	{
		SDL_RenderCopy(rend, m_LoseScreen, NULL, NULL);
	}

	else if (state == GAME_ACTIVE)
	{
		player->Render(rend);
		ball->Render(rend);

		if (!levels.empty())
		{
			levels.back().Render(rend);
		}
	
		score->Render();
	}

	

	SDL_RenderPresent(rend);
}

void Game::Clear()
{
	Mix_FreeChunk(hitSFX);
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
