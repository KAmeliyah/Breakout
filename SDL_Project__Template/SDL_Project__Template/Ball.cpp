#include "Ball.h"

void Ball::Update(SDL_Renderer* _rend)
{
	pos += moveVec;

	if (pos.y <= 0)
	{
		moveVec *= -1;

	}

	dRect.x = pos.x;
	dRect.y = pos.y;
}

void Ball::Render(SDL_Renderer* _rend)
{
	SDL_RenderCopy(_rend, spriteTexture, &sRect, &dRect);
}
