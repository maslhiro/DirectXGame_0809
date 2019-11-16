#pragma once
#include "GameObject.h"
#include "Camera.h"
#include "FixedGrid.h"

class Aladin :
	public GameObject
{
private:

	pFixedGrid _grid;

	pInputHandler _input;
	std::unordered_map<int, bool> _keys;

	// Pos voi viewPort
	Vec3 _pos;

	// Bien bool check Player da dung tren mat dat chua
	bool _isOnGround;
public:
	Aladin();

	void setPosView(Vec3);
	void setPosView(int, int);

	Vec3 getPosView();

	void setGrid(pFixedGrid);

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);

	// Update dong thoi posView va posWorld
	void updateAllPos(Vec3);
};

typedef Aladin* pAladin;