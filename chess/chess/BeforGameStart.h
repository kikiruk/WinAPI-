#pragma once
#include "State.h"

class BeforGameStart : public State
{
	friend class GameStart;
	friend class Main;
private:
	HDC bitmapDC;
	HDC BackGround_bitmapDC;
	int count;
	int backGround_count;

	int Y;
	int speed;
public:
	virtual void progress();
	virtual void render();
	void initialize();
public:
	BeforGameStart();
};

