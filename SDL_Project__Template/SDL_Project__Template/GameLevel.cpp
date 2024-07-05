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
		std::cout << "Reading file" << std::endl;
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
				Block* block = { nullptr };
				block = new Block(blockType[type], x * 50, 50 + y * 30, 0, _rend);
				blocks.push_back(block);

				
			}

		}
	}
}

void GameLevel::Update(Ball* _ball)
{
	for (int i = 0; i < blocks.size(); i++)
	{
		if (SDL_HasIntersection(_ball->GetRect(), blocks[i]->GetRect()))
		{
			blocks[i]->SetAlive(false);
			_ball->Reverse(blocks[i]->GetRect());
			
		}
	}

	//errors have arisen from trying to remove blocks

	for (int i = 0; i < blocks.size(); i++)
	{
		if (!blocks[i]->GetAlive())
		{
			delete blocks[i];
			blocks[i] = nullptr;
		}
		
	}
	blocks.erase(std::remove(blocks.begin(), blocks.end(), nullptr), blocks.end());


}

void GameLevel::Render(SDL_Renderer* _rend)
{

	for (int i = 0; i < blocks.size(); i++)
	{
		blocks[i]->Render(_rend);
	}

}
