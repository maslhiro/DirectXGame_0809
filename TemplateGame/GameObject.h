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

	// 
	Animation _curAnimation;

	// Map state voi idAnimation tuong ung
	std::unordered_map<int, Animation> _listAnimation;

	// Doi tuong nao dung yen thi state = NONE
	int _state;

	// Lat nguoc sprite 
	bool _isReverse;
	bool _isAnimated;

	float _speed; // vx

	Vec3 _pos;
	Vec2 _scale;

	pDeviceManager _device;
	pTexture _texture;

public:

	int getId();
	void setId(int);

	void setSpeed(float);
	void setState(int);

	void setPosition(Vec3);
	void setPosition(Vec2);
	void setPosition(float, float);

	void setScale(Vec2);
	void setScale(float, float);
	void setScale(float);

	void setIsReverse(bool);
	void setIsAnimated(bool);

	// Load Animation từ Animation Manager vao map Animation
	virtual void loadResource() = 0;

	virtual void render() = 0;

	virtual void update(float) = 0;

	// bắt sự kiện phím thay dổi, đặt trước hàm update để fix pos -> dưa theo speed :rainbow:
	virtual void handlerInput() = 0;

	// Fix pos khi chuyển animation
	virtual void fixPosAnimation(int) = 0;

	GameObject();
	~GameObject();
};

typedef GameObject* pGameObject;