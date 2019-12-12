#include "AppleThrow.h"

AppleThrow::AppleThrow() : GameObject()
{
	_idType = eIdObject::APPLE;
	_isTerminated = false;
	_speed = 450.f;
	_gravity = 60.f;
}

AppleThrow::AppleThrow(int id) : GameObject(id)
{
	_idType = eIdObject::APPLE;
}

void AppleThrow::setListGameObj(std::vector<pGameObject> list)
{
	_listGameObj = list;
}

void AppleThrow::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::APPLE_THROW);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::APPLE_THROW_EXPLODE);

	this->setState(eIdState::NONE);
}

void AppleThrow::render()
{
	if (_isTerminated) return;

	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void AppleThrow::update(float dt)
{
	_curAnimation.setIsAnimated(_isAnimated);

	if (_isTerminated) return;

	if (_state == eIdState::EXPLODE)
	{
		if (_curAnimation.getLoopCount() > 0)
			_isTerminated = true;
		goto updateAni;
	}

	_posWorld.x += _dx * dt;
	//_posWorld.y += _gravity * dt;
	_posWorld.y += pow(_dx * dt, 2) / 20;

	// Ktra va cham 
	for (size_t i = 0; i < _listGameObj.size(); i++)
	{
		bool check = this->checkCollision(_listGameObj[i]->getBoundingBox());

		int id = _listGameObj[i]->getIdType();
		if (id == eIdObject::STONE_COLUMN_1 || id == eIdObject::STONE_COLUMN_2 || id == eIdObject::STONE_COLUMN_3 || id == eIdObject::STONE_COLUMN_4) continue;
		if (check) {
			this->setState(eIdState::EXPLODE);
			goto updateAni;
		}
	}
updateAni:
	_curAnimation.update(dt);
}

void AppleThrow::handlerInput(float)
{
}

void AppleThrow::moveLeft()
{
	_dx = -_speed;
}

void AppleThrow::moveRight()
{
	_dx = _speed;
}