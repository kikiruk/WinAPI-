#pragma once
#include "State.h"
#include "Main.h"
#include "Option.h"
#include "GameStart.h"
#include "BeforGameStart.h"
#include "Game_Clear.h"

/***********************************
새로운 State 를 만들고 싶으면 State 클래스를 상속 받는 클래스를 만든 후
여기서 등록하면 된다 
Include.h 에 STATES enum 에도 등록해야한다
그리고 게임속에서 해당 State 로 이동하고 싶으면 
setStateNow 함수를 호출하면 된다
************************************/

class StateManager
{
	friend class MainGame;

private:
	static State* StateNow;
	static Main* _main;
	static Option* option;
	static GameStart* gameStart;
	static BeforGameStart* beforGameStart;
	static Game_Clear* game_Clear;

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

