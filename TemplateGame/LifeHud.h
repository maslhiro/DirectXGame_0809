#pragma once
#include "GameObject.h"

class LifeHud : GameObject
{
private:
	int _numLife;
	Animation _cha01, _cha02;
public:

	LifeHud();
	~LifeHud();

	void loadResource();

	void setNumLife(int);

	void render();

	void update(float);

	void handlerInput(float) {};
};

typedef LifeHud* pLifeHud;
