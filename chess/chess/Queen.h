#pragma once
#include "ChessHorse.h"

class Queen : public ChessHorse
{
public:
	virtual void render();
	virtual bool calCulateCanGo(const ChessHorse* const [], int index);

public:
	Queen(int index);
	Queen(int index,bool isWhite);
	~Queen();
};
