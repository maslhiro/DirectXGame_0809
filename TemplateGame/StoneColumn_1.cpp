#include "StoneColumn_1.h"

StoneColumn_1::StoneColumn_1() :GameObject()
{
	_idType = eIdObject::STONE_COLUMN_1;
}

void StoneColumn_1::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::STONE_COLUMN_01_VISIBLE);

	this->setState(eIdState::NONE);
}

void StoneColumn_1::render()
{
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void StoneColumn_1::update(float)
{
}

void StoneColumn_1::handlerInput(float)
{
}