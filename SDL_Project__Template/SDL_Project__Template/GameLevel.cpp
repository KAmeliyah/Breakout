#include "GameLevel.h"

GameLevel::GameLevel()
{
	blockType[1] = "./Sprites/Block.bmp";
	blockType[2] = "./Sprites/BlueBlock.bmp";
	blockType[3] = "./Sprites/GreenBlock.bmp";
	blockType[4] = "./Sprites/RedBlock.bmp";
	blockType[5] = "./Sprites/YellowBlock.bmp";

}

GameLevel::~GameLevel()
{
}

void GameLevel::LoadLevel(const char* file)
{
	this->blocks.clear();
	this->blockData.clear();
	int tile;
	std::string line;
	std::ifstream fstream(file);
	

	if (fstream)
	{
		while (std::getline(fstream, line))
		{
			std::istringstream sstream(line);
			std::vector <int> row;
			while (sstream >> tile)
			{
				row.push_back(tile);
			}
			blockData.push_back(row);

		}
		
	}

}

void GameLevel::InitLevel(SDL_Renderer* _rend)
{
	int height = blockData.size();
	int width = blockData[0].size();

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int type = blockData[y][x];

			if (type != 0)
			{
				
				blocks.push_back(Block(blockType[type], 0, 0, 0, _rend));

				
			}

		}
	}
}

void GameLevel::Update()
{
}

void GameLevel::Render()
{
}
