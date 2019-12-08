#include "Rope.h"

Rope::Rope() :GameObject()
{
	_isStaticObj = true;
	_idType = eIdObject::ROPE;
}

void Rope::loadResource()
{

}

void Rope::render()
{
	auto _devive = DeviceManager::getInstance();
	auto _texture = Texture::getInstance();

	RECT bound;

	bound.left = 0;
	bound.right = getBoundingBox().right - getBoundingBox().left;
	bound.top = 0;
	bound.bottom = getBoundingBox().bottom - getBoundingBox().top;

	_device->getSpriteHandler()->Draw(_texture->get(eIdTexture::BOX_RED_TEX), &bound, NULL, &Vec3(getBoundingBox().left, getBoundingBox().top, 0), D3DCOLOR_ARGB(255, 255, 255, 255));
}

void Rope::update(float dt)
{

}

void Rope::handlerInput(float)
{
}
