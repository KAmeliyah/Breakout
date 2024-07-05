#pragma once
#include "GameObject.h"
class Block : public GameObject
{
private:
	int type{ 0 }; // 0 - 5
	// 0 is empty
	// 1 is unbreakable
	// 2-5 are colours
public:

	Block(const char* _spriteName, int _x, int _y, int _speed, SDL_Renderer* _rend) : GameObject(_spriteName, _x, _y, _speed, _rend) {
		dRect.x = pos.x;
		dRect.y = pos.y;
	};

	void Update(SDL_Renderer* _rend);

	void Render(SDL_Renderer* _rend);

	void SetType(int _type);

	int GetType();
};

