#pragma once
#include "Include.h"

typedef struct PosXY
{
	int X;
	int Y;
		
	PosXY(int _X, int _Y) :
		X(_X),
		Y(_Y)
	{};
};


class ChessHorse
{
public:
	static const PosXY chessPos[64];
	static const PosXY dieChessPos_black[16];
	static const PosXY dieChessPos_white[16];

protected:
	HDC memDC;
	HDC bitmapDC;
	HDC bitmpaDC_selected;
	HDC bitmpaDC_coolTime;

	friend class Bishop;
	friend class King;
	friend class Look;
	friend class Night;
	friend class Pawn;
	friend class Queen;
	friend class GameStart;
	friend class Computer;

protected:
	int X;
	int Y;
	int toGo;
	signed short locationNow;
	bool isMoveing;
	bool isWhite;
	bool die;
	short MovingSpeed;
	int count;
	int coolTime;
	short currentHorseNum;
	short enemyHorseNum;
	bool isPawn;
	
public:
	virtual void progress();
	virtual void dieProgress();
	virtual void render() = 0;
	virtual bool calCulateCanGo(const ChessHorse* const [],int index) = 0;
	void renderCanGO(const ChessHorse* const[]);

protected:
	void setPosByIndex(int index);

public:
	ChessHorse();	
	virtual ~ChessHorse();

protected:
	short check_arr[64] = { 0, };
	void set_check_arr(const ChessHorse* const []);
	void set_check_arr_black(const ChessHorse* const chesses[]);
	void initialize_check_arr();
	void initialize_coolTime();
	void render_cool_time();
};

