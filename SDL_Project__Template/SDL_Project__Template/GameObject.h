#pragma once
#include <SDL.h>
#include <iostream>

class GameObject
{
protected:
	int x{ 0 };
	int y{ 0 };
	int width{ 0 };
	int height{ 0 };

	int speed{ 0 };

	bool alive{ false };

	SDL_Texture* spriteTexture;
	SDL_Rect sRect;
	SDL_Rect dRect;

public:

	GameObject(const char* _spriteName,int _x, int _y, int _speed, SDL_Renderer* _rend);
	
    ~GameObject();

	virtual void Update(SDL_Renderer* _rend) =  0;

	virtual void Render(SDL_Renderer* _rend) = 0;

	bool GetAlive();

	void SetAlive(bool _alive);


};

