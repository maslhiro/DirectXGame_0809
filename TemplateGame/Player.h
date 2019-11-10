#pragma once
#include "define.h"
#include "DeviceManager.h"
#include "Texture.h"
#include "Camera.h"
#include "FixedGrid.h"

class Player
{
private:
	Vec3 _pos;
	Vec3 _posWorld;

	pInputHandler _input;
	pCamera _camera;
	pFixedGrid _grid;

public:
	Player();
	~Player();

	void setPos(int, int);
	void setPosWorld(int, int);

	void setPos(Vec3);
	void setPosWorld(Vec3);

	void setGrid(pFixedGrid);

	void setCamera(pCamera);

	bool checkCollision(RECT);

	RECT getBounding();

	void init();
	void render();
	void update(float);
	void handlerInput(float);
};

