﻿#pragma once
#include "define.h"

class Camera
{
public:
	Camera();
	Camera(float, float);
	~Camera();;

	//center of camera
	void setPositisonWorld(float, float);
	void setPositisonWorld(Vec3);

	void setPositionWorld_X(float);
	void setPositionWorld_Y(float);

	void setSizeWindow(int, int);

	int getWidth();
	int getHeight();

	D3DXVECTOR3 getPositionWorld();

	// get Bouding view port trong world
	RECT getBounding();

	// Kiem tra xem rect nay co nam trong map ko ?
	bool isContain(RECT);

private:

	// Mac dinh la pos center cua map
	Vec2 _positionWorld;

	int _width;
	int _height;

};

typedef Camera* pCamera;
