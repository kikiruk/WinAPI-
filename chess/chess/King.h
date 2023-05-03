#pragma once
#include "ChessHorse.h"

class King : public ChessHorse
{
public:
	virtual void render();
	virtual bool calCulateCanGo(const ChessHorse* const [], int index);

public:
	King(int index);
	King(int index, bool isWhite);
	~King();
};

