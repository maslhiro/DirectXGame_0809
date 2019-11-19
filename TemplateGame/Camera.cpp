﻿#include "Camera.h"

Camera::Camera()
{
	_width = 0;
	_height = 0;

	_mapWidth = 0;
	_mapHeight = 0;

	_speed = 140.f;

	_isMoving = false;

	_positionWorld = _nextPosWorld = Vec2();
}

Camera::Camera(int width, int height)
{
	_width = width;
	_height = height;

	_mapWidth = 0;
	_mapHeight = 0;

	_speed = 140.f;

	_isMoving = false;

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

void Camera::setSpeed(float val)
{
	_speed = val;
}

void Camera::setNextPositisonWorld(int x, int y)
{
	//_RPT1(0, "[ CAM ] SET NEXT POS %d\n", x);
	//_RPT1(0, "[ CAM ] CUR POS %f\n", _positionWorld.x);
	_nextPosWorld = Vec2((float)x, (float)y);
}

void Camera::setNextPositisonWorld(Vec3 pos)
{
	_nextPosWorld = Vec2(pos.x, pos.y);
}

void Camera::addNextPositisonWorld(Vec3 pos)
{
	_nextPosWorld += Vec2(pos.x, pos.y);
}

void Camera::addNextPositisonWorld(int x, int y)
{
	_nextPosWorld += Vec2((float)x, (float)y);
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

void Camera::setSizeMap(int _mW, int _mH)
{
	_mapWidth = _mW;
	_mapHeight = _mH;
}

void Camera::update(float dt)
{
	if (_positionWorld == _nextPosWorld) return;

	// Không cho cam ra khỏi map
	if (_nextPosWorld.x < (_width * 2.0 / 3.0))
	{
		_nextPosWorld.x = ((float)_width) * 2.0 / 3.0;
	}
	if (_nextPosWorld.x > (_mapWidth - _width / 2))
	{
		_nextPosWorld.x = (float)(_mapWidth - _width) / 2.0;
	}

	if (_isMoving)
	{

		if (_nextPosWorld.x > _positionWorld.x)
		{
			_positionWorld += Vec2(_speed*dt, 0);
		}
		else if (_nextPosWorld.x < _positionWorld.x)
		{
			_positionWorld -= Vec2(_speed*dt, 0);
		}

		//_RPT0(0, "==================================\n");
		//_RPT1(0, "[ CAM ] NEXT %f\n", _nextPosWorld.x);
		//_RPT1(0, "[ CAM ] CUR %f\n", _positionWorld.x);
		//_RPT0(0, "==================================\n");

		if (abs(_nextPosWorld.x - _positionWorld.x) <= DISTANCE_X)
		{
			_isMoving = false;
			//_RPT1(0, "== [ CAM ] == MOVING DONE %f\n", _nextPosWorld.x);
			_nextPosWorld = _positionWorld;
		}
	}
	else if (abs(_nextPosWorld.x - _positionWorld.x) > DISTANCE_X)
	{
		_isMoving = true;
	}


}

D3DXVECTOR3 Camera::getPositionWorld()
{
	return _positionWorld;
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
