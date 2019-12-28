#include "Bat.h"

Bat::Bat() : GameObject()
{
	_idType = eIdObject::BAT;
	_isTerminated = false;
	_isAnimated = false;
	_speed = 230.f;
	_isFly = false;
	_flyTime = 0.f;
	posPlayer = Vec3();
}

Bat::Bat(int id) : GameObject(id)
{
	_idType = eIdObject::BAT;
}

void Bat::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::BAT_VISIBLE);

	_listAnimation[99] = AnimationManager::getInstance()->get(eIdAnimation::BAT_FLY);

	_listAnimation[98] = AnimationManager::getInstance()->get(eIdAnimation::BAT_ROTATE);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::ENERMY_EXPLODE);

	this->setState(eIdState::NONE);
}

void Bat::setPosPlayer(Vec3 val)
{
	if (!_isFly) {
		posPlayer = val + Vec3(0, 140, 0);

		_initPos = _posWorld;

		_finalPos.x = posPlayer.x + (posPlayer.x - _initPos.x) / 2;
		_finalPos.y = _initPos.y;

	}
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

	if (abs(_posWorld.x - posPlayer.x) <= ATTACK_DISTANCE * 1.5 &&
		abs(_posWorld.y - posPlayer.y) <= ATTACK_DISTANCE * 2 &&
		!_isFly)
	{
		_isAnimated = true;
		_isFly = true;
	}

	if (_state == eIdState::EXPLODE)
	{
		if (_curAnimation.getLoopCount() > 0) {
			_isTerminated = true;
		}
		goto updateAni;
	}

	if (_state == 99)
	{
		if (_curAnimation.getLoopCount() > 0)
		{
			this->setState(eIdState::NONE);
			//_state = eIdState::NONE;
			//_curAnimation = _listAnimation[98];
			_isAnimated = false;

		}
	}
	else if (_isFly)
	{
		// Dung lai de xoay
		if (_flyTime > 2.)
		{
			_flyTime = 0;
			_isFly = false;
			_posWorld = _finalPos;


			this->setState(eIdState::NONE);
			_isAnimated = false;

			goto updateAni;
		}

		_flyTime += dt;

		float t = _flyTime / 2.;

		_posWorld = pow((1 - t), 2)*_initPos + 2 * t*(1 - t)*posPlayer + pow(t, 2)*_finalPos;

	}

updateAni:
	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.update(dt);
}

void Bat::handlerInput(float)
{
}
