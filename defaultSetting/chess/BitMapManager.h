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
	// 파라메터 창에표시될 왼쪽, 위쪽, 가로길이 , 세로길이 / 원본사진 자르기위한 시작점 왼쪽, 위쪽, 자를가로길이, 세로길이 이다
	// 전체화면 크기 가로 1000 세로 700

	//Rectangle(memDC, 왼쪽위꼭짓점X, 왼쪽위꼭짓점Y, 오른쪽아래꼭짓점X, 오른쪽아래꼭짓점Y); 를통해서 미리 놓을곳에 테스트 해보고 놓는것을 추천
	
	//"리소스를 로드할 수 없습니다" 나올 경우에 그림판에서 bmp 파일로 변환하기 눌러서 변환할것
	//그냥 임의로 파일명 변경하면 로드안됨

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
	static HDC GameStart_background_bitmapDC; // 빨간색 카페트 배경
	static HDC Set_difficultly_logo_bitmapDC; // 난이도 설정 버튼 위에 글자
	static HDC Change_pawn_window_bitmapDC; // 난이도 설정 버튼 위에 글자

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


/******아래의 코드를 사용하면 런타임중에 좌표를 알수있고 이미지를 입력할때 좌표를 찾기 유리하다******/

//필요한 헤더파일
/*************************화면에 수치표시용 (완성후삭제)*********************************/
#pragma warning(disable:4996)
#include <stdlib.h>
/*************************************************************************************/

/*************************화면에 수치표시용 (완성후삭제)*********************************/
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

