#pragma once
#include "State.h"
#include "Main.h"

/***********************************
새로운 State 를 만들고 싶으면 State 클래스를 상속 받는 클래스를 만든 후
여기서 등록하면 된다 STATES enum 에도 등록해야한다
그리고 게임속에서 해당 State 로 이동하고 싶으면 
setStateNow 함수를 호출하면 된다
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

	//Computer 은 State 는 아니지만 Option 과 GameStart가 접근이 가능해야하기에 여기에 정의해둠
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

