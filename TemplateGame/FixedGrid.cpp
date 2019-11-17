#include "FixedGrid.h"
#define __STDC_WANT_LIB_EXT1__ 1

FixedGrid::FixedGrid()
{
	_widthUnit = _heightUnit = 0;
	_textureMapId = _mapWidth = _mapHeight = 0;
	_numX = _numY = _numObj = 0;
	_isLoaded = false;
	_posWorld_PLAYER = Vec3();
}

void FixedGrid::init()
{
	FILE* file;
	fopen_s(&file, _fileSavePath, "r");

	// File ko ton tai
	if (file == NULL) {
		setIsLoaded(false);
		return;
	}

	fclose(file);

}

void FixedGrid::load(const char* filePath)
{

#pragma region LOAD FILE TXT MAP || LUU LAI GRID TXT
	FILE* file;
	FILE* fileSave;

	fopen_s(&fileSave, _fileSavePath, "w+");
	fopen_s(&file, filePath, "r");


	if (file == NULL) {
		fclose(fileSave);
		return;
	}

	int countline = 0;

	while (!feof(file))
	{
		// Dong dau tien thong so map
		//
		// idTexture - mapW - mapH - tileW - tileH - objW - objH
		//

		if (countline == 0)
		{
			// Doc info cua map
			fscanf(file, "%d %d %d %d %d %d", &_textureMapId, &_mapWidth, &_mapHeight, &_widthUnit, &_heightUnit, &_numObj);

			// Tinh so num X, Y
			_numX = _mapWidth / _widthUnit;
			_numY = _mapHeight / _heightUnit;

			// Dong dau tien la thong tin cua grid
			// numX - numY - unitW - unitH - mapW - mapH 
			fprintf(fileSave, "%d\t%d\t%d\t%d\t%d\t%d\n", _numX, _numY, _widthUnit, _heightUnit, _mapWidth, _mapHeight);

			_RPT1(0, "[MAP TXT] %d %d %d %d %d %d \n", _textureMapId, _mapWidth, _mapHeight, _widthUnit, _heightUnit, _numObj);
		}
		else if (countline == 1)
		{
			int posx, posy;
			fscanf(file, "%d %d", &posx, &posy);
			_RPT1(0, "[MAP TXT - PLAYER ] %d %d \n", posx, posy);
			_posWorld_PLAYER = Vec3((float)posx, (float)posy, 0);
			if (_isLoaded) {
				return;
			}
		}
		else
		{
			int idTypeObj, idObj, posObj_X, posObj_Y, objW, objH;

			// Doc pos va idType cua cac obj
			fscanf(file, "%d %d %d %d %d %d", &idTypeObj, &idObj, &posObj_X, &posObj_Y, &objW, &objH);

			_RPT1(0, "[MAP TXT] Load OBJ: %d %d || ( %d , %d ) || w %d h %d \n", idTypeObj, idObj, posObj_X, posObj_Y, objW, objH);

			//Tu idTypeObj = > RECT = > BOUNDING cua obj do

			pGameObject _obj;

			switch (idTypeObj)
			{
			case eIdObject::APPLE:
			{
				_obj = new Apple();
				break;
			}
			case eIdObject::WRECKING_BALL:
			{
				_obj = new WreckingBall();
				break;
			}
			case eIdObject::STONE_COLUMN_1:
			{
				_obj = new StoneColumn_1();
				break;
			}
			case eIdObject::STONE_COLUMN_2:
			{
				_obj = new StoneColumn_2();
				break;
			}
			case eIdObject::STONE_COLUMN_3:
			{
				_obj = new StoneColumn_3();
				break;
			}
			case eIdObject::STONE_COLUMN_4:
			{
				_obj = new StoneColumn_4();
				break;
			}
			case eIdObject::LAND:
			{
				_obj = new Land();

				RECT rec;
				rec.left = posObj_X;
				rec.top = posObj_Y;
				rec.right = objW;
				rec.bottom = objH;
				_obj->setRectWorld(rec);

				break;
			}
			default:
				_obj = new Apple();
				break;
			}

			_obj->setId(idObj);
			_obj->loadResource();
			_obj->setScale(2.0f);
			_obj->setPositionWorld(posObj_X, posObj_Y);

			RECT rect = _obj->getBoundingBox();
			//_RPT1(0, "[MAP TXT] RECT OBJ : %d %d %d %d \n", rect.left, rect.top, rect.right, rect.bottom);

			// Kiem tra xem obj do nam o UNIT NAO
			Vec3 posLEFT_T = Vec3(rect.left, rect.top, 0);
			Vec3 posRIGHT_BT = Vec3(rect.right, rect.bottom, 0);

			int min_CellX = posLEFT_T.x / _widthUnit;
			int min_CellY = posLEFT_T.y / _heightUnit;

			int max_CellX = posRIGHT_BT.x / _widthUnit;
			int max_CellY = posRIGHT_BT.y / _heightUnit;

			for (int x = min_CellX; x <= max_CellX; x++)
			{
				for (int y = min_CellY; y <= max_CellY; y++)
				{
					this->_cell[x][y].addGameObj(_obj);

					if (countline == _numObj + 1 && x == max_CellX && y == max_CellY)
					{
						fprintf(fileSave, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d", x, y, idTypeObj, idObj, posObj_X, posObj_Y, objW, objH);
					}
					else fprintf(fileSave, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", x, y, idTypeObj, idObj, posObj_X, posObj_Y, objW, objH);

				}
			}
		}
		countline += 1;
	}

	fclose(file);
	fclose(fileSave);

#pragma endregion

#pragma region Chia Unit || Set Bounding Tung Unit
	int count = 0;
	int cellX = 0, cellY = 0;

	for (int x = 0; x < _mapWidth; x += _widthUnit)
	{
		for (int y = 0; y < _mapHeight; y += _heightUnit)
		{
			cellX = x / _widthUnit;
			cellY = y / _heightUnit;
			//_RPT1(0, "[INFO GRID] CELL x: %d y: %d \n", cellX, cellY);
			this->_cell[cellX][cellY].setIndex(cellX, cellY);
			this->_cell[cellX][cellY].setSize(_widthUnit, _heightUnit);
			this->_cell[cellX][cellY].setPosWorld(x, y);

			count++;
		}
	}

	_RPT1(0, "[MAP TXT] Num UNIT %d \n", count);

#pragma endregion

}

int FixedGrid::getWidthUnit()
{
	return _widthUnit;
}

int FixedGrid::getHeightUnit()
{
	return _heightUnit;
}

int FixedGrid::getIdTextureMap()
{
	return this->_textureMapId;
}

int FixedGrid::getMapWidth()
{
	return this->_mapWidth;
}

int FixedGrid::getMapHeight()
{
	return this->_mapHeight;
}

Vec3 FixedGrid::getPosWorld_PLAYER()
{
	return _posWorld_PLAYER;
}

int FixedGrid::getNumX()
{
	return this->_numX;
}

int FixedGrid::getNumY()
{
	return this->_numY;
}

void FixedGrid::setIsLoaded(bool val)
{
	this->_isLoaded = val;
}

void FixedGrid::setPathTxt(char *path)
{
	this->_fileSavePath = path;
}

std::vector<Unit> FixedGrid::getUnitsContain(RECT _view)
{
	std::vector<Unit> listUnit;
	// Lay ra Cac Unit contain voi viewport
	Vec3 posLEFT_T = Vec3(_view.left, _view.top, 0);
	Vec3 posRIGHT_BT = Vec3(_view.right, _view.bottom, 0);

	int min_CellX = posLEFT_T.x / _widthUnit;
	int min_CellY = posLEFT_T.y / _heightUnit;

	int max_CellX = posRIGHT_BT.x / _widthUnit;
	int max_CellY = posRIGHT_BT.y / _heightUnit;

	for (int x = min_CellX; x <= max_CellX; x++)
	{
		for (int y = min_CellY; y <= max_CellY; y++)
		{
			listUnit.push_back(_cell[x][y]);
		}
	}

	return listUnit;
}

std::vector<pGameObject> FixedGrid::getListGameObjContain(RECT r)
{
	std::vector<Unit> listUnit = getUnitsContain(r);
	std::vector<int> listId;
	std::vector<pGameObject> listGameObj;
	//_RPT0(0, "==================================\n");
	for (int i = 0; i < listUnit.size(); i++)
	{
		auto listObj = listUnit[i].getListGameObj();

		if (listObj.size() == 0) continue;

		for (int j = 0; j < listObj.size(); j++)
		{
			bool foundId = false;

			for (auto & elem : listId)
			{
				if (elem == listObj[j]->getId())
				{
					foundId = true;
					break;
				}
			}

			if (!foundId)
			{
				//_RPT1(0, "[ID OBJ] %d \n", listObj[j]->getId());
				listGameObj.push_back(listObj[j]);

				listId.push_back(listObj[j]->getId());
			}
		}
	}

	//_RPT0(0, "==================================\n");

	return listGameObj;
}

Unit FixedGrid::getUnit(int x, int y)
{
	return _cell[x][y];
}
