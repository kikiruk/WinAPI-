#pragma once
#include "ChessHorse.h"

class Pawn : public ChessHorse
{
public:
	virtual void render();
	virtual bool calCulateCanGo(const ChessHorse* const [], int index);

public:
	Pawn(int index);
	Pawn(int index, bool isWhite);
	~Pawn();
};
