#include "Paddle.h"

void Paddle::Update(SDL_Renderer* _rend)
{
	int x;
	SDL_GetMouseState(&x,NULL);

	if (x < 50)
	{
		pos.x = 0;
		
	}
	else if (x > 550)
	{

		pos.x = 500;
	}
	else
	{
		pos.x = x - 50;
	}

	dRect.x = pos.x;

}

void Paddle::Render(SDL_Renderer* _rend)
{

	SDL_RenderCopy(_rend, spriteTexture, &sRect, &dRect);
}
