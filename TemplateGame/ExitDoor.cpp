#include "ExitDoor.h"

ExitDoor::ExitDoor() :GameObject()
{
	_idType = eIdObject::EXIT_DOOR;
}

void ExitDoor::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::EXIT_DOOR_VISIBLE);

	this->setState(eIdState::NONE);
}

void ExitDoor::render()
{
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void ExitDoor::update(float)
{
}

void ExitDoor::handlerInput(float)
{
}