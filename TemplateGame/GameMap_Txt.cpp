#include "GameMap_Txt.h"

GameMap_Txt::GameMap_Txt()
{
}


GameMap_Txt::~GameMap_Txt()
{
}

void GameMap_Txt::init()
{
	_texture = Texture::getInstance();
	_device = DeviceManager::getInstance();
	_input = InputHandler::getInstance();
	_grid = new FixedGrid();
	_camera = nullptr;

	_posWorld_Player = Vec3();
	_scale = Vec2(1, 1);

	_textureMapId = _mapWidth = _mapHeight = _tileWidth = _tileHeight = 0;

}

void GameMap_Txt::setCamera(pCamera camera)
{

	_camera = camera;

}

void GameMap_Txt::setScale(Vec2 scale)
{
	_scale = scale;
}

void GameMap_Txt::setScale(float scale)
{
	_scale = Vec2(scale, scale);
}

int GameMap_Txt::getWidth()
{
	return _mapWidth;
}

int GameMap_Txt::getHeight()
{
	return _mapHeight;
}

int GameMap_Txt::getTileWidth()
{
	return _tileWidth;
}

int GameMap_Txt::getTileHeight()
{
	return _tileHeight;
}

Vec3 GameMap_Txt::getPosWorld_PLAYER()
{
	return _posWorld_Player;
}

pCamera GameMap_Txt::getCamera()
{
	return _camera;
}

void GameMap_Txt::load(const char *filePath)
{
	auto listUnit = _grid->_cell;


#pragma region Load File TXT
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
			fscanf_s(file, "%d %d %d %d %d", &_textureMapId, &_mapWidth, &_mapHeight, &_tileWidth, &_tileHeight);
			_RPT1(0, "[MAP TXT] %d %d %d %d %d \n", _textureMapId, _mapWidth, _mapHeight, _tileWidth, _tileHeight);
			_grid->setWidthUnit(_tileWidth);
			_grid->setWidthUnit(_tileHeight);
			//return;
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

			int min_CellX = posLEFT_T.x / _tileWidth;
			int min_CellY = posLEFT_T.y / _tileHeight;

			int max_CellX = posRIGHT_BT.x / _tileWidth;
			int max_CellY = posRIGHT_BT.y / _tileHeight;

			for (int x = min_CellX; x <= max_CellX; x++)
			{
				for (int y = min_CellY; y <= max_CellY; y++)
				{
					_grid->_cell[x][y].addGameObj(_obj);
				}
			}

		}

		countline += 1;
	}
	fclose(file);

#pragma endregion

#pragma region Chia Unit || Load Grid
	int count = 0;
	int cellX = 0, cellY = 0;

	for (int x = 0; x < _mapWidth; x += _tileWidth)
	{
		for (int y = 0; y < _mapHeight; y += _tileHeight)
		{

			cellX = x / _tileWidth;
			cellY = y / _tileHeight;

			listUnit[cellX][cellY].setIndex(cellX, cellY);
			listUnit[cellX][cellY].setSize(_tileWidth, _tileHeight);
			listUnit[cellX][cellY].setPosWorld(x, y);

			count++;
		}
	}

	_RPT1(0, "[MAP TXT] Num UNIT %d \n", count);

#pragma endregion

	_RPT0(0, "[INFO] Load List TXT Done\n");
}

void GameMap_Txt::release()
{

}

