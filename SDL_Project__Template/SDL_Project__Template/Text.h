#pragma once
#include <SDL_ttf.h>
#include <string>
#include <iostream>
#include "Vec2D.h"

//Updated version of GameText from Space Invaders
class Text
{
protected:

	int x;
	int y;
	int value{ 0 };

	TTF_Font* font;
	SDL_Renderer* rend;
	SDL_Surface* text;
	SDL_Texture* textTexture{ nullptr };

	SDL_Color color = { 255,255,255 };
	SDL_Rect dest = { NULL };

	bool changed{ false };

public:

	Text(SDL_Renderer* _rend, TTF_Font* _font,  int _x, int _y);
	Text(int _value, SDL_Renderer* _rend, TTF_Font* _font,  int _x, int _y);
	Text(const char* _text, SDL_Renderer* _rend, TTF_Font* _font,  int _x, int _y);
	Text(int _value, const char* _text, SDL_Renderer* _rend, TTF_Font* _font,  int _x, int _y);

	Text(std::string _text, SDL_Renderer* _rend, TTF_Font* _font, int _x, int _y);
	
	Text(int _value, std::string _text, SDL_Renderer* _rend, TTF_Font* _font, int _x, int _y);

	~Text();

	void Update();

	void Render();


	
	void Increase(int _value);
	void Decrease(int _value);

	void SetValue(int _value);

	int GetValue();

	
};

