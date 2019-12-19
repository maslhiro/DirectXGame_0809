#include "Jafar.h"

Jafar::Jafar() : GameObject()
{
	_idType = eIdObject::JAFAR;

	_isAnimated = true;
	_isTerminated = false;
	posPlayer = Vec3();

	_numBlood = BLOOD_JAFAR;
	_throwTime = 0.f;
	_isFlip = false;
}

Jafar::Jafar(int id) : GameObject(id)
{
	_idType = eIdObject::JAFAR;
}

void Jafar::setPosPlayer(Vec3 val)
{
	posPlayer = val;
}


void Jafar::loadResource()
{
	_listAnimation[eIdState::STAND] = AnimationManager::getInstance()->get(eIdAnimation::JAFAR_SLASH);

	_listAnimation[eIdState::THROW] = AnimationManager::getInstance()->get(eIdAnimation::JAFAR_THROW);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::ENERMY_EXPLODE);

	Animation _fire = AnimationManager::getInstance()->get(eIdAnimation::GROUND_FIRE_VISIBLE);

	_fireBehind.push_back(_fire);
	_fireBehind.push_back(_fire);
	_fireBehind.push_back(_fire);

	this->setState(eIdState::THROW);
}

void Jafar::getDamaged(int val)
{
	_numBlood -= val;
}

int Jafar::getState()
{
	return _state;
}

void Jafar::render()
{
	if (_isTerminated) return;

	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);
	_curAnimation.render(_device, _texture);

	if (_state == eIdState::THROW)
	{
		// Lua phia sau
		for (size_t i = 0; i < _fireBehind.size(); i++)
		{
			_fireBehind[i].setPosition(_posWorld + Vec3(65 * (i), 15, 0) - Vec3(65, 0, 0));
			_fireBehind[i].setScale(_scale);
			_fireBehind[i].render(_device, _texture);
		}
	}

	for (size_t i = 0; i < _listFlame.size(); i++)
	{
		if (_listFlame[i]->getIsTerminated()) continue;

		_listFlame[i]->setScale(_scale);
		_listFlame[i]->render();
	}

}

void Jafar::update(float dt)
{
	//_RPT1(0, "BLOOD %d \n", _numBlood);

	if (_isTerminated) return;

	if (posPlayer.x < _posWorld.x)
	{
		_isFlip = true;
	}
	else {
		_isFlip = false;
	}

	if (_state == eIdState::THROW)
	{
		_throwTime += dt;
		// ket thuc 1 vong loop thi ban ra lua
		if (_throwTime > 3.f)
		{
			_throwTime = 0.f;
			_RPT0(0, "[INFFFFIIF]\n");
			pJafarFlame _flame = new JafarFlame();
			_flame->loadResource();
			_flame->setDirection(_isFlip);
			_flame->setPositionWorld(_posWorld);
			_listFlame.push_back(_flame);
		}
	}

	for (size_t i = 0; i < _listFlame.size(); i++)
	{
		if (_listFlame[i]->getIsTerminated()) continue;

		_listFlame[i]->update(dt);
	}

	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setIsFlip(_isFlip);

	_curAnimation.update(dt);

	if (_state == eIdState::THROW)
	{
		for (size_t i = 0; i < _fireBehind.size(); i++)
		{
			_fireBehind[i].update(dt);
		}
	}
}

void Jafar::handlerInput(float)
{
}

bool Jafar::checkCollisionFlame(RECT other)
{
	for (size_t i = 0; i < _listFlame.size(); i++)
	{
		if (_listFlame[i]->getIsTerminated()) continue;

		bool check = _listFlame[i]->checkCollision(other);

		if (check && _listFlame[i]->getCurrentFrame() == 4) return check;

	}
	return false;
}
