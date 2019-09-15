#pragma once
#include "define.h"
#include "DeviceManager.h"

class Texture
{
private:
	pDeviceManager _device;

	static Texture * _instance;

	std::unordered_map<int, DirectTexture> _listTexture;

public:
	Texture();

	void init(pDeviceManager);

	void release();

	void add(eIdTexture, LPCWSTR, D3DCOLOR);

	DirectTexture get(unsigned int);

	static Texture * getInstance();
};

typedef Texture* pTexture;