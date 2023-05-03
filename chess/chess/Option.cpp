#include "Option.h"
#include "MouseManager.h"
#include "StateManager.h"
#include "BitMapManager.h"
#include "Computer.h"

/*************************화면에 수치표시용 (완성후삭제)*********************************/
#pragma warning(disable:4996)
#include <stdlib.h>
/*************************************************************************************/


void Option::progress()
{
	int MouseX = MouseManager::getX();
	int MouseY = MouseManager::getY();

	buttonProgress(MouseX,MouseY);
}

void Option::render()
{
	TextOut(memDC, 0, 0, TEXT("Option"), 6);
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

	char buf_3[256];
	strcpy(buf_3, "difficulty : ");
	int len_3 = 13;
	len_3 += sprintf(buf_3 + len_3, "%d ", computer->difficulty);
	puts(buf_3);
	TextOut(memDC, 0, 40, TEXT(buf_3), strlen(buf_3));
	/***************************************************************************************/


}

Option::Option(Computer* computer)
{
	Buttons_bitmapDC = BitMapManager::getButtons_bitmapDC();
	difficultly_Buttons_bitmapDC = BitMapManager::getDifficultly_bitmapDC();
	GotoMainButton = { 867,577,967,647 }; //가로 100 세로 70
	difficulty = {13,118,63,168};
	this->computer = computer;
}


Option::~Option()
{
}

inline void Option::buttonRender(int MouseX, int MouseY)
{
	//difficultly
	for (int i = 0; i < 5; i++)
	{
		if (i == computer->difficulty - 1)
		{
			TransparentBlt(memDC, difficulty.left + (i * 50), difficulty.top, 50, 50, difficultly_Buttons_bitmapDC, (i * 50), 50, 50, 50, RGB(255, 0, 255));
		}
		else
		{
			TransparentBlt(memDC, difficulty.left + (i * 50), difficulty.top, 50, 50, difficultly_Buttons_bitmapDC, (i * 50), 0, 50, 50, RGB(255, 0, 255));
		}
	}

	//GotoMainButton
	if (MouseX > GotoMainButton.left && GotoMainButton.right > MouseX
		&& MouseY > GotoMainButton.top && GotoMainButton.bottom > MouseY)
	{
		TransparentBlt(memDC, 867, 577, 100, 70, Buttons_bitmapDC, 100, 30, 100, 70, RGB(255, 0, 255));
	}
	else
	{
		TransparentBlt(memDC, 867, 577, 100, 70, Buttons_bitmapDC, 0, 30, 100, 70, RGB(255, 0, 255));
	}
}

inline void Option::buttonProgress(int MouseX, int MouseY)
{
	if (MouseManager::left)
	{
		//GotoMainButton
		if (MouseX > GotoMainButton.left && GotoMainButton.right > MouseX
			&& MouseY > GotoMainButton.top && GotoMainButton.bottom > MouseY)
		{
			StateManager::setStateNow(MAIN);
		}
		
		for (int i = 0; i < 5; i++)
		{
			if (MouseX > difficulty.left + (i * 50) && difficulty.right + (i * 50) > MouseX
				&& MouseY > difficulty.top && difficulty.bottom > MouseY)
			{
				computer->difficulty = i + 1;
			}
		}
	}
}
