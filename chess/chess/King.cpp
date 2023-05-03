#include "King.h"


void King::render()
{
	if (isWhite)
	{
		TransparentBlt(memDC, X, Y, 95, 95, bitmapDC, 512, 128, 128, 128, RGB(255, 0, 255));
	}
	else
	{
		TransparentBlt(memDC, X, Y, 95, 95, bitmapDC, 512, 0, 128, 128, RGB(255, 0, 255));
	}
}

bool King::calCulateCanGo(const ChessHorse* const chesses[], int index)
{
	initialize_check_arr();

	if (isWhite)
		set_check_arr(chesses);
	else
		set_check_arr_black(chesses);

	short chess_X = ((index) % 8);
	short chess_Y = (index) / 8;

	short king_X = ((locationNow) % 8);
	short king_Y = (locationNow) / 8;

	if (chess_Y == king_Y - 1 || chess_Y == king_Y + 1) //Y 축으로 한칸위쪽 , 또는 한칸 아래쪽
	{
		for (short i = king_X - 1; i < king_X + 2; i++)
		{
			if (index == (chess_Y * 8) + i && check_arr[(chess_Y * 8) + i] != currentHorseNum)
			{
				return true;
			}
		}
	}
	else if (chess_Y == king_Y) //Y축 같을 경우
	{
		if (index == (king_Y * 8) + (king_X - 1) && check_arr[(king_Y * 8) + (king_X - 1)] != currentHorseNum) //왼쪽 한칸
		{
			return true;
		}

		if (index == (king_Y * 8) + (king_X + 1) && check_arr[(king_Y * 8) + (king_X + 1)] != currentHorseNum) // 오른쪽 한칸
		{
			return true;
		}
	}


	return false;
}


King::King(int index)
{
	setPosByIndex(index);
	locationNow = index;
}

King::King(int index, bool isWhite)
{
	setPosByIndex(index);
	this->isWhite = isWhite;
	locationNow = index;
	currentHorseNum = 2;
	enemyHorseNum = 1;
}


King::~King()
{
}
