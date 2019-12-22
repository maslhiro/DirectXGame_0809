#include "CompleteScene.h"


CompleteScene::CompleteScene()
{
}


CompleteScene::~CompleteScene()
{
}

void CompleteScene::init()
{
	_texture = Texture::getInstance();

	_device = DeviceManager::getInstance();

	_aniManager = AnimationManager::getInstance();

	_sceneManager = SceneManager::getInstance();

	_pos = Vec3(560, 400, 0);

	_dx = 120.;
}

void CompleteScene::loadResource()
{
	_listAni[0] = _aniManager->get(eIdAnimation::ALADDIN_DANCE);
	_listAni[0].setIsLoop(true);
	_listAni[0].setIsFlip(true);
	_listAni[0].setPosition(_pos);
	_listAni[0].setScale(Vec2(2, 2));
	//_listAni[0].setDrawingBound(true);

	_listAni[1] = _aniManager->get(eIdAnimation::ABU_RUN);
	_listAni[1].setIsLoop(true);
	_listAni[1].setPosition(_pos + Vec3(100, 30, 0));
	_listAni[1].setScale(Vec2(2, 2));
	//_listAni[1].setDrawingBound(true);

	Sound::getInstance()->stopAll();
	Sound::getInstance()->play(eIdSound::S_LEVEL_COMPLETE);
}

void CompleteScene::update(float dt)
{
	_listAni[1].update(dt);

	_listAni[0].update(dt);

	_pos -= Vec3(_dx*dt, 0, 0);

	if (_pos.x < -100)
	{
		_sceneManager->navigateScene(eIdScene::SE_MENU);
		return;
	}
}

void CompleteScene::render()
{
	RECT re;
	re.left = 740;
	re.top = 325;
	re.right = 1204;
	re.bottom = 607;

	_device->getSpriteHandler()->Draw(
		_texture->get(eIdTexture::ITEM_TEX),
		&re,
		NULL,
		&Vec3(90, 20, 0),
		D3DCOLOR_XRGB(255, 255, 255)
	);
	_listAni[0].setPosition(_pos);

	_listAni[0].render(_device, _texture);

	_listAni[1].setPosition(_pos + Vec3(100, 30, 0));

	_listAni[1].render(_device, _texture);
}

void CompleteScene::handlerInput(float dt)
{

}

void CompleteScene::reset()
{
}

void CompleteScene::replaySound()
{
	//_sound->stopAll();
	//_sound->playLoop(eIdSound::S_MENU);
}

void CompleteScene::release()
{

}
