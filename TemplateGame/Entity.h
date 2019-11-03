#pragma once
#include "define.h"
#include "DeviceManager.h"
#include "Texture.h"

class Entity
{
public:
	Entity();
	~Entity();

	void setDrawingBound(bool);

	void setPos(Vec3);
	void setPos(int, int);

	void render();

	void update(float);

private:

	bool _drawingBound;
	Vec3 _pos;
};

typedef Entity* pEntity;