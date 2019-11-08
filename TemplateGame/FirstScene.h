#pragma once
#include "Scene.h"
#include "Player.h"
#include "Apple.h"
#include "GameMap_Txt.h"

class FirstScene :
	public Scene
{
private:
	//GameMap _map;
	GameMap_Txt _map2;
	pCamera _camera;

	//pGameObject _apple;

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

