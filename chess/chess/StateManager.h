#pragma once
#include "State.h"
#include "Main.h"
#include "Option.h"
#include "GameStart.h"
#include "BeforGameStart.h"
#include "Game_Clear.h"
#include "Computer.h"

/***********************************
새로운 State 를 만들고 싶으면 State 클래스를 상속 받는 클래스를 만든 후
여기서 등록하면 된다 STATES enum 에도 등록해야한다
그리고 게임속에서 해당 State 로 이동하고 싶으면 
setStateNow 함수를 호출하면 된다
************************************/

enum STATES
{
	MAIN,
	GAME_START,
	BEFOR_GAME_START,
	GAME_CLEAR,
	OPTION
};

class StateManager
{
	friend class MainGame;

private:
	StateManager() = delete;

private:

	//Computer 은 State 는 아니지만 Option 과 GameStart가 접근이 가능해야하기에 여기에 정의해둠
	static Computer* computer; 
	static State* StateNow;
	static Main* _main;
	static Option* option;
	static GameStart* gameStart;
	static BeforGameStart* beforGameStart;
	static Game_Clear* game_Clear;

private:
	static void initialize();

public:
	static void setStateNow(STATES state)
	{
		switch (state)
		{
		case MAIN:
			StateNow = _main;
			break;

		case OPTION:
			StateNow = option;
			break;

		case GAME_START:
			StateNow = gameStart;
			break;

		case BEFOR_GAME_START:
			StateNow = beforGameStart;
			break;

		case GAME_CLEAR:
			StateNow = game_Clear;
			break;

		}
	};

public:

	static Main* getMainState();
	static Option* getOptionState();
	static GameStart* getGameStartState();
	static BeforGameStart* getBeforGameStartState();
	static Game_Clear* getGame_Clear();
};

