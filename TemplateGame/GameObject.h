#pragma once
#include "define.h"
#include "DeviceManager.h"

class GameObject
{
protected:
	Vec3 _pos;
	pDeviceManager _device;
	LPDIRECT3DTEXTURE9 _texture;
public:

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