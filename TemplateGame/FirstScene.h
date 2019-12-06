#pragma once
#include "Scene.h"
#include "Apple.h"
#include "GameMap.h"
#include "Aladdin.h"

class FirstScene :
	public Scene
{
private:

	GameMap _map;

	GameMap _mapAbove;

	pCamera _cam;

	pCamera _camAbove;

	pFixedGrid _grid;
	pAladdin _player;

public:
	FirstScene();
	~FirstScene();

	void init();
	void loadResource();
	void update(float);
	void render();

	void handlerInput(float);
	void release();
};

