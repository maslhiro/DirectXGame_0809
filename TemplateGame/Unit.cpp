#include "Unit.h"

Unit::Unit()
{
}

void Unit::setIndex(int x, int y)
{
	_x = x;
	_y = y;
}

void Unit::addEnity(pEntity entity)
{
	_listEntity.push_back(entity);
}

std::vector<pEntity> Unit::getListEntity()
{
	return _listEntity;
}
