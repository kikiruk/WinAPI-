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
};

