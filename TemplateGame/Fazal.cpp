#include "Fazal.h"

Fazal::Fazal() : GameObject()
{
	_idType = eIdObject::FAZAL;

	_isAnimated = true;
	_isTerminated = false;
	_posX = 0.f;

	_numBlood = BLOOD_FAZAL;

	_isFlip = false;
}

Fazal::Fazal(int id) : GameObject(id)
{
	_idType = eIdObject::FAZAL;
}

void Fazal::setPosXPlayer(float val)
{
	_posX = val;
}


void Fazal::loadResource()
{
	_listAnimation[eIdState::STAND] = AnimationManager::getInstance()->get(eIdAnimation::FAZAL_STAND);

	_listAnimation[eIdState::DAMAGE] = AnimationManager::getInstance()->get(eIdAnimation::FAZAL_DAMAGE);

	_listAnimation[eIdState::ATTACK] = AnimationManager::getInstance()->get(eIdAnimation::FAZAL_ATTACK);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::ENERMY_EXPLODE);

	this->setState(eIdState::STAND);
}

void Fazal::getDamaged(int val)
{
	_numBlood -= val;
	if (_state != eIdState::DAMAGE && _numBlood > 0)
	{
		this->fixPosAnimation(eIdState::DAMAGE);
		this->setState(eIdState::DAMAGE);
	}
}

int Fazal::getState()
{
	return _state;
}

void Fazal::render()
{
	if (_isTerminated) return;

	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void Fazal::update(float dt)
{
	//_RPT1(0, "BLOOD %d \n", _numBlood);

	if (_isTerminated) return;

	if (_numBlood <= 0 && _state != eIdState::EXPLODE)
	{
		this->setState(eIdState::EXPLODE);
	}

	if (_posX < _posWorld.x)
	{
		_isFlip = true;
	}
	else {
		_isFlip = false;
	}
	if (_state != eIdState::EXPLODE && _state != eIdState::DAMAGE)
	{
		if (abs(_posWorld.x - _posX) <= ATTACK_DISTANCE & _state != eIdState::ATTACK)
		{
			this->fixPosAnimation(eIdState::ATTACK);
			this->setState(eIdState::ATTACK);
		}
		else if (abs(_posWorld.x - _posX) > ATTACK_DISTANCE)
		{
			this->fixPosAnimation(eIdState::STAND);
			this->setState(eIdState::STAND);
		}

	}
	else if (_state == eIdState::EXPLODE)
	{
		if (_curAnimation.getLoopCount() > 0)
		{
			_isTerminated = true;
		}
	}
	else if (_state == eIdState::DAMAGE)
	{
		if (_curAnimation.getLoopCount() > 0)
		{
			this->fixPosAnimation(eIdState::STAND);
			this->setState(eIdState::STAND);
		}
	}


	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setIsFlip(_isFlip);

	_curAnimation.update(dt);
}

void Fazal::handlerInput(float)
{
}
