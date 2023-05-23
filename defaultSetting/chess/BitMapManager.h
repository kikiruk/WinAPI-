#pragma once
#include "Include.h"

class BitMapManager
{
	/********************************************************
	TransparentBlt() �Լ��� ������ ���� ���ڸ� �ʿ�� �մϴ�.
	hdcDest: ����� DC(Device Context)�� �ڵ�
	nXDest: ����� ��ǥ�� X�� ��ġ
	nYDest: ����� ��ǥ�� Y�� ��ġ
	nWidth: ����� ��Ʈ���� ��
	nHeight: ����� ��Ʈ���� ����
	hdcSrc: ����� ��Ʈ���� DC �ڵ�
	nXSrc: ����� ��Ʈ���� ��ǥ�� X�� ��ġ
	nYSrc: ����� ��Ʈ���� ��ǥ�� Y�� ��ġ
	crTransparent: ����� ��Ʈ�ʿ��� ������ ���� �� (���� ��� RGB(255,0,255)�� ����Ÿ�� �ǹ�)
	bAlpha: ����� ��Ʈ���� ���� �� (0~255 ������ ��)
	**********************************************************/
	// �Ķ���� â��ǥ�õ� ����, ����, ���α��� , ���α��� / �������� �ڸ������� ������ ����, ����, �ڸ����α���, ���α��� �̴�
	// ��üȭ�� ũ�� ���� 1000 ���� 700

	//Rectangle(memDC, ������������X, ������������Y, �����ʾƷ�������X, �����ʾƷ�������Y); �����ؼ� �̸� �������� �׽�Ʈ �غ��� ���°��� ��õ
	
	//"���ҽ��� �ε��� �� �����ϴ�" ���� ��쿡 �׸��ǿ��� bmp ���Ϸ� ��ȯ�ϱ� ������ ��ȯ�Ұ�
	//�׳� ���Ƿ� ���ϸ� �����ϸ� �ε�ȵ�

private:
	static HDC ChessHorse_bitmapDC;//ü����	
	static HDC GameStart_bitmapDC;//ü����
	static HDC Display_bitmapDC;//ü����
	static HDC CoolTime_bitmapDC;//��Ÿ��ǥ��
	static HDC Killed_bitmapDC;//���� ü���� ��°� ǥ��
	static HDC Logo_game_start_bitmapDC;
	static HDC Logo_clear_bitmapDC;
	static HDC Logo_you_bitmapDC;
	static HDC Logo_loose_bitmapDC;
	static HDC Buttons_bitmapDC;//��ư�� (�÷���,��ž )
	static HDC BackGround_bitmapDC;//ü���Ǹ�� ��׶���
	static HDC CheckMate_white_bitmapDC;
	static HDC CheckMate_black_bitmapDC;
	static HDC StartLogo_bitmapDC;//�����Ҷ� �ΰ�
	static HDC MainButtons_bitmapDC;//�����Ҷ� �ɼǹ�ư, ���۹�ư
	static HDC Difficultly_bitmapDC;//��������Ҷ�
	static HDC Option_background_bitmapDC; // �ɼ� ���ȭ�� 
	static HDC GameStart_background_bitmapDC; // ������ ī��Ʈ ���
	static HDC Set_difficultly_logo_bitmapDC; // ���̵� ���� ��ư ���� ����
	static HDC Change_pawn_window_bitmapDC; // ���̵� ���� ��ư ���� ����

public:
	static void initialize();

public:
	static HDC getChessHorse_bitmapDC();
	static HDC getGameStart_bitmapDC();
	static HDC getDisplay_bitmapDC();
	static HDC getCoolTime_bitmapDC();
	static HDC getKilled_bitmapDC();
	static HDC getLogo_game_start_bitmapDC();
	static HDC getLogo_clear_bitmapDC();
	static HDC getLogo_you_bitmapDC();
	static HDC getLogo_loose_bitmapDC();
	static HDC getButtons_bitmapDC();
	static HDC getBackGround_bitmapDC();
	static HDC getCheckMate_black_bitmapDC();
	static HDC getCheckMate_white_bitmapDC();
	static HDC getStartLogo_bitmapDC();
	static HDC getMainButtons_bitmapDC();
	static HDC getDifficultly_bitmapDC();
	static HDC getOption_background_bitmapDC();
	static HDC getGameStart_background_bitmapDC();
	static HDC getSet_difficultly_logo_bitmapDC();
	static HDC getChange_pawn_window_bitmapDC();
};


/******�Ʒ��� �ڵ带 ����ϸ� ��Ÿ���߿� ��ǥ�� �˼��ְ� �̹����� �Է��Ҷ� ��ǥ�� ã�� �����ϴ�******/

//�ʿ��� �������
/*************************ȭ�鿡 ��ġǥ�ÿ� (�ϼ��Ļ���)*********************************/
#pragma warning(disable:4996)
#include <stdlib.h>
/*************************************************************************************/

/*************************ȭ�鿡 ��ġǥ�ÿ� (�ϼ��Ļ���)*********************************/
//char buf[256];
//strcpy(buf, "X : ");
//int len = 4;
//len += sprintf(buf + len, "%d ", MouseManager::getX());
//puts(buf);
//TextOut(memDC, 0, 0, TEXT(buf), strlen(buf));
//
//char buf_2[256];
//strcpy(buf_2, "Y : ");
//int len_2 = 4;
//len_2 += sprintf(buf_2 + len_2, "%d ", MouseManager::getY());
//puts(buf_2);
//TextOut(memDC, 0, 20, TEXT(buf_2), strlen(buf_2));
//
//char buf_3[256];
//strcpy(buf_3, "test_click : ");
//int len_3 = 13;
//len_3 += sprintf(buf_3 + len_3, "%d ", test_click);
//puts(buf_3);
//
//TextOut(memDC, 0, 40, TEXT(buf_3), strlen(buf_3));
//
//
////test_click
/***************************************************************************************/

