#pragma once
#include "Scene.h"
#include "Apple.h"
#include "GameMap_Txt.h"
#include "Aladin.h"

class FirstScene :
	public Scene
{
private:

	GameMap_Txt _map2;
	pCamera _camera;

	pFixedGrid _grid;
	pAladin _player;

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

