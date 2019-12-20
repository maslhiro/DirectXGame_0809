#pragma once
#include "GameObject.h"

class JafarStar :
	public GameObject
{
private:
	float _distance;
	float _moveTime;
	float _explodeTime;
	bool _isUp;

	int t;

	// Vector chi phuong
	Vec3 _vector;
	Vec3 _initPos;
	Vec3 _posPlayer;

public:
	JafarStar();
	JafarStar(int);

	void setPosPlayer(Vec3);

	void setInitPos(Vec3);

	void loadResource();

	void render();

	void setExplode();

	void update(float);

	void handlerInput(float);

	bool checkCollisionPlayer(Vec3);
};

typedef JafarStar* pJafarStar;