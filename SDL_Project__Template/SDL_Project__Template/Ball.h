#pragma once
#include "GameObject.h"

class Ball : public GameObject
{
private:
	Vec2D moveVec{0,-3};
public:

	Ball(const char* _spriteName, int _x, int _y, int _speed, SDL_Renderer* _rend) : GameObject(_spriteName, _x, _y, _speed, _rend) {
		dRect.x = pos.x;
		dRect.y = pos.y;
	};

	void Update(SDL_Renderer* _rend);

	void Render(SDL_Renderer* _rend);

	void Reverse();
};

