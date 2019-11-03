#pragma once
#include "define.h"
#include "Entity.h"

class Unit
{
public:
	Unit();
	void setIndex(int, int);

	void addEnity(pEntity);
	std::vector<pEntity> getListEntity();

private:
	// So thu tu cua Unit
	int _x, _y;

	// List entity trong Unit
	std::vector<pEntity> _listEntity;

};

typedef Unit* pUnit;