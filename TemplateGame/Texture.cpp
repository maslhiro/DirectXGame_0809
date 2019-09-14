﻿#include "Texture.h"

Texture * Texture::_instance = nullptr;

Texture::Texture()
{

}

Texture *Texture::getInstance()
{
	if (_instance == nullptr) _instance = new Texture();
	return _instance;
}

void Texture::init(pDeviceManager device) {
	this->_device = device;
}

void Texture::add(int id, LPCWSTR filePath, D3DCOLOR transparentColor)
{
	D3DXIMAGE_INFO info;
	HRESULT result = D3DXGetImageInfoFromFile(filePath, &info);

	if (result != D3D_OK)
	{
		_RPT1(0, "[ERROR] GetImageInfoFromFile failed: %s\n", filePath);
		return;
	}

	DirectDevice d3ddv = _device->getDevice();
	DirectTexture texture;

	result = D3DXCreateTextureFromFileEx(
		d3ddv,								// Pointer to Direct3D device object
		filePath,							// Path to the image to load
		info.Width,							// Texture width
		info.Height,						// Texture height
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparentColor,                  // màu nền của ảnh
		&info,
		NULL,
		&texture);								// Created texture pointer

	if (result != D3D_OK)
	{
		_RPT0(0, "[ERROR] CreateTextureFromFile failed\n");
		return;
	}

	_listTexture[id] = texture;
	_RPT1(0, "[INFO] Texture loaded Ok : id = %d, %s \n", id, filePath);
}

LPDIRECT3DTEXTURE9 Texture::get(unsigned int i)
{
	return _listTexture[i];
}

void Texture::release()
{
	delete _instance;
	_instance = nullptr;
}



