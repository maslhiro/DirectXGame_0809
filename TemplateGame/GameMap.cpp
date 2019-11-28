#include "GameMap.h"

GameMap::GameMap()
{
}


GameMap::~GameMap()
{
}

void GameMap::init()
{
	_texture = Texture::getInstance();
	_device = DeviceManager::getInstance();
	_input = InputHandler::getInstance();

	_grid = nullptr;
	_camera = nullptr;
	_player = nullptr;

	_scale = Vec2(1, 1);

	_textureMapId = _mapWidth = _mapHeight = _textureMapAboveId = _tileWidth = _tileHeight = 0;

}

void GameMap::setIdTextureMapAbove(int id)
{
	_textureMapAboveId = id;
}

void GameMap::setCamera(pCamera camera)
{
	_camera = camera;
	_camera->setSizeMap(_mapWidth, _mapHeight);

}

void GameMap::setScale(Vec2 scale)
{
	_scale = scale;
}

void GameMap::setScale(float scale)
{
	_scale = Vec2(scale, scale);
}

void GameMap::setGrid(pFixedGrid grid)
{
	_grid = grid;
}

int GameMap::getWidth()
{
	return _mapWidth;
}

int GameMap::getHeight()
{
	return _mapHeight;
}

int GameMap::getTileWidth()
{
	return _tileWidth;
}

int GameMap::getTileHeight()
{
	return _tileHeight;
}

pFixedGrid GameMap::getGrid()
{
	return _grid;
}

pCamera GameMap::getCamera()
{
	return _camera;
}

void GameMap::setPointerPlayer(pAladin val)
{
	this->_player = val;
}

void GameMap::loadGameObj(const char *filePath)
{
	if (_grid == nullptr) return;

	_grid->load(filePath);
	_player->setPositionWorld(_grid->getPosWorld_PLAYER());

	_RPT0(0, "[INFO] Load GAME OBJ TXT Done\n");
}

void GameMap::loadTileSet(const char *filePath)
{
	std::ifstream fileTile;

	fileTile.open(filePath);

	if (fileTile.fail())
	{
		_RPT0(0, "[INFO] Failed to open tile txt! \n");
		return;
	}

	int idTexture = 0;
	fileTile >> idTexture;

	int numTile = 0;
	fileTile >> numTile;

	_RPT1(0, "[TILE TXT] Texture %d \n", idTexture);
	_RPT1(0, "[TILE TXT] NUM Tile %d \n", numTile);

	int left = 0;
	int top = 0;
	int right = 0;
	int bottom = 0;

	int id = 0;

	while (numTile != 0)
	{
		fileTile >> id;

		fileTile >> left;
		fileTile >> top;
		fileTile >> right;
		fileTile >> bottom;

		RectSprite r;
		r.setIdTexture(id);
		r.left = left;
		r.top = top;
		r.right = right;
		r.bottom = bottom;
		_RPT1(0, "[TILE TXT %d %d %d %d %d\n", id, left, top, right, bottom);

		_tiles.push_back(r);

		numTile -= 1;
	}

	fileTile.close();
}

void GameMap::load(const char *filePath)
{
	std::ifstream fileMap;

	fileMap.open(filePath);

	if (fileMap.fail())
	{
		_RPT0(0, "[INFO] Failed to open map txt! \n");
		return;
	}

	int numTile_X = 0;
	fileMap >> numTile_X;

	int numTile_Y = 0;
	fileMap >> numTile_Y;

	_mapWidth = numTile_X * TILE_SIZE;
	_mapHeight = numTile_Y * TILE_SIZE;

	_RPT1(0, "[MAP TXT] NUM X %d \n", numTile_X);
	_RPT1(0, "[MAP TXT] NUM Y %d \n", numTile_Y);

	int numTile = numTile_X * numTile_Y;
	int numX = 0;
	int numY = 0;
	int id = 0;

	while (numTile != 0)
	{
		fileMap >> id;

		Tile t;
		t.setTileId(id);
		// Toa do trong ma tran
		t._x = numX;
		t._y = numY;

		t.setPosWorld(numX*TILE_SIZE, numY*TILE_SIZE);

		_RPT1(0, "[MAP TXT] ID TILE %d NUM X %d || NUM Y L %d\n", id, t._x, t._y);

		_map.push_back(t);


		if (numX == numTile_X - 1)
		{
			numY += 1;
			numX = 0;
		}
		else numX += 1;

		numTile -= 1;
	}

	fileMap.close();
}

std::vector<Tile> GameMap::getMapContain(RECT _view)
{
	std::vector<Tile> listTile;
	// Lay ra Cac Unit contain voi viewport
	Vec3 posLEFT_T = Vec3(_view.left, _view.top, 0);
	Vec3 posRIGHT_BT = Vec3(_view.right, _view.bottom, 0);

	int min_CellX = posLEFT_T.x / TILE_SIZE;
	int min_CellY = posLEFT_T.y / TILE_SIZE;

	int max_CellX = posRIGHT_BT.x / TILE_SIZE;
	int max_CellY = posRIGHT_BT.y / TILE_SIZE;

	for (size_t i = 0; i < _map.size(); i++)
	{
		if ((_map[i]._x >= min_CellX && _map[i]._x <= max_CellX) && (_map[i]._y >= min_CellY && _map[i]._y <= max_CellY))
		{
			_RPT1(0, "[MAP CONTAIN] %d \n", i);
			listTile.push_back(_map[i]);
		}
	}

	return listTile;
}

