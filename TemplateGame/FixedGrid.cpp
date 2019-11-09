#include "FixedGrid.h"

FixedGrid::FixedGrid()
{
	_widthUnit = _heightUnit = 0;
	_isLoaded = false;
}


void FixedGrid::init(Tmx::Map* _map)
{
	// Chia map thanh nhieu UNIT
	int count = 0;
	for (int h = _map->GetHeight()*_map->GetTileHeight(); h > 0; h -= HEIGHT_UNIT)
	{
		for (int w = 0; w < _map->GetWidth()*_map->GetTileWidth(); w += WIDTH_UNIT)
		{
			count += 1;
		}
	}

	_RPT1(0, "[GRID] Count %d \n", count);

	// Ktra xem co object nao trong Unit nay ko ?
	for (size_t i = 0; i < _map->GetNumObjectGroups(); i++)
	{
		const Tmx::ObjectGroup *objectGroup = _map->GetObjectGroup(i);

		if (objectGroup->GetName() == "player") continue;

		for (size_t j = 0; j < objectGroup->GetNumObjects(); j++)
		{
			auto *object = objectGroup->GetObjects().at(j);

			int posX = object->GetX();
			int posY = object->GetY();

			int cellX = posX / WIDTH_UNIT + 1;
			int cellY = posY / HEIGHT_UNIT + 1;

			pEntity entity = new Entity();
			entity->setPos(posX, posY);

			_cell[cellX][cellY].addEnity(entity);

			//_RPT0(0, "=============== \n");
			//_RPT1(0, "[UNIT ID] %d %d \n", cellX, cellY);
			//_RPT1(0, "[OBJ MAP] %s : %d %d \n", object->GetName().c_str(), object->GetX() + object->GetWidth(), object->GetY() + object->GetHeight());

		}
	}


}

void FixedGrid::setWidthUnit(int w)
{
	_widthUnit = w;
}

void FixedGrid::setHeightUnit(int h)
{
	_heightUnit = h;
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
