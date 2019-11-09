#include "FixedGrid.h"

FixedGrid::FixedGrid()
{
	_widthUnit = _heightUnit = 0;
	_textureMapId = _mapWidth = _mapHeight = 0;
	_isLoaded = false;
}

void FixedGrid::init(const char * filePath)
{
}

void FixedGrid::load(const char * filePath)
{

#pragma region LOAD FILE TXT MAP
	FILE* file;
	fopen_s(&file, filePath, "r");

	if (file == NULL) return;

	int countline = 0;
	int idTypeObj, posObj_X, posObj_Y, objW, objH;

	while (!feof(file))
	{
		// Dong dau tien thong so map
		//
		// idTexture - mapW - mapH - tileW - tileH - objW - objH
		//

		if (countline == 0)
		{
			// Doc info cua map
			fscanf_s(file, "%d %d %d %d %d", &_textureMapId, &_mapWidth, &_mapHeight, &_widthUnit, &_heightUnit);
			_RPT1(0, "[MAP TXT] %d %d %d %d %d \n", _textureMapId, _mapWidth, _mapHeight, _widthUnit, _heightUnit);
			if (_isLoaded) {
				return;
			}
		}
		else
		{
			char idObj[100];
			// Doc pos va idType cua cac obj

			std::fscanf(file, "%d %s %d %d %d %d", &idTypeObj, &idObj, &posObj_X, &posObj_Y, &objW, &objH);

			_RPT1(0, "[MAP TXT] Load OBJ: %d %s || ( %d , %d ) || w %d h %d \n", idTypeObj, idObj, posObj_X, posObj_Y, objW, objH);

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

			_obj->setId(std::string(idObj));
			_obj->loadResource();
			_obj->setScale(2.0f);
			_obj->setPositionWorld(posObj_X, posObj_Y);

			RECT rect = _obj->getBoudingBox();
			_RPT1(0, "[MAP TXT] RECT OBJ : %d %d %d %d \n", rect.left, rect.top, rect.right, rect.bottom);

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
				}
			}
		}
		countline += 1;
	}

	fclose(file);
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

			this->_cell[cellX][cellY].setIndex(cellX, cellY);
			this->_cell[cellX][cellY].setSize(_widthUnit, _heightUnit);
			this->_cell[cellX][cellY].setPosWorld(x, y);

			count++;
		}
	}

	_RPT1(0, "[MAP TXT] Num UNIT %d \n", count);

#pragma endregion

}

void FixedGrid::save()
{
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

void FixedGrid::setIsLoaded(bool val)
{
	this->_isLoaded = val;
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

Unit FixedGrid::getUnit(int x, int y)
{
	return _cell[x][y];
}
