#include "Queen.h"

void Queen::render()
{
	if (isWhite)
	{
		TransparentBlt(memDC, X, Y, 95, 95, bitmapDC, 384, 128, 128, 128, RGB(255, 0, 255));
	}
	else
	{
		TransparentBlt(memDC, X, Y, 95, 95, bitmapDC, 384, 0, 128, 128, RGB(255, 0, 255));
	}
}

bool Queen::calCulateCanGo(const ChessHorse* const chesses[], int index)
{
	initialize_check_arr();

	if (isWhite)
		set_check_arr(chesses);
	else
		set_check_arr_black(chesses);

	short chess_X = ((index) % 8);
	short chess_Y = (index) / 8;

	short queen_X = ((locationNow) % 8);
	short queen_Y = (locationNow) / 8;


	if (index < locationNow)
	{
		for (int i = queen_X - 1, j = queen_Y - 1; j >= 0, i >= 0; i--, j--) // 왼쪽 위 대각선
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

		for (int i = queen_X + 1, j = queen_Y - 1; j >= 0, i <= 7; i++, j--) // 오른쪽 위 대각선
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

		for (int i = queen_X + 1, j = queen_Y + 1; j <= 7, i <= 7; i++, j++)		// 오른쪽 아래 대각선
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

		for (int i = queen_X - 1, j = queen_Y + 1; j <= 7, i >= 0; i--, j++)		//왼쪽 아래 대각선
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

	if (chess_X == queen_X) //세로로 일직선상에 있는 경우
	{
		if (chess_Y > queen_Y) //목적좌표가 아래에 있음
		{
			queen_Y++;
			for (queen_Y; queen_Y < chess_Y; queen_Y++)
			{
				if (check_arr[(queen_Y * 8) + queen_X] != 0)
				{
					return false; // 가는길 중간에 체스말이 존재시 못감
				}
			}

			if (check_arr[(queen_Y * 8) + queen_X] == currentHorseNum)
			{
				return false;
			}

			if (check_arr[(queen_Y * 8) + queen_X] == enemyHorseNum)
			{
				return true;
			}

			return true;
		}
		else if (chess_Y < queen_Y) //목적좌표가 위에 있음
		{
			queen_Y--;
			for (queen_Y; queen_Y > chess_Y; queen_Y--)
			{
				if (check_arr[(queen_Y * 8) + queen_X] != 0)
				{
					return false; // 가는길 중간에 체스말이 존재시 못감
				}
			}

			if (check_arr[(queen_Y * 8) + queen_X] == currentHorseNum) //검은말일 경우 못감
			{
				return false;
			}
			else if (check_arr[(queen_Y * 8) + queen_X] == enemyHorseNum) //흰 말일 경우 못감
			{
				return true;
			}

			return true;
		}
	}

	if (chess_Y == queen_Y) //가로로 일직선상에 있는 경우
	{
		if (queen_X < chess_X) //목적지가 오른쪽에 있는 경우
		{
			queen_X++;
			for (queen_X; queen_X < chess_X; queen_X++)
			{
				if (check_arr[(queen_Y * 8) + queen_X] != 0)
				{
					return false; // 가는길 중간에 체스말이 존재시 못감
				}
			}

			if (check_arr[(queen_Y * 8) + queen_X] == currentHorseNum) //검은 말일 경우 못감
			{
				return false;
			}
			else if (check_arr[(queen_Y * 8) + queen_X] == enemyHorseNum)//흰색 말일 경우
			{
				return true;
			}

			return true;
		}
		else if (queen_X > chess_X) //목적지가 왼쪽에 있는 경우
		{
			queen_X--;
			for (queen_X; queen_X > chess_X; queen_X--)
			{
				if (check_arr[(queen_Y * 8) + queen_X] != 0)
				{
					return false; // 가는길 중간에 체스말이 존재시 못감
				}
			}

			if (check_arr[(queen_Y * 8) + queen_X] == currentHorseNum) //검은 말일 경우 못감
			{
				return false;
			}
			else if (check_arr[(queen_Y * 8) + queen_X] == enemyHorseNum)//흰색 말일 경우
			{
				return true;
			}

			return true;
		}
	}

	return false;
}


Queen::Queen(int index)
{
	setPosByIndex(index);
	locationNow = index;
	MovingSpeed = 3;
	coolTime = 120;
}

Queen::Queen(int index, bool isWhite)
{
	setPosByIndex(index);
	this->isWhite = isWhite;
	locationNow = index;
	MovingSpeed = 3;
	currentHorseNum = 2;
	enemyHorseNum = 1;
	coolTime = 120;
}


Queen::~Queen()
{
}
