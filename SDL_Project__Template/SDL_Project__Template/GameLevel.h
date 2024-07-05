#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

#include "Block.h"
#include "Ball.h"
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

	void Update(Ball* _ball);
	void Render(SDL_Renderer* _rend);

	


};

