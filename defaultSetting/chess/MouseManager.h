#pragma once
#include "Include.h"
/*****************************************************
���콺�Ŵ���
left -> ���� ���콺 Ŭ���Ǿ��ִ� �����Ͻ� true
right -> ������ ���콺 Ŭ���Ǿ��ִ� �����Ͻ� true





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

