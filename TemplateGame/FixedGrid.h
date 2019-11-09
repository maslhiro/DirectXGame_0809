#pragma once
#include "Unit.h"

#pragma region List GAME OBJ

#include "GameObject.h"

#include "Apple.h"
#include "Land.h"
#include "WreckingBall.h"
#include "StoneColumn_1.h"
#include "StoneColumn_2.h"
#include "StoneColumn_3.h"
#include "StoneColumn_4.h"

#pragma endregion

class FixedGrid
{
private:

	int _widthUnit, _heightUnit;

	// Info map 
	int _textureMapId, _mapWidth, _mapHeight;

	// Kiem tra grid da dc load chua ?
	bool _isLoaded;

public:

	Unit _cell[20][10];

	static const int NUM_X = 20;
	static const int NUM_Y = 10;

	FixedGrid();

	// Tao grid tu 1 file txt cho truoc
	void init(const char*);

	// Doc file map txt => info map : idTexture, mapW, mapH, unitW, unitH
	// Sau do ktra _isLoaded de biet dc da load grid chua 
	// Neu load roi thi => doc dong dau tien sau do return 
	void load(const char*);

	// Luu lai grid xuong file txt o duong dan mac dinh
	void save();

	int getWidthUnit();
	int getHeightUnit();
	int getIdTextureMap();
	int getMapWidth();
	int getMapHeight();

	void setIsLoaded(bool);

	// Tra ve list Unit cotain voi RECT
	std::vector<Unit> getUnitsContain(RECT);

	Unit getUnit(int, int);
};

typedef FixedGrid* pFixedGrid;