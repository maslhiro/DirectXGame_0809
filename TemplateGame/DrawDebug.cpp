#include "DrawDebug.h"

pDrawDebug DrawDebug::_instance = nullptr;

DrawDebug::DrawDebug()
{
}

pDrawDebug DrawDebug::getInstance()
{
	if (_instance == nullptr) {
		_instance = new DrawDebug();
	}
	return _instance;
}

void DrawDebug::release()
{
	delete _instance;
	_instance = nullptr;
}

void DrawDebug::init()
{
	D3DXCreateLine(DeviceManager::getInstance()->getDevice(), &_lineDraw);
}

void DrawDebug::drawLine(Vec2 start, Vec2 end, DWORD color, float width)
{
	Vec2 _line[] = { start,end };
	_lineDraw->SetWidth(width);

	_lineDraw->Begin();
	_lineDraw->Draw(_line, 2, color);
	_lineDraw->End();
}


void DrawDebug::drawLineHorizontal(int pos, int length, DWORD color, int width)
{
	RECT line;
	line.left = 0;
	line.right = length;
	line.top = pos;
	line.bottom = pos + width;

	auto _spriteHandler = DeviceManager::getInstance()->getSpriteHandler();
	auto _texture = Texture::getInstance();

	Vec3 position = Vec3(0, pos, 0);

	_spriteHandler->Draw(_texture->get(eIdTexture::BOX_RED_TEX),
		&line,
		NULL,
		&position,
		D3DCOLOR_ARGB(255, 255, 255, 255)); // nhung pixel nao co mau trang se duoc to mau nay len


	//Vec2 _line[] = {
	//	Vec2(0,pos),
	//	Vec2(length,pos)
	//};
	//_lineDraw->SetWidth(width);

	//_lineDraw->Begin();
	//_lineDraw->Draw(_line, 2, color);
	//_lineDraw->End();
}


void DrawDebug::drawLineVertical(int pos, int length, DWORD color, int width)
{
	RECT line;
	line.left = pos;
	line.right = pos + width;
	line.top = 0;
	line.bottom = length;

	auto _spriteHandler = DeviceManager::getInstance()->getSpriteHandler();
	auto _texture = Texture::getInstance();

	Vec3 position = Vec3(pos, 0, 0);

	_spriteHandler->Draw(_texture->get(eIdTexture::BOX_RED_TEX),
		&line,
		NULL,
		&position,
		D3DCOLOR_ARGB(255, 255, 255, 255)); // nhung pixel nao co mau trang se duoc to mau nay len


	//Vec2 _line[] = {
	//	Vec2(pos,0),
	//	Vec2(pos,length),
	//};
	//_lineDraw->SetWidth(width);

	//_lineDraw->Begin();
	//_lineDraw->Draw(_line, 2, color);
	//_lineDraw->End();
}



