#pragma once
#include "GameObject.h"

class CoinHud : GameObject
{
private:
	int _numCoin;
	Animation _cha01, _cha02;
public:

	CoinHud();
	~CoinHud();

	void loadResource();

	void setNumCoin(int);

	void render();

	void update(float);

	void handlerInput(float) {};
};

typedef CoinHud* pCoinHud;
