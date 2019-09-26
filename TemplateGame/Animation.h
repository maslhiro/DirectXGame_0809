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

	// index frame hien tai va frame cuoi
	int _currentFrame;
	int _loopCount;
	bool _isLoop;		// default : true , false => chay 1 lan va ko lap 
	bool _isReverse;	// default false,  true => lật ảnh ngược lại
	bool _isAnimated;   // default true, false => chi hien thi sprite dau tien

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

	void setIsLoop(bool);
	void setIsReverse(bool);
	void setIsAnimated(bool);

	void setPosition(Vec3);
	void setScale(Vec2);
	void setScale(float, float);

	void setDrawingBound(bool);
	void setColorBound(DWORD);

	void release();

	int getSprite(int);
	void addSprite(eIdSprite);
	int render(pDeviceManager, pTexture);
	int update(float);

	// Get width va heigt frame dau tien cua Animation de fix pos
	// khi Obj chuyen doi giua cac animation
	float getWidth();
	float getHeight();

	// Can theo bottom
	float fixPosHeight(RectSprite);

	// Can theo left
	float fixPosWidth(RectSprite);

	std::vector<int> getListSprite();
};

typedef Animation* pAnimation;