void GameMap::release()
{

}

void GameMap::render()
{
	D3DXMATRIX matFinal;
	D3DXMATRIX matTransformed;
	D3DXMATRIX matOld;

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
	auto mapContain = getMapContain(_viewPort);

	for (size_t i = 0; i < mapContain.size(); i++)
	{
		RectSprite rectTile = _tiles[mapContain[i].getTileId() - 1];
		RECT boudingTile = rectTile.getRECT();

		Vec3 pos = mapContain[i].getPosWorld();
		_RPT1(0, "[INFO] POS TILE %f %f \n", pos.x, pos.y);
		_spriteHandler->Draw(
			_texture->get(70),
			&boudingTile, NULL, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	}

	// Sau do ve entity
	// tranh truong hon map ve tren entity
	//auto listObj = _grid->getListGameObjContain(_viewPort);

	//for (size_t i = 0; i < listObj.size(); i++)
	//{
	//	int idType = listObj[i]->getIdType();

	//	// Doi voi 4 cot da thi render sau khi ve aladin
	//	if (idType == eIdObject::STONE_COLUMN_1 ||
	//		idType == eIdObject::STONE_COLUMN_2 ||
	//		idType == eIdObject::STONE_COLUMN_3 ||
	//		idType == eIdObject::STONE_COLUMN_4)
	//	{
	//		continue;
	//	}
	//	else listObj[i]->render();
	//}

	//// Cuoi cung la ve thang aladdin
	//_player->render();

	_spriteHandler->SetTransform(&matOld); // set lai matrix cu~ chi ap dung transfrom voi class nay
}

void GameMap::renderAbove()
{

	D3DXMATRIX matFinal;
	D3DXMATRIX matTransformed;
	D3DXMATRIX matOld;

	auto _spriteHandler = _device->getSpriteHandler();

	Vec2 trans(_device->getWidthWindow() / 2 - _camera->getPositionWorld().x, _device->getHeightWindow() / 2 - _camera->getPositionWorld().y);

	Vec2 centerMap = Vec2((float)_mapWidth / 2, (float)_mapHeight / 2);

	_spriteHandler->GetTransform(&matOld);

	D3DXMatrixTransformation2D(&matTransformed, &centerMap, 0, &_scale, &centerMap, 0, &trans);

	matFinal = matTransformed * matOld;

	_spriteHandler->SetTransform(&matFinal);

	// Render map above

	RECT _viewPort = _camera->getBounding();

	auto listObj = _grid->getListGameObjContain(_viewPort);

	for (size_t i = 0; i < listObj.size(); i++)
	{
		int idType = listObj[i]->getIdType();

		// Doi voi 4 cot da thi render sau khi ve aladin
		if (idType == eIdObject::STONE_COLUMN_1 ||
			idType == eIdObject::STONE_COLUMN_2 ||
			idType == eIdObject::STONE_COLUMN_3 ||
			idType == eIdObject::STONE_COLUMN_4)
		{
			listObj[i]->render();
		}
	}

	auto listUnit = _grid->getUnitsContain(_viewPort);

	//for (size_t i = 0; i < listUnit.size(); i++)
	//{
	//	Unit curUnit = listUnit[i];

	//	RECT tile = curUnit.getBoudingUnit();

	//	Vec3 pos = curUnit.getPosWorld();
	//	//_RPT1(0, "[INFO] POS TILE %d %d %d %d \n", tile.left, tile.top, tile.right, tile.bottom);
	//	_spriteHandler->Draw(
	//		_texture->get(_textureMapAboveId),
	//		&tile, NULL, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	//}

	_spriteHandler->SetTransform(&matOld);
	// set lai matrix cu~ chi ap dung transfrom voi class nay
}

void GameMap::update(float dt)
{
	// Update cac obj tinh apple , ball, ....
	RECT _viewPort = _camera->getBounding();

	auto listObj = _grid->getListGameObjContain(_viewPort);

	//_RPT0(0, "============================================\n");
	for (size_t i = 0; i < listObj.size(); i++)
	{
		int idType = listObj[i]->getIdType();
		if (idType == eIdObject::WRECKING_BALL) {
			listObj[i]->update(dt);
			//_RPT1(0, "[UPDATE MAP] ID Obj %d \n", listObj[i]->getId());
			//RECT r = listObj[i]->getCurrentBoudingBox();
			//_RPT1(0, "[UPDATE MAP] RECT %d %d %d %d \n", r.left, r.top, r.right, r.bottom);
		}
		else if (idType == eIdObject::APPLE) {
			listObj[i]->update(dt);
		}
		else if (idType == eIdObject::ROCK) {
			listObj[i]->update(dt);
		}
	}
	//_RPT0(0, "============================================\n");

}
