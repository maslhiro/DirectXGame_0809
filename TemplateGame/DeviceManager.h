#pragma once
#include "define.h"
#include "Graphic.h"

class DeviceManager {

private:
	static DeviceManager* _instance;
	RECT _sizeWindow;

	LPDIRECT3D9			_pD3d;
	DirectDevice	_pDevice;
	DirectSurface	_backBuffer;
	DirectSprite _spriteHandler;

	DWORD  _colorLine;
	ID3DXLine *lineDraw;

public:
	DeviceManager();
	~DeviceManager();

	static DeviceManager* getInstance();
	static void release();
	void clearScreen();
	void present();

	int init(pGraphic);

	RECT getSizeWindow();

	DirectSprite getSpriteHandler();
	DirectDevice getDevice();
	DirectSurface getSurface();
	DirectSurface	getBackBuffer();
};

typedef DeviceManager *pDeviceManager;