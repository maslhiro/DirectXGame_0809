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
	_grid = new FixedGrid();
	_camera = nullptr;

	_scale = Vec2(1, 1);
}

void GameMap::setCamera(pCamera camera)
{

	_camera = camera;

}

void GameMap::setScale(Vec2 scale)
{
	_scale = scale;
}

void GameMap::setScale(float scale)
{
	_scale = Vec2(scale, scale);
}

int GameMap::getWidth()
{
	//if (_map != nullptr)
	return _map->GetWidth() * _map->GetTileWidth();
	//return 0;
}

int GameMap::getHeight()
{
	return _map->GetHeight() *_map->GetTileHeight();
}

Vec3 GameMap::getPosWorld_PLAYER()
{
	for (size_t i = 0; i < _map->GetNumObjectGroups(); i++)
	{
		const Tmx::ObjectGroup *objectGroup = _map->GetObjectGroup(i);

		if (objectGroup->GetName() != "player") continue;

		for (size_t j = 0; j < objectGroup->GetNumObjects(); j++)
		{
			auto *object = objectGroup->GetObjects().at(j);

			if (!object->IsVisible())
			{
				continue;
			}

			return Vec3((float)object->GetX(), (float)object->GetY(), 0);
		}
	}
	return Vec3();
}

Tmx::Map* GameMap::getTMXMap()
{
	return _map;
}

pCamera GameMap::getCamera()
{
	return _camera;
}

void GameMap::load(char *filePath)
{
	_map = new Tmx::Map();
	_map->ParseFile(filePath);

	_grid->init(_map);
	_RPT1(0, "[INFO] LOAD MAP DONE %s \n", filePath);

}

void GameMap::release()
{
	delete _map;
}

