#pragma once
#include "State.h"

class Game_Clear : public State
{
public:
	virtual void progress();
	virtual void render();

private:
	inline void buttonRender(int MouseX, int MouseY);
	inline void buttonProgress(int MouseX, int MouseY);
};

