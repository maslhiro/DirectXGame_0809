#pragma once
#include "GameObject.h"

class Fazal :
	public GameObject
{
private:
	Vec3 posPlayer;

	int _numBlood;
public:
	Fazal();
	Fazal(int);

	void setPosPlayer(Vec3);

	void loadResource();

	void getDamaged(int);

	int getState();

	void render();

	void update(float);

	void handlerInput(float);
};

typedef Fazal* pFazal;

