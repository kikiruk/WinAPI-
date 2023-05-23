#include "StateManager.h"

State* StateManager::StateNow = nullptr; // �ʱ�ȭ �����ָ� ������ ������
Main* StateManager::_main = nullptr; 

void StateManager::initialize()
{
	// ���� �Ҵ��� ���ִ� ������ WindowsAPI HDC ����� 
	// WindowsAPI ���� ��ü���� ���� �ʱ�ȭ�� �̷�� �� ���Ŀ� �Ҵ������� �ϱ� �����̴�
	// �� initialize �Լ��� MainGame�����ڿ��� ȣ��Ǿ�����

	_main = new Main;
	StateNow = _main;
}

void StateManager::release()
{
	delete _main;
}

Main* StateManager::getMainState()
{
	return _main;
}
