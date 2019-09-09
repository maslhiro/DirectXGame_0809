#pragma once
#include "define.h"
#include "Graphic.h"

class DeviceManager {

private:
	static DeviceManager* _instance;
	LPDIRECT3D9			_pD3d;
	LPDIRECT3DDEVICE9	_pDevice;
	LPDIRECT3DSURFACE9	_backBuffer;
	LPD3DXSPRITE _spriteHandler;
public:
	DeviceManager(void);
	~DeviceManager(void);

	static DeviceManager* getInstance();
	static void release();
	void clearScreen();
	void present();

	int init(pGraphic);

	LPD3DXSPRITE getSpriteHandler();
	LPDIRECT3DDEVICE9 getDevice();
	LPDIRECT3DSURFACE9 getSurface();
	LPDIRECT3DSURFACE9	getBackBuffer();
};

typedef DeviceManager *pDeviceManager;