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

	void Update();

	void Render();
};

