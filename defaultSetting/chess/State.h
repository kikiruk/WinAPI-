#pragma once
#include "OverallVariables.h"
// State 폴더 안에 있는 모든 Class 들은 State 를 상속 받는다 

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

	// 생성자 이니셜라이저 
	State() : 
		hWnd(OverallVariables::getHWnd()),
		hdc(OverallVariables::getHdc()),
		memDC(OverallVariables::getMemDC()),
		crt(OverallVariables::getCrt())
	{};
};