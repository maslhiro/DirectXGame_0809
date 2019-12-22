#include "Peddler.h"

Peddler::Peddler() : GameObject()
{
	_idType = eIdObject::PEDDLER;
	_isAnimated = false;
	_isTerminated = false;
	_timeShow = 0.f;
	_timeFlash = 0.f;
	_isFlash = false;
	posPlayer = Vec3();
}

Peddler::Peddler(int id) : GameObject(id)
{
	_idType = eIdObject::PEDDLER;
}

void Peddler::setPosPlayer(Vec3 val)
{
	posPlayer = val;
}


void Peddler::loadResource()
{
	_listAnimation[eIdState::WAIT_01] = AnimationManager::getInstance()->get(eIdAnimation::PEDDLER_IDLE);

	_listAnimation[eIdState::SELL] = AnimationManager::getInstance()->get(eIdAnimation::PEDDLER_SELL);

	_listAnimation[eIdState::PREPARE] = AnimationManager::getInstance()->get(eIdAnimation::PEDDLER_PREPARE);

	_listChar["a" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_01);
	_listChar["b" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_02);
	_listChar["c" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_03);
	_listChar["d" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_04);
	_listChar["e" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_05);
	_listChar["f" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_06);
	_listChar["g" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_07);
	_listChar["h" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_08);
	_listChar["i" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_09);
	_listChar["j" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_10);
	_listChar["k" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_11);
	_listChar["l" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_12);
	_listChar["m" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_13);
	_listChar["n" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_14);
	_listChar["o" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_15);
	_listChar["p" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_16);
	_listChar["q" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_17);
	_listChar["r" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_18);
	_listChar["s" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_19);
	_listChar["t" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_20);
	_listChar["u" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_21);
	_listChar["v" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_22);
	_listChar["w" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_23);
	_listChar["x" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_24);
	_listChar["y" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_25);
	_listChar["z" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_26);
	_listChar[" " - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_27);
	this->setState(eIdState::WAIT_01);
}

void Peddler::buySuccess()
{
	Sound::getInstance()->playNew(eIdSound::S_CASH_REGISTER);
	_curChar.clear();

	_curChar.push_back(_listChar["i" - "0"]);
	_curChar.push_back(_listChar["t" - "0"]);
	_curChar.push_back(_listChar[" " - "0"]);
	_curChar.push_back(_listChar["i" - "0"]);
	_curChar.push_back(_listChar["s" - "0"]);
	_curChar.push_back(_listChar[" " - "0"]);
	_curChar.push_back(_listChar["a" - "0"]);
	_curChar.push_back(_listChar[" " - "0"]);
	_curChar.push_back(_listChar["d" - "0"]);
	_curChar.push_back(_listChar["e" - "0"]);
	_curChar.push_back(_listChar["a" - "0"]);
	_curChar.push_back(_listChar["l" - "0"]);
}

void Peddler::buyFail()
{
	Sound::getInstance()->playNew(eIdSound::S_CASH_REGISTER);
	_curChar.clear();

	_curChar.push_back(_listChar["f" - "0"]);
	_curChar.push_back(_listChar["i" - "0"]);
	_curChar.push_back(_listChar["n" - "0"]);
	_curChar.push_back(_listChar["d" - "0"]);
	_curChar.push_back(_listChar[" " - "0"]);
	_curChar.push_back(_listChar["m" - "0"]);
	_curChar.push_back(_listChar["o" - "0"]);
	_curChar.push_back(_listChar["r" - "0"]);
	_curChar.push_back(_listChar["e" - "0"]);
	_curChar.push_back(_listChar[" " - "0"]);
	_curChar.push_back(_listChar["c" - "0"]);
	_curChar.push_back(_listChar["o" - "0"]);
	_curChar.push_back(_listChar["i" - "0"]);
	_curChar.push_back(_listChar["n" - "0"]);

}

int Peddler::getState()
{
	return _state;
}

void Peddler::render()
{
	if (_isTerminated) return;

	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);

	for (size_t i = 0; i < _curChar.size(); i++)
	{
		_curChar[i].setPosition(_posWorld + Vec3(30 * i, 150, 0) - Vec3(300, 0, 0));
		_curChar[i].setScale(Vec2(3.f, 3.f));
		_curChar[i].setIsFlash(_isFlash);
		_curChar[i].render(_device, _texture);
	}

}

void Peddler::fixPosBottom(int nextState)
{
	float fixBottom = this->fixPosHeight(nextState);
	float fixLeft = (nextState == eIdState::PREPARE ? 0 : 40);

	this->setPositionWorld(_posWorld.x + fixLeft, _posWorld.y + fixBottom * _scale.y);
}

void Peddler::update(float dt)
{
	if (_isTerminated) return;

	if (abs(_posWorld.x - posPlayer.x) <= ATTACK_DISTANCE && abs(_posWorld.y - posPlayer.y) <= ATTACK_DISTANCE)
	{
		_isAnimated = true;
	}

	if (_state == eIdState::WAIT_01)
	{
		if (_curAnimation.getLoopCount() > 0)
		{
			this->fixPosBottom(eIdState::PREPARE);
			this->setState(eIdState::PREPARE);
		}
	}
	else if (_state == eIdState::PREPARE)
	{
		if (_curAnimation.getCurrentFrame() == 12)
		{
			Sound::getInstance()->play(eIdSound::S_PEDDLER_SHOP);
		}

		if (_curAnimation.getLoopCount() > 0)
		{
			this->fixPosBottom(eIdState::SELL);
			this->setState(eIdState::SELL);
		}
	}

	srand(time(NULL));
	if (_timeFlash > 0.4f)
	{
		_timeFlash = 0.f;
		_isFlash = !_isFlash;
	}
	else
	{
		_timeFlash += dt;
	}

	if (_timeShow > 2.f)
	{
		_curChar.clear();
		_timeShow = 0.f;
		_timeFlash = 0.f;
	}

	if (_curChar.size() > 0)
	{
		_timeShow += dt;
	}

	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setDrawingBound(false);
	_curAnimation.update(dt);
}

void Peddler::handlerInput(float)
{
}