void GameMap_Txt::render()
{
	D3DXMATRIX matFinal;
	D3DXMATRIX matTransformed;
	D3DXMATRIX matOld;

	auto listUnit = _grid->_cell;
	auto _spriteHandler = _device->getSpriteHandler();

	Vec2 trans(_device->getWidthWindow() / 2 - _camera->getPositionWorld().x, _device->getHeightWindow() / 2 - _camera->getPositionWorld().y);

	Vec2 centerMap = Vec2((float)_mapWidth / 2, (float)_mapHeight / 2);

	Vec3 centerTile = Vec3((float)_tileWidth / 2, (float)_tileHeight / 2, 0);

	_spriteHandler->GetTransform(&matOld);

	D3DXMatrixTransformation2D(&matTransformed, &centerMap, 0, &_scale, &centerMap, 0, &trans);

	matFinal = matTransformed * matOld;

	_spriteHandler->SetTransform(&matFinal);

	// Render map

	RECT _viewPort = _camera->getBounding();

	// Lay ra Cac Unit contain voi viewport
	Vec3 posLEFT_T = Vec3(_viewPort.left, _viewPort.top, 0);
	Vec3 posRIGHT_BT = Vec3(_viewPort.right, _viewPort.bottom, 0);

	int min_CellX = posLEFT_T.x / _tileWidth;
	int min_CellY = posLEFT_T.y / _tileHeight;

	int max_CellX = posRIGHT_BT.x / _tileWidth;
	int max_CellY = posRIGHT_BT.y / _tileHeight;

	//_RPT1(0, "[INFO] CELL X %d %d \n", min_CellX, max_CellX);
	//_RPT1(0, "[INFO] CELL Y %d %d \n", min_CellY, max_CellY);

	// Ve map truoc
	for (int x = min_CellX; x <= max_CellX; x++)
	{
		for (int y = min_CellY; y <= max_CellY; y++)
		{
			auto curUnit = listUnit[x][y];

			RECT tile = curUnit.getBoudingUnit();

			Vec3 pos = curUnit.getPosWorld();
			//_RPT1(0, "[INFO] POS TILE %d %d %d %d \n", tile.left, tile.top, tile.right, tile.bottom);
			_spriteHandler->Draw(
				_texture->get(_textureMapId),
				&tile, NULL, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

		}
	}

	// Sau do ve entity
	// tranh truong hon map ve tren entity
	for (int x = min_CellX; x <= max_CellX; x++)
	{
		for (int y = min_CellY; y <= max_CellY; y++)
		{
			auto curUnit = listUnit[x][y];

			Vec3 pos = curUnit.getPosWorld();

			auto listGameObj = curUnit.getListGameObj();

			if (listGameObj.size() == 0) continue;

			for (int i = 0; i < listGameObj.size(); i++)
			{
				int idType = listGameObj[i]->getIdType();

				// Doi voi 4 cot da thi render sau khi ve aladin
				if (idType == eIdObject::STONE_COLUMN_1 ||
					idType == eIdObject::STONE_COLUMN_2 ||
					idType == eIdObject::STONE_COLUMN_3 ||
					idType == eIdObject::STONE_COLUMN_4)
				{
					continue;

				}
				listGameObj[i]->render();
			}
		}
	}

	_spriteHandler->SetTransform(&matOld); // set lai matrix cu~ chi ap dung transfrom voi class nay
}

void GameMap_Txt::renderAbove()
{

	D3DXMATRIX matFinal;
	D3DXMATRIX matTransformed;
	D3DXMATRIX matOld;

	auto listUnit = _grid->_cell;
	auto _spriteHandler = _device->getSpriteHandler();

	Vec2 trans(_device->getWidthWindow() / 2 - _camera->getPositionWorld().x, _device->getHeightWindow() / 2 - _camera->getPositionWorld().y);

	Vec2 centerMap = Vec2((float)_mapWidth / 2, (float)_mapHeight / 2);

	_spriteHandler->GetTransform(&matOld);

	D3DXMatrixTransformation2D(&matTransformed, &centerMap, 0, &_scale, &centerMap, 0, &trans);

	matFinal = matTransformed * matOld;

	_spriteHandler->SetTransform(&matFinal);

	// Render map

	RECT _viewPort = _camera->getBounding();

	// Lay ra Cac Unit contain voi viewport
	Vec3 posLEFT_T = Vec3(_viewPort.left, _viewPort.top, 0);
	Vec3 posRIGHT_BT = Vec3(_viewPort.right, _viewPort.bottom, 0);

	int min_CellX = posLEFT_T.x / _tileWidth;
	int min_CellY = posLEFT_T.y / _tileHeight;

	int max_CellX = posRIGHT_BT.x / _tileWidth;
	int max_CellY = posRIGHT_BT.y / _tileHeight;

	for (int x = min_CellX; x <= max_CellX; x++)
	{
		for (int y = min_CellY; y <= max_CellY; y++)
		{
			auto curUnit = listUnit[x][y];

			Vec3 pos = curUnit.getPosWorld();

			auto listGameObj = curUnit.getListGameObj();

			if (listGameObj.size() == 0) continue;

			for (int i = 0; i < listGameObj.size(); i++)
			{
				int idType = listGameObj[i]->getIdType();

				// Doi voi 4 cot da thi render sau khi ve aladin
				if (idType == eIdObject::STONE_COLUMN_1 ||
					idType == eIdObject::STONE_COLUMN_2 ||
					idType == eIdObject::STONE_COLUMN_3 ||
					idType == eIdObject::STONE_COLUMN_4)
				{
					listGameObj[i]->render();
				}
				else continue;
			}
		}
	}
	_spriteHandler->SetTransform(&matOld); // set lai matrix cu~ chi ap dung transfrom voi class nay
}

void GameMap_Txt::update(float dt)
{
	// Update cac obj tinh apple , ball, ....
	RECT _viewPort = _camera->getBounding();

	auto listUnit = _grid->_cell;

	// Luon Update
	for (int x = 0; x < _grid->NUM_X; x++)
	{
		for (int y = 0; y < _grid->NUM_Y; y++)
		{
			auto curUnit = listUnit[x][y];

			auto listGameObj = curUnit.getListGameObj();

			if (listGameObj.size() == 0) continue;

			for (int i = 0; i < listGameObj.size(); i++)
			{
				int idType = listGameObj[i]->getIdType();

				if (idType == eIdObject::WRECKING_BALL) {
					listGameObj[i]->update(dt);

				}
			}
		}
	}
}
