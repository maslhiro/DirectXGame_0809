#pragma once
#include "GameObject.h"

class Bone :
	public GameObject
{
private:

	std::vector<pGameObject> _listObj;
	float _distance;

public:
	Bone();
	Bone(int);

	void setListObj(std::vector<pGameObject>);

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

typedef Bone* pBone;