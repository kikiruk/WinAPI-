#include "ChessHorse.h"
#include "OverallVariables.h"
#include "BitMapManager.h"

const PosXY ChessHorse::chessPos[64] = //체스판 한칸 가로세로 길이는 62 bit
{
	PosXY(240 ,80), PosXY(302 ,80), PosXY(364 ,80), PosXY(426 ,80), PosXY(488 ,80), PosXY(550 ,80), PosXY(612 ,80), PosXY(674 ,80),
	PosXY(240 ,142), PosXY(302 ,142), PosXY(364 ,142), PosXY(426 ,142), PosXY(488 ,142), PosXY(550 ,142), PosXY(612 ,142), PosXY(674 ,142),
	PosXY(240 ,204), PosXY(302 ,204), PosXY(364 ,204), PosXY(426 ,204), PosXY(488 ,204), PosXY(550 ,204), PosXY(612 ,204), PosXY(674 ,204),
	PosXY(240 ,266), PosXY(302 ,266), PosXY(364 ,266), PosXY(426 ,266), PosXY(488 ,266), PosXY(550 ,266), PosXY(612 ,266), PosXY(674 ,266),
	PosXY(240 ,328), PosXY(302 ,328), PosXY(364 ,328), PosXY(426 ,328), PosXY(488 ,328), PosXY(550 ,328), PosXY(612 ,328), PosXY(674 ,328),
	PosXY(240 ,390), PosXY(302 ,390), PosXY(364 ,390), PosXY(426 ,390), PosXY(488 ,390), PosXY(550 ,390), PosXY(612 ,390), PosXY(674 ,390),
	PosXY(240 ,452), PosXY(302 ,452), PosXY(364 ,452), PosXY(426 ,452), PosXY(488 ,452), PosXY(550 ,452), PosXY(612 ,452), PosXY(674 ,452),
	PosXY(240 ,514), PosXY(302 ,514), PosXY(364 ,514), PosXY(426 ,514), PosXY(488 ,514), PosXY(550 ,514), PosXY(612 ,514), PosXY(674 ,514)
};

const PosXY ChessHorse::dieChessPos_black[16] = //죽은 흑말 저장소의 좌표
{
	PosXY(116,80),PosXY(178,80),
	PosXY(116,142),PosXY(178,142),
	PosXY(116,204),PosXY(178,204),
	PosXY(116,266),PosXY(178,266),
	PosXY(116,328),PosXY(178,328),
	PosXY(116,390),PosXY(178,390),
	PosXY(116,452),PosXY(178,452),
	PosXY(116,514),PosXY(178,514)
};


const PosXY ChessHorse::dieChessPos_white[16] = //죽은 흰말 저장소의 좌표
{
	PosXY(737,80),PosXY(799,80),
	PosXY(737,142),PosXY(799,142),
	PosXY(737,204),PosXY(799,204),
	PosXY(737,266),PosXY(799,266),
	PosXY(737,328),PosXY(799,328),
	PosXY(737,390),PosXY(799,390),
	PosXY(737,452),PosXY(799,452),
	PosXY(737,514),PosXY(799,514)
};

void ChessHorse::progress()
{

	if (count == 0) //쿨타임을나타내는 카운트
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
	}
	else
	{
		count--;
	}

}

void ChessHorse::dieProgress()
{
	if (isMoveing) //움직일 경우에만
	{
		const PosXY* DieArrAdd = nullptr; //배열 주소로 배열을 저장

		if (isWhite)
		{
			DieArrAdd = dieChessPos_white;
		}
		else
		{
			DieArrAdd = dieChessPos_black;
		}

		int chessPos_toGo_X = DieArrAdd[toGo].X;
		int chessPos_toGo_Y = DieArrAdd[toGo].Y;
		if (X < chessPos_toGo_X)
		{
			X = X + 5;
		}

		if (X > chessPos_toGo_X)
		{
			X = X - 5;
		}

		if (Y < chessPos_toGo_Y)
		{
			Y = Y + 5;;
		}

		if (Y > chessPos_toGo_Y)
		{
			Y = Y - 5;;
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

}

void ChessHorse::renderCanGO(const ChessHorse* const chesses[])
{
	if (!isMoveing)
	{
		for (int i = 0; i < 64; i++)
		{
			if (calCulateCanGo(chesses, i))
			{
				if (check_arr[i] == 2)
				{
					TransparentBlt(memDC, chessPos[i].X, chessPos[i].Y, 62, 62, bitmpaDC_selected, 62, 0, 62, 62, RGB(255, 0, 255));
				}
				else
				{
					TransparentBlt(memDC, chessPos[i].X, chessPos[i].Y, 62, 62, bitmpaDC_selected, 124, 0, 62, 62, RGB(255, 0, 255));
				}
			}
		}
	}
}

void ChessHorse::setPosByIndex(int index)
{
	X = chessPos[index].X;
	Y = chessPos[index].Y;
}

ChessHorse::ChessHorse():
memDC(OverallVariables::getMemDC()),
bitmapDC(BitMapManager::getChessHorse_bitmapDC()),
bitmpaDC_selected(BitMapManager::getDisplay_bitmapDC()),
bitmpaDC_coolTime(BitMapManager::getCoolTime_bitmapDC()),
toGo(-1),
isMoveing(0),
isWhite(false),
die(false)
{
	X = 0;
	Y = 0;
	locationNow = 0;
	MovingSpeed = 1;
	count = 0;
	coolTime = 40;
	currentHorseNum = 1;
	enemyHorseNum = 2;
	isPawn = false;
}


ChessHorse::~ChessHorse()
{}

void ChessHorse::set_check_arr(const ChessHorse* const chesses[])
{
	for (int i = 0; i < 32; i++)
	{
		//흑말이 먹으로 가는도중인데 이미 먹은것처럼 판단되는거 방지
		if (chesses[i] != nullptr)
		{
			if (check_arr[chesses[i]->locationNow] != 2)
			{
				check_arr[chesses[i]->locationNow] = chesses[i]->currentHorseNum;
			}
		}
	}
}

void ChessHorse::set_check_arr_black(const ChessHorse* const chesses[])
{
	for (int i = 0; i < 32; i++)
	{
		if (chesses[i] != nullptr)
		{
			check_arr[chesses[i]->locationNow] = chesses[i]->currentHorseNum;
		}
	}
}

void ChessHorse::initialize_check_arr()
{
	for (int i = 0; i < 64; i++)
	{
		check_arr[i] = 0;
	}
}

void ChessHorse::initialize_coolTime()
{
	count = coolTime;
}

void ChessHorse::render_cool_time()
{
	if (count != 0)
	{
		int time = count / 70;
		TransparentBlt(memDC, chessPos[locationNow].X, chessPos[locationNow].Y, 62, 62, bitmpaDC_coolTime, (time * 62), 0, 62, 62, RGB(255, 0, 255));
	}
}
