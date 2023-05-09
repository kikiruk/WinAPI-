#include "MainGame.h"
#include "OverallVariables.h"
#include "StateManager.h"

void MainGame::Progress()
{
	StateManager::StateNow->progress();
}

void MainGame::Render()
{
	// 백그라운드를 하얀색으로 초기화 하는 코드
	FillRect(memDC, &crt, (HBRUSH)GetStockObject(WHITE_BRUSH)); 
	
	// StateNow 는 현재 스테이트고 그 현재 State 에 해당하는
	// State를 render 한다 (State 의 자식 객체) (다형성)
	StateManager::StateNow->render(); 

	//hdc 에 memDC 를 복사하여 표시한다
	BitBlt(hdc, crt.left, crt.top, crt.right, crt.bottom, memDC, 0, 0, SRCCOPY); 
}


MainGame::MainGame() :
	hWnd(OverallVariables::getHWnd()),
	hdc(OverallVariables::getHdc()),
	memDC(OverallVariables::getMemDC()),
	crt(OverallVariables::getCrt())
{
	StateManager::initialize();
}


MainGame::~MainGame()
{
	delete StateManager::_main;
	delete StateManager::option;
	delete StateManager::gameStart;
	delete StateManager::beforGameStart;
	delete StateManager::game_Clear;

}