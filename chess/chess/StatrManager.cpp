#include "StateManager.h"

State* StateManager::StateNow = nullptr;
Main* StateManager::_main = nullptr;
Option* StateManager::option = nullptr;
GameStart* StateManager::gameStart = nullptr;
BeforGameStart* StateManager::beforGameStart = nullptr;
Game_Clear* StateManager::game_Clear = nullptr;

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
