#include "MenuScene.h"

MenuScene::MenuScene() :Scene()
{
}


MenuScene::~MenuScene()
{
}

void MenuScene::init()
{
	_texture = Texture::getInstance();

	_device = DeviceManager::getInstance();

	_aniManager = AnimationManager::getInstance();

	_sceneManager = SceneManager::getInstance();

	_sound = Sound::getInstance();

	_index = 0;
}

void MenuScene::loadResource()
{
	_listChar["a" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_01);
	_listChar["b" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_02);
	_listChar["c" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_03);
	_listChar["d" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_04);
	_listChar["e" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_05);
	_listChar["f" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_06);
	_listChar["g" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_07);
	_listChar["h" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_08);
	_listChar["i" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_09);
	_listChar["j" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_10);
	_listChar["k" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_11);
	_listChar["l" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_12);
	_listChar["m" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_13);
	_listChar["n" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_14);
	_listChar["o" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_15);
	_listChar["p" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_16);
	_listChar["q" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_17);
	_listChar["r" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_18);
	_listChar["s" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_19);
	_listChar["t" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_20);
	_listChar["u" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_21);
	_listChar["v" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_22);
	_listChar["w" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_23);
	_listChar["x" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_24);
	_listChar["y" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_25);
	_listChar["z" - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_26);
	_listChar[" " - "0"] = AnimationManager::getInstance()->get(eIdAnimation::TEXT_PEDDLER_27);

	_curChar01.clear();
	_curChar01.push_back(_listChar["s" - "0"]);
	_curChar01.push_back(_listChar["u" - "0"]);
	_curChar01.push_back(_listChar["t" - "0"]);
	_curChar01.push_back(_listChar["a" - "0"]);
	_curChar01.push_back(_listChar["n" - "0"]);
	_curChar01.push_back(_listChar["s" - "0"]);
	_curChar01.push_back(_listChar[" " - "0"]);
	_curChar01.push_back(_listChar["d" - "0"]);
	_curChar01.push_back(_listChar["u" - "0"]);
	_curChar01.push_back(_listChar["n" - "0"]);
	_curChar01.push_back(_listChar["g" - "0"]);
	_curChar01.push_back(_listChar["e" - "0"]);
	_curChar01.push_back(_listChar["o" - "0"]);
	_curChar01.push_back(_listChar["n" - "0"]);

	_curChar02.clear();
	_curChar02.push_back(_listChar["j" - "0"]);
	_curChar02.push_back(_listChar["a" - "0"]);
	_curChar02.push_back(_listChar["f" - "0"]);
	_curChar02.push_back(_listChar["a" - "0"]);
	_curChar02.push_back(_listChar["r" - "0"]);
	_curChar02.push_back(_listChar["s" - "0"]);
	_curChar02.push_back(_listChar[" " - "0"]);
	_curChar02.push_back(_listChar["p" - "0"]);
	_curChar02.push_back(_listChar["l" - "0"]);
	_curChar02.push_back(_listChar["a" - "0"]);
	_curChar02.push_back(_listChar["c" - "0"]);
	_curChar02.push_back(_listChar["e" - "0"]);

	_sound->stopAll();
	_sound->playLoop(eIdSound::S_MENU);
}

void MenuScene::update(float dt)
{

}

void MenuScene::render()
{
	Vec3 pos = Vec3(320, 220, 0);
	RECT _view;
	_view.left = pos.x - _device->getWidthWindow() / 2;
	_view.right = pos.x + _device->getWidthWindow() / 2;
	_view.top = pos.y - _device->getHeightWindow() / 2;
	_view.bottom = pos.y + _device->getHeightWindow() / 2;

	_device->getSpriteHandler()->Draw(_texture->get(eIdTexture::MENU_TEX), &_view, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	RECT _logo;
	_logo.left = 748;
	_logo.top = 630;
	_logo.right = 992;
	_logo.bottom = 721;

	_device->getSpriteHandler()->Draw(_texture->get(eIdTexture::ITEM_TEX), &_logo, NULL, &Vec3(200, 50, 0), D3DCOLOR_XRGB(255, 255, 255));

	for (size_t i = 0; i < _curChar01.size(); i++)
	{
		_curChar01[i].setPosition(Vec3(200, 250, 0) + Vec3(20 * i, 0, 0));
		_curChar01[i].setScale(Vec2(2.f, 2.f));
		_curChar01[i].render(_device, _texture);
	}

	for (size_t i = 0; i < _curChar02.size(); i++)
	{
		_curChar02[i].setPosition(Vec3(200, 300, 0) + Vec3(20 * i, 0, 0));
		_curChar02[i].setScale(Vec2(2.f, 2.f));
		_curChar02[i].render(_device, _texture);
	}

	RECT _cursor;
	_cursor.left = 641;
	_cursor.top = 1111;
	_cursor.right = 674;
	_cursor.bottom = 1123;


	Vec3 posCursor = _index ? Vec3(150, 295, 0) : Vec3(150, 245, 0);

	_device->getSpriteHandler()->Draw(_texture->get(eIdTexture::ITEM_TEX), &_cursor, NULL, &posCursor, D3DCOLOR_XRGB(255, 255, 255));

}

void MenuScene::handlerInput(float dt)
{
	if (_input->getMapKey()[KEY_W])
	{
		_index = 0;
		_sound->play(eIdSound::S_MENU_SELECT);
	}
	else if (_input->getMapKey()[KEY_S])
	{
		_index = 1;
		_sound->play(eIdSound::S_MENU_SELECT);
	}
	else if (_input->getMapKey()[KEY_H])
	{
		_sceneManager->navigateScene(_index ? eIdScene::SE_JAFAR : eIdScene::SE_DUNGEON);
	}
}

void MenuScene::reset()
{
}

void MenuScene::replaySound()
{
	if (_sound == nullptr) return;

	_sound->stopAll();
	_sound->playLoop(eIdSound::S_MENU);
}

void MenuScene::release()
{

}
