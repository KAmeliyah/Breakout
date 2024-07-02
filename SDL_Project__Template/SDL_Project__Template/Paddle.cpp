#include "Paddle.h"

void Paddle::Update(SDL_Renderer* _rend)
{

	SDL_GetMouseState(&x,NULL);
	dRect.x = x - 50;
	



}

void Paddle::Render(SDL_Renderer* _rend)
{

	SDL_RenderCopy(_rend, spriteTexture, &sRect, &dRect);
}
