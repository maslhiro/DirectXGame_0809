#include "Bat.h"

Bat::Bat() : GameObject()
{
	_idType = eIdObject::BAT;
	_isTerminated = false;
	_isAnimated = false;
	_speed = 230.f;
	_isFly = 0;
	_backwardTime = 0.f;
	posPlayer = Vec3();
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

void Bat::setPosPlayer(Vec3 val)
{
	if (_isFly != 1) posPlayer = val;
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

	if (abs(_posWorld.x - posPlayer.x) <= ATTACK_DISTANCE &&
		abs(_posWorld.y - posPlayer.y) <= ATTACK_DISTANCE * 2 &&
		!_isAnimated)
	{
		_isAnimated = true;
		_isFly = 1;
	}

	if (_state == eIdState::EXPLODE)
	{
		if (_curAnimation.getLoopCount() > 0) {
			_isTerminated = true;
		}
		goto updateAni;
	}

	if (_isAnimated)
	{
		if (_isFly == 1)
		{
			if (_posWorld.y > posPlayer.y - 10)
			{
				_isFly = -1;
			}
			else
			{
				_dx = _posWorld.x > posPlayer.x ? -_speed : _speed;
				_posWorld.x += _dx * dt;
				_posWorld.y += _speed * dt;
			}
		}
		else if (_isFly == 2)
		{
			_backwardTime += dt;

			if (_backwardTime > 0.5f)
			{
				_isFly = 1;
				_backwardTime = 0.f;
			}

			_posWorld.x += _dx * dt;
			_posWorld.y += _speed * dt;
		}
		else if (_isFly == -1)
		{
			_backwardTime += dt;

			if (_backwardTime > 0.6f && _backwardTime < 0.7f)
			{
				_dx = _speed;
			}
			else if (_backwardTime >= 1.f)
			{
				_isFly = 2;
				_backwardTime = 0.f;
			}

			_posWorld.x += _dx * dt;
			_posWorld.y += -_speed * dt;
		}
	}

updateAni:
	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.update(dt);
}

void Bat::handlerInput(float)
{
}
