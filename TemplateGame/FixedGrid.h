#pragma once
#include "Unit.h"

#pragma region List GAME OBJ

#include "GameObject.h"

#include "Apple.h"
#include "AppleThrow.h"
#include "Ground.h"
#include "GroundFire.h"
#include "Spike.h"
#include "Peddler.h"
#include "Column.h"
#include "Bat.h"
#include "Rope.h"
#include "Nahbi.h"
#include "Fazal.h"
#include "Jafar.h"
#include "SavePoint.h"
#include "ExtraHealth.h"
#include "Skeleton.h"
#include "Rock.h"
#include "GenieHead.h"
#include "Coin.h"
#include "WreckingBall.h"
#include "ExitDoor.h"
#include "StoneColumn_1.h"
#include "StoneColumn_2.h"
#include "StoneColumn_3.h"
#include "StoneColumn_4.h"

#pragma endregion

#pragma region STRUCT UNIT TEMP
// dung de luu id tu file grid.txt
struct UnitTemp
{
	int x, y, idObj;
};

#pragma endregion


class FixedGrid
{
private:

	// Info map 
	int _mapWidth, _mapHeight, _numObj;

	// 
	int _numX, _numY;

	// Kiem tra grid da dc load chua ?
	bool _isLoaded;

	Vec3 _posWorld_PLAYER;

	// Path file grid lưu lại và load lên lúc init
	char* _fileSavePath;

	// List static obj như => 
	std::vector<pGameObject> _listStaticObj;

public:

	Unit _cell[25][17];

	// Mang tam de luu id cac ganobj tu grid.txt khi init
	std::vector<UnitTemp> _cellTemp;

	FixedGrid();

	// Load grid tu file txt neu pathfile hop le
	void init();

	// Doc file OBJ TXT => gan cac obj vao unit
	// Sau do ktra _isLoaded de biet dc da load grid chua 
	// Neu load roi thi => doc dong dau tien sau do return 
	void load(const char*);

	Vec3 getPosWorld_PLAYER();

	int getNumX();
	int getNumY();

	void setIsLoaded(bool);
	void setPathTxt(char*);

	// Tra ve list Unit cotain voi RECT
	std::vector<Unit> getUnitsContain(RECT);

	std::vector<pGameObject> getListGameObjContain(RECT);
	Unit getUnit(int, int);
};

typedef FixedGrid* pFixedGrid;