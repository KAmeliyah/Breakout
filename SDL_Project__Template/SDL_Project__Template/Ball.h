#pragma once
#include "GameObject.h"
class Ball : public GameObject
{
public:
	void Update(SDL_Renderer* _rend);

	void Render(SDL_Renderer* _rend);
};

