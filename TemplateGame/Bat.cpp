#include "Bat.h"

Bat::Bat() : GameObject()
{
	_idType = eIdObject::BAT;
	_isTerminated = false;
	_isAnimated = false;
	_dx = -100.f;

	_posX = 0.f;
}

Bat::Bat(int id) : GameObject(id)
{
	_idType = eIdObject::BAT;
}

void Bat::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::BAT_VISIBLE);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::ENERMY_EXPLODE);

	this->setState(eIdState::NONE);
}

void Bat::setPosXPlayer(Vec3 val)
{
	_posX = val.x;
	_posY = val.y;
}

void Bat::getDamaged(int)
{
}

void Bat::render()
{
	if (_isTerminated) return;

	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void Bat::update(float dt)
{
	if (_isTerminated) return;

	if (abs(_posWorld.x - _posX) <= ATTACK_DISTANCE && !_isAnimated)
	{
		_isAnimated = true;
	}

	if (_state == eIdState::EXPLODE)
	{
		if (_curAnimation.getLoopCount() > 0) {
			_isTerminated = true;
		}
		goto updateAni;
	}
	else if (_isAnimated)
	{
		_posWorld.x += _dx * dt;
		//_posWorld.y += _gravity * dt;
		_posWorld.y += abs(_dx) * dt;
	}

updateAni:
	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.update(dt);
}

void Bat::handlerInput(float)
{
}
