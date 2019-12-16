#pragma once
#include "GameObject.h"
#include "Bone.h"

class Skeleton :
	public GameObject
{
private:
	std::vector<pGameObject> _listObj;
	std::vector<pBone> _listBone;

public:
	Skeleton();
	Skeleton(int);

	void setListObj(std::vector<pGameObject>);

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);
};

typedef Skeleton* pSkeleton;