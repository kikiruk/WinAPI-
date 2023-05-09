#include "StateManager.h"

Computer* StateManager::computer = nullptr; // �ʱ�ȭ �����ָ� ������ ������
State* StateManager::StateNow = nullptr;
Main* StateManager::_main = nullptr;
Option* StateManager::option = nullptr;
GameStart* StateManager::gameStart = nullptr;
BeforGameStart* StateManager::beforGameStart = nullptr;

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
	StateNow = _main;
}

void StateManager::release()
{
	delete _main;
	delete computer;
	delete option;
	delete gameStart;
	delete beforGameStart;
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
