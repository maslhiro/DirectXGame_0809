#pragma once
#include "GameObject.h"

class JafarStar :
	public GameObject
{
private:
	float _flyTime;

	bool _isFlyed;

	Vec3 _finalPos;
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