#include "GameObject.h"


GameObject::GameObject(const char* _spriteName, int _x, int _y, int _speed, SDL_Renderer* _rend)
{
	pos.x = _x;
	pos.y = _y;
	speed = _speed;

	alive = true;

	SDL_Surface* surface = SDL_LoadBMP(_spriteName);
	if (surface == nullptr)
	{
		std::cout << "Failed to load image " << _spriteName << SDL_GetError() << std::endl;
	}
	spriteTexture = SDL_CreateTextureFromSurface(_rend, surface);

	SDL_FreeSurface(surface);

	SDL_QueryTexture(spriteTexture, 0, 0, &sRect.w, &sRect.h);
	sRect.x = 0;
	sRect.y = 0;

	dRect.w = sRect.w;
	dRect.h = sRect.h;



}

GameObject::~GameObject()
{
}

bool GameObject::GetAlive()
{
	return alive;
}

void GameObject::SetAlive(bool _alive)
{
	alive = _alive;
}

SDL_Rect* GameObject::GetRect()
{
	return &dRect;
}

