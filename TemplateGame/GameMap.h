#pragma once
#include "define.h"
#include "DeviceManager.h"
#include "Texture.h"
#include "Camera.h"
#include "FixedGrid.h"

#pragma region List GAME OBJ

#include "GameObject.h"

#include "Aladin.h"

#include "Apple.h"
#include "Ground.h"
#include "WreckingBall.h"
#include "StoneColumn_1.h"
#include "StoneColumn_2.h"
#include "StoneColumn_3.h"
#include "StoneColumn_4.h"

#pragma endregion


class GameMap
{

private:

	pTexture _texture;
	pDeviceManager _device;
	pInputHandler _input;

	pCamera _camera;
	pFixedGrid _grid;

	Vec2 _scale;
	pAladin _player;

	// Thong tin map
	int _textureMapId, _textureMapAboveId, _mapWidth, _mapHeight, _tileWidth, _tileHeight;

public:
	GameMap();
	~GameMap();

	void init();

	void setIdTextureMapAbove(int);
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

	void setPointerPlayer(pAladin);

	void load(const char*);

	void release();

	void render();

	// render cac obj nam tren player va map
	void renderAbove();

	void update(float);

};

typedef GameMap* pGameMap;