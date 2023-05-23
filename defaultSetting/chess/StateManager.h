#pragma once
#include "State.h"
#include "Main.h"

/***********************************
���ο� State �� ����� ������ State Ŭ������ ��� �޴� Ŭ������ ���� ��
���⼭ ����ϸ� �ȴ� STATES enum ���� ����ؾ��Ѵ�
�׸��� ���Ӽӿ��� �ش� State �� �̵��ϰ� ������ 
setStateNow �Լ��� ȣ���ϸ� �ȴ�
************************************/

enum STATES
{
	MAIN
};

class StateManager
{
	friend class MainGame;

private:
	StateManager() = delete;

private:

	//Computer �� State �� �ƴ����� Option �� GameStart�� ������ �����ؾ��ϱ⿡ ���⿡ �����ص�
	static State* StateNow;
	static Main* _main;

private:
	static void initialize();
	static void release();

public:
	static void setStateNow(STATES state)
	{
		switch (state)
		{
		case MAIN:
			StateNow = _main;
			break;

		default :
			break;
		}
	};

public:
	static Main* getMainState();
};

