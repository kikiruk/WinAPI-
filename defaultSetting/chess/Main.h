#pragma once
#include "State.h"

class Main : public State
{
private:
	HDC BackGround_bitmapDC;
	HDC StartLogo_bitmapDC;
	HDC MainButtons_bitmapDC;
	RECT optionButton;
	RECT StartButton;

	int count;

public:
	virtual void progress();


	virtual void render();

private:
	inline void buttonRender(int MouseX, int MouseY);
	inline void buttonProgress(int MouseX, int MouseY);

public:
	Main();
	~Main();
};

