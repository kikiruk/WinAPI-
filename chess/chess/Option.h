#pragma once
#include "State.h"
#include "Computer.h"

class Option : public State
{
private:
	HDC	Buttons_bitmapDC;
	HDC	difficultly_Buttons_bitmapDC;
	RECT GotoMainButton;
	RECT difficulty;
	Computer* computer;

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

