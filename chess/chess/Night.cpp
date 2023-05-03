#include "Night.h"

void Night::render()
{
	if (isWhite)
	{
		TransparentBlt(memDC, X, Y, 95, 95, bitmapDC, 640, 128, 128, 128, RGB(255, 0, 255));
	}
	else
	{
		TransparentBlt(memDC, X, Y, 95, 95, bitmapDC, 640, 0, 128, 128, RGB(255, 0, 255));
	}
}

void Night::progress() //Night 는 움직임이 특이하므로 따로 오버라이딩
{
	if (count == 0)
	{
		int chessPos_toGo_X = chessPos[toGo].X;
		int chessPos_toGo_Y = chessPos[toGo].Y;

		if (isMoveing)
		{
			if (X < chessPos_toGo_X)
			{
				X = X + MovingSpeed;
			}

			if (X > chessPos_toGo_X)
			{
				X = X - MovingSpeed;
			}

			if (Y < chessPos_toGo_Y)
			{
				Y = Y + MovingSpeed;;
			}

			if (Y > chessPos_toGo_Y)
			{
				Y = Y - MovingSpeed;;
			}
		}

		if (X + 10 > chessPos_toGo_X && X + 52 < chessPos_toGo_X + 62)
		{
			if (Y + 10 > chessPos_toGo_Y && Y + 52 < chessPos_toGo_Y + 62)
			{
				X = chessPos_toGo_X;
				Y = chessPos_toGo_Y;
				toGo = -1;
				isMoveing = false;
			}
		}
	}
	else
	{
		count--;
	}
}

bool Night::calCulateCanGo(const ChessHorse* const chesses[], int index)
{
	initialize_check_arr();

	if (isWhite)
		set_check_arr(chesses);
	else
		set_check_arr_black(chesses);

	short look_X = ((locationNow) % 8);
	short look_Y = (locationNow) / 8;

	short go_X = ((index) % 8);
	short go_Y = (index) / 8;

	if (check_arr[index] != currentHorseNum)
	{
		if (go_X == look_X - 2)
		{
			if (go_Y == look_Y - 1)
			{
				return true;
			}
			else if (go_Y == look_Y + 1)
			{
				return true;
			}
		}
		else if(go_X == look_X + 2)
		{
			if (go_Y == look_Y - 1)
			{
				return true;
			}
			else if (go_Y == look_Y + 1)
			{
				return true;
			}
		}
		else if (go_Y == look_Y - 2)
		{
			if (go_X == look_X - 1)
			{
				return true;
			}
			else if (go_X == look_X + 1)
			{
				return true;
			}
		}
		else if (go_Y == look_Y + 2)
		{
			if (go_X == look_X - 1)
			{
				return true;
			}
			else if (go_X == look_X + 1)
			{
				return true;
			}
		}
	}

	return false;
}



Night::Night(int index)
{
	setPosByIndex(index);
	locationNow = index;
}

Night::Night(int index, bool isWhite)
{
	setPosByIndex(index);
	this->isWhite = isWhite;
	locationNow = index;
	currentHorseNum = 2;
	enemyHorseNum = 1;
}


Night::~Night()
{
}
