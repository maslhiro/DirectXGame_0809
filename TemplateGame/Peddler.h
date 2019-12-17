#pragma once
#include "GameObject.h"

class Peddler :
	public GameObject
{
private:
	Vec3 posPlayer;

	std::unordered_map<int, Animation> _listChar;

	std::vector<Animation> _curChar;

	int _numBlood;
	float _timeShow;
	bool _isFlash;
	float _timeFlash;

public:
	Peddler();
	Peddler(int);

	void setPosPlayer(Vec3);

	void loadResource();

	void buySuccess();

	void buyFail();

	int getState();

	void render();

	void fixPosBottom(int);

	void update(float);

	void handlerInput(float);
};

typedef Peddler* pPeddler;