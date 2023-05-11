#include "Option.h"
#include "MouseManager.h"
#include "StateManager.h"
#include "BitMapManager.h"
#include "Computer.h"

void Option::progress()
{
	int MouseX = MouseManager::getX();
	int MouseY = MouseManager::getY();

	buttonProgress(MouseX,MouseY);
}

void Option::render()
{
	//TextOut(memDC, 0, 0, TEXT("Option"), 6); // �����ִ� �ڵ��ε� �뵵�� �𸣰پ �ϴ� �ּ�ó��
	
	//�̺κ��� ����ȭ�鿡 üũ���� ����� �����ʿ��� �������� �����̴� �������� �����Ѱ��̴� 
	count++;

	if (1000 - (count * 5) == 0)
	{
		count = 0;
	}

	//RGB 255,0,255 �� ��ũ���� ��Ÿ���� �̺κи� �������� ǥ���ȴٴ� �ǹ��̴� 
	TransparentBlt(memDC, -(count * 5), 0, 1000, 700, BackGround_bitmapDC, 0, 0, 800, 800, RGB(255, 0, 255));
	TransparentBlt(memDC, 1000 - (count * 5), 0, 1000, 700, BackGround_bitmapDC, 0, 0, 800, 800, RGB(255, 0, 255));

	//�Ķ���� â��ǥ�õ� ����, ����, ���α��� , ���α��� / �������� �ڸ������� ������ ����, ����, �ڸ����α���, ���α��� �̴�
	TransparentBlt(memDC, 0, 0, 1000, 822,option_background_bitmapDC, 0, 50, 1000, 772, RGB(255, 0, 255)); // ���� 822 , ���� 1000 �� ���ȭ�� ���
	buttonRender(MouseManager::getX(), MouseManager::getY());

}

Option::Option(Computer* computer)//������
{
	Buttons_bitmapDC = BitMapManager::getButtons_bitmapDC();
	difficultly_Buttons_bitmapDC = BitMapManager::getDifficultly_bitmapDC();
	option_background_bitmapDC = BitMapManager::getOption_background_bitmapDC(); // ���� 1000 ���� 822
	BackGround_bitmapDC = BitMapManager::getBackGround_bitmapDC();
	Option_background_bitmapDC = BitMapManager::getSet_difficultly_logo_bitmapDC();
	GotoMainButton = { 867,577,967,647 }; //���� 100 ���� 70
	difficulty = {119,445,169,495}; //���� 50 ���� 50

	this->computer = computer;
}


Option::~Option()
{
} // �Ҹ���

inline void Option::buttonRender(int MouseX, int MouseY)
{
	// ���̵� ���� ��ư ���� �۾� 262
	TransparentBlt(memDC, difficulty.left + 22 , difficulty.top - 90, 200, 114,
		Option_background_bitmapDC, 0, 0, 295, 121, RGB(255, 0, 255));

	//difficultly = { 119,319,50,358 }; 
	for (int i = 0; i < 5; i++)
	{
		if (i == computer->difficulty - 1) //���� ���õ� difficulty (���̵�) ���ش�Ǵ°͸� ��ư ���� �ٸ��� �� 
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
