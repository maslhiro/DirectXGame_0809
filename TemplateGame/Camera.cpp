#include "Camera.h"

Camera::Camera()
{
	_width = 0;
	_height = 0;
}

Camera::Camera(float width, float height)
{
	_width = width;
	_height = height;
}

Camera::~Camera()
{
}

void Camera::setPositisonWorld(float x, float y)
{
	_positionWorld = Vec2(x, y);
}

void Camera::setPositisonWorld(Vec3 pos)
{
	_positionWorld = Vec2(pos.x, pos.y);
}

void Camera::setPositionWorld_X(float x)
{
	_positionWorld = Vec2(x, _positionWorld.y);
}

void Camera::setPositionWorld_Y(float y)
{
	_positionWorld = Vec2(_positionWorld.x, y);
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

D3DXVECTOR3 Camera::getPositionWorld()
{
	return _positionWorld;
}

RECT Camera::getBounding()
{
	RECT _bounding;

	_bounding.left = _positionWorld.x - _width / 2;
	_bounding.top = _positionWorld.y - _height / 2;
	_bounding.right = _positionWorld.x + _width / 2;
	_bounding.bottom = _positionWorld.y + _height / 2;

	return _bounding;
}

bool Camera::isContain(RECT obj)
{
	RECT _map = getBounding();
	return !(obj.left > _map.right || obj.right < _map.left || obj.top > _map.bottom || obj.bottom < _map.top);
}
