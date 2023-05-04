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
	//TextOut(memDC, 0, 0, TEXT("Option"), 6); // 원래있던 코드인데 용도를 모르겟어서 일단 주석처리
	
	//이부분은 바탕화면에 체크무늬 모양이 오른쪽에서 왼쪽으로 움직이는 디자인을 구현한것이다 
	count++;

	if (1000 - (count * 5) == 0)
	{
		count = 0;
	}

	//RGB 255,0,255 는 핑크색을 나타낸다 이부분만 투명으로 표현된다는 의미이다 
	TransparentBlt(memDC, -(count * 5), 0, 1000, 700, BackGround_bitmapDC, 0, 0, 800, 800, RGB(255, 0, 255));
	TransparentBlt(memDC, 1000 - (count * 5), 0, 1000, 700, BackGround_bitmapDC, 0, 0, 800, 800, RGB(255, 0, 255));

	//파라메터 창에표시될 왼쪽, 위쪽, 가로길이 , 세로길이 / 원본사진 자르기위한 시작점 왼쪽, 위쪽, 자를가로길이, 세로길이 이다
	TransparentBlt(memDC, 0, 0, 1000, 822,option_background_bitmapDC, 0, 50, 1000, 772, RGB(255, 0, 255)); // 가로 822 , 세로 1000 의 배경화면 출력
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

Option::Option(Computer* computer)//생성자
{
	Buttons_bitmapDC = BitMapManager::getButtons_bitmapDC();
	difficultly_Buttons_bitmapDC = BitMapManager::getDifficultly_bitmapDC();
	option_background_bitmapDC = BitMapManager::getOption_background_bitmapDC(); // 가로 1000 세로 822
	BackGround_bitmapDC = BitMapManager::getBackGround_bitmapDC();
	GotoMainButton = { 867,577,967,647 }; //가로 100 세로 70
	difficulty = {0,308,50,358}; //가로 50 세로 50

	this->computer = computer;
}


Option::~Option()
{
} // 소멸자

inline void Option::buttonRender(int MouseX, int MouseY)
{
	//difficultly
	for (int i = 0; i < 5; i++)
	{
		if (i == computer->difficulty - 1) //현재 선택된 difficulty (난이도) 에해당되는것만 버튼 색깔 다르게 함 
		{
			TransparentBlt(memDC, difficulty.left + (i * 50), difficulty.top, 50, 50, 
				difficultly_Buttons_bitmapDC, (i * 50), 50, 50, 50, RGB(255, 0, 255));
		}
		else
		{
			TransparentBlt(memDC, difficulty.left + (i * 50), difficulty.top, 50, 50, 
				difficultly_Buttons_bitmapDC, (i * 50), 0, 50, 50, RGB(255, 0, 255));
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
