#pragma once
#include "ChessHorse.h"

class Night : public ChessHorse
{
public:
	virtual void render();
	virtual void progress();
	virtual bool calCulateCanGo(const ChessHorse* const [], int index);

public:
	Night(int index);
	Night(int index, bool isWhite);
	~Night();
};


