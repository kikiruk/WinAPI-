#include "BitMapManager.h"
#include "OverallVariables.h"
#include <assert.h>

HDC BitMapManager::ChessHorse_bitmapDC = nullptr;
HDC BitMapManager::GameStart_bitmapDC = nullptr;
HDC BitMapManager::Display_bitmapDC = nullptr;
HDC BitMapManager::CoolTime_bitmapDC = nullptr;
HDC BitMapManager::Killed_bitmapDC = nullptr;
HDC	BitMapManager::Logo_game_start_bitmapDC = nullptr;
HDC	BitMapManager::Logo_clear_bitmapDC = nullptr;
HDC	BitMapManager::Logo_you_bitmapDC = nullptr;
HDC	BitMapManager::Logo_loose_bitmapDC = nullptr;
HDC	BitMapManager::Buttons_bitmapDC = nullptr;
HDC	BitMapManager::BackGround_bitmapDC = nullptr;
HDC	BitMapManager::CheckMate_white_bitmapDC = nullptr;
HDC	BitMapManager::CheckMate_black_bitmapDC = nullptr;
HDC	BitMapManager::StartLogo_bitmapDC = nullptr;
HDC	BitMapManager::MainButtons_bitmapDC = nullptr;
HDC	BitMapManager::Difficultly_bitmapDC = nullptr;
HDC	BitMapManager::Option_background_bitmapDC = nullptr;
HDC	BitMapManager::GameStart_background_bitmapDC = nullptr;
HDC	BitMapManager::Set_difficultly_logo_bitmapDC = nullptr;

void BitMapManager::initialize()
{

	//BackGround_bitmapDC
	BackGround_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP BackGround_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(103));
	HBITMAP BackGround_oldBitMap = (HBITMAP)SelectObject(BackGround_bitmapDC, BackGround_myBitMap);

	//buttons
	Buttons_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP Buttons_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(104));
	HBITMAP Buttons_oldBitMap = (HBITMAP)SelectObject(Buttons_bitmapDC, Buttons_myBitMap);

	//Difficultly_bitmapDC
	Difficultly_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP Difficultly_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(105));
	HBITMAP Difficultly_oldBitMap = (HBITMAP)SelectObject(Difficultly_bitmapDC, Difficultly_myBitMap);

	//106 메인버튼
	MainButtons_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP MainButtons_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(106));
	HBITMAP MainButtons_oldBitMap = (HBITMAP)SelectObject(MainButtons_bitmapDC, MainButtons_myBitMap);

	//죽인 체스말 담는곳 표시
	Killed_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP Killed_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(107));
	HBITMAP Killed_oldBitMap = (HBITMAP)SelectObject(Killed_bitmapDC, Killed_myBitMap);
	
	//체스말
	ChessHorse_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP ChessHorse_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(108));
	(HBITMAP)SelectObject(ChessHorse_bitmapDC, ChessHorse_myBitMap);

	//체스판
	GameStart_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP GameStart_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(109));
	HBITMAP GameStart_oldBitMap = (HBITMAP)SelectObject(GameStart_bitmapDC, GameStart_myBitMap);

	//선택된 체스말 표시
	Display_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP Display_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(110));
	HBITMAP Display_oldBitMap = (HBITMAP)SelectObject(Display_bitmapDC, Display_myBitMap);

	//쿨타임 체스말 표시
	CoolTime_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP CoolTime_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(111));
	HBITMAP CoolTime_oldBitMap = (HBITMAP)SelectObject(CoolTime_bitmapDC, CoolTime_myBitMap);
	
	//CheckMate_black
	CheckMate_black_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP CheckMate_black_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(112));
	HBITMAP CheckMate_black_oldBitMap = (HBITMAP)SelectObject(CheckMate_black_bitmapDC, CheckMate_black_myBitMap);

	//CheckMate_white
	CheckMate_white_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP CheckMate_white_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(113));
	HBITMAP CheckMate_white_oldBitMap = (HBITMAP)SelectObject(CheckMate_white_bitmapDC, CheckMate_white_myBitMap);

	//clear logo
	Logo_clear_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP Logo_clear_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(114));
	HBITMAP Logo_clear_oldBitMap = (HBITMAP)SelectObject(Logo_clear_bitmapDC, Logo_clear_myBitMap);


	//Game Start logo
	Logo_game_start_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP Logo_game_start_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(115));
	HBITMAP Logo_game_start_oldBitMap = (HBITMAP)SelectObject(Logo_game_start_bitmapDC, Logo_game_start_myBitMap);

	//loose logo
	Logo_loose_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP Logo_loose_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(116));
	HBITMAP Logo_loose_oldBitMap = (HBITMAP)SelectObject(Logo_loose_bitmapDC, Logo_loose_myBitMap);

	//105 난이도설정
	StartLogo_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP StartLogo_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(117));
	HBITMAP StartLogo_oldBitMap = (HBITMAP)SelectObject(StartLogo_bitmapDC, StartLogo_myBitMap);

	//you logo
	Logo_you_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP Logo_you_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(118));
	HBITMAP Logo_you_oldBitMap = (HBITMAP)SelectObject(Logo_you_bitmapDC, Logo_you_myBitMap);

	//you logo
	Option_background_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP Option_background_bitmapDC_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(122));
	HBITMAP Option_background_bitmapDC_oldBitMap = (HBITMAP)SelectObject(Option_background_bitmapDC, Option_background_bitmapDC_myBitMap);

	//게임화면에 빨간색 카펫 배경화면
	GameStart_background_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP GameStart_background_bitmapDC_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(123));
	HBITMAP GameStart_background_bitmapDC_oldBitMap = (HBITMAP)SelectObject(GameStart_background_bitmapDC, GameStart_background_bitmapDC_myBitMap);

	//난이도 설정 버튼 위에 글씨
	Set_difficultly_logo_bitmapDC = CreateCompatibleDC(OverallVariables::getMemDC());
	HBITMAP Set_difficultly_logo_bitmapDC_myBitMap = LoadBitmap(OverallVariables::getHInst(), MAKEINTRESOURCE(125));
	HBITMAP Set_difficultly_logo_bitmapDC_oldBitMap = (HBITMAP)SelectObject(Set_difficultly_logo_bitmapDC, Set_difficultly_logo_bitmapDC_myBitMap);
}

