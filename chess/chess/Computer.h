#pragma once
#include "ChessHorse.h"
#include "GameStart.h"

class Computer
{
	friend class GameStart;
	friend class Option;

private:
	short difficulty;
	void progress(ChessHorse* chesshorse[32], GameStart* gameStart);

public:
	void setDifficulty(short difficulty);
	int getDifficulty();

private:
	inline void progressPwan(ChessHorse* chesses[32], GameStart* gameStart);
	void progressKing(ChessHorse* chesses[32], GameStart* gameStart);
	void progressOtheres(ChessHorse* chesses[32], GameStart* gameStart);

public:
	Computer();

};