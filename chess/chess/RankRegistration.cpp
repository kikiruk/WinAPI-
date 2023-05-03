#include "RankRegistration.h"
#include "BitMapManager.h"
#include "MouseManager.h"
#include "StateManager.h"

/*************************화면에 수치표시용 (완성후삭제)*********************************/
#pragma warning(disable:4996)
#include <stdlib.h>
/*************************************************************************************/

void RankRegistration::progress()
{
	buttonProgress(MouseManager::getX(), MouseManager::getY());
}

void RankRegistration::render()
{
	buttonRender(MouseManager::getX(), MouseManager::getY());
}

inline void RankRegistration::buttonRender(int MouseX, int MouseY)
{
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
	//GotoMainButton

	Rectangle(memDC, 29, 70, 899, 140);

	int j = 0;
	for (int i = 0; i < 3; i++)
	{
		for (j = 0; j < 10; j++)
		{
			Rectangle(memDC, 29 + (j * 80), 280 + (i * 80), 99 + (j * 80), 350 + (i * 80));

			if (i * 10 + j == 26)
				break;
		}

	}

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

inline void RankRegistration::buttonProgress(int MouseX, int MouseY)
{
	if (MouseManager::left)
	{
		//GotoMainButton
		if (MouseX > GotoMainButton.left && GotoMainButton.right > MouseX
			&& MouseY > GotoMainButton.top && GotoMainButton.bottom > MouseY)
		{
			StateManager::setStateNow(MAIN);
		}
	}
}

RankRegistration::RankRegistration()
{
	Buttons_bitmapDC = BitMapManager::getButtons_bitmapDC();
	GotoMainButton = { 867,577,967,647 }; //가로 100 세로 70
}

RankRegistration::~RankRegistration()
{

}
