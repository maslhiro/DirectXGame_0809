#include "JafarStar.h"

JafarStar::JafarStar() : GameObject()
{
	_idType = eIdObject::JAFAR_STAR;
	_isTerminated = false;
	_isAnimated = true;
	_isUp = false;

	t = 0;
	_scale = Vec2(2.f, 2.f);

	_explodeTime = 0.f;
	_initPos = Vec3();
	_vector = Vec3();
}

JafarStar::JafarStar(int id) : GameObject(id)
{
	_idType = eIdObject::JAFAR_STAR;
}

void JafarStar::setPosPlayer(Vec3 val)
{
	_posPlayer = val;
	_vector = _initPos - _posPlayer;

	_vector.x *= 2;

	_speed = abs(_vector.x);
	_gravity = abs(_vector.y);
}

void JafarStar::setInitPos(Vec3 val)
{
	_initPos = val;
}

void JafarStar::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::JAFAR_STAR_THROW);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::JAFAR_STAR_THROW_EXPLODE);

	this->setState(eIdState::NONE);
}

void JafarStar::render()
{
	if (_isTerminated) return;


	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void JafarStar::setExplode()
{
	this->setState(eIdState::EXPLODE);
	_initPos = _posWorld;
}

void JafarStar::update(float dt)
{
	if (_isTerminated) return;

	if (_state == eIdState::EXPLODE)
	{
		if (_curAnimation.getLoopCount() > 0)
		{
			_isTerminated = true;
		}
	}
	else
	{
		if (!_isUp)
		{
			_moveTime += dt;
			_posWorld.x = _initPos.x - _vector.x * _moveTime;
			_posWorld.y = _initPos.y - _vector.y * _moveTime;

			if (_posWorld.x < 0 || _posWorld.x > 1500 || _posWorld.y > 800 || _posWorld.y < 400)
			{
				_isTerminated = true;
				/*	_isUp = true;
					_dx = _speed * (_posWorld.x < 200 ? 1.5 : -1.5);
					_dy = -_gravity / 2;*/
			}
		}
		else
		{
			_posWorld.x += _dx * dt;
			_posWorld.y += _dy * dt;
		}
	}


	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setIsFlip(_isFlip);
	_curAnimation.update(dt);

}

void JafarStar::handlerInput(float)
{
}

bool JafarStar::checkCollisionPlayer(Vec3 pos)
{
	return (abs(pos.x - _posWorld.x) < 20 && abs(pos.y - _posWorld.y) < 40);
}
