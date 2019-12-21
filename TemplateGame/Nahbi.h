#pragma once
#include "GameObject.h"
#include "Sound.h"

class Nahbi :
	public GameObject
{
private:
	Vec3 posPlayer;
	float _waitTime;

	// chi cho di qua trai va qua phai 1 lan 
	bool _isMovedLeft;
	bool _isMovedRight;

	// quang duong ma nahbi da di
	float _distanceMove;

	int _numBlood;

public:
	Nahbi();
	Nahbi(int);

	void setPosPlayer(Vec3);

	void loadResource();

	void getDamaged(int);

	int getState();

	void render();

	void update(float);

	void handlerInput(float);
};

typedef Nahbi* pNahbi;

