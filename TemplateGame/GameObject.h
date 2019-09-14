#pragma once
#include "define.h"
#include "DeviceManager.h"

class GameObject
{
protected:
	int _id;
	Vec3 _pos;
	pDeviceManager _device;
	DirectTexture _texture;
public:

	int getId();
	void setId(int);

	void setPosition(Vec3);
	void setPosition(Vec2);
	void setPosition(float, float);

	virtual int init(pDeviceManager) = 0;
	int draw();
	virtual int update() = 0;

	GameObject();
	~GameObject();
};

typedef GameObject* pGameObject;

class Tank : public GameObject
{
public:
	int init(pDeviceManager);
	int update();
};

typedef Tank* pTank;