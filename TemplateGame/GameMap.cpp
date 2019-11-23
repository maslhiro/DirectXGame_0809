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

void GameMap::load(const char *filePath)
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

	auto listUnit = _grid->getUnitsContain(_viewPort);

	for (size_t i = 0; i < listUnit.size(); i++)
	{
		Unit curUnit = listUnit[i];

		RECT tile = curUnit.getBoudingUnit();

		Vec3 pos = curUnit.getPosWorld();
		//_RPT1(0, "[INFO] POS TILE %d %d %d %d \n", tile.left, tile.top, tile.right, tile.bottom);
		_spriteHandler->Draw(
			_texture->get(_textureMapId),
			&tile, NULL, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	}


	// Sau do ve entity
	// tranh truong hon map ve tren entity
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
			continue;
		}
		else listObj[i]->render();
	}

	// Cuoi cung la ve thang aladdin
	_player->render();

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
