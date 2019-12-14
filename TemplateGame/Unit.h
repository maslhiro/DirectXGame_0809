#pragma once
#include "define.h"
#include "GameObject.h"

class Unit
{
public:
	Unit();

	void setIndex(int, int);
	void setSize(int, int);

	void setPosWorld(int, int);
	void setPosWorld(Vec3);

	void getIndex(int&, int&);

	Vec3 getPosWorld();
	RECT getBoudingUnit();

	void addGameObj(pGameObject);
	std::vector<pGameObject> getListGameObj();


private:
	// So thu tu cua Unit
	int _x, _y;

	// List gameobject
	std::vector<pGameObject> _listGameObj;

	// vi tri center cua Unit
	Vec3 _posWorld;

	int _width, _height;


};

typedef Unit* pUnit;