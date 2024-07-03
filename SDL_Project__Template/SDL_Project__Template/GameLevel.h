#pragma once
#include <vector>
#include "Block.h"
class GameLevel
{
private:
	std::vector <Block> blocks;
	bool active{ false };

public:
	GameLevel();
	~GameLevel();

	void LoadLevel();

	


};

