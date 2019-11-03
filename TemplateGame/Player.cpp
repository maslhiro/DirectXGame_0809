#include "Player.h"

Player::Player()
{
	_pos = Vec3();
	_posWorld = Vec3();
	_camera = nullptr;
}


Player::~Player()
{
}

void Player::setPos(int x, int y)
{
	_pos = Vec3((float)x, (float)y, 0);
}

void Player::setPosWorld(int x, int y)
{
	_posWorld = Vec3((float)x, (float)y, 0);

}

void Player::setPos(Vec3 pos)
{
	_pos = pos;
}

void Player::setPosWorld(Vec3 pos)
{
	_posWorld = pos;
}

void Player::setCamera(pCamera cam)
{
	_camera = cam;
}

RECT Player::getBounding()
{
	RECT rect;

	rect.top = _posWorld.y - 75;
	rect.bottom = _posWorld.y + 75;
	rect.left = _posWorld.x - 50;
	rect.right = _posWorld.x + 50;

	return rect;
}

void Player::init()
{
}

void Player::render()
{
	auto _texture = Texture::getInstance();
	auto _spriteHandler = DeviceManager::getInstance()->getSpriteHandler();

	RECT rect;
	rect.left = rect.top = 0;
	rect.right = 100;
	rect.bottom = 150;

	Vec3 center = Vec3(50, 75, 0);

	_spriteHandler->Draw(
		_texture->get(eIdTexture::BOX_GRAY_TEX),
		&rect, &center, &_pos,
		D3DCOLOR_XRGB(255, 255, 255));

}

void Player::update(float)
{
}

void Player::handlerInput(float)
{
	auto _device = DeviceManager::getInstance();
	auto _input = InputHandler::getInstance();

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
		if (_camera->getPositionWorld().x < (4540 - _device->getWidthWindow() / 2))
		{
			_camera->setPositisonWorld(_camera->getPositionWorld() + Vec3(DISTANCE_X, 0, 0));
		}
		else
		{
			_camera->setPositionWorld_X(4540 - _device->getWidthWindow() / 2);
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
		if (_camera->getPositionWorld().y < (2280 - _device->getHeightWindow() / 2))
		{
			_camera->setPositisonWorld(_camera->getPositionWorld() + Vec3(0, DISTANCE_Y, 0));
		}
		else
		{
			_camera->setPositionWorld_Y(2280 - _device->getHeightWindow() / 2);
		}

	}
}
