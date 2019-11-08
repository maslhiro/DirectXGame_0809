#include "Billy.h"


Billy::Billy()
{
	_input = InputHandler::getInstance();
}

void Billy::loadResource()
{
	//_listAnimation[eIdState::STANDING] = AnimationManager::getInstance()->get(eIdAnimation::BILLY_STANDING);
	//_listAnimation[eIdState::PUNCHING] = AnimationManager::getInstance()->get(eIdAnimation::BILLY_PUNCHING);

	this->setState(eIdState::STANDING);
}

void Billy::render()
{
	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);
	_curAnimation.setIsFlip(_isFlip);
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
		if (_input->getMapKey()[KEY_A]) {
			_RPT0(0, "OK A \n");
			this->setIsFlip(true);
			//this->setIsAnimated(true);

			//_pos.x -= _speed;
		}
		else if (_input->getMapKey()[KEY_D])
		{
			_RPT0(0, "OK D \n");
			this->setIsFlip(false);
			//this->setIsAnimated(true);

			//_pos.x += _speed;
		}
		else if (_input->getMapKey()[KEY_S])
		{
			// Fix pos truoc sau do moi set State
			this->fixPosAnimation(eIdState::PUNCHING);

			this->setState(eIdState::PUNCHING);

			this->setIsAnimated(true);
		}
		else
		{
			this->setIsAnimated(false);
		}
		break;

	case eIdState::PUNCHING:
		if (_curAnimation.getLoopCount() == 1) {

			this->fixPosAnimation(eIdState::STANDING);

			this->setState(eIdState::STANDING);
		}

		break;
	default:
		break;
	}

}
