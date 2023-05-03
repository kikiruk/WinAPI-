#pragma once
#include "ChessHorse.h"

class Look : public ChessHorse
{
public:
	virtual void render();
	virtual bool calCulateCanGo(const ChessHorse* const [], int index);

public:
	Look(int index);
	Look(int index, bool isWhite);
	~Look();

};
