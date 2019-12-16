#pragma once
#include "GameObject.h"

class Bat :
	public GameObject
{
private:
	float _posX;
	float _posY;
public:
	Bat();
	Bat(int);

	void loadResource();

	void setPosXPlayer(Vec3);

	void getDamaged(int);

	void render();

	void update(float);

	void handlerInput(float);
};

typedef Bat* pBat;