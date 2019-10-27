#pragma once
#include "define.h"
#include "DeviceManager.h"
#include "Texture.h"
#include "Camera.h"
#include "MapReader/Tmx.h.in"

// dinh dang file tmx 
// cac tileset dat trung voi id cua texture da load luc dau
// nen luc render chi can get name la biet base la texture nao
// Hay ko :)))))

class GameMap
{
private:

	Tmx::Map *_map;
	pTexture _texture;
	pDeviceManager _device;
	pInputHandler _input;

	pCamera _camera;

public:
	GameMap();
	~GameMap();

	void init();

	void setCamera(pCamera);

	int getWidth();
	int getHeight();

	void load(char*);

	void release();

	void render();

	void renderTileMap(int, RECT&, Vec3, Vec2, int, int);

	void update(float);

	void handlerInput(float);

};

typedef GameMap* pGameMap;

