#include "Land.h"

Land::Land() :GameObject()
{
	_isStaticObj = true;
	_idType = eIdObject::LAND;
}

void Land::loadResource()
{

}

void Land::render()
{
	//auto _devive = DeviceManager::getInstance();
	//auto _texture = Texture::getInstance();

	//RECT bound;

	//bound.left = 0;
	//bound.right = getBoudingBox().right - getBoudingBox().left;
	//bound.top = 0;
	//bound.bottom = getBoudingBox().bottom - getBoudingBox().top;

	//// Render test
	//_device->getSpriteHandler()->Draw(_texture->get(eIdTexture::BOX_RED_TEX), &bound, NULL, &Vec3(getBoudingBox().left, getBoudingBox().top, 0), D3DCOLOR_ARGB(255, 255, 255, 255));
}

void Land::update(float dt)
{

}

void Land::handlerInput(float)
{
}
