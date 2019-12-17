#include "FixedGrid.h"
#define __STDC_WANT_LIB_EXT1__ 1

FixedGrid::FixedGrid()
{
	_mapWidth = _mapHeight = 0;
	_numX = _numY = _numObj = 0;
	_isLoaded = false;
	_posWorld_PLAYER = Vec3();
}

void FixedGrid::init()
{
	std::ifstream file;

	file.open(_fileSavePath);

	if (file.fail())
	{
		setIsLoaded(false);
		return;
	}
	while (!file.eof())
	{
		UnitTemp _cell;

		file >> _cell.x;
		file >> _cell.y;
		file >> _cell.idObj;

		_cellTemp.push_back(_cell);

		//_RPT1(0, "[INIT GRID] [%d,%d] - %d \n", _cell.x, _cell.y, _cell.idObj);

	}

	setIsLoaded(true);

	file.close();
}

void FixedGrid::load(const char* filePath)
{
#pragma region LOAD FILE OBJ TXT || LUU LAI GRID TXT
	FILE* file;
	FILE* fileSave;
	fopen_s(&file, filePath, "r");
	fopen_s(&fileSave, _fileSavePath, "w+");

	if (file == NULL) {
		goto closeFile;
	}

	int countline = 0;

	while (!feof(file))
	{
		// Dong dau tien so OBJ
		//
		// numObj - mapW - mapH
		//

		if (countline == 0)
		{
			// Doc info cua map
			fscanf(file, "%d %d %d", &_numObj, &_mapWidth, &_mapHeight);

			//_RPT1(0, "[GRID OBJ TXT] NUM OBJ  %d W: \n", _numObj, _mapWidth, _mapHeight);
		}
		else if (countline == 1)
		{
			int posx, posy;
			fscanf(file, "%d %d", &posx, &posy);
			//_RPT1(0, "[MAP TXT - PLAYER ] %d %d \n", posx, posy);
			_posWorld_PLAYER = Vec3((float)posx, (float)posy, 0);
		}
		else
		{
			int idTypeObj, idObj, posObj_X, posObj_Y, objW, objH;

			// Doc pos va idType cua cac obj
			fscanf(file, "%d %d %d %d %d %d", &idTypeObj, &idObj, &posObj_X, &posObj_Y, &objW, &objH);

			//_RPT1(0, "[MAP TXT] Load OBJ: %d %d || ( %d , %d ) || w %d h %d \n", idTypeObj, idObj, posObj_X, posObj_Y, objW, objH);

			//Tu idTypeObj = > RECT = > BOUNDING cua obj do

			pGameObject _obj;

			switch (idTypeObj)
			{
			case eIdObject::APPLE:
			{
				_obj = new Coin();
				break;
			}
			case eIdObject::COIN:
			{
				_obj = new Coin();
				break;
			}
			case eIdObject::GENIE_HEAD:
			{
				_obj = new GenieHead();
				break;
			}
			case eIdObject::ROCK:
			{
				_obj = new Rock();
				break;
			}
			case eIdObject::SPIKE:
			{
				_obj = new Spike();
				break;
			}
			case eIdObject::BAT:
			{
				_obj = new Bat();
				break;
			}
			case eIdObject::NAHBI:
			{
				_obj = new Nahbi();
				break;
			}
			case eIdObject::FAZAL:
			{
				_obj = new Fazal();
				break;
			}
			case eIdObject::PEDDLER:
			{
				_obj = new Peddler();
				break;
			}
			case eIdObject::SKELETON:
			{
				_obj = new Skeleton();
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
			case eIdObject::GROUND:
			{
				_obj = new Ground();

				RECT rec;
				rec.left = posObj_X;
				rec.top = posObj_Y;
				rec.right = objW;
				rec.bottom = objH;
				_obj->setRectWorld(rec);

				break;
			}
			case eIdObject::ROPE:
			{
				_obj = new Rope();

				RECT rec;
				rec.left = posObj_X;
				rec.top = posObj_Y;
				rec.right = objW;
				rec.bottom = objH;
				_obj->setRectWorld(rec);

				break;
			}
			case eIdObject::COLUMN:
			{
				_obj = new Column();

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

#pragma region  WITHOUT GRID.TXT
			if (!_isLoaded)
			{
				RECT rect = _obj->getBoundingBox();
				//_RPT1(0, "[MAP TXT] RECT OBJ : %d %d %d %d \n", rect.left, rect.top, rect.right, rect.bottom);

				// Kiem tra xem obj do nam o UNIT NAO
				Vec3 posLEFT_T = Vec3(rect.left, rect.top, 0);
				Vec3 posRIGHT_BT = Vec3(rect.right, rect.bottom, 0);

				int min_CellX = posLEFT_T.x / UNIT_WIDTH;
				int min_CellY = posLEFT_T.y / UNIT_HEIGHT;

				int max_CellX = posRIGHT_BT.x / UNIT_WIDTH;
				int max_CellY = posRIGHT_BT.y / UNIT_HEIGHT;

				for (int x = min_CellX; x <= max_CellX; x++)
				{
					for (int y = min_CellY; y <= max_CellY; y++)
					{
						this->_cell[x][y].addGameObj(_obj);
						fprintf(fileSave, "%d\t%d\t%d\n", x, y, idObj);

					}
				}
			}
#pragma endregion
#pragma region WITH GRID TXT
			else
			{
				std::vector<UnitTemp> cellTemp;

				// Tim tat ca cac cell co id == idObj
				for (int i = 0; i < _cellTemp.size(); i++)
				{
					auto cell = _cellTemp[i];
					if (cell.idObj == idObj) cellTemp.push_back(cell);
				}

				for (int i = 0; i < cellTemp.size(); i++)
				{
					auto cell = cellTemp[i];
					this->_cell[cell.x][cell.y].addGameObj(_obj);
				}
			}
#pragma endregion
		}
		countline += 1;
	}

	if (_isLoaded)
	{
		for (int i = 0; i < _cellTemp.size(); i++)
		{
			auto cell = _cellTemp[i];
			fprintf(fileSave, "%d\t%d\t%d\n", cell.x, cell.y, cell.idObj);
		}
	}

closeFile:
	fclose(file);
	fclose(fileSave);
#pragma endregion
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

	int min_CellX = (posLEFT_T.x / UNIT_WIDTH);
	int min_CellY = (posLEFT_T.y / UNIT_HEIGHT);

	int max_CellX = posRIGHT_BT.x / UNIT_WIDTH;
	int max_CellY = posRIGHT_BT.y / UNIT_HEIGHT;
	//_RPT0(0, "==================================\n");
	//_RPT1(0, "MAX X %d MAX Y %d \n", max_CellX, max_CellY);
	//_RPT1(0, "MIN X %d MIN Y %d \n", min_CellX, min_CellY);
	//_RPT1(0, "VIEW PORT :%d %d %d %d \n", _view.left, _view.top, _view.right, _view.bottom);

	for (int x = min_CellX; x <= max_CellX + 1; x++)
	{
		for (int y = min_CellY; y <= max_CellY + 1; y++)
		{
			//_RPT1(0, "X %d Y %d \n", x, y);

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
	for (size_t i = 0; i < listUnit.size(); i++)
	{
		auto listObj = listUnit[i].getListGameObj();

		if (listObj.size() == 0) continue;

		for (size_t j = 0; j < listObj.size(); j++)
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
