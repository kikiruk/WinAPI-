 #pragma once
#include "ChessHorse.h"

class Bishop : public ChessHorse
{
public:
	virtual void render();
	virtual bool calCulateCanGo(const ChessHorse* const [], int index);

public:
	Bishop(int index);
	Bishop(int index, bool isWhite);
	~Bishop();
};

