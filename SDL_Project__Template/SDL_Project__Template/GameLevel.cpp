#include "GameLevel.h"

GameLevel::GameLevel()
{
	blockType[1] = "./Sprites/Block.bmp";
	blockType[2] = "./Sprites/BlueBlock.bmp";
	blockType[3] = "./Sprites/GreenBlock.bmp";
	blockType[4] = "./Sprites/RedBlock.bmp";
	blockType[5] = "./Sprites/YellowBlock.bmp";

	active = true;
	IsCompleted = false;



}

GameLevel::~GameLevel()
{
}

void GameLevel::LoadLevel(const char* file)
{
	// clean up previous data to start fresh with new data
	this->blocks.clear();
	this->blockData.clear();
	int tile;
	std::string line;

	//ifstream reads the content of the given file
	std::ifstream fstream(file);

	//if the file has content
	if (fstream)
	{
		// read each line of the text file
		while (std::getline(fstream, line))
		{
			//stores line as a string object
			std::istringstream sstream(line);
			std::vector <int> row;

			//read each number in the line and store as block data
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
	//separate data indexing into rows and columns
	int height = blockData.size();
	int width = blockData[0].size();

	//loop through the data
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			//Get type of block from data
			int type = blockData[y][x];

			//if there is a block, instantiate the corresponding block
			if (type != 0)
			{
				Block* block = { nullptr };
				block = new Block(blockType[type], x * 50, 50 + y * 30, 0, _rend);
				blocks.push_back(block);
			}
		}
	}
}

void GameLevel::Update(Ball* _ball, Mix_Chunk* _hit, Text* _score)
{
	if (blocks.empty())
	{
		SetCompleted(true);
	}

	for (int i = 0; i < blocks.size(); i++)
	{
		if (SDL_HasIntersection(_ball->GetRect(), blocks[i]->GetRect()))
		{
			_ball->Reverse(blocks[i]->GetRect());
			Mix_PlayChannel(-1, _hit, 0);
			_score->Increase(4);
			
			blocks[i]->SetAlive(false);
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

void GameLevel::SetActive(bool _active)
{
	active = _active;
}

bool GameLevel::GetActive()
{
	return active;
}

void GameLevel::SetCompleted(bool _completed)
{
	IsCompleted = _completed;
}

bool GameLevel::GetCompleted()
{
	return IsCompleted;
}
