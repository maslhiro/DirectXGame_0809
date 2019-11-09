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
	//_grid = new FixedGrid();
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

	//_grid->init(_map);
	_RPT1(0, "[INFO] LOAD MAP DONE %s \n", filePath);

}

void GameMap::release()
{
	delete _map;
}

void GameMap::render(RECT _rectPlayer)
{

}

void GameMap::update(float dt)
{

}
