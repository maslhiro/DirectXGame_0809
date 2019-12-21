#include "Jafar.h"

Jafar::Jafar() : GameObject()
{
	_idType = eIdObject::JAFAR;

	_isAnimated = true;
	_isTerminated = false;
	posPlayer = Vec3();
	_numThrow = 0;
	_numBlood = BLOOD_JAFAR;
	_throwTime = 0.f;

	_wait = false;
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

	_listAnimation[eIdState::THROW] = AnimationManager::getInstance()->get(eIdAnimation::JAFAR_THROW);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::JAFAR_STAR_THROW_EXPLODE);

	Animation _fire = AnimationManager::getInstance()->get(eIdAnimation::GROUND_FIRE_VISIBLE);

	_fireBehind.push_back(_fire);
	_fireBehind.push_back(_fire);
	_fireBehind.push_back(_fire);

	this->setState(eIdState::STAND);
}

int Jafar::getState()
{
	return _state;
}

void Jafar::getDamaged(int val)
{
	_numBlood -= val;
	if (_numBlood == 150)
	{
		this->setState(eIdState::THROW);
	}
}

void Jafar::render()
{
	if (_isTerminated) return;

	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);
	_curAnimation.render(_device, _texture);

	if (_state == eIdState::THROW)
	{
		// Lua phia sau
		for (size_t i = 0; i < _fireBehind.size(); i++)
		{
			_fireBehind[i].setPosition(_posWorld + Vec3(65 * (i), 15, 0) - Vec3(65, 0, 0));
			_fireBehind[i].setScale(_scale);
			_fireBehind[i].render(_device, _texture);
		}
	}

	for (size_t i = 0; i < _listFlame.size(); i++)
	{
		if (_listFlame[i]->getIsTerminated()) continue;

		_listFlame[i]->setScale(_scale);
		_listFlame[i]->render();
	}

	for (size_t i = 0; i < _listStar.size(); i++)
	{
		if (_listStar[i]->getIsTerminated()) continue;
		_listStar[i]->setScale(_scale);
		_listStar[i]->render();
	}

}

void Jafar::update(float dt)
{
	//_RPT1(0, "BLOOD %d \n", _numBlood);
	std::srand(std::time(0));

	if (_isTerminated) return;

	if (posPlayer.x < _posWorld.x)
	{
		_isFlip = true;
	}
	else {
		_isFlip = false;
	}

	if (_state == eIdState::STAND)
	{
		_waitTime += dt;

		if (_waitTime < 1.f) _wait = true;
		else if (_waitTime >= 1.f && _waitTime <= 2.f) _wait = false;
		else _waitTime = 0.f;

		if (!_wait)
		{
			_throwTime += dt;


			// ket thuc 1 vong loop thi ban ra lua
			if (_throwTime > 0.07)
			{

				_waitTime += _throwTime;
				_throwTime = 0.f;

				_numThrow += 1;
				Vec3 _initPos = _posWorld + Vec3((_isFlip ? -70 : 70), (std::rand() % 11) * -5, 0);
				pJafarStar _star = new JafarStar();
				_star->loadResource();
				_star->setInitPos(_initPos);
				_star->setPosPlayer(posPlayer + Vec3(0, 20, 0));
				_listStar.push_back(_star);
			}
		}
	}


	if (_state == eIdState::THROW)
	{
		_throwTime += dt;

		// ket thuc 1 vong loop thi ban ra lua
		if (_throwTime > 3.f)
		{
			_throwTime = 0.f;
			//_RPT0(0, "[INFFFFIIF]\n");
			Sound::getInstance()->play(eIdSound::S_JAFAR_SNAKE);

			pJafarFlame _flame = new JafarFlame();
			_flame->loadResource();
			_flame->setDirection(_isFlip);
			_flame->setPositionWorld(_posWorld);
			_listFlame.push_back(_flame);
		}
	}

	for (size_t i = 0; i < _listFlame.size(); i++)
	{
		if (_listFlame[i]->getIsTerminated()) continue;

		_listFlame[i]->update(dt);
	}

	int checkTer = 0;
	for (size_t i = 0; i < _listStar.size(); i++)
	{
		if (_listStar[i]->getIsTerminated())
		{
			checkTer += 1;
			continue;
		}
		_listStar[i]->update(dt);
	}

	if (_listStar.size() - checkTer) _numThrow = 0;

	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setIsFlip(_isFlip);

	_curAnimation.update(dt);

	if (_state == eIdState::THROW)
	{
		for (size_t i = 0; i < _fireBehind.size(); i++)
		{
			_fireBehind[i].update(dt);
		}
	}
}

void Jafar::handlerInput(float)
{
}

int Jafar::checkCollisionStar(Vec3 pos)
{
	int num = 0;
	for (size_t i = 0; i < _listStar.size(); i++)
	{
		if (_listStar[i]->getIsTerminated() || _listStar[i]->getState() == eIdState::EXPLODE) continue;

		bool check = _listStar[i]->checkCollisionPlayer(pos);

		if (check) {
			num += 1;
			_listStar[i]->setExplode();
		}

	}
	return num;
}

bool Jafar::checkCollisionFlame(RECT other)
{
	for (size_t i = 0; i < _listFlame.size(); i++)
	{
		if (_listFlame[i]->getIsTerminated()) continue;

		bool check = _listFlame[i]->checkCollision(other);

		if (check && abs(other.left - _listFlame[i]->getBoundingBox().right) >= 40) return check;

	}
	return false;
}
