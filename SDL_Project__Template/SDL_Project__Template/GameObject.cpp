#include "GameObject.h"


GameObject::GameObject(int _x, int _y, int _speed)
{
	posX = _y;
	posY = _y;
	speed = _speed;

	alive = true;
}

bool GameObject::GetAlive()
{
	return alive;
}

void GameObject::SetAlive(bool _alive)
{
	alive = _alive;
}

