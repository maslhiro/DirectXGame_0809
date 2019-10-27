#pragma once
#include "define.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	bool virtual init() = 0;
	void virtual updateInput(float dt) = 0;
	void virtual update(float dt) = 0;
	void virtual render(LPD3DXSPRITE spriteHandle) = 0;
	void virtual release() = 0;

	bool isInit();
protected:
	bool _isInit;
};

