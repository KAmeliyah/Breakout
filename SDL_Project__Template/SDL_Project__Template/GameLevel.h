#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <SDL_mixer.h>

#include "Block.h"
#include "Ball.h"
#include "Text.h"

class GameLevel
{
private:
	std::vector <Block*> blocks;

	std::vector <std::vector <int>> blockData;

	//need a dictionary for block type to file name
	std::map <int, const char*> blockType;
	
	bool active{ false };

	bool IsCompleted{ false };

public:
	GameLevel();
	~GameLevel();

	void LoadLevel(const char* file);

	void InitLevel(SDL_Renderer* _rend);

	void Update(Ball* _ball, Mix_Chunk* _hit, Text* _score);
	void Render(SDL_Renderer* _rend);

	void SetActive(bool _active);

	bool GetActive();

	void SetCompleted(bool _completed);

	bool GetCompleted();

	


};