void GameMap::render(RECT _rectPlayer)
{
	D3DXMATRIX matFinal;
	D3DXMATRIX matTransformed;
	D3DXMATRIX matOld;
	auto _spriteHandler = _device->getSpriteHandler();

	Vec2 trans(_device->getWidthWindow() / 2 - _camera->getPositionWorld().x, _device->getHeightWindow() / 2 - _camera->getPositionWorld().y);

	//_RPT1(0, "[INFO] MAP WIDHT %d \n", _map->GetWidth()* _map->GetTileWidth());

	//_RPT1(0, "[INFO] MAP HEIGHT %d \n", _map->GetHeight()*_map->GetTileHeight());

	Vec2 centerMap = Vec2(_map->GetWidth()* _map->GetTileWidth() / 2, _map->GetHeight()*_map->GetTileHeight() / 2);

	_spriteHandler->GetTransform(&matOld);

	D3DXMatrixTransformation2D(&matTransformed, &centerMap, 0, &_scale, &centerMap, 0, &trans);

	matFinal = matTransformed * matOld;

	_spriteHandler->SetTransform(&matFinal);

	for (size_t i = 0; i < _map->GetNumTileLayers(); i++)
	{
		// moi tile layer co 1 dong tileset =__=
		const Tmx::TileLayer *_layer = _map->GetTileLayer(i);

		if (!_layer->IsVisible())
		{
			continue;
		}

		RECT sourceRECT;

		int tileWidth = _map->GetTileWidth();
		int tileHeight = _map->GetTileHeight();

		for (size_t m = 0; m < _layer->GetHeight(); m++)
		{
			for (size_t n = 0; n < _layer->GetWidth(); n++)
			{
				int tilesetIndex = _layer->GetTileTilesetIndex(n, m);

				if (tilesetIndex != -1)
				{
					const Tmx::Tileset *tileSet = _map->GetTileset(tilesetIndex);

					int tileSetWidth = tileSet->GetImage()->GetWidth() / tileWidth;
					int tileSetHeight = tileSet->GetImage()->GetHeight() / tileHeight;

					int idTexture = 0;
					sscanf(tileSet->GetName().c_str(), "%d", &idTexture);
					//_RPT1(0, "[INFO] TEXTURE MAP %d \n", idTexture);

					//tile index
					int tileID = _layer->GetTileId(n, m);

					int y = tileID / tileSetWidth;
					int x = tileID - y * tileSetWidth;

					sourceRECT.top = y * tileHeight;
					sourceRECT.bottom = sourceRECT.top + tileHeight;
					sourceRECT.left = x * tileWidth;
					sourceRECT.right = sourceRECT.left + tileWidth;

					//tru tilewidth/2 va tileheight/2 vi Sprite ve o vi tri giua hinh anh cho nen doi hinh de cho
					//dung toa do (0,0) cua the gioi thuc la (0,0) neu khong thi se la (-tilewidth/2, -tileheigth/2);
					Vec3 pos(n * tileWidth + tileWidth / 2, m * tileHeight + tileHeight / 2, 0);

					// kiem tra tile do co nam ngoai map ko ?
					if (_camera != nullptr)
					{
						Vec3 transPos = pos;

						//D3DXVec3TransformCoord(&transPos, &pos, &matFinal);

						RECT objRECT;
						objRECT.left = transPos.x - (tileWidth / 2) * _scale.x;
						objRECT.top = transPos.y - (tileHeight / 2) * _scale.y;
						objRECT.right = objRECT.left + (tileWidth)* _scale.x;
						objRECT.bottom = objRECT.top + (tileHeight)* _scale.y;

						//neu nam ngoai camera thi khong render
						if (_camera->isContain(objRECT) == false)
						{
							continue;
						}
					}

					Vec3 center = Vec3(tileWidth / 2, tileHeight / 2, 0);

					_spriteHandler->Draw(_texture->get(idTexture),
						&sourceRECT,
						&center,
						&pos,
						D3DCOLOR_ARGB(255, 255, 255, 255)); // nhung pixel nao co mau trang se duoc to mau nay len



				}
			}
		}
	}

	// Lay toa do 2 goc => tinh ra cac UNIT dang trong man hinh
	RECT _viewPort = _camera->getBounding();

	Vec3 posLEFT_T = Vec3(_viewPort.left, _viewPort.top, 0);
	Vec3 posRIGHT_BT = Vec3(_viewPort.right, _viewPort.bottom, 0);

	int min_CellX = posLEFT_T.x / WIDTH_UNIT + 1;
	int min_CellY = posLEFT_T.y / HEIGHT_UNIT + 1;

	int max_CellX = posRIGHT_BT.x / WIDTH_UNIT + 1;
	int max_CellY = posRIGHT_BT.y / HEIGHT_UNIT + 1;

	// Kiem tra bound _player nam trong UNIT nao ?

	Vec3 posLEFT_T_PLAYER = Vec3(_rectPlayer.left, _rectPlayer.top, 0);
	Vec3 posRIGHT_BT_PLAYER = Vec3(_rectPlayer.right, _rectPlayer.bottom, 0);

	int min_CellX_PLAYER = posLEFT_T_PLAYER.x / WIDTH_UNIT + 1;
	int min_CellY_PLAYER = posLEFT_T_PLAYER.y / HEIGHT_UNIT + 1;

	int max_CellX_PLAYER = posRIGHT_BT_PLAYER.x / WIDTH_UNIT + 1;
	int max_CellY_PLAYER = posRIGHT_BT_PLAYER.y / HEIGHT_UNIT + 1;

	_RPT1(0, "[INFO] CELL PLAYER X %d %d \n", min_CellX_PLAYER, max_CellX_PLAYER);
	_RPT1(0, "[INFO] CELL PLAYER Y %d %d \n", min_CellY_PLAYER, max_CellY_PLAYER);

	//_RPT1(0, "[INFO] %d %d %d %d \n", _viewPort.left, _viewPort.top, _viewPort.right, _viewPort.bottom);

	_RPT1(0, "[INFO] CELL X %d %d \n", min_CellX, max_CellX);
	_RPT1(0, "[INFO] CELL Y %d %d \n", min_CellY, max_CellY);

	for (int x = min_CellX; x <= max_CellX; x++)
	{
		for (int y = min_CellY; y <= max_CellY; y++)
		{
			auto curUnit = _grid->getUnit(x, y);

			auto listEntity = curUnit.getListEntity();

			if (listEntity.size() == 0) continue;

			bool bounding = false;

			_RPT1(0, "[OK] x : %d y : %d \n", x, y);
			//_RPT1(0, "[INFO] CELL PLAYER X %d %d \n", min_CellX_PLAYER, max_CellX_PLAYER);
			//_RPT1(0, "[INFO] CELL PLAYER Y %d %d \n", min_CellY_PLAYER, max_CellY_PLAYER);

			if ((x >= min_CellX_PLAYER && x <= max_CellX_PLAYER) && (y >= min_CellY_PLAYER && y <= max_CellY_PLAYER))
			{
				_RPT1(0, "[OK] x : %d y : %d \n", x, y);
				bounding = true;
			}

			for (int i = 0; i < listEntity.size(); i++)
			{
				listEntity[i]->setDrawingBound(bounding);
				listEntity[i]->render();
			}
		}
	}

	_spriteHandler->SetTransform(&matOld); // set lai matrix cu~ chi ap dung transfrom voi class nay
}

void GameMap::update(float dt)
{

}
