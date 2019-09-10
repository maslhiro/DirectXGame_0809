#include "GameObject.h"

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::setPosition(Vec3 pos) {
	this->_pos = pos;
}

void GameObject::setPosition(Vec2 pos) {
	this->_pos = Vec3(pos.x, pos.y, 0);
}

void GameObject::setPosition(float x, float y) {
	this->setPosition(Vec2(x, y));
}


int GameObject::draw() {
	_device->getSpriteHandler()->Draw(_texture, NULL, NULL, &_pos, D3DCOLOR_XRGB(255, 255, 255));
	return 1;
}

int Tank::init(pDeviceManager device) {

	this->setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	this->_device = device;

	D3DXIMAGE_INFO _info;
	HRESULT result = D3DXGetImageInfoFromFile(L"logo.png", &_info);

	result = D3DXCreateTextureFromFileEx(
		this->_device->getDevice(),								// Pointer to Direct3D device object
		L"logo.png",					// Path to the image to load
		_info.Width,							// Texture width
		_info.Height,						// Texture height
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(0, 0, 0),			// Transparent color
		&_info,
		NULL,
		&_texture);

	return 1;
}


int Tank::update() {

	if (_pos.x < SCREEN_WIDTH) this->_pos.x += 0.5;
	else _pos.x = 0;

	return 1;
}