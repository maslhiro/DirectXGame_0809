#pragma once
#include "GameObject.h"
#include "JafarFlame.h"

class Jafar :
	public GameObject
{
private:

	Vec3 posPlayer;

	std::vector<Animation> _fireBehind;

	std::vector<pJafarFlame> _listFlame;

	float _throwTime;

	int _numBlood;

public:
	Jafar();
	Jafar(int);

	void setPosPlayer(Vec3);

	void loadResource();

	void getDamaged(int);

	int getState();

	void render();

	void update(float);

	void handlerInput(float);

	bool checkCollisionFlame(RECT);
};

typedef Jafar* pJafar;

