#include "Main.h"
#include "MouseManager.h"
#include "StateManager.h"
#include "BitMapManager.h"

/*************************화면에 수치표시용 (완성후삭제)*********************************/

#pragma warning(disable:4996)
#include <stdlib.h>
/*************************************************************************************/

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

	//RGB 255,0,255 는 핑크색을 나타낸다 이부분만 투명으로 표현된다는 의미이다 
	TransparentBlt(memDC, -(count * 5), 0, 1000, 700, BackGround_bitmapDC, 0, 0, 800, 800, RGB(255, 0, 255));
	TransparentBlt(memDC, 1000 - (count * 5), 0, 1000, 700, BackGround_bitmapDC, 0, 0, 800, 800, RGB(255, 0, 255));

	TransparentBlt(memDC, 0, 0, 1000, 700, StartLogo_bitmapDC, 0, 0, 1000, 700, RGB(255, 0, 255));

	buttonRender(MouseManager::getX(), MouseManager::getY());

	/*************************화면에 수치표시용 (완성후삭제)*********************************/
	char buf[256];
	strcpy(buf, "X : ");
	int len = 4;
	len += sprintf(buf + len, "%d ", MouseManager::getX());
	puts(buf);
	TextOut(memDC, 0, 0, TEXT(buf), strlen(buf));
	
	char buf_2[256];
	strcpy(buf_2, "Y : ");
	int len_2 = 4;
	len_2 += sprintf(buf_2 + len_2, "%d ", MouseManager::getY());
	puts(buf_2);
	
	TextOut(memDC, 0, 20, TEXT(buf_2), strlen(buf_2));
	/***************************************************************************************/
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
