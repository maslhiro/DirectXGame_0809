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
	ID3DXLine *_lineDraw;

	// index frame hien tai va frame cuoi
	int _currentFrame;
	int _loopCount;

	bool _isLoop;		// default : true , false => chay 1 lan va ko lap 
	bool _isFlip;		// default : false, true => lật ảnh ngược lại
	bool _isAnimated;   // default : true, false => chi hien thi sprite dau tien
	int _typeFixPos;	// default :	1 => fix pos Left BTom sprite dau tien, 
						//				2 => fix pos left top
						//				3 => center

	// Xet sprite xuat hien dau tien sau lần lặp đầu tiên
	// EX => xét = 4 thì trong lần điên nó sẽ chạy đủ hết listSprite nhưng đến lần lặp tiếp sẽ bắt đầu = 4 thay bằng = 0
	int _indexStart;

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
	void setIsFlip(bool);
	void setIsAnimated(bool);
	void setTypeFixPos(int);
	void setIndexStart(int);

	void setPosition(Vec3);
	void setScale(Vec2);
	void setScale(float, float);

	void setDrawingBound(bool);
	void setColorBound(DWORD);

	int getLoopCount();
	bool isLoopDone();

	void release();

	int getSprite(int);
	void addSprite(eIdSprite);
	int render(pDeviceManager, pTexture);
	int update(float);

	// Get width va height MAC DINH cua frame dau tien de GameObjetc fix pos
	// khi chuyen doi giua cac animation
	float getWidth();
	float getHeight();

	float getCurrentWidth();
	float getCurrentHeight();

	int getCurrentFrame();

	// Get bouding cua frame đầu tiên 
	RECT getBounding();

	// Get bouding cua frame theo PosWorld
	// Do các SPRITE có kích thước ko đều nên 
	// Pos đưa vào cho animation 
	// se dc fix theo từng sprite
	RECT getCurrentBounding();

	// Can theo bottom
	float fixPosHeight(RectSprite);

	// Can theo left
	float fixPosWidth(RectSprite);

	std::vector<int> getListSprite();
};

typedef Animation* pAnimation;

