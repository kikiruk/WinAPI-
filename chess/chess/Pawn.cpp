#include "Pawn.h"

void Pawn::render()
{
	if (isWhite)
	{
		TransparentBlt(memDC, X, Y, 95, 95, bitmapDC, 0, 128, 128, 128, RGB(255, 0, 255));
	}
	else
	{
		TransparentBlt(memDC, X, Y,95, 95, bitmapDC, 0, 0, 128, 128, RGB(255, 0, 255));
	}
}

bool Pawn::calCulateCanGo(const ChessHorse* const chesses[], int index)
{
	initialize_check_arr();

	if (isWhite)
		set_check_arr(chesses);
	else
		set_check_arr_black(chesses);

	short pawn_X = ((locationNow) % 8);
	short pawn_Y = (locationNow) / 8;

	short go_X = ((index) % 8);
	short go_Y = (index) / 8;

	if (pawn_X < go_X + 2 && pawn_X > go_X - 2)
	{
		if (isWhite)
		{
			if (index == (locationNow + 8)) //직선 한칸
			{
				if (check_arr[index] != 0)
				{
					return false; //앞에 적군이든 아군이든 체스말이 있으면 못감
				}

				return true; // 앞에 아무것도 없으면 갈수 있음.
			}
			else if (index == (locationNow + 9)) // 왼쪽 대각선 한칸
			{
				if (check_arr[index] == enemyHorseNum)
				{
					return true; // 왼쪽 대각선 한칸이 흰색말일경우
				}
			}
			else if (index == (locationNow + 7)) // 오른쪽 대각선 한칸
			{
				if (check_arr[index] == enemyHorseNum)
				{
					return true; // 오른쪽 대각선 한칸이 흰색말일경우
				}
			}
		}
		else
		{
			if (index == (locationNow - 8)) //직선 한칸
			{
				if (check_arr[index] != 0)
				{
					return false; //앞에 적군이든 아군이든 체스말이 있으면 못감
				}

				return true; // 앞에 아무것도 없으면 갈수 있음.
			}
			else if (index == (locationNow - 9)) // 왼쪽 대각선 한칸
			{
				if (check_arr[index] == enemyHorseNum)
				{
					return true; // 왼쪽 대각선 한칸이 흰색말일경우
				}
			}
			else if (index == (locationNow - 7)) // 오른쪽 대각선 한칸
			{
				if (check_arr[index] == enemyHorseNum)
				{
					return true; // 오른쪽 대각선 한칸이 흰색말일경우
				}
			}
		}

	}

	return false; //위의 조건을 아무것도 충족하지 않는다면 어차피 못가는 곳임.
}


Pawn::Pawn(int index)
{
	setPosByIndex(index);
	locationNow = index;
	isPawn = true;
}

Pawn::Pawn(int index, bool isWhite)
{
	setPosByIndex(index);
	this->isWhite = isWhite;
	locationNow = index;
	currentHorseNum = 2;
	enemyHorseNum = 1;
	isPawn = true;
}


Pawn::~Pawn()
{
}
