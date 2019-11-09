#pragma once
#include "Unit.h"
#include "MapReader/Tmx.h.in"

class FixedGrid
{
private:

	int _widthUnit, _heightUnit;

	// Kiem tra grid da dc load chua ?
	bool _isLoaded;

public:

	Unit _cell[20][10];

	static const int NUM_X = 20;
	static const int NUM_Y = 10;

	FixedGrid();

	void init(Tmx::Map*);

	void setWidthUnit(int);
	void setHeightUnit(int);
	void setIsLoaded(bool);

	// Tra ve list Unit cotain voi RECT
	std::vector<Unit> getUnitsContain(RECT);

	Unit getUnit(int, int);
};

typedef FixedGrid* pFixedGrid;