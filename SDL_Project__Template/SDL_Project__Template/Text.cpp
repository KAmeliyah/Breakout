#include "Text.h"

Text::Text(SDL_Renderer* _rend, TTF_Font* _font, int _x, int _y)
{
	font = _font;
	rend = _rend;
	x = _x;
	y = _y;
	

	std::string score = std::to_string(value);

	//unwrapped to prevent distortion
	//creating the surface
	SDL_Surface* text = TTF_RenderText_Solid_Wrapped(font, score.c_str(), color, 0);

	//error checking
	if (!text)
	{
		std::cout << "Failed to render text: " << TTF_GetError() << std::endl;

	}

	textTexture = SDL_CreateTextureFromSurface(rend, text);

	dest = { x,y,text->w,text->h };

	//cleaning up
	SDL_FreeSurface(text);
}

Text::Text(int _value, SDL_Renderer* _rend, TTF_Font* _font, int _x, int _y)
{
	value = _value;
	font = _font;
	rend = _rend;
	x = _x;
	y = _y;


	std::string score = std::to_string(value);

	//unwrapped to prevent distortion
	//creating the surface
	SDL_Surface* text = TTF_RenderText_Solid_Wrapped(font, score.c_str(), color, 0);

	//error checking
	if (!text)
	{
		std::cout << "Failed to render text: " << TTF_GetError() << std::endl;

	}

	textTexture = SDL_CreateTextureFromSurface(rend, text);

	dest = { x,y,text->w,text->h };

	//cleaning up
	SDL_FreeSurface(text);
}

Text::Text(const char* _text, SDL_Renderer* _rend, TTF_Font* _font, int _x, int _y)
{
	font = _font;
	rend = _rend;
	x = _x;
	y = _y;
	

	//unwrapped to prevent distortion
	SDL_Surface* text = TTF_RenderText_Solid_Wrapped(font, _text, color, 0);
	if (!text)
	{
		std::cout << "Failed to render text: " << TTF_GetError() << std::endl;

	}
	textTexture = SDL_CreateTextureFromSurface(rend, text);

	dest = { x,y,text->w,text->h };
	SDL_FreeSurface(text);
}

Text::Text(int _value, const char* _text, SDL_Renderer* _rend, TTF_Font* _font, int _x, int _y)
{
	value = _value;
	font = _font;
	rend = _rend;
	x = _x;
	y = _y;

	std::string score = std::to_string(value);
	

	std::string scoreText = _text;
	scoreText += score;

	//unwrapped to prevent distortion
	SDL_Surface* text = TTF_RenderText_Solid_Wrapped(font, scoreText.c_str(), color, 0);
	if (!text)
	{
		std::cout << "Failed to render text: " << TTF_GetError() << std::endl;

	}
	textTexture = SDL_CreateTextureFromSurface(rend, text);

	dest = { x,y,text->w,text->h };
	SDL_FreeSurface(text);
}

Text::Text(std::string _text, SDL_Renderer* _rend, TTF_Font* _font, int _x, int _y)
{
	font = _font;
	rend = _rend;
	x = _x;
	y = _y;


	//unwrapped to prevent distortion
	SDL_Surface* text = TTF_RenderText_Solid_Wrapped(font, _text.c_str(), color, 0);
	if (!text)
	{
		std::cout << "Failed to render text: " << TTF_GetError() << std::endl;

	}
	textTexture = SDL_CreateTextureFromSurface(rend, text);

	dest = { x,y,text->w,text->h };
	SDL_FreeSurface(text);
}

Text::Text(int _value, std::string _text, SDL_Renderer* _rend, TTF_Font* _font, int _x, int _y)
{
	value = _value;
	font = _font;
	rend = _rend;
	x = _x;
	y = _y;


	//unwrapped to prevent distortion
	SDL_Surface* text = TTF_RenderText_Solid_Wrapped(font, _text.c_str(), color, 0);
	if (!text)
	{
		std::cout << "Failed to render text: " << TTF_GetError() << std::endl;

	}
	textTexture = SDL_CreateTextureFromSurface(rend, text);

	dest = { x,y,text->w,text->h };
	SDL_FreeSurface(text);
}

Text::~Text()
{
}

void Text::Update()
{
	if (changed)
	{
		std::string score = std::to_string(value);
		SDL_Surface* text = TTF_RenderText_Solid_Wrapped(font, score.c_str(), color, 0);

		if (!text)
		{
			std::cout << "Failed to render text: " << TTF_GetError() << std::endl;

		}
		textTexture = SDL_CreateTextureFromSurface(rend, text);

		dest = { x,y,text->w,text->h };
		SDL_FreeSurface(text);
		changed = false;
	}
}

void Text::Increase(int _value)
{
	value += _value;
	changed = true;
}

void Text::Decrease(int _value)
{
	value -= _value;
	changed = true;
}

void Text::Render()
{
	SDL_RenderCopy(rend, textTexture, NULL, &dest);
}

void Text::SetValue(int _value)
{
	value = _value;
}

int Text::GetValue()
{
	return value;
}
