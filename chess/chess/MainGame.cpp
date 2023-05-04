#include "MainGame.h"
#include "OverallVariables.h"
#include "StateManager.h"

void MainGame::Progress()
{
	StateManager::StateNow->progress();
}

void MainGame::Render()
{
	// ��׶��带 �Ͼ������ �ʱ�ȭ �ϴ� �ڵ�
	FillRect(memDC, &crt, (HBRUSH)GetStockObject(WHITE_BRUSH)); 
	
	// StateNow �� ���� ������Ʈ�� �� ���� State �� �ش��ϴ�
	// State�� render �Ѵ� (State �� �ڽ� ��ü) (������)
	StateManager::StateNow->render(); 

	//hdc �� memDC �� �����Ͽ� ǥ���Ѵ�
	BitBlt(hdc, crt.left, crt.top, crt.right, crt.bottom, memDC, 0, 0, SRCCOPY); 


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