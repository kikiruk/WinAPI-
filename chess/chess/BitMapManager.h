#pragma once
#include "Include.h"

class BitMapManager
{
	/********************************************************
	TransparentBlt() 함수는 다음과 같은 인자를 필요로 합니다.
	hdcDest: 출력할 DC(Device Context)의 핸들
	nXDest: 출력할 좌표의 X축 위치
	nYDest: 출력할 좌표의 Y축 위치
	nWidth: 출력할 비트맵의 폭
	nHeight: 출력할 비트맵의 높이
	hdcSrc: 출력할 비트맵의 DC 핸들
	nXSrc: 출력할 비트맵의 좌표의 X축 위치
	nYSrc: 출력할 비트맵의 좌표의 Y축 위치
	crTransparent: 출력할 비트맵에서 투명한 색상 값 (예를 들어 RGB(255,0,255)는 마젠타를 의미)
	bAlpha: 출력할 비트맵의 알파 값 (0~255 사이의 값)
	**********************************************************/

private:
	static HDC ChessHorse_bitmapDC;//체스말	
	static HDC GameStart_bitmapDC;//체스판
	static HDC Display_bitmapDC;//체스판
	static HDC CoolTime_bitmapDC;//쿨타임표시
	static HDC Killed_bitmapDC;//죽인 체스말 담는곳 표시
	static HDC Logo_game_start_bitmapDC;
	static HDC Logo_clear_bitmapDC;
	static HDC Logo_you_bitmapDC;
	static HDC Logo_loose_bitmapDC;
	static HDC Buttons_bitmapDC;//버튼들 (플레이,스탑 )
	static HDC BackGround_bitmapDC;//체스판모양 백그라운드
	static HDC CheckMate_white_bitmapDC;
	static HDC CheckMate_black_bitmapDC;
	static HDC StartLogo_bitmapDC;//시작할때 로고
	static HDC MainButtons_bitmapDC;//시작할때 옵션버튼, 시작버튼
	static HDC Difficultly_bitmapDC;//어려움설정할때
	static HDC Option_background_bitmapDC; // 옵션 배경화면 

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

