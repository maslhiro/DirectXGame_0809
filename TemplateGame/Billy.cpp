#include "Billy.h"


Billy::Billy()
{
	_input = InputHandler::getInstance();
}

void Billy::loadResource()
{
	_listAnimation[eIdState::STANDING] = AnimationManager::getInstance()->get(eIdAnimation::BILLY_STANDING);
	_listAnimation[eIdState::PUNCHING] = AnimationManager::getInstance()->get(eIdAnimation::BILLY_PUNCHING);

	_state = eIdState::STANDING;
	_curAnimation = _listAnimation[_state];
}

void Billy::render()
{
	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setPosition(_pos);
	_curAnimation.setScale(_scale);
	_curAnimation.setIsReverse(_isReverse);
	_curAnimation.render(_device, _texture);

}

void Billy::update(float dt)
{
	_curAnimation.update(dt);
}

void Billy::handlerInput()
{
	switch (_state)
	{
	case eIdState::STANDING:
		if (_input->_keys[65]) {
			//_state = eIdState::PUNCHING;
			this->setIsReverse(true);
			this->setIsAnimated(true);
			// Fix pos animation
			//this->fixPosAnimation(_state);
			_pos.x -= 1;
		}
		else if (_input->_keys[68])
		{
			//_state = eIdState::PUNCHING;
			this->setIsReverse(false);
			this->setIsAnimated(true);
			// Fix pos animation
			//this->fixPosAnimation(_state);
			_pos.x += 1;
		}
		else {
			this->setIsAnimated(false);
		}

	default:
		break;
	}
	//A
	//if (_input->_keys[65]) {
	//	if (_state != eIdState::RUNNING) {
	//		_state = eIdState::RUNNING;


	//		// Fix pos animation
	//		this->fixPosAnimation(_state);
	//	}
	//	_pos.x -= 1;
	//}

	//// DD
	//else if (_input->_keys[68]) {
	//	if (_state != eIdState::RUNNING) {
	//		_state = eIdState::RUNNING;

	//		// Fix pos animation
	//		this->fixPosAnimation(_state);
	//	}
	//	_pos.x += 1;
	//}
	//else {
	//	if (_state != eIdState::STANDING) {
	//		_state = eIdState::STANDING;

	//		// Fix pos animation
	//		this->fixPosAnimation(_state);

	//	}
	//}
}

void Billy::fixPosAnimation(int state)
{
	float preHeight = _curAnimation.getHeight();
	_curAnimation = _listAnimation[_state];
	float curHeight = _curAnimation.getHeight();
	this->setPosition(_pos.x, _pos.y + (preHeight - curHeight));
}
