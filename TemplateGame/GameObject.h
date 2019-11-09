#pragma once
#include "define.h"
#include "Texture.h"
#include "Animation.h"
#include "DeviceManager.h"
#include "AnimationManager.h"

class GameObject
{
protected:

	std::string _id;

	// Chia Id de phan biet cac the loai game obj :)))
	int _idType;

	// 
	Animation _curAnimation;

	// Map state voi idAnimation tuong ung
	std::unordered_map<int, Animation> _listAnimation;

	// Doi tuong nao dung yen thi state = NONE
	int _state;

	// Lat nguoc sprite 
	bool _isFlip;
	bool _isAnimated;

	float _speed; // vx

	Vec3 _posWorld;
	Vec2 _scale;

	pDeviceManager _device;
	pTexture _texture;

public:

	std::string getId();
	void setId(std::string);

	int getIdType();
	void setIdType(int);

	void setSpeed(float);
	void setState(int);

	void setPositionWorld(Vec3);
	void setPositionWorld(Vec2);
	void setPositionWorld(int, int);

	void setScale(Vec2);
	void setScale(float, float);
	void setScale(float);

	void setIsFlip(bool);
	void setIsAnimated(bool);

	// Load Animation từ Animation Manager vao map Animation
	virtual void loadResource() = 0;

	virtual void render() = 0;

	virtual void update(float) = 0;

	// bắt sự kiện phím thay dổi, đặt trước hàm update để fix pos -> dưa theo speed :rainbow:
	virtual void handlerInput() = 0;

	// Fix pos khi chuyển animation
	void fixPosAnimation(int);

	// Mac dinh fix theo bottom
	float fixPosHeight(int);

	// Mac dinh fix theo left
	float fixPosWidth(int);

	// Lay RECT cua ani hien tai
	RECT getBoudingBox();

	GameObject();
	~GameObject();
};

typedef GameObject* pGameObject;