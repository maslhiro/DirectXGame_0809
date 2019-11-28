#include "Tile.h"

Tile::Tile()
{
	_x = _y = _idTile = 0;
}


Tile::~Tile()
{
}

int Tile::getTileId()
{
	return _idTile;
}

void Tile::setTileId(int val)
{
	_idTile = val;
}

Vec3 Tile::getPosWorld()
{
	return _posWorld;
}

void Tile::setPosWorld(Vec3 val)
{
	_posWorld = val;
}

void Tile::setPosWorld(int x, int y)
{
	_posWorld = Vec3((float)x, (float)y, 0);
}

