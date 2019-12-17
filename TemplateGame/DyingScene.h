#pragma once
#include "Scene.h"

class DyingScene :
	public Scene
{
private:


public:
	DyingScene();
	~DyingScene();

	void init();
	void loadResource();
	void update(float);
	void render();

	void handlerInput(float);
	void release();
};

