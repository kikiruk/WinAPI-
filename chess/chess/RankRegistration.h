#pragma once
#include "State.h"

class RankRegistration : public State
{
private:
	HDC Buttons_bitmapDC;
	RECT GotoMainButton;

public:
	virtual void progress();
	virtual void render();

private:
	inline void buttonRender(int MouseX, int MouseY);
	inline void buttonProgress(int MouseX, int MouseY);

public:
	RankRegistration();
	~RankRegistration();
};

