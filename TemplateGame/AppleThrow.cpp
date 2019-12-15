#include "AppleThrow.h"

AppleThrow::AppleThrow() : GameObject()
{
	_idType = eIdObject::APPLE;
	_isTerminated = false;
	_speed = 480.f;
	_gravity = 80.f;
	_timeUp = 0.f;
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

	if (_isTerminated) {
		_timeUp = 0.f;
		return;
	}
	if (_state == eIdState::EXPLODE)
	{
		if (_curAnimation.getLoopCount() > 0)
			_isTerminated = true;
		goto updateAni;
	}

	_posWorld.x += _dx * dt;

	_timeUp += dt;

	if (_timeUp >= 0.2f)
	{
		//_RPT1(0, "TIME UP %f \n", _timeUp);
		_posWorld.y += _gravity * dt;
	}
	else
	{
		_posWorld.y -= _gravity / 2. *dt;
	}


	// Ktra va cham 
	for (size_t i = 0; i < _listGameObj.size(); i++)
	{
		bool check = this->checkCollision(_listGameObj[i]->getBoundingBox());

		int id = _listGameObj[i]->getIdType();
		if (id == eIdObject::STONE_COLUMN_1 || id == eIdObject::STONE_COLUMN_2 || id == eIdObject::STONE_COLUMN_3 || id == eIdObject::STONE_COLUMN_4) continue;
		if (check) {
			if (id == eIdObject::NAHBI)
			{
				pNahbi obj = dynamic_cast<pNahbi>(_listGameObj[i]);

				obj->getDamaged(THROW_DAMAGE_ALADDIN);
			}
			else if (id == eIdObject::FAZAL)
			{
				pFazal obj = dynamic_cast<pFazal>(_listGameObj[i]);

				obj->getDamaged(THROW_DAMAGE_ALADDIN);
			}
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