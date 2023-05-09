#pragma once
#include "Main.h"
#include "Option.h"
#include "GameStart.h"
#include "BeforGameStart.h"
#include "Game_Clear.h"

class MainGame
{

private:
	HWND hWnd;
	HDC hdc, memDC;
	RECT crt;

private:
	Computer computer;
	Main _main;
	Option option;
	GameStart gameStart;
	BeforGameStart beforGameStart;
	Game_Clear game_Clear;

public:
	void Progress();
	void Render();

public:
	MainGame();
	~MainGame();

private:
};


