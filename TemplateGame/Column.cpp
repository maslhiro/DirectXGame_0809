#include "Column.h"

Column::Column() :GameObject()
{
	_isStaticObj = true;
	_idType = eIdObject::COLUMN;
}

void Column::loadResource()
{

}

void Column::render()
{
	auto _devive = DeviceManager::getInstance();
	auto _texture = Texture::getInstance();

	RECT bound;

	bound.left = 0;
	bound.right = getBoundingBox().right - getBoundingBox().left;
	bound.top = 0;
	bound.bottom = getBoundingBox().bottom - getBoundingBox().top;

	_device->getSpriteHandler()->Draw(_texture->get(eIdTexture::BOX_GRAY_TEX), &bound, NULL, &Vec3(getBoundingBox().left, getBoundingBox().top, 0), D3DCOLOR_ARGB(255, 255, 255, 255));

}

void Column::update(float dt)
{

}

void Column::handlerInput(float)
{
}
