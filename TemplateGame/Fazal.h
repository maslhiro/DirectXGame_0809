#pragma once
#include "GameObject.h"

class Fazal :
	public GameObject
{
private:
	float _posX;

	int _numBlood;
public:
	Fazal();
	Fazal(int);

	void setPosXPlayer(float);

	void loadResource();

	void getDamaged(int);

	int getState();

	void render();

	void update(float);

	void handlerInput(float);
};

typedef Fazal* pFazal;

