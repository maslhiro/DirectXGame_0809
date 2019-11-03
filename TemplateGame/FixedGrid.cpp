#include "FixedGrid.h"

FixedGrid::FixedGrid()
{
}


void FixedGrid::init(Tmx::Map* _map)
{
	// Clear the FixedGrid.
	//for (int x = 0; x < NUM_CELLS; x++)
	//{
	//	for (int y = 0; y < NUM_CELLS; y++)
	//	{
	//		_cell[x][y] == nullptr;
	//	}
	//}

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

			_RPT0(0, "=============== \n");
			_RPT1(0, "[UNIT ID] %d %d \n", cellX, cellY);
			_RPT1(0, "[OBJ MAP] %s : %d %d \n", object->GetName().c_str(), object->GetX() + object->GetWidth(), object->GetY() + object->GetHeight());

		}
	}


}

Unit FixedGrid::getUnit(int x, int y)
{
	return _cell[x][y];
}

