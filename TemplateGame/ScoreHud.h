#pragma once
#include "GameObject.h"

class ScoreHud : GameObject
{
private:
	int _numScore;
	std::vector<Animation> _listScore;
public:

	ScoreHud();
	~ScoreHud();

	void loadResource();

	void setNumScore(int);

	void render();

	void update(float);

	void handlerInput(float) {};
};

typedef ScoreHud* pScoreHud;
