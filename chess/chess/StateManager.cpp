#include "StateManager.h"

State* StateManager::StateNow = nullptr;
Main* StateManager::_main = nullptr;
Option* StateManager::option = nullptr;
GameStart* StateManager::gameStart = nullptr;
BeforGameStart* StateManager::beforGameStart = nullptr;
Game_Clear* StateManager::game_Clear = nullptr;

void StateManager::initialize()
{
	// 동적 할당을 해주는 이유는 WindowsAPI HDC 라던지 
	// WindowsAPI 관련 객체들이 먼저 초기화가 이루어 진 이후에 할당시켜줘야 하기 때문이다
	// 이 initialize 함수는 MainGame생성자에서 호출되어진다

	_main = new Main;
	computer = new Computer;
	option = new Option(computer);
	gameStart = new GameStart(computer);
	beforGameStart = new BeforGameStart;
	game_Clear = new Game_Clear;
	StateNow = _main;
}

Main* StateManager::getMainState()
{
	return _main;
}


GameStart* StateManager::getGameStartState()
{
	return gameStart;
}

Option* StateManager::getOptionState()
{
	return option;
}

BeforGameStart* StateManager::getBeforGameStartState()
{
	return beforGameStart;
}

Game_Clear* StateManager::getGame_Clear()
{
	return game_Clear;
}
