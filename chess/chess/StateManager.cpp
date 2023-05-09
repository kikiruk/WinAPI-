#include "StateManager.h"

State* StateManager::StateNow = nullptr;
Main* StateManager::_main = nullptr;
Option* StateManager::option = nullptr;
GameStart* StateManager::gameStart = nullptr;
BeforGameStart* StateManager::beforGameStart = nullptr;
Game_Clear* StateManager::game_Clear = nullptr;

void StateManager::initialize()
{
	// ���� �Ҵ��� ���ִ� ������ WindowsAPI HDC ����� 
	// WindowsAPI ���� ��ü���� ���� �ʱ�ȭ�� �̷�� �� ���Ŀ� �Ҵ������� �ϱ� �����̴�
	// �� initialize �Լ��� MainGame�����ڿ��� ȣ��Ǿ�����

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
