#pragma once
#include "define.h"
#include "Entity.h"
#include "GameObject.h"

class Unit
{
public:
	Unit();

	void setIndex(int, int);
	void setSize(int, int);

	void setPosWorld(int, int);
	void setPosWorld(Vec3);


	Vec3 getPosWorld();
	RECT getBoudingUnit();

	// 2 ham test map
	void addEnity(pEntity);
	std::vector<pEntity> getListEntity();

	void addGameObj(pGameObject);
	std::vector<pGameObject> getListGameObj();
private:
	// So thu tu cua Unit
	int _x, _y;

	// Test map tmx
	// List entity trong Unit
	std::vector<pEntity> _listEntity;

	// List gameobject
	std::vector<pGameObject> _listGameObj;

	// vi tri center cua Unit
	Vec3 _posWorld;

	int _width, _height;


};

typedef Unit* pUnit;