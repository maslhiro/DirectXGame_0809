#pragma once
#include "define.h"
#include "DeviceManager.h"
#include "Texture.h"
#include "MapReader/Tmx.h.in"

// dinh dang file tmx 
// cac tileset dat trung voi id cua texture da load luc dau
// nen luc render chi can get name la biet base la texture nao
class GameMap
{
private:

	Tmx::Map *_map;
	pTexture _texture;
	pDeviceManager _device;

public:
	GameMap();
	~GameMap();
	void init();

	int getWidth();
	int getHeight();

	void load(char*);
	void release();

	void render();


};

typedef GameMap* pGameMap;

