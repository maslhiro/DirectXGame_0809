#include "Nahbi.h"

Nahbi::Nahbi() : GameObject()
{
	_idType = eIdObject::NAHBI;

	_isAnimated = true;
	_isTerminated = false;
	posPlayer = Vec3();

	_waitTime = 0.f;

	_isFlip = false;
	_speed = 35.f;

	_isMovedLeft = _isMovedRight = false;
	_distanceMove = 0.f;

	_numBlood = BLOOD_NAHBI;
}

Nahbi::Nahbi(int id) : GameObject(id)
{
	_idType = eIdObject::NAHBI;
}

void Nahbi::setPosPlayer(Vec3 val)
{
	posPlayer = val;
}


void Nahbi::loadResource()
{
	_listAnimation[eIdState::STAND] = AnimationManager::getInstance()->get(eIdAnimation::NAHBI_STAND);

	_listAnimation[eIdState::WAIT_01] = AnimationManager::getInstance()->get(eIdAnimation::NAHBI_WAIT);

	_listAnimation[eIdState::RUN] = AnimationManager::getInstance()->get(eIdAnimation::NAHBI_RUN);

	_listAnimation[eIdState::ATTACK] = AnimationManager::getInstance()->get(eIdAnimation::NAHBI_ATTACK);

	_listAnimation[eIdState::DAMAGE] = AnimationManager::getInstance()->get(eIdAnimation::NAHBI_DAMAGE);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::ENERMY_EXPLODE);

	this->setState(eIdState::STAND);
}

void Nahbi::getDamaged(int val)
{
	_numBlood -= val;
	if (_state != eIdState::DAMAGE && _numBlood > 0)
	{
		this->fixPosAnimation(eIdState::DAMAGE);
		this->setState(eIdState::DAMAGE);
	}
}

int Nahbi::getState()
{
	return _state;
}

void Nahbi::render()
{
	if (_isTerminated) return;

	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void Nahbi::update(float dt)
{
	if (_isTerminated) return;

	if (_numBlood <= 0 && _state != eIdState::EXPLODE)
	{
		this->setState(eIdState::EXPLODE);
	}

	if (_state != eIdState::EXPLODE && _state != eIdState::DAMAGE)
	{
		if (_state == eIdState::STAND || _state == eIdState::WAIT_01)
		{
			// Kiem tra phia aladdin so voi obj
			if (posPlayer.x < _posWorld.x)
			{
				_isFlip = true;
			}
			else {
				_isFlip = false;
			}

			if (_state == eIdState::WAIT_01)
			{
				if (_curAnimation.getLoopCount() > 2)
				{
					this->fixPosAnimation(eIdState::STAND);
					this->setState(eIdState::STAND);
				}
			}
			else
			{
				_waitTime += dt;
				if (_waitTime >= WAIT_TIME_NAHBI)
				{
					_waitTime = 0.f;
					this->fixPosAnimation(eIdState::WAIT_01);
					this->setState(eIdState::WAIT_01);
				}
			}
			//_RPT1(0, "[NAHBI] %f \n", (abs(_posWorld.x - _posX)));
			// Kiem tra khaong cach hien tai
			if ((abs(_posWorld.x - posPlayer.x) <= MOVE_DISTANCE) &&
				(abs(_posWorld.y - posPlayer.y) <= 10) &&
				(abs(_posWorld.x - posPlayer.x) >= ATTACK_DISTANCE))
			{

				if (posPlayer.x < _posWorld.x && !_isMovedLeft)
				{
					this->setState(eIdState::RUN);
					_isMovedLeft = true;
					this->setDx(-_speed);
				}
				else if (posPlayer.x > _posWorld.x && !_isMovedRight)
				{
					this->setState(eIdState::RUN);
					_isMovedRight = true;
					this->setDx(_speed);
				}
			}
			else if (abs(_posWorld.x - posPlayer.x) < ATTACK_DISTANCE && abs(_posWorld.y - posPlayer.y) < 10)
			{
				this->setState(eIdState::ATTACK);
			}
		}

		if (_state == eIdState::ATTACK)
		{
			if (_curAnimation.getLoopCount() > 2) {
				_waitTime = 0.f;

				// set lai de _curAnimation dc reset
				this->setState(eIdState::STAND);
			}
			goto updateAni;
		}
		else if (_state == eIdState::RUN)
		{
			_posWorld += Vec3(_dx*dt, 0, 0);
			_distanceMove += abs(_dx*dt);

			if (posPlayer.x < _posWorld.x)
			{
				if (!_isFlip)
				{
					_isFlip = true;
					this->setState(eIdState::STAND);
				}
			}
			else {
				if (_isFlip)
				{
					_isFlip = false;
					this->setState(eIdState::STAND);
				}
			}

			if (_distanceMove >= MOVE_DISTANCE * 2. / 3.)
			{
				_distanceMove = 0.f;
				this->setState(eIdState::STAND);
			}
			goto updateAni;
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

updateAni:
	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setIsFlip(_isFlip);

	_curAnimation.update(dt);
}

void Nahbi::handlerInput(float)
{
}
