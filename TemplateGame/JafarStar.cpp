#include "JafarStar.h"

JafarStar::JafarStar() : GameObject()
{
	_idType = eIdObject::JAFAR_STAR;
	_isTerminated = false;
	_isAnimated = true;
	_isFlyed = false;

	_scale = Vec2(2.f, 2.f);

	_flyTime = 0.f;

	_finalPos = Vec3();
	_initPos = Vec3();
	_posPlayer = Vec3();
}

JafarStar::JafarStar(int id) : GameObject(id)
{
	_idType = eIdObject::JAFAR_STAR;
}

void JafarStar::setPosPlayer(Vec3 val)
{
	if (!_isFlyed) {
		_isFlyed = true;
		_posPlayer = val + Vec3(0, 50, 0);

		_initPos = _posWorld;

		if (_posWorld.x > val.x) _finalPos = val + Vec3(-200, -100, 0);
		else _finalPos = val + Vec3(200, -100, 0);

		/*	_RPT0(0, "===============\n");
			_RPT1(0, "[JAFAR STAR] POS PLAYER %f %f \n", _posPlayer.x, _posPlayer.y);
			_RPT1(0, "[JAFAR STAR] POS INIT %f %f \n", _initPos.x, _initPos.y);
			_RPT1(0, "[JAFAR STAR] POS FINAL %f %f \n", _finalPos.x, _finalPos.y);*/

	}

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
	/*_RPT0(0, "========RE=======\n");
	_RPT1(0, "[POS WORLD] %f %f \n", _posWorld.x, _posWorld.y);*/

	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void JafarStar::setExplode()
{
	this->setState(eIdState::EXPLODE);
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
	else if (_isFlyed)
	{
		//_posWorld.x += -100.f*dt;
		if (_flyTime > 1.)
		{
			_isFlyed = false;
			_flyTime = 0.f;
			goto updateAnimation;
		}

		_flyTime += dt;

		float t = _flyTime;

		_posWorld = pow((1 - t), 2)*_initPos + 2 * t*(1 - t)*_posPlayer + pow(t, 2)*_finalPos;

	}

updateAnimation:
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setIsAnimated(true);
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
