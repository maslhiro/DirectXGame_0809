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

	_grid = nullptr;
	_camera = nullptr;
	_player = nullptr;

	_scale = Vec2(1, 1);

	_textureMapId = _mapWidth = _mapHeight = _tileWidth = _tileHeight = 0;

}

void GameMap_Txt::setCamera(pCamera camera)
{
	_camera = camera;
	_camera->setSizeMap(_mapWidth, _mapHeight);

}

void GameMap_Txt::setScale(Vec2 scale)
{
	_scale = scale;
}

void GameMap_Txt::setScale(float scale)
{
	_scale = Vec2(scale, scale);
}

void GameMap_Txt::setGrid(pFixedGrid grid)
{
	_grid = grid;
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

pFixedGrid GameMap_Txt::getGrid()
{
	return _grid;
}

pCamera GameMap_Txt::getCamera()
{
	return _camera;
}

void GameMap_Txt::setPointerPlayer(pAladin val)
{
	this->_player = val;
}

void GameMap_Txt::load(const char *filePath)
{
	if (_grid == nullptr) return;

	_grid->load(filePath);

	_textureMapId = _grid->getIdTextureMap();
	_mapWidth = _grid->getMapWidth();
	_mapHeight = _grid->getMapHeight();
	_tileWidth = _grid->getWidthUnit();
	_tileHeight = _grid->getHeightUnit();

	_player->setPositionWorld(_grid->getPosWorld_PLAYER());

	_RPT0(0, "[INFO] Load GAME MAP TXT Done\n");
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
			Unit curUnit = listUnit[x][y];

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
			Unit curUnit = listUnit[x][y];

			Vec3 pos = curUnit.getPosWorld();

			std::vector<pGameObject> listGameObj = curUnit.getListGameObj();

			if (listGameObj.size() == 0) continue;

			for (int i = 0; i < listGameObj.size(); i++)
			{
				int idType = listGameObj[i]->getIdType();

				//int objID = listGameObj[i]->getId();
				//_RPT1(0, "[ID OBJ] %d \n", objID);

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

	// Cuoi cung la ve thang aladdin
	_player->render();

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

	// Luon Update Cac OBJ dac biet
	for (int x = 0; x < _grid->getNumX(); x++)
	{
		for (int y = 0; y < _grid->getNumY(); y++)
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
