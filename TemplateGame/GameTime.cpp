#include "GameTime.h"

GameTime* GameTime::_instance = nullptr;

GameTime::GameTime(void)
{
}

GameTime::~GameTime(void)
{
}

GameTime* GameTime::getInstance()
{
	if (_instance == nullptr)
		_instance = new GameTime();
	return _instance;
}

void GameTime::release()
{
	delete _instance;
	_instance = nullptr;
}

void GameTime::init()
{
	QueryPerformanceFrequency(&this->_frequency);
	//// Ham tra ve microsecond
	//// 10000000 : microsecond.
	//// milisecond : 1000
	//// second :1

	QueryPerformanceCounter(&_timer);

	_lastTicks = _timer.QuadPart;

	_totalGameTime = 0;
}

void GameTime::updateGameTime()
{
	QueryPerformanceCounter(&_timer);
	_curTicks = _timer.QuadPart;

	this->_elapsedGameTime = ((float)(_curTicks - _lastTicks)) / _frequency.QuadPart;

	this->setTotalGameTime(_totalGameTime + _elapsedGameTime);

	_lastTicks = _curTicks;

}

void GameTime::setTotalGameTime(float totalTime) {
	_totalGameTime = totalTime;
}

float GameTime::getElapsedGameTime() {
	return this->_elapsedGameTime;
}


float GameTime::getTotalGameTime() {
	return this->_totalGameTime;
}