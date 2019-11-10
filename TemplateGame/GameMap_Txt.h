#pragma once
#include "define.h"
#include "DeviceManager.h"
#include "Texture.h"
#include "Camera.h"
#include "FixedGrid.h"

#pragma region List GAME OBJ

#include "GameObject.h"

#include "Apple.h"
#include "Land.h"
#include "WreckingBall.h"
#include "StoneColumn_1.h"
#include "StoneColumn_2.h"
#include "StoneColumn_3.h"
#include "StoneColumn_4.h"

#pragma endregion


class GameMap_Txt
{

private:

	pTexture _texture;
	pDeviceManager _device;
	pInputHandler _input;

	pCamera _camera;
	pFixedGrid _grid;

	Vec2 _scale;

	// Thong tin map
	int _textureMapId, _mapWidth, _mapHeight, _tileWidth, _tileHeight;

public:
	GameMap_Txt();
	~GameMap_Txt();

	void init();

	void setCamera(pCamera);
	void setScale(Vec2);
	void setScale(float);
	void setGrid(pFixedGrid);

	int getWidth();
	int getHeight();

	int getTileWidth();
	int getTileHeight();

	pFixedGrid getGrid();

	pCamera getCamera();

	void load(const char*);

	void release();

	void render();

	// render cac obj nam tren player va map
	void renderAbove();

	void update(float);

};

typedef GameMap_Txt* pGameMap_Txt;