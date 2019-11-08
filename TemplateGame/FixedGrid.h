#pragma once
#include "Unit.h"
#include "MapReader/Tmx.h.in"

class FixedGrid
{
private:

public:

	Unit _cell[20][10];

	static const int NUM_X = 20;
	static const int NUM_Y = 10;

	FixedGrid();

	void init(Tmx::Map*);

	Unit getUnit(int, int);
};

typedef FixedGrid* pFixedGrid;