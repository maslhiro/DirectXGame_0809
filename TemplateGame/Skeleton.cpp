#include "Skeleton.h"

Skeleton::Skeleton() : GameObject()
{
	_idType = eIdObject::SKELETON;
	_isTerminated = false;
}

Skeleton::Skeleton(int id) : GameObject(id)
{
	_idType = eIdObject::SKELETON;
}

void Skeleton::setListObj(std::vector<pGameObject> list)
{
	_listObj = list;
}

void Skeleton::loadResource()
{
	_listAnimation[eIdState::NONE] = AnimationManager::getInstance()->get(eIdAnimation::SKELETON_VISIBLE);

	_listAnimation[eIdState::EXPLODE] = AnimationManager::getInstance()->get(eIdAnimation::ENERMY_EXPLODE);

	//_listAnimation[99] = AnimationManager::getInstance()->get(eIdAnimation::APPLE_EXPLODE);

	this->setState(eIdState::NONE);
}

void Skeleton::render()
{
	if (_isTerminated) return;

	_curAnimation.setIsAnimated(_isAnimated);
	_curAnimation.setPosition(_posWorld);
	_curAnimation.setScale(_scale);

	_curAnimation.render(_device, _texture);

	if (_state == 99)
	{
		for (size_t i = 0; i < _listBone.size(); i++)
		{
			_listBone[i]->render();
		}
	}
}

void Skeleton::update(float dt)
{
	if (_isTerminated) return;

	if (_state == eIdState::EXPLODE)
	{
		if (_curAnimation.getLoopCount() > 0) _isTerminated = true;
	}
	else if (_state == eIdState::NONE)
	{
		if (_curAnimation.getLoopCount() > 0)
		{
			this->setState(99);
			int i = -3;
			while (i < 5)
			{
				pBone bone = new Bone();
				bone->setPositionWorld(_posWorld);
				bone->setListObj(_listObj);
				bone->setDx(80 * i);
				bone->loadResource();
				_listBone.push_back(bone);
				i += 1;
			}

		}
	}
	// Skeleton da no ? chi update bone
	else if (_state == 99)
	{
		if (_curAnimation.getLoopCount() > 0) _curAnimation = _listAnimation[100];

		for (size_t i = 0; i < _listBone.size(); i++)
		{
			_listBone[i]->update(dt);
		}
	}

	_curAnimation.update(dt);
}

void Skeleton::handlerInput(float)
{
}
