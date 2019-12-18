#include "Bone.h"

Bone::Bone() : GameObject()
{
	_idType = eIdObject::BONE;
	_isTerminated = false;
	_isAnimated = true;
	_scale = Vec2(2.f, 2.f);
	_gravity = 100.f;
	_distance = 0.f;
}

Bone::Bone(int id) : GameObject(id)
{
	_idType = eIdObject::BONE;
}

void Bone::setListObj(std::vector<pGameObject> list)
{
	_listObj = list;
}

void Bone::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::BONE_VISIBLE);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::APPLE_THROW_EXPLODE);

	this->setState(eIdState::NONE);
}

void Bone::render()
{
	if (_isTerminated) return;

	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);
}

void Bone::update(float dt)
{
	if (_isTerminated) return;


	if (_state == eIdState::EXPLODE)
	{
		if (_curAnimation.getLoopCount() > 0) {
			_isTerminated = true;
		}
	}
	else
	{
		_posWorld.x += _dx * dt;

		_posWorld.y += _gravity * dt;


		for (size_t i = 0; i < _listObj.size(); i++)
		{
			if (_listObj[i]->getIdType() != eIdObject::COLUMN) continue;

			bool check = checkCollision(_listObj[i]->getBoundingBox());

			if (check)
			{
				this->setState(eIdState::EXPLODE);
			}
		}
	}

updateAni:
	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.update(dt);

}

void Bone::handlerInput(float)
{
}
