#include "Paddle.h"

void Paddle::Update(SDL_Renderer* _rend)
{

	SDL_GetMouseState(&x,NULL);

	if (x < 50)
	{
		dRect.x = 0;
	}
	else if (x > 550)
	{
		dRect.x = 500;
	}
	else
	{
		dRect.x = x - 50;
	}
	
	



}

void Paddle::Render(SDL_Renderer* _rend)
{

	SDL_RenderCopy(_rend, spriteTexture, &sRect, &dRect);
}
