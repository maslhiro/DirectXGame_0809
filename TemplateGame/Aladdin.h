#pragma once
#include "GameObject.h"
#include "AppleThrow.h"
#include "Camera.h"
#include "FixedGrid.h"

class Aladdin :
	public GameObject
{
private:

	pFixedGrid _grid;
	pCamera _camera;

	pInputHandler _input;
	std::unordered_map<int, bool> _keys;

	std::vector<pAppleThrow> _listApple;
	int _indexApple;

	// Xet huong di chuyen
	// 1 -> right
	// 0 -> none
	// -1 -> left
	int _moveDirection;

	// Xet huong di chuyen
	// -1 -> up
	// 0 -> none
	// 1 -> down

	int _isClimb;
	// Pos voi viewPort
	Vec3 _pos;

	// Bien bool check Player da dung tren mat dat chua
	bool _isOnGround;

	// Bien bool check Player da dung tren mat dat chua
	bool _isJump;

	bool _isThrow;

	bool _isFall;
	float _distanceJump;

	bool _isRunJump;
	bool _isClimbJump;
	bool _isSit;
	bool _isDamage;
	bool _isAttack;
	bool _checkClimb;

	bool _canMoveRight;
	bool _canMoveLeft;

	int _idGroundObj;
	int _idRopeObj;

	float _waitTime;
	float _flashTime;

	bool _isFlash;

	int _numBlood;

public:
	Aladdin();

	void setPosView(Vec3);
	void setPosView(int, int);

	Vec3 getPosView();

	int getNumBlood();

	void setGrid(pFixedGrid);

	void setCamera(pCamera);

	void loadResource();

	void render();

	void update(float);

	void handlerInput(float);

	// Update dong thoi posView va posWorld
	void updateAllPos(Vec3);
};

typedef Aladdin* pAladdin;