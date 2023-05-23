#pragma once
#include "OverallVariables.h"

class MainGame
{

private:
	HWND hWnd;
	HDC hdc, memDC;
	RECT crt;

public:
	void Progress();
	void Render();

public:
	MainGame();
	~MainGame();

private:
};


