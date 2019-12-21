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

	_listAnimation[eIdState::EXPLODE_] = AnimationManager::getInstance()->get(eIdAnimation::APPLE_THROW_EXPLODE_);

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
	if (_state == eIdState::EXPLODE || _state == eIdState::EXPLODE_)
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
		if (_listGameObj[i]->getIsTerminated()) continue;

		int id = _listGameObj[i]->getIdType();
		if (id == eIdObject::STONE_COLUMN_1 ||
			id == eIdObject::WRECKING_BALL ||
			id == eIdObject::SPIKE ||
			id == eIdObject::ROCK ||
			id == eIdObject::ROPE ||
			id == eIdObject::COIN ||
			id == eIdObject::SAVE_POINT ||
			id == eIdObject::EXTRA_HEALTH ||
			id == eIdObject::APPLE ||
			id == eIdObject::STONE_COLUMN_2 ||
			id == eIdObject::STONE_COLUMN_3 ||
			id == eIdObject::STONE_COLUMN_4) continue;

		bool check = this->checkCollision(_listGameObj[i]->getCurrentBoudingBox());

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
			else if (id == eIdObject::BAT)
			{
				pBat bat = dynamic_cast<pBat>(_listGameObj[i]);
				bat->setIsAnimated(true);
				Sound::getInstance()->playNew(eIdSound::S_ENERMY_EXPLODE);
				bat->setState(eIdState::EXPLODE);
			}
			else if (id == eIdObject::SKELETON)
			{
				pSkeleton ke = dynamic_cast<pSkeleton>(_listGameObj[i]);
				Sound::getInstance()->playNew(eIdSound::S_ENERMY_EXPLODE);
				ke->setIsAnimated(true);
				ke->setState(eIdState::EXPLODE);
			}
			else if (id == eIdObject::JAFAR)
			{
				pJafar ja = dynamic_cast<pJafar>(_listGameObj[i]);

				ja->getDamaged(THROW_DAMAGE_ALADDIN);

			}

			this->setState(id != eIdObject::JAFAR ? eIdState::EXPLODE : eIdState::EXPLODE_);

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