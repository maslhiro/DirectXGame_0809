#include "Tank.h"

Tank::Tank()
{
	_input = InputHandler::getInstance();
}

void Tank::loadResource()
{
	Animation animationRun = AnimationManager::getInstance()->get(eIdAnimation::TANK_RUNNING);

	_listAnimation[eIdState::RUNNING] = AnimationManager::getInstance()->get(eIdAnimation::TANK_RUNNING);

	_curAnimation = _listAnimation[eIdState::RUNNING];
}

void Tank::render()
{
	// Kiem tra state co thay doi ko ? de tao _curAnimation moi
	// de khong lost _curAnimation khi update 
	// HAM DO CODE SAU -_-

	_curAnimation.setPosition(_pos);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);

}

void Tank::update(float dt)
{
	_curAnimation.update(dt);
}

void Tank::handlerInput()
{
	_keys = _input->getMapKey();

	//A
	if (_input->_keys[65]) {
		_pos.x -= 1;
	}

	// DD
	if (_input->_keys[68]) {
		_pos.x += 2;
	}

}
