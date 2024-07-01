#pragma once

class GameObject
{
protected:
	int posX{ 0 };
	int posY{ 0 };
	int speed{ 0 };
	bool alive{ false };

public:

	GameObject(int _x, int _y, int _speed);

	virtual void Update() =  0;

	virtual void Render() = 0;

	bool GetAlive();

	void SetAlive(bool _alive);


};

