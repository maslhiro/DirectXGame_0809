#pragma once
#include "define.h"
#include "Sprite.h"
#include "Texture.h"

class Animation
{
private:

	pSprite _sprite;

	float _timePerFrame;
	float _totalTime;

	bool _drawingBound;
	DWORD  _colorBound;
	ID3DXLine *lineDraw;

	// index frame hien tai va framcuoi
	int _currentFrame;

	// Vi tri vẽ sprite lên màn hình
	Vec3 _position;

	// scale sprite
	Vec2 _scale;

	std::vector<int> _listSpriteId;
	// Fix pos cho từng frame , khi add 1 sprite mới sẽ tự fix pos frame đó với 
	std::vector<Vec3> _fixPosVec;

	std::vector<Vec3> _listOrigin;

public:
	Animation();
	~Animation();

	void setTimePerFrame(float);

	void setPosition(Vec3);
	void setScale(Vec2);

	void setDrawingBound(bool);
	void setColorBound(DWORD);

	void init(float);

	void release();

	int getSprite(int);
	void addSprite(eIdSprite);
	int render(pDeviceManager, pTexture);
	int update(float);

	std::vector<int> getListSprite();
};

typedef Animation* pAnimation;

