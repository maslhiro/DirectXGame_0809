#pragma once
#include "define.h"
#include "Texture.h"
#include "Animation.h"
#include "DeviceManager.h"
#include "AnimationManager.h"

class GameObject
{
protected:

	int _id;

	// Chia Id de phan biet cac the loai game obj :)))
	int _idType;

	// Static obj : land, pillar, rope, ..
	bool _isStaticObj;
	// Lưu lại rect của các obj như land, rope,.. bởi vì chúng nó đéo có animation
	RECT _boudingWorld;

	Animation _curAnimation;

	// Map state voi idAnimation tuong ung
	std::unordered_map<int, Animation> _listAnimation;

	// Doi tuong nao dung yen thi state = NONE
	int _state;

	// Lat nguoc sprite 
	bool _isFlip;
	bool _isAnimated;
	bool _isTerminated;

	float _speed; // vx
	float _dx, _dy;

	Vec3 _posWorld;
	Vec2 _scale;

	pDeviceManager _device;
	pTexture _texture;

public:

	int getId();
	void setId(int);

	void setIsStaticObj(bool);
	bool getIsStaticObj();

	void setRectWorld(RECT);

	int getIdType();
	void setIdType(int);

	void setSpeed(float);
	void setDx(float);
	void setDy(float);
	void setState(int);

	void setPositionWorld(Vec3);
	void setPositionWorld(Vec2);
	void setPositionWorld(int, int);

	Vec3 getPosWorld();

	void setScale(Vec2);
	void setScale(float, float);
	void setScale(float);

	void setIsFlip(bool);
	void setIsAnimated(bool);
	void setIsTerminated(bool);

	// Load Animation từ Animation Manager vao map Animation
	virtual void loadResource() = 0;

	virtual void render() = 0;

	virtual void update(float) = 0;

	// bắt sự kiện phím thay dổi, đặt trước hàm update để fix pos -> dưa theo speed :rainbow:
	virtual void handlerInput(float) = 0;

	RECT getSweptBroadphaseRect();

	bool checkCollision(RECT);

	float checkCollision_SweptAABB(RECT, float);

	// Fix pos khi chuyển animation
	void fixPosAnimation(int);

	// Mac dinh fix theo bottom
	float fixPosHeight(int);

	// Mac dinh fix theo left
	float fixPosWidth(int);

	// isStatic = false => Lay RECT cua ani hien tai
	// isStatic = true => lay bouding world obj
	RECT getBoudingBox();

	GameObject();
	GameObject(int);

	~GameObject();
};

typedef GameObject* pGameObject;