﻿#pragma once
#include "define.h"

class Camera
{
public:
	Camera();
	Camera(int, int);
	~Camera();;

	//center of camera
	void setPositisonWorld(int, int);
	void setPositisonWorld(Vec3);

	void setSpeed(float);

	// Xet vi tri tiep theo cua camera
	void setNextPositisonWorld(int, int);
	void setNextPositisonWorld(Vec3);

	void addNextPositisonWorld(Vec3);
	void addNextPositisonWorld(int, int);

	void setPositionWorld_X(int);
	void setPositionWorld_Y(int);

	void setSizeWindow(int, int);

	int getWidth();
	int getHeight();

	void setSizeMap(int, int);

	void update(float);

	D3DXVECTOR3 getPositionWorld();

	// get Bouding view port trong world
	RECT getBounding();

	// Kiem tra xem rect nay co nam trong map ko ?
	bool isContain(RECT);

private:

	// Mac dinh la pos center cua map
	Vec2 _positionWorld;
	// Pos mốc để camera di chuyển tịnh tiến 
	Vec2 _nextPosWorld;

	// Vân tốc cam di chuyển
	float _speed;

	bool _isMoving;

	int _width;
	int _height;

	int _mapWidth;
	int _mapHeight;

};

typedef Camera* pCamera;

