#pragma once
#include "Scene.h"
#include "Player.h"

class FirstScene :
	public Scene
{
private:
	GameMap _map;
	pCamera _camera;


	Player _player;
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

