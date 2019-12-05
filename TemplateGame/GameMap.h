#pragma once
#include "define.h"
#include "DeviceManager.h"
#include "Texture.h"
#include "Camera.h"
#include "FixedGrid.h"
#include "Tile.h"

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

	pCamera _cam;

	pFixedGrid _grid;

	Vec2 _scale;
	pAladin _player;

	// tileset cua map
	std::unordered_map<int, RECT> _tiles;

	std::vector<Tile> _map;
	// Thong tin map
	int _textureMapId, _textureMapAboveId, _mapWidth, _mapHeight;

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

	pFixedGrid getGrid();

	pCamera getCamera();

	void setPointerPlayer(pAladin);

	void loadGameObj(const char*);

	void loadTileSet(const char*);

	// Load Map txt ma tran 
	// set luon w, h cua game
	void load(const char*);

	std::vector<Tile> getMapContain(RECT);

	void release();

	void render();

	// render cac obj nam tren player va map
	void renderAbove();

	void update(float);

};

typedef GameMap* pGameMap;