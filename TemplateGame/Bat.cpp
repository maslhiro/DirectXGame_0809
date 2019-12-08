#include "Bat.h"

Bat::Bat() : GameObject()
{
	_idType = eIdObject::BAT;
	_isTerminated = false;
	_dx = -10.f;
}

Bat::Bat(int id) : GameObject(id)
{
	_idType = eIdObject::BAT;
}

void Bat::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::BAT_VISIBLE);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::APPLE_EXPLODE);

	this->setState(eIdState::NONE);
}

void Bat::render()
{
	if (_isTerminated) return;

	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void Bat::update(float dt)
{
	if (_isTerminated) return;

	if (_state == eIdState::EXPLODE)
	{
		if (_curAnimation.getLoopCount() > 0) {
			_isTerminated = true;
		}
		goto updateAni;
	}


	_posWorld.x += _dx * dt;
	//_posWorld.y += _gravity * dt;
	_posWorld.y += abs(_dx) * dt;

updateAni:
	_curAnimation.update(dt);
}

void Bat::handlerInput(float)
{
}
