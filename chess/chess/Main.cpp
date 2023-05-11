#include "Main.h"
#include "MouseManager.h"
#include "StateManager.h"
#include "BitMapManager.h"

//�̰��� ���� ���ڸ��� �ִ� ȭ���̴� 

void Main::progress()
{
	int MouseX = MouseManager::getX();
	int MouseY = MouseManager::getY();

	buttonProgress(MouseX, MouseY);
}

void Main::render()
{
	count++;

	if (1000 - (count * 5) == 0)
	{
		count = 0;
	}

	//RGB 255,0,255 �� ��ũ���� ��Ÿ���� �̺κи� �������� ǥ���ȴٴ� �ǹ��̴� 
	TransparentBlt(memDC, -(count * 5), 0, 1000, 700, BackGround_bitmapDC, 0, 0, 800, 800, RGB(255, 0, 255));
	TransparentBlt(memDC, 1000 - (count * 5), 0, 1000, 700, BackGround_bitmapDC, 0, 0, 800, 800, RGB(255, 0, 255));

	TransparentBlt(memDC, 0, 0, 1000, 700, StartLogo_bitmapDC, 0, 0, 1000, 700, RGB(255, 0, 255));

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
	if (MouseManager::left)
	{
		if (optionButton.left < MouseX && optionButton.right > MouseX)
		{
			if (optionButton.top < MouseY && optionButton.bottom > MouseY)
			{
				if (MouseManager::left)
					StateManager::setStateNow(OPTION);
			}
		}

		if (StartButton.left < MouseX && StartButton.right > MouseX)
		{
			if (StartButton.top < MouseY && StartButton.bottom > MouseY)
			{
				if (MouseManager::left)
				{
					StateManager::getBeforGameStartState()->initialize();
					StateManager::setStateNow(BEFOR_GAME_START);
				}
			}
		}
	}
}

Main::Main()
{
	BackGround_bitmapDC = BitMapManager::getBackGround_bitmapDC();
	StartLogo_bitmapDC = BitMapManager::getStartLogo_bitmapDC();
	MainButtons_bitmapDC = BitMapManager::getMainButtons_bitmapDC();
	optionButton = { 240 , 380, 440, 430 };
	StartButton = { 490, 380, 690, 430 };
	count = 0;
}


Main::~Main()
{
}
