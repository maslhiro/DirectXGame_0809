#ifndef __GAMETIME_H__
#define __GAMETIME_H__

#include "define.h"

class GameTime
{
public:
	~GameTime(void);

	static void release();

	static GameTime* getInstance();

	void init();

	void updateGameTime();

	void setTotalGameTime(float);

	float getTotalGameTime();

	float getElapsedGameTime();

private:
	static GameTime* _instance;

	LARGE_INTEGER	_timer;
	LARGE_INTEGER _frequency;

	LONGLONG		_lastTicks;
	LONGLONG		_curTicks;

	float _totalGameTime;
	// Tổng thời gian game chayh từ khi gọi hàm init 

	float _elapsedGameTime;
	// Khoảng thời gian giữa 2 lần gọi hàm updateGameTime

	GameTime(void);

};
typedef GameTime* pGameTime;

#endif 
