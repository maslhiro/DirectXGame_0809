#pragma once
#include "define.h"

class Tile
{
public:
	Tile();
	~Tile();

	int getTileId();
	void setTileId(int);
	Vec3 getPosWorld();
	void setPosWorld(Vec3);
	void setPosWorld(int, int);
	// Toa do game
	Vec3 _posWorld;

	// cell X,Y trong ma tran
	int _x, _y;

	// id Tile trong tile set da load ban dau
	int _idTile;
};

