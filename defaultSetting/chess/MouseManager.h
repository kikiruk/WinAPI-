#pragma once
#include "Include.h"
/*****************************************************
마우스매니저
left -> 왼쪽 마우스 클릭되어있는 상태일시 true
right -> 오른쪽 마우스 클릭되어있는 상태일시 true





******************************************************/

class MouseManager
{
private:
	static POINT mouse;
	static POINT* const mousePointer;
public:
	static bool left;
	static bool right;
public:
	static void progress();
	static int getX();
	static int getY();

};

