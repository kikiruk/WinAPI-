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
					if (rand() % (100 * (6 - difficulty)) < 1) //난이도 설정 부분
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

		for (short i = 0; i < 3; i++) //왕이 갈수있는곳에 적말이 존재하는 경우 공격
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

		for (short i = 0; i < 32; i++) //왕에게 오는 말이 있으면 피하기
		{
			if (chesses[i] != nullptr && chesses[i]->isMoveing && chesses[i]->locationNow == _locationNow)
			{
				for (short j = 0; j < 3; j++)
				{
					for (int k = _locationNow + 8 - (j * 8) - 1; k < _locationNow + 8 - (j * 8) + 2; k++)
					{
						if (king->calCulateCanGo(chesses, k))
						{
							if (rand() % 1000 < (1 * difficulty)) //난이도 설정 부분
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
		if (chesses[i] != nullptr && i != 4)// i != 4 왕빼고
		{
			for (short j = 0; j < 64; j++)
			{
				if (chesses[i]->calCulateCanGo(chesses, j))
				{
					// 갈수있는 길목에 적 체스말이 존재하는 경우 먹으로감 //난이도설정
					if (chesses[i]->check_arr[j] == 1 && rand() % 1000 < (3 * difficulty))
					{
						gameStart->chessHorseMoveProgress(chesses[i], j);
						continue;
					}

					//난이도 설정	//계속 움직이고 있을수록 어려움.
					if (rand() % 1000 < (100 * difficulty) && rand() % 1000 < 10)
					{
						gameStart->chessHorseMoveProgress(chesses[i],j);
					}
				}
			}
		}
	}
}

