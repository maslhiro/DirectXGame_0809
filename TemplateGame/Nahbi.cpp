#include "Nahbi.h"

Nahbi::Nahbi() : GameObject()
{
	_idType = eIdObject::NAHBI;
	_isTerminated = false;
	_dx = -10.f;
}

Nahbi::Nahbi(int id) : GameObject(id)
{
	_idType = eIdObject::NAHBI;
}

void Nahbi::loadResource()
{
	_listAnimation[eIdState::STAND] = AnimationManager::getInstance()->get(eIdAnimation::NAHBI_STAND);

	_listAnimation[eIdState::RUN] = AnimationManager::getInstance()->get(eIdAnimation::NAHBI_RUN);

	_listAnimation[eIdState::ATTACK] = AnimationManager::getInstance()->get(eIdAnimation::NAHBI_ATTACK);

	this->setState(eIdState::STAND);
}

void Nahbi::render()
{
	if (_isTerminated) return;

	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void Nahbi::update(float dt)
{
	if (_isTerminated) return;

	if (_state == eIdState::STAND)
	{
		if (_curAnimation.getLoopCount() > 2) {
			this->fixPosAnimation(eIdState::RUN);
			this->setState(eIdState::RUN);
		}
		goto updateAni;
	}

	if (_state == eIdState::RUN)
	{
		_posWorld.x += _dx * dt;
		if (_curAnimation.getLoopCount() > 2) {
			this->fixPosAnimation(eIdState::ATTACK);
			this->setState(eIdState::ATTACK);
		}
		goto updateAni;
	}


updateAni:
	_curAnimation.update(dt);
}

void Nahbi::handlerInput(float)
{
}
