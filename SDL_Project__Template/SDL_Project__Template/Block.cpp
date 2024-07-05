#include "Block.h"

void Block::Update(SDL_Renderer* _rend)
{

}

void Block::Render(SDL_Renderer* _rend)
{
	SDL_RenderCopy(_rend, spriteTexture, &sRect, &dRect);
}

void Block::SetType(int _type)
{
	type = _type;
}

int Block::GetType()
{
	return type;
}
