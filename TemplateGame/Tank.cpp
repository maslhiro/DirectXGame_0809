#include "Tank.h"

Tank::Tank()
{
	_input = InputHandler::getInstance();
}

void Tank::loadResource()
{
	//_listAnimation[eIdState::RUNNING] = AnimationManager::getInstance()->get(eIdAnimation::TANK_RUNNING);
	//_listAnimation[eIdState::STANDING] = AnimationManager::getInstance()->get(eIdAnimation::TANK_EXPLODING);

	this->setState(eIdState::NONE);
}

void Tank::render()
{
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);

}

void Tank::update(float dt)
{
	_curAnimation.update(dt);
}

void Tank::handlerInput(float)
{
	//switch (_state)
	//{
	//case eIdState::RUNNING:


	//default:
	//	break;
	//}
	//A
	if (_input->_keys[65]) {
		if (_state != eIdState::RUNNING) {
			_state = eIdState::RUNNING;


			// Fix pos animation
			this->fixPosAnimation(_state);
		}
		_posWorld.x -= 1;
	}

	// DD
	else if (_input->_keys[68]) {
		if (_state != eIdState::RUNNING) {
			_state = eIdState::RUNNING;

			// Fix pos animation
			this->fixPosAnimation(_state);
		}
		_posWorld.x += 1;
	}
	else {
		if (_state != eIdState::STANDING) {
			_state = eIdState::STANDING;

			// Fix pos animation
			this->fixPosAnimation(_state);

		}
	}
}

void Tank::fixPosAnimation(int state)
{
	float preHeight = _curAnimation.getHeight();
	_curAnimation = _listAnimation[_state];
	float curHeight = _curAnimation.getHeight();
	this->setPositionWorld(_posWorld.x, _posWorld.y + (preHeight - curHeight));
}
