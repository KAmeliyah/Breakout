#include "Ball.h"

void Ball::Update(SDL_Renderer* _rend)
{
	if (lives <= 0)
	{
		alive = false;
	}

	pos.x += moveVec.x * speed;
	pos.y += moveVec.y * speed;


	if (pos.y <= 0)
	{
		moveVec.y *= -1;

	}

	if (pos.y >= 750)
	{
		RemoveLives();

	}

	if (pos.x <= 0 || pos.x + dRect.w >= 600)
	{
		moveVec.x *= -1;
	}

	

	dRect.x = pos.x;
	dRect.y = pos.y;
}

void Ball::Render(SDL_Renderer* _rend)
{
	SDL_RenderCopy(_rend, spriteTexture, &sRect, &dRect);
}

void Ball::Reverse(SDL_Rect* coll)
{
	//calculate angle of entry to figure out angle of exit and normalise to get the vector
	//figure out what needs to be reversed
	
	double reverseAngle = ((pos.x + 12.5) - (coll->x + 50)) / 100;

	
	moveVec.x = reverseAngle;

	moveVec.y *= -1;

	moveVec.Normalise();
	
}

int Ball::GetLives()
{
	return lives;
}

void Ball::Reset()
{
	lives = 3;
	moveVec.Set(0, -1);
	pos.Set(250, 625);

}

void Ball::RemoveLives()
{

	lives -= 1;
	moveVec.Set(0, -1);
	pos.Set(250, 625);

}
