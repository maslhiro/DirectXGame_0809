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

void GameMap::load(char *filePath)
{
	_map = new Tmx::Map();
	_map->ParseFile(filePath);
	_RPT1(0, "[INFO] LOAD MAP DONE %s \n", filePath);
}

void GameMap::release()
{
	delete _map;
}

void GameMap::render()
{
	D3DXMATRIX matFinal;
	D3DXMATRIX matTransformed;
	D3DXMATRIX matOld;
	auto mSpriteHandler = _device->getSpriteHandler();

	Vec2 trans(_device->getWidthWindow() / 2 - _camera->getPositionWorld().x, _device->getHeightWindow() / 2 - _camera->getPositionWorld().y);

	//_RPT1(0, "[INFO] MAP WIDHT %d \n", _map->GetWidth()* _map->GetTileWidth());

	//_RPT1(0, "[INFO] MAP HEIGHT %d \n", _map->GetHeight()*_map->GetTileHeight());

	Vec2 centerMap = Vec2(_map->GetWidth()* _map->GetTileWidth() / 2, _map->GetHeight()*_map->GetTileHeight() / 2);

	mSpriteHandler->GetTransform(&matOld);

	D3DXMatrixTransformation2D(&matTransformed, &centerMap, 0, &_scale, &centerMap, 0, &trans);

	matFinal = matTransformed * matOld;

	mSpriteHandler->SetTransform(&matFinal);

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

					mSpriteHandler->Draw(_texture->get(idTexture),
						&sourceRECT,
						&center,
						&pos,
						D3DCOLOR_ARGB(255, 255, 255, 255)); // nhung pixel nao co mau trang se duoc to mau nay len



				}
			}
		}
	}

	mSpriteHandler->SetTransform(&matOld); // set lai matrix cu~ chi ap dung transfrom voi class nay
}

void GameMap::update(float dt)
{
	handlerInput(dt);
}

#define DISTANCE_X 5
#define DISTANCE_Y 5

void GameMap::handlerInput(float)
{
	if (_input->getMapKey()[KEY_A]) {
		//_RPT0(0, "OK A \n");
		if (_camera->getPositionWorld().x > _device->getWidthWindow() / 2)
		{
			_camera->setPositisonWorld(_camera->getPositionWorld() + Vec3(-DISTANCE_X, 0, 0));
		}
		else
		{
			_camera->setPositionWorld_X(_device->getWidthWindow() / 2);
		}

	}
	else if (_input->getMapKey()[KEY_D])
	{
		//_RPT0(0, "OK D \n");
		if (_camera->getPositionWorld().x < (getWidth() - _device->getWidthWindow() / 2))
		{
			_camera->setPositisonWorld(_camera->getPositionWorld() + Vec3(DISTANCE_X, 0, 0));
		}
		else
		{
			_camera->setPositionWorld_X(getWidth() - _device->getWidthWindow() / 2);
		}


	}
	else if (_input->getMapKey()[KEY_W])
	{
		//_RPT0(0, "OK W \n");
		if (_camera->getPositionWorld().y > (_device->getHeightWindow() / 2))
		{
			_camera->setPositisonWorld(_camera->getPositionWorld() + Vec3(0, -DISTANCE_Y, 0));
		}
		else
		{
			_camera->setPositionWorld_Y(_device->getHeightWindow() / 2);
		}


	}

	else if (_input->getMapKey()[KEY_S])
	{
		//_RPT0(0, "OK S \n");
		if (_camera->getPositionWorld().y < (getHeight() - _device->getHeightWindow() / 2))
		{
			_camera->setPositisonWorld(_camera->getPositionWorld() + Vec3(0, DISTANCE_Y, 0));
		}
		else
		{
			_camera->setPositionWorld_Y(getHeight() - _device->getHeightWindow() / 2);
		}

	}
}
