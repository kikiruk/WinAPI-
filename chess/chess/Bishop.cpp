#include "Bishop.h"

void Bishop::render()
{
	if (isWhite)
	{
		TransparentBlt(memDC, X, Y, 95, 95, bitmapDC, 128, 128, 128, 128, RGB(255, 0, 255));
	}
	else
	{
		TransparentBlt(ChessHorse::memDC, X, Y, 95, 95, ChessHorse::bitmapDC, 128, 0, 128, 128, RGB(255, 0, 255));
	}
}

bool Bishop::calCulateCanGo(const ChessHorse* const chesses[], int index)
{
	initialize_check_arr();
	set_check_arr(chesses);
	short chess_X = ((index) % 8);
	short chess_Y = (index) / 8;
	
	short bishop_X = ((locationNow) % 8);
	short bishop_Y = (locationNow) / 8;

	//if(index != 0)
	if (index < locationNow)
	{
		for(int i = bishop_X - 1,j = bishop_Y - 1; j >= 0 && i >= 0; i--,j--) // 왼쪽 위 대각선
		{
			if (((j * 8) + i) == index)
			{
				if (check_arr[((j * 8) + i)] != currentHorseNum)
				{
					return true;
				}
				else
				{
					return false;
				}
			}

			if (check_arr[((j * 8) + i)] != 0)
			{
				break;
			}
		}

		for (int i = bishop_X + 1, j = bishop_Y - 1; j >= 0 && i <= 7; i++, j--) // 오른쪽 위 대각선
		{
			if (((j * 8) + i) == index)
			{
				if (check_arr[((j * 8) + i)] != currentHorseNum)
				{
					return true;
				}
				else
				{
					return false;
				}
			}

			if (check_arr[((j * 8) + i)] != 0)
			{
				break;
			}
		}
	}
	else
	{

		for (int i = bishop_X + 1, j = bishop_Y + 1; j <= 7 && i <= 7; i++, j++)		// 오른쪽 아래 대각선
		{
			if (((j * 8) + i) == index)
			{
				if (check_arr[((j * 8) + i)] != currentHorseNum)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			
			if (check_arr[((j * 8) + i)] != 0)
			{
				break;
			}
		}

		for (int i = bishop_X - 1, j = bishop_Y + 1; j <= 7 && i >= 0; i--, j++)		//왼쪽 아래 대각선
		{
			if (((j * 8) + i) == index)
			{
				if (check_arr[((j * 8) + i)] != currentHorseNum)
				{
					return true;
				}
				else
				{
					return false;
				}
			}

			if (check_arr[((j * 8) + i)] != 0)
			{
				break;
			}
		}
	}


	return false;
}

Bishop::Bishop(int index)
{
	setPosByIndex(index);
	locationNow = index;
	MovingSpeed = 3;
	coolTime = 120;
}

Bishop::Bishop(int index, bool isWhite)
{
	setPosByIndex(index);
	this->isWhite = isWhite;
	locationNow = index;
	MovingSpeed = 3;
	currentHorseNum = 2;
	enemyHorseNum = 1;
	coolTime = 120;
}


Bishop::~Bishop()
{
}
