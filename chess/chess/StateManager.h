#pragma once
#include "State.h"
#include "Main.h"
#include "Option.h"
#include "GameStart.h"
#include "BeforGameStart.h"
#include "Game_Clear.h"
#include "Computer.h"

/***********************************
���ο� State �� ����� ������ State Ŭ������ ��� �޴� Ŭ������ ���� ��
���⼭ ����ϸ� �ȴ� STATES enum ���� ����ؾ��Ѵ�
�׸��� ���Ӽӿ��� �ش� State �� �̵��ϰ� ������ 
setStateNow �Լ��� ȣ���ϸ� �ȴ�
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

	//Computer �� State �� �ƴ����� Option �� GameStart�� ������ �����ؾ��ϱ⿡ ���⿡ �����ص�
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

