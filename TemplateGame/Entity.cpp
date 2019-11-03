#include "Entity.h"



Entity::Entity()
{
	_pos = Vec3(0, 0, 0);
	_drawingBound = false;
}


Entity::~Entity()
{
}

void Entity::setDrawingBound(bool val)
{
	_drawingBound = val;
}

void Entity::setPos(Vec3 pos)
{
	_pos = pos;
}

void Entity::setPos(int x, int y)
{
	_pos = Vec3((float)x, (float)y, 0);
}

void Entity::render()
{
	auto _spriteHandler = DeviceManager::getInstance()->getSpriteHandler();
	auto _texture = Texture::getInstance();

	RECT rect;

	rect.left = 0;
	rect.top = 0;
	rect.right = 50;
	rect.bottom = 50;

	Vec3 center = Vec3(25, 25, 0);

	if (_drawingBound)
	{

		RECT rectDrawing;

		rectDrawing.left = 0;
		rectDrawing.top = 0;
		rectDrawing.right = 50 + BBOX_WIDTH;
		rectDrawing.bottom = 50 + BBOX_WIDTH;

		Vec3 centerDrawing = Vec3(rectDrawing.right / 2, rectDrawing.bottom / 2, 0);

		_spriteHandler->Draw(_texture->get(eIdTexture::BOX_GREEN_TEX),
			&rectDrawing,
			&centerDrawing,
			&_pos,
			D3DCOLOR_ARGB(255, 255, 255, 255)); // nhung pixel nao co mau trang se duoc to mau nay len
	}

	_spriteHandler->Draw(_texture->get(eIdTexture::BOX_RED_TEX),
		&rect,
		&center,
		&_pos,
		D3DCOLOR_ARGB(255, 255, 255, 255)); // nhung pixel nao co mau trang se duoc to mau nay len

}

void Entity::update(float)
{
}
