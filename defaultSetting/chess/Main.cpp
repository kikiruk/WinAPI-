#include "Main.h"
#include "MouseManager.h"
#include "StateManager.h"
#include "BitMapManager.h"

//이곳은 게임 켜자마자 있는 화면이다 

void Main::progress()
{
	int MouseX = MouseManager::getX();
	int MouseY = MouseManager::getY();

	buttonProgress(MouseX, MouseY);
}

void Main::render()
{

	//RGB 255,0,255 는 핑크색을 나타낸다 이부분만 투명으로 표현된다는 의미이다 

	//TransparentBlt(memDC, 0, 0, 1000, 700, StartLogo_bitmapDC, 0, 0, 1000, 700, RGB(255, 0, 255));

	buttonRender(MouseManager::getX(), MouseManager::getY());
}

inline void Main::buttonRender(int MouseX, int MouseY)
{
	if (optionButton.left < MouseX && optionButton.right > MouseX
		&& optionButton.top < MouseY && optionButton.bottom > MouseY)
	{
		TransparentBlt(memDC, optionButton.left, optionButton.top, 200, 50, MainButtons_bitmapDC, 0, 50, 200, 50, RGB(255, 0, 255));
	}
	else
	{
		TransparentBlt(memDC, optionButton.left, optionButton.top, 200, 50, MainButtons_bitmapDC, 0, 0, 200, 50, RGB(255, 0, 255));
	}

	if (StartButton.left < MouseX && StartButton.right > MouseX
		&& StartButton.top < MouseY && StartButton.bottom > MouseY)
	{
		TransparentBlt(memDC, StartButton.left, StartButton.top, 200, 50, MainButtons_bitmapDC, 200, 50, 200, 50, RGB(255, 0, 255));
	}
	else
	{
		TransparentBlt(memDC, StartButton.left, StartButton.top, 200, 50, MainButtons_bitmapDC, 200, 0, 200, 50, RGB(255, 0, 255));
	}
}

inline void Main::buttonProgress(int MouseX, int MouseY)
{
}

Main::Main()
{
	BackGround_bitmapDC = BitMapManager::getBackGround_bitmapDC();
	StartLogo_bitmapDC = BitMapManager::getStartLogo_bitmapDC();
	MainButtons_bitmapDC = BitMapManager::getMainButtons_bitmapDC();
	optionButton = { 240 , 380, 440, 430 };
	StartButton = { 490, 380, 690, 430 };
	count = 1;
}


Main::~Main()
{
}
