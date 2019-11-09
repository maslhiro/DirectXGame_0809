#pragma once
#include "define.h"
#include "DeviceManager.h"
#include "Texture.h"
#include "Camera.h"
#include "FixedGrid.h"

#pragma region List GAME OBJ

#include "GameObject.h"

#include "Apple.h"
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

	// Pos player
	Vec3 _posWorld_Player;

public:
	GameMap_Txt();
	~GameMap_Txt();

	void init();

	void setCamera(pCamera);
	void setScale(Vec2);
	void setScale(float);

	int getWidth();
	int getHeight();

	int getTileWidth();
	int getTileHeight();

	Vec3 getPosWorld_PLAYER();

	pCamera getCamera();

	void load(const char*);

	void release();

	void render();

	// render cac obj nam tren player va map
	void renderAbove();

	void update(float);

};

typedef GameMap_Txt* pGameMap_Txt;