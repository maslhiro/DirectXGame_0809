#include "Jafar.h"

Jafar::Jafar() : GameObject()
{
	_idType = eIdObject::JAFAR;

	_isAnimated = true;
	_isTerminated = false;
	posPlayer = Vec3();

	_numBlood = BLOOD_JAFAR;

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

	_listAnimation[eIdState::DAMAGE] = AnimationManager::getInstance()->get(eIdAnimation::FAZAL_DAMAGE);

	_listAnimation[eIdState::ATTACK] = AnimationManager::getInstance()->get(eIdAnimation::JAFAR_THROW);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::ENERMY_EXPLODE);

	this->setState(eIdState::STAND);
}

void Jafar::getDamaged(int val)
{
	_numBlood -= val;
	if (_state != eIdState::DAMAGE && _numBlood > 0)
	{
		this->fixPosAnimation(eIdState::DAMAGE);
		this->setState(eIdState::DAMAGE);
	}
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

	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setIsFlip(_isFlip);

	_curAnimation.update(dt);
}

void Jafar::handlerInput(float)
{
}
