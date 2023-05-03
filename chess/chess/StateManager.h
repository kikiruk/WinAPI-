#pragma once
#include "State.h"
#include "Main.h"
#include "Option.h"
#include "GameStart.h"
#include "BeforGameStart.h"
#include "Game_Clear.h"
#include "RankRegistration.h"

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
	static RankRegistration* rankRegistration;

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

		case REGISTER:
			StateNow = rankRegistration;
			break;

		}
	};

public:
	static Main* getMainState();
	static Option* getOptionState();
	static GameStart* getGameStartState();
	static BeforGameStart* getBeforGameStartState();
	static Game_Clear* getGame_Clear();
	static RankRegistration* getRankRegistrationr();
};

