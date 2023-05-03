#include "Computer.h"
#include "Computer.h"


Computer::Computer()
{
	difficulty = 1;
}

void Computer::progress(ChessHorse* chesses[32], GameStart* gameStart)
{
	progressPwan(chesses, gameStart);
	progressKing(chesses, gameStart);
	progressOtheres(chesses, gameStart);
}

void Computer::setDifficulty(short difficulty)
{
	this->difficulty = difficulty;
}

int Computer::getDifficulty()
{
	return difficulty;
}

inline void Computer::progressPwan(ChessHorse* chesses[32], GameStart* gameStart)
{
	for (int i = 8; i < 16; i++)
	{
		for (int j = 0; j < 64; j++)
		{
			if (chesses[i] != nullptr)
			{
				if (chesses[i]->calCulateCanGo(chesses, j))
				{
					if (rand() % (100 * (6 - difficulty)) < 1) //���̵� ���� �κ�
					{
						gameStart->chessHorseMoveProgress(chesses[i], j);
					}
				}
			}
		}
	}
}

inline void Computer::progressKing(ChessHorse* chesses[32], GameStart* gameStart)
{
	if (chesses[4] != nullptr)
	{
		short _locationNow = chesses[4]->locationNow;
		ChessHorse* king = chesses[4];

		for (short i = 0; i < 3; i++) //���� �����ִ°��� ������ �����ϴ� ��� ����
		{
			for (int j = _locationNow + 8 - (i * 8) - 1; j < _locationNow + 8 - (i * 8) + 2; j++)
			{
				if (king->calCulateCanGo(chesses, j))
				{
					if (king->check_arr[j] == 1)
					{
						for (short k = 16; k < 32; k++)
						{
							if (chesses[k] != nullptr)
							{
								if (chesses[k]->locationNow == j && !(chesses[k]->isMoveing))
								{
									gameStart->chessHorseMoveProgress(king,j);
								}
							}
						}
					}
				}
			}
		}

		for (short i = 0; i < 32; i++) //�տ��� ���� ���� ������ ���ϱ�
		{
			if (chesses[i] != nullptr && chesses[i]->isMoveing && chesses[i]->locationNow == _locationNow)
			{
				for (short j = 0; j < 3; j++)
				{
					for (int k = _locationNow + 8 - (j * 8) - 1; k < _locationNow + 8 - (j * 8) + 2; k++)
					{
						if (king->calCulateCanGo(chesses, k))
						{
							if (rand() % 1000 < (1 * difficulty)) //���̵� ���� �κ�
							{
								gameStart->chessHorseMoveProgress(king,k);
							}
						}
					}
				}
			}
		}
	}

}

inline void Computer::progressOtheres(ChessHorse* chesses[32], GameStart* gameStart)
{
	for (short i = 0; i < 8; i++)
	{
		if (chesses[i] != nullptr && i != 4)// i != 4 �ջ���
		{
			for (short j = 0; j < 64; j++)
			{
				if (chesses[i]->calCulateCanGo(chesses, j))
				{
					// �����ִ� ��� �� ü������ �����ϴ� ��� �����ΰ� //���̵�����
					if (chesses[i]->check_arr[j] == 1 && rand() % 1000 < (3 * difficulty))
					{
						gameStart->chessHorseMoveProgress(chesses[i], j);
						continue;
					}

					//���̵� ����	//��� �����̰� �������� �����.
					if (rand() % 1000 < (100 * difficulty) && rand() % 1000 < 10)
					{
						gameStart->chessHorseMoveProgress(chesses[i],j);
					}
				}
			}
		}
	}
}

