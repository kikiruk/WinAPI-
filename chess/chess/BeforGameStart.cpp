#include "BeforGameStart.h"
#include "StateManager.h"
#include "BitMapManager.h"

void BeforGameStart::progress()
{
	count++;
	backGround_count++;

	if (1000 - (backGround_count * 5) == 0)
	{
		backGround_count = 0;
	}

	if (count == 2)
	{
		StateManager::getGameStartState()->initialize();
	}

	if (count < 150)
		Y -= (speed - (count / 11));

	if(count > 200)
		StateManager::setStateNow(GAME_START);
}

void BeforGameStart::render()
{
	TransparentBlt(memDC, -(backGround_count * 5), 0, 1000, 700, BackGround_bitmapDC, 0, 0, 800, 800, RGB(255, 0, 255)); // 뒤에 배경 체스판 그리기
	TransparentBlt(memDC, 1000 - (backGround_count * 5), 0, 1000, 700, BackGround_bitmapDC, 0, 0, 800, 800, RGB(255, 0, 255));
	TransparentBlt(memDC, 0, Y, 1000, 700, bitmapDC, 0, 0, 1000, 700, RGB(255, 0, 255));
}

void BeforGameStart::initialize()
{
	count = 1;
	backGround_count = 0;
	Y = 700;
}

BeforGameStart::BeforGameStart() :
bitmapDC(BitMapManager::getLogo_game_start_bitmapDC()),
BackGround_bitmapDC(BitMapManager::getBackGround_bitmapDC()),
count(1),
backGround_count(0),
Y(700),
speed(11)
{
}
