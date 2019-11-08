#include "Unit.h"

Unit::Unit()
{
	_width = _height = 0;
}

void Unit::setIndex(int x, int y)
{
	_x = x;
	_y = y;
}

void Unit::setSize(int width, int height)
{
	this->_height = height;
	this->_width = width;
}

void Unit::setPosWorld(int x, int y)
{
	_posWorld = Vec3((float)x, (float)y, 0);
}

void Unit::setPosWorld(Vec3 pos)
{
	_posWorld = pos;
}

Vec3 Unit::getPosWorld()
{
	return _posWorld;
}

RECT Unit::getBoudingUnit()
{
	RECT rect;

	rect.left = (int)_posWorld.x;
	rect.right = (int)_posWorld.x + _width;
	rect.top = (int)_posWorld.y;
	rect.bottom = (int)_posWorld.y + _height;

	//rect.left = (int)_posWorld.x - _width / 2;
	//rect.right = (int)_posWorld.x + _width / 2;
	//rect.top = (int)_posWorld.y - _height / 2;
	//rect.bottom = (int)_posWorld.y + _height / 2;

	return rect;
}

void Unit::addEnity(pEntity entity)
{
	_listEntity.push_back(entity);
}

std::vector<pEntity> Unit::getListEntity()
{
	return _listEntity;
}

void Unit::addGameObj(pGameObject gameObj)
{
	_listGameObj.push_back(gameObj);
}

std::vector<pGameObject> Unit::getListGameObj()
{
	return _listGameObj;
}
