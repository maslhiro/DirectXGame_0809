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

	_lineDraw->Begin();
	_lineDraw->SetWidth(width);
	_lineDraw->Draw(_line, 2, color);
	_lineDraw->End();
}
