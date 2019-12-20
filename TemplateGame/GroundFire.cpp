#include "GroundFire.h"

GroundFire::GroundFire() :GameObject()
{
	_isStaticObj = true;
	posPlayer = Vec3();
	posFire = Vec3();
	_scale = Vec2(2.f, 2.f);
	_stop = true;
	_waitTime = 0.1f;
	_idType = eIdObject::GROUND_FIRE;
}

void GroundFire::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::GROUND_FIRE_VISIBLE);
	_curAnimation = _listAnimation[eIdState::NONE];
}

void GroundFire::setPosPlayer(Vec3 val)
{
	if (_isTerminated) return;
	if (_waitTime < .2f) return;

	_waitTime = 0.f;
	_stop = false;

	if (_curAnimation.getLoopCount() > 0)
	{
		posPlayer = val;
		_curAnimation = _listAnimation[eIdState::NONE];
	}
}

void GroundFire::render()
{
	if (_isTerminated) return;

	if (_stop && _curAnimation.getLoopCount() > 2) return;

	if (posPlayer == Vec3()) return;

	Vec3 pos = _posWorld - Vec3(0, 50, 0);


	if (posPlayer.x > _boundingWorld.right)
	{
		pos.x = _boundingWorld.right - 5;
	}
	else if (posPlayer.x < _boundingWorld.left)
	{
		//_RPT1(0, "[RECT] %d %d - %f \n", _boundingWorld.left, _boundingWorld.right, posPlayer.x);

		pos.x = _boundingWorld.left + 5;
	}
	else pos.x = posPlayer.x;

	posFire = pos;

	_curAnimation.setScale(_scale);
	_curAnimation.setPosition(posFire);
	_curAnimation.render(_device, _texture);

}

void GroundFire::stopFire()
{
	_stop = true;
}

void GroundFire::update(float dt)
{
	_waitTime += dt;

	if (_stop && _curAnimation.getLoopCount() > 2) return;

	_curAnimation.update(dt);


}

void GroundFire::handlerInput(float)
{
}

bool GroundFire::checkCollisionFire(RECT r)
{
	RECT _cur = _curAnimation.getBounding();

	if (_curAnimation.getCurrentFrame() < 4) return false;

	return !(
		_cur.left > r.right ||
		_cur.right < r.left ||
		_cur.top > r.bottom ||
		_cur.bottom < r.top);
}
