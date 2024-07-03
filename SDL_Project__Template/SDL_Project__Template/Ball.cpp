#include "Ball.h"

void Ball::Update(SDL_Renderer* _rend)
{
	pos += moveVec;

	if (pos.y <= 0)
	{
		moveVec.y *= -1;

	}



	dRect.x = pos.x;
	dRect.y = pos.y;
}

void Ball::Render(SDL_Renderer* _rend)
{
	SDL_RenderCopy(_rend, spriteTexture, &sRect, &dRect);
}

void Ball::Reverse()
{
	//calculate angle of entry to figure out angle of exit and normalise to get the vector

	moveVec.y *= -1;

}
