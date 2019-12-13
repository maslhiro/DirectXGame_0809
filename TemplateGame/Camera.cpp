#include "Camera.h"

Camera::Camera()
{
	_width = 0;
	_height = 0;

	_mapWidth = 0;
	_mapHeight = 0;

	_speedX = _speedY = 140.f;

	_isMovingHorizontal = _isMovingVertical = false;

	_positionWorld = _nextPosWorld = Vec2();
}

Camera::Camera(int width, int height)
{
	_width = width;
	_height = height;

	_mapWidth = 0;
	_mapHeight = 0;

	_speedX = _speedY = 140.f;

	_isMovingHorizontal = _isMovingVertical = false;
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

void Camera::setSpeedX(float val)
{
	_speedX = val;
}

void Camera::setSpeedY(float val)
{
	_speedY = val;
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

int Camera::getMapWidth()
{
	return _mapWidth;
}

int Camera::getMapHeight()
{
	return _mapHeight;
}

void Camera::setSizeMap(int _mW, int _mH)
{
	_mapWidth = _mW;
	_mapHeight = _mH;
}

void Camera::update(float dt)
{
	// Cam ko di chuyen
	if (_positionWorld == _nextPosWorld) return;

	// Check cam có đang ở 4 cạnh của map ko ?

	// do map  t cat bi du -_- 1 khoang nên mới có cái distance này bù vào
	float distance_ = 60.;

	if ((_nextPosWorld.x > _width / 2. + distance_) && (_nextPosWorld.x < (_mapWidth - _width / 2 - distance_)))
	{
		if (_isMovingHorizontal)
		{
			if (_nextPosWorld.x > _positionWorld.x)
			{
				_positionWorld += Vec2(_speedX*dt, 0);
			}
			else if (_nextPosWorld.x < _positionWorld.x)
			{
				_positionWorld -= Vec2(_speedX*dt, 0);
			}

			//_RPT0(0, "==================================\n");
			//_RPT1(0, "[ CAM ] NEXT %f\n", _nextPosWorld.x);
			//_RPT1(0, "[ CAM ] CUR %f\n", _positionWorld.x);
			//_RPT0(0, "==================================\n");

			if (abs(_nextPosWorld.x - _positionWorld.x) <= DISTANCE_X)
			{
				_isMovingHorizontal = false;
				//_RPT1(0, "== [ CAM ] == MOVING DONE %f\n", _nextPosWorld.x);
				_nextPosWorld.x = _positionWorld.x;
			}
		}
		else if (abs(_nextPosWorld.x - _positionWorld.x) > DISTANCE_X)
		{
			_isMovingHorizontal = true;
		}
	}

	if ((_nextPosWorld.y > _height / 2.) && (_nextPosWorld.y < (_mapHeight - _height / 2)))
	{

		if (_isMovingVertical)
		{

			if (_nextPosWorld.y > _positionWorld.y)
			{
				_positionWorld += Vec2(0, _speedY*dt);
			}
			else if (_nextPosWorld.y < _positionWorld.y)
			{
				_positionWorld -= Vec2(0, _speedY*dt);
			}
			//_RPT0(0, "==================================\n");
			//_RPT1(0, "[ CAM ] NEXT %f\n", _nextPosWorld.x);
			//_RPT1(0, "[ CAM ] CUR %f\n", _positionWorld.x);
			//_RPT0(0, "==================================\n");

			if (abs(_nextPosWorld.y - _positionWorld.y) <= DISTANCE_Y)
			{
				_isMovingVertical = false;
				//_RPT1(0, "== [ CAM ] == MOVING DONE %f\n", _nextPosWorld.x);
				_nextPosWorld.y = _positionWorld.y;
			}
		}
		else if (abs(_nextPosWorld.y - _positionWorld.y) > DISTANCE_Y)
		{
			_isMovingVertical = true;
		}
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
