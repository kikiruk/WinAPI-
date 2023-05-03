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

		if (chess_X == look_X) //���η� �������� �ִ� ���
		{
			if (chess_Y > look_Y) //������ǥ�� �Ʒ��� ����
			{
				look_Y++;
				for (look_Y; look_Y < chess_Y; look_Y++)
				{
					if (check_arr[(look_Y * 8) + look_X] != 0)
					{
						return false; // ���±� �߰��� ü������ ����� ����
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
			else if (chess_Y < look_Y) //������ǥ�� ���� ����
			{
				look_Y--;
				for (look_Y; look_Y > chess_Y; look_Y--)
				{
					if (check_arr[(look_Y * 8) + look_X] != 0)
					{
						return false; // ���±� �߰��� ü������ ����� ����
					}
				}

				if (check_arr[(look_Y * 8) + look_X] == currentHorseNum) //�������� ��� ����
				{
					return false;
				}
				else if (check_arr[(look_Y * 8) + look_X] == enemyHorseNum) //�� ���� ��� ����
				{
					return true;
				}

				return true;
			}
		}

		if (chess_Y == look_Y) //���η� �������� �ִ� ���
		{
			if (look_X < chess_X) //�������� �����ʿ� �ִ� ���
			{
				look_X++;
				for (look_X; look_X < chess_X; look_X++)
				{
					if (check_arr[(look_Y * 8) + look_X] != 0)
					{
						return false; // ���±� �߰��� ü������ ����� ����
					}
				}

				if (check_arr[(look_Y * 8) + look_X] == currentHorseNum) //���� ���� ��� ����
				{
					return false;
				}
				else if (check_arr[(look_Y * 8) + look_X] == enemyHorseNum)//��� ���� ���
				{
					return true;
				}

				return true;
			}
			else if (look_X > chess_X) //�������� ���ʿ� �ִ� ���
			{
				look_X--;
				for (look_X; look_X > chess_X; look_X--)
				{
					if (check_arr[(look_Y * 8) + look_X] != 0)
					{
						return false; // ���±� �߰��� ü������ ����� ����
					}
				}

				if (check_arr[(look_Y * 8) + look_X] == currentHorseNum) //���� ���� ��� ����
				{
					return false;
				}
				else if (check_arr[(look_Y * 8) + look_X] == enemyHorseNum)//��� ���� ���
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
