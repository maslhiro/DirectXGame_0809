#pragma once
#include "Scene.h"

class FirstScene :
	public Scene
{
private:
	GameMap _map;
	pCamera _camera;

public:
	FirstScene();
	~FirstScene();

	void init();
	void loadResource();
	void update(float);
	void render();

	void updateInput(float);
	void release();
};

