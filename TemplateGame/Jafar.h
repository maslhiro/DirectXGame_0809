#pragma once
#include "GameObject.h"
#include "JafarFlame.h"
#include "JafarStar.h"

class Jafar :
	public GameObject
{
private:

	Vec3 posPlayer;

	std::vector<Animation> _fireBehind;

	std::vector<pJafarStar> _listStar;

	std::vector<pJafarFlame> _listFlame;

	float _throwTime;
	float _waitTime;

	bool _wait;

	int _numThrow;

	int _numBlood;

public:
	Jafar();
	Jafar(int);

	void setPosPlayer(Vec3);

	void loadResource();

	void getDamaged(int);

	int getNumBlood();

	int getState();

	void render();

	void update(float);

	void handlerInput(float);

	int checkCollisionStar(Vec3);

	bool checkCollisionFlame(RECT);
};

typedef Jafar* pJafar;

