#include "Look.h"

void Look::render()
{
	if (isWhite)
	{
		TransparentBlt(memDC, X, Y, 95, 95, bitmapDC, 256, 128, 128, 128, RGB(255, 0, 255));
	}
	else
	{
		TransparentBlt(memDC, X, Y, 95, 95, bitmapDC, 256, 0, 128, 128, RGB(255, 0, 255));
	}
}

bool Look::calCulateCanGo(const ChessHorse* const chesses[], int index)
{
	initialize_check_arr();

	if (isWhite)
		set_check_arr(chesses);
	else
		set_check_arr_black(chesses);

	if (0 <= index)
	{
		short chess_X = ((index ) % 8);
		short chess_Y = (index) / 8;
	
		short look_X = ((locationNow) % 8);
		short look_Y = (locationNow ) / 8;

		if (chess_X == look_X) //세로로 일직선상에 있는 경우
		{
			if (chess_Y > look_Y) //목적좌표가 아래에 있음
			{
				look_Y++;
				for (look_Y; look_Y < chess_Y; look_Y++)
				{
					if (check_arr[(look_Y * 8) + look_X] != 0)
					{
						return false; // 가는길 중간에 체스말이 존재시 못감
					}
				}

				if (check_arr[(look_Y * 8) + look_X] == currentHorseNum)
				{
					return false;
				}
				
				if (check_arr[(look_Y * 8) + look_X] == enemyHorseNum)
				{
					return true;
				}

				return true;
			}	
			else if (chess_Y < look_Y) //목적좌표가 위에 있음
			{
				look_Y--;
				for (look_Y; look_Y > chess_Y; look_Y--)
				{
					if (check_arr[(look_Y * 8) + look_X] != 0)
					{
						return false; // 가는길 중간에 체스말이 존재시 못감
					}
				}

				if (check_arr[(look_Y * 8) + look_X] == currentHorseNum) //검은말일 경우 못감
				{
					return false;
				}
				else if (check_arr[(look_Y * 8) + look_X] == enemyHorseNum) //흰 말일 경우 못감
				{
					return true;
				}

				return true;
			}
		}

		if (chess_Y == look_Y) //가로로 일직선상에 있는 경우
		{
			if (look_X < chess_X) //목적지가 오른쪽에 있는 경우
			{
				look_X++;
				for (look_X; look_X < chess_X; look_X++)
				{
					if (check_arr[(look_Y * 8) + look_X] != 0)
					{
						return false; // 가는길 중간에 체스말이 존재시 못감
					}
				}

				if (check_arr[(look_Y * 8) + look_X] == currentHorseNum) //검은 말일 경우 못감
				{
					return false;
				}
				else if (check_arr[(look_Y * 8) + look_X] == enemyHorseNum)//흰색 말일 경우
				{
					return true;
				}

				return true;
			}
			else if (look_X > chess_X) //목적지가 왼쪽에 있는 경우
			{
				look_X--;
				for (look_X; look_X > chess_X; look_X--)
				{
					if (check_arr[(look_Y * 8) + look_X] != 0)
					{
						return false; // 가는길 중간에 체스말이 존재시 못감
					}
				}

				if (check_arr[(look_Y * 8) + look_X] == currentHorseNum) //검은 말일 경우 못감
				{
					return false;
				}
				else if (check_arr[(look_Y * 8) + look_X] == enemyHorseNum)//흰색 말일 경우
				{
					return true;
				}

				return true;
			}
		}
	}

	return false;
}

Look::Look(int index)
{
	setPosByIndex(index);
	locationNow = index;
	MovingSpeed = 3;
	coolTime = 120;
}

Look::Look(int index, bool isWhite)
{
	setPosByIndex(index);
	this->isWhite = isWhite;
	locationNow = index;
	MovingSpeed = 3;
	currentHorseNum = 2;
	enemyHorseNum = 1;
	coolTime = 120;
}


Look::~Look()
{
}
