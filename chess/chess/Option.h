#pragma once
#include "State.h"
#include "Computer.h"

class Option : public State
{
private:
	HDC	Buttons_bitmapDC;
	HDC	difficultly_Buttons_bitmapDC;
	HDC	option_background_bitmapDC;
	HDC	BackGround_bitmapDC;
	HDC	Option_background_bitmapDC;
	RECT GotoMainButton;
	RECT difficulty;
	Computer* computer;
	int count = 0;

public:
	virtual void progress();
	virtual void render();

public:
	Option(Computer*);
	~Option();

private:
	inline void buttonRender(int MouseX, int MouseY);
	inline void buttonProgress(int MouseX, int MouseY);
};

