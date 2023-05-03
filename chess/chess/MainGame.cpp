#include "MainGame.h"
#include "OverallVariables.h"
#include "StateManager.h"

void MainGame::Progress()
{
	StateManager::StateNow->progress();
}

void MainGame::Render()
{
	FillRect(memDC, &crt, (HBRUSH)GetStockObject(WHITE_BRUSH)); // 기본 코드 (더블버퍼)

	StateManager::StateNow->render();
	BitBlt(hdc, crt.left, crt.top, crt.right, crt.bottom, memDC, 0, 0, SRCCOPY); // 기본 코드 (더블버퍼)
}


MainGame::MainGame() :
	hWnd(OverallVariables::getHWnd()),
	hdc(OverallVariables::getHdc()),
	memDC(OverallVariables::getMemDC()),
	crt(OverallVariables::getCrt()),
	computer(),
	_main(),
	option(&computer),
	gameStart(&computer)
{
	StateManager::StateNow = &_main;
	StateManager::gameStart = &gameStart;
	StateManager::_main = &_main;
	StateManager::option = &option;
	StateManager::beforGameStart = &beforGameStart;
	StateManager::rankRegistration = &rankRegistration;

}


MainGame::~MainGame()
{

}