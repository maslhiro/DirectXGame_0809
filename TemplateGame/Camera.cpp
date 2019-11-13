#include "Camera.h"

Camera::Camera()
{
	_width = 0;
	_height = 0;

	_positionWorld = _nextPosWorld = Vec2();
}

Camera::Camera(int width, int height)
{
	_width = width;
	_height = height;

	_positionWorld = _nextPosWorld = Vec2();

}

Camera::~Camera()
{
}

void Camera::setPositisonWorld(int x, int y)
{
	_positionWorld = Vec2((float)x, (float)y);
	_nextPosWorld = _positionWorld;
}

void Camera::setPositisonWorld(Vec3 pos)
{
	_positionWorld = Vec2(pos.x, pos.y);
	_nextPosWorld = _positionWorld;
}

void Camera::setNextPositisonWorld(int x, int y)
{
	_nextPosWorld = Vec2((float)x, (float)y);
}

void Camera::setNextPositisonWorld(Vec3 pos)
{
	_nextPosWorld = Vec2(pos.x, pos.y);
}

void Camera::setPositionWorld_X(int x)
{
	_positionWorld = Vec2((float)x, _positionWorld.y);
	_nextPosWorld = _positionWorld;
}

void Camera::setPositionWorld_Y(int y)
{
	_positionWorld = Vec2(_positionWorld.x, (float)y);
	_nextPosWorld = _positionWorld;
}

void Camera::setSizeWindow(int width, int height)
{
	_width = width;
	_height = height;
}

int Camera::getWidth()
{
	return _width;
}

int Camera::getHeight()
{
	return _height;
}

void Camera::update(float dt)
{
	if (_positionWorld == _nextPosWorld) return;
}

D3DXVECTOR3 Camera::getPositionWorld()
{
	return this->_positionWorld;
}

RECT Camera::getBounding()
{
	RECT _bounding;

	_bounding.left = (int)_positionWorld.x - _width / 2;
	_bounding.top = (int)_positionWorld.y - _height / 2;
	_bounding.right = (int)_positionWorld.x + _width / 2;
	_bounding.bottom = (int)_positionWorld.y + _height / 2;

	return _bounding;
}

bool Camera::isContain(RECT obj)
{
	RECT _map = getBounding();
	return !(obj.left > _map.right || obj.right < _map.left || obj.top > _map.bottom || obj.bottom < _map.top);
}