HDC BitMapManager::getChessHorse_bitmapDC()
{
	return ChessHorse_bitmapDC;
}

HDC BitMapManager::getGameStart_bitmapDC()
{
	return GameStart_bitmapDC;
}

HDC BitMapManager::getDisplay_bitmapDC()
{
	return Display_bitmapDC;
}

HDC BitMapManager::getCoolTime_bitmapDC()
{
	return CoolTime_bitmapDC;
}

HDC BitMapManager::getKilled_bitmapDC()
{
	return Killed_bitmapDC;
}

HDC BitMapManager::getLogo_game_start_bitmapDC()
{
	return Logo_game_start_bitmapDC;
}

HDC BitMapManager::getLogo_clear_bitmapDC()
{
	return Logo_clear_bitmapDC;
}

HDC BitMapManager::getLogo_you_bitmapDC()
{
	return Logo_you_bitmapDC;
}

HDC BitMapManager::getLogo_loose_bitmapDC()
{
	return Logo_loose_bitmapDC;
}

HDC BitMapManager::getButtons_bitmapDC()
{
	return Buttons_bitmapDC;
}

HDC BitMapManager::getBackGround_bitmapDC()
{
	return BackGround_bitmapDC;
}

HDC BitMapManager::getCheckMate_black_bitmapDC()
{
	return CheckMate_black_bitmapDC;
}

HDC BitMapManager::getCheckMate_white_bitmapDC()
{
	return CheckMate_white_bitmapDC;
}

HDC BitMapManager::getStartLogo_bitmapDC()
{
	return StartLogo_bitmapDC;
}

HDC BitMapManager::getMainButtons_bitmapDC()
{
	return MainButtons_bitmapDC;
}

HDC BitMapManager::getDifficultly_bitmapDC()
{
	return Difficultly_bitmapDC;
}

HDC BitMapManager::getOption_background_bitmapDC()
{
	return Option_background_bitmapDC;
}

HDC BitMapManager::getGameStart_background_bitmapDC()
{
	return GameStart_background_bitmapDC;
}

HDC BitMapManager::getSet_difficultly_logo_bitmapDC()
{
	return Set_difficultly_logo_bitmapDC;
}

