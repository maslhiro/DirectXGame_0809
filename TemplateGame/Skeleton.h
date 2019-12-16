#pragma once
#include "GameObject.h"
#include "Bone.h"

class Skeleton :
	public GameObject
{
private:
	std::vector<pGameObject> _listObj;
	std::vector<pBone> _listBone;

	Vec3 posPlayer;

public:
	Skeleton();
	Skeleton(int);

	void setListObj(std::vector<pGameObject>);

	void loadResource();

	void setPosPlayer(Vec3);

	void render();

	void update(float);

	void handlerInput(float);
};

typedef Skeleton* pSkeleton;