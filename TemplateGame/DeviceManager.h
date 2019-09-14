#pragma once
#include "define.h"
#include "Graphic.h"

class DeviceManager {

private:
	static DeviceManager* _instance;
	LPDIRECT3D9			_pD3d;
	DirectDevice	_pDevice;
	DirectSurface	_backBuffer;
	DirectSprite _spriteHandler;
public:
	DeviceManager(void);
	~DeviceManager(void);

	static DeviceManager* getInstance();
	static void release();
	void clearScreen();
	void present();

	int init(pGraphic);

	DirectSprite getSpriteHandler();
	DirectDevice getDevice();
	DirectSurface getSurface();
	DirectSurface	getBackBuffer();
};

typedef DeviceManager *pDeviceManager;