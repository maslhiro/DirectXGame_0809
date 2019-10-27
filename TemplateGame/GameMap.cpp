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
}

void GameMap::setCamera(pCamera camera)
{

	_camera = camera;

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
	//delete _map;
	//delete _camera;
}

void GameMap::render()
{

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
					Vec3 position(n * tileWidth + tileWidth / 2, m * tileHeight + tileHeight / 2, 0);

					// kiem tra tile do co nam ngoai map ko ?
					if (_camera != nullptr)
					{
						//_RPT1(0, "[INFO] MAP RECT %d %d %d %d \n", _camera->getBounding().left, _camera->getBounding().top, _camera->getBounding().right, _camera->getBounding().bottom);
						RECT objRECT;
						objRECT.left = position.x - tileWidth / 2;
						objRECT.top = position.y - tileHeight / 2;
						objRECT.right = objRECT.left + tileWidth;
						objRECT.bottom = objRECT.top + tileHeight;

						//_RPT1(0, "[INFO] TILE RECT %d %d %d %d \n", sourceRECT.left, sourceRECT.top, sourceRECT.right, sourceRECT.bottom);
						//neu nam ngoai camera thi khong render
						//if (_camera->isContain(objRECT) == false) continue;
					}


					Vec2 trans(SCREEN_WIDTH / 2 - _camera->getPositionWorld().x, SCREEN_HEIGHT / 2 - _camera->getPositionWorld().y);

					renderTileMap(idTexture, sourceRECT, position, trans, tileWidth, tileHeight);

				}
			}
		}
	}
}

void GameMap::renderTileMap(int idTexture, RECT &rect, Vec3 pos, Vec2 trans, int tileWidth, int tileHeight)
{
	D3DXMATRIX  mMatrix;
	auto mSpriteHandler = _device->getSpriteHandler();

	Vec2 scalingScenter = Vec2(pos.x, pos.y);


	D3DXMatrixTransformation2D(&mMatrix, &scalingScenter, 0, &Vec2(1, 1), &Vec2(pos.x, pos.y), 0, &trans);

	D3DXMATRIX oldMatrix;
	mSpriteHandler->GetTransform(&oldMatrix);
	mSpriteHandler->SetTransform(&mMatrix);

	Vec3 center = Vec3(tileWidth / 2, tileHeight / 2, 0);

	mSpriteHandler->Draw(_texture->get(idTexture),
		&rect,
		&center,
		&pos,
		D3DCOLOR_ARGB(255, 255, 255, 255)); // nhung pixel nao co mau trang se duoc to mau nay len

	mSpriteHandler->SetTransform(&oldMatrix); // set lai matrix cu~ de Sprite chi ap dung transfrom voi class nay
}

void GameMap::update(float dt)
{
	handlerInput(dt);
}

#define DISTANCE_X 30
#define DISTANCE_Y 30

void GameMap::handlerInput(float)
{
	if (_input->getMapKey()[KEY_A]) {
		_RPT0(0, "OK A \n");
		_camera->setPositisonWorld(_camera->getPositionWorld() + Vec3(-DISTANCE_X, 0, 0));
	}
	else if (_input->getMapKey()[KEY_D])
	{
		_RPT0(0, "OK D \n");
		_camera->setPositisonWorld(_camera->getPositionWorld() + Vec3(DISTANCE_X, 0, 0));

	}
	else if (_input->getMapKey()[KEY_W])
	{
		_RPT0(0, "OK W \n");
		_camera->setPositisonWorld(_camera->getPositionWorld() + Vec3(0, -DISTANCE_Y, 0));

	}

	else if (_input->getMapKey()[KEY_S])
	{
		_RPT0(0, "OK S \n");
		_camera->setPositisonWorld(_camera->getPositionWorld() + Vec3(0, DISTANCE_Y, 0));

	}
}
