#pragma once
#include "OverallVariables.h"
// State ���� �ȿ� �ִ� ��� Class ���� State �� ��� �޴´� 

class State
{
protected:
	HWND hWnd;
	HDC hdc, memDC;
	RECT crt;

public:
	virtual void progress() = 0;
	virtual void render() = 0;

public:

	// ������ �̴ϼȶ����� 
	State() : 
		hWnd(OverallVariables::getHWnd()),
		hdc(OverallVariables::getHdc()),
		memDC(OverallVariables::getMemDC()),
		crt(OverallVariables::getCrt())
	{};
};