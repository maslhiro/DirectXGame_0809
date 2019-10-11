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
					_RPT1(0, "[INFO] TEXTURE MAP %d \n", idTexture);
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
					D3DXVECTOR3 position(n * tileWidth + tileWidth / 2, m * tileHeight + tileHeight / 2, 0);

					_device->getSpriteHandler()->Draw(_texture->get(idTexture), &sourceRECT, &D3DXVECTOR3(tileWidth / 2, tileHeight / 2, 0), &position, D3DCOLOR_XRGB(255, 255, 255));
				}
			}
		}
	}
}
