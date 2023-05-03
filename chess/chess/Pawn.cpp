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
			if (index == (locationNow + 8)) //���� ��ĭ
			{
				if (check_arr[index] != 0)
				{
					return false; //�տ� �����̵� �Ʊ��̵� ü������ ������ ����
				}

				return true; // �տ� �ƹ��͵� ������ ���� ����.
			}
			else if (index == (locationNow + 9)) // ���� �밢�� ��ĭ
			{
				if (check_arr[index] == enemyHorseNum)
				{
					return true; // ���� �밢�� ��ĭ�� ������ϰ��
				}
			}
			else if (index == (locationNow + 7)) // ������ �밢�� ��ĭ
			{
				if (check_arr[index] == enemyHorseNum)
				{
					return true; // ������ �밢�� ��ĭ�� ������ϰ��
				}
			}
		}
		else
		{
			if (index == (locationNow - 8)) //���� ��ĭ
			{
				if (check_arr[index] != 0)
				{
					return false; //�տ� �����̵� �Ʊ��̵� ü������ ������ ����
				}

				return true; // �տ� �ƹ��͵� ������ ���� ����.
			}
			else if (index == (locationNow - 9)) // ���� �밢�� ��ĭ
			{
				if (check_arr[index] == enemyHorseNum)
				{
					return true; // ���� �밢�� ��ĭ�� ������ϰ��
				}
			}
			else if (index == (locationNow - 7)) // ������ �밢�� ��ĭ
			{
				if (check_arr[index] == enemyHorseNum)
				{
					return true; // ������ �밢�� ��ĭ�� ������ϰ��
				}
			}
		}

	}

	return false; //���� ������ �ƹ��͵� �������� �ʴ´ٸ� ������ ������ ����.
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
