#pragma once
#pragma comment (lib, "MSimg32.lib")

#include <Windows.h>
#include <list>
#include <math.h>
#include <time.h>
#include <cstdlib>

using namespace std;

//#include "resource.h"


#define BUFFER_WIDTH 1000
#define BUFFER_HEIGHT 700

enum KEYNOW
{
	NULL_KEY,
	LEFT,
	RIGHT,
	UP,
	DOWN,
	SPACE
};

enum STATES
{
	MAIN,
	GAME_START,
	BEFOR_GAME_START,
	GAME_CLEAR,
	REGISTER,
	OPTION
};

