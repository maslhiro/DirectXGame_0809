#include "DyingScene.h"


DyingScene::DyingScene()
{
}


DyingScene::~DyingScene()
{
}

void DyingScene::init()
{
	_texture = Texture::getInstance();

	_device = DeviceManager::getInstance();

	_aniManager = AnimationManager::getInstance();

	_sceneManager = SceneManager::getInstance();
}

void DyingScene::loadResource()
{
	_listAni[0] = _aniManager->get(eIdAnimation::ALADDIN_DIE);
	_listAni[0].setPosition(Vec3(300, 250, 0));
	_listAni[0].setIsLoop(true);
	_listAni[0].setScale(Vec2(2, 2));
	//_listAni[0].setDrawingBound(true);

	_listAni[1] = _aniManager->get(eIdAnimation::ALADDIN_MASSAGE);
	_listAni[1].setPosition(Vec3(300, 250, 0));
	_listAni[1].setIsLoop(true);
	_listAni[1].setScale(Vec2(2, 2));
	//_listAni[1].setDrawingBound(true);

	_listAni[2] = _aniManager->get(eIdAnimation::ABU_MASSAGE);
	_listAni[2].setPosition(Vec3(400, 350, 0));
	_listAni[2].setIsLoop(true);
	_listAni[2].setScale(Vec2(2, 2));
	//_listAni[2].setDrawingBound(true);

}

void DyingScene::update(float dt)
{
	if (_listAni[0].getLoopCount() > 2)
	{
		_listAni[1].update(dt);
	}
	else
	{
		_listAni[0].update(dt);
	}

	_listAni[2].update(dt);

	if (_listAni[1].getLoopCount() > 4)
	{
		_sceneManager->navigateScene(0);
	}
}

void DyingScene::render()
{

	if (_listAni[0].getLoopCount() > 2)
	{
		_listAni[1].render(_device, _texture);
	}
	else _listAni[0].render(_device, _texture);

	_listAni[2].render(_device, _texture);
}

void DyingScene::handlerInput(float dt)
{

}

void DyingScene::release()
{

}
