#pragma once
#include "Unit.h"
#include "MapReader/Tmx.h.in"

class FixedGrid
{
private:
	Unit _cell[50][50];
public:
	FixedGrid();

	void init(Tmx::Map*);

	Unit getUnit(int, int);
	// De mac dinh tam vay
	static const int NUM_CELLS = 50;
	static const int CELL_SIZE = 50;

};

typedef FixedGrid* pFixedGrid;