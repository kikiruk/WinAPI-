#pragma once
#include "State.h"
#include "ChessHorse.h"
#include "Computer.h"
#include "King.h"
#include "Bishop.h"
#include "Look.h"
#include "Pawn.h"
#include "Night.h"
#include "Queen.h"

class GameStart : public State
{
	friend class Computer;
	friend class BeforGameStart;

private:
	HDC bitmapDC;
	HDC ChessHorse_bitmapDC;
	HDC bitmpaDC_selected;
	HDC bitmapDC_killed;
	HDC	Logo_clear_bitmapDC;
	HDC	Logo_you_bitmapDC;
	HDC	Logo_loose_bitmapDC;
	HDC	Buttons_bitmapDC;
	HDC	CheckMate_black_bitmapDC;
	HDC	CheckMate_white_bitmapDC;
	HDC	GameStart_background_bitmapDC;

	RECT StopPlayButton;
	RECT RestartButton;
	RECT GotoMainButton;

	ChessHorse* selected_horse;

	ChessHorse* chesses[32] = { nullptr, };
	ChessHorse* toChangeHorse[48] = { nullptr, };
	ChessHorse* AttackHorsess[32] = { nullptr, }; //�����̰� �ִ� ü������ ��� �ִ� . 
	ChessHorse* DieWhiteHorsess[16] = { nullptr, };
	ChessHorse* DieBlackHorsess[16] = { nullptr, };

	Computer* computer;

private:
	bool gameOver;
	int GameOverCount;
	inline void checkGameOver();
	inline void gameOverRender();

//��ư���� �����
private:
	bool isStop; //������ �����ִ��� ���� ��Ÿ��
	int bottonCount;
	ChessHorse** isBlackCrushWall; 
	bool test_click; //�׽�Ʈ��,���߿������

public:
	virtual void progress();
	virtual void render();
	void initialize();
	inline void release();

private:
	inline void selectHorse(int MouseX, int MouseY);
	inline void renderMap();
	inline void chessHorseMoveProgress(ChessHorse* chesseHorse, int _clickIndexNow);
	inline void chessHorseDieProgress(ChessHorse* chessHorse);

private:
	bool isWhiteCheckMate; 
	bool isBlackCHeckMate;
	int WhiteCheckMateCount; // checkMate ǥ�ø� ȭ�鿡 ��ﶧ �� �۾��� �ִϸ��̼��� ���� ���� ���̴� ����
	int BlackCheckMateCount;
	void renderCheckMate(bool isWhite);
	void renderChangeHorse(int MouseX, int MouseY);
	void progressChangeHorse(ChessHorse** pawn);

private:
	inline void buttonRender(int MouseX, int MouseY);
	inline void buttonProgress(int MouseX, int MouseY);

private:
	short check_arr[64] = { 0, };
	void set_check_arr();
	void initialize_check_arr();

public:
	GameStart(Computer* computer);
	~GameStart();
};

