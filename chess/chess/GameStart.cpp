#include "GameStart.h"
#include "MouseManager.h"
#include "BitMapManager.h"
#include "StateManager.h"

/*************************화면에 수치표시용 (완성후삭제)*********************************/
#pragma warning(disable:4996)
#include <stdlib.h>
/*************************************************************************************/

inline int clickIndexNow()
{
		return ((MouseManager::getX() - 240) / 62 + (((MouseManager::getY() - 80) / 62) * 8));
}

void GameStart::progress()
{
	int MouseX = MouseManager::getX();
	int MouseY = MouseManager::getY();
	buttonProgress(MouseX,MouseY);

	if (!gameOver && !isStop && isBlackCrushWall == nullptr)
	{
		int _clickIndexNow = -1; //0으로 초기화하면 index 0 번을 가르키므로 위험함.

		if (MouseManager::right) //마우스 클릭 위치 index 가져오기
		{
			if (240 < MouseX && 737 > MouseX)
			{
				if (80 < MouseY && 577 > MouseY)
				{
					_clickIndexNow = clickIndexNow();
				}
			}
		}

		set_check_arr();//check_arr 생성

		// 빈공간인지 아닌지 판별,클릭한 index에 맞게 말을 선택해줌
		selectHorse(MouseX, MouseY);

		bool isNotWhiteCheckmate = true; // chackMate 검사용
		bool isNotBlackCheckmate = true; // chackMate 검사용

		// 어떤 말이 다른 말을 잡아먹었는 경우가 있는지 검사
		for (short i = 0; i < 32; i++)
		{
			if (AttackHorsess[i] != nullptr)
			{
				if (AttackHorsess[i]->toGo == -1)
				{
					if (check_arr[AttackHorsess[i]->locationNow] != 0)
					{
						for (short j = 0; j < 32; j++)
						{
							if (chesses[j] != nullptr)
							{
								if (chesses[j]->locationNow == AttackHorsess[i]->locationNow //공격중인 말이 목적지에 도착하였고
									&& !(chesses[j]->isWhite) == AttackHorsess[i]->isWhite //공격중인 말과 목적지에 있던 말의 색깔이 다르고,
									&& !(chesses[j]->isMoveing))							//공격하는 말이 움직이는 중이 아닐경우에
								{															//죽었음을 표시한다
									chesses[j]->die = true;

									//selected_horse 가 죽었는데도 renderCanGo 가 표시되는것 방지
									if (chesses[j] == selected_horse)
									{
										selected_horse = nullptr;
									}
								}
							}
						}
					}
					AttackHorsess[i]->initialize_coolTime(); // 말이 목적지에 도착함을 기준으로쿨타임 초기화.
					AttackHorsess[i] = nullptr; //목적지에 말이 도착을 하면 공격중인 말목록에서 제외
				}
			}

			//for문을 한번더 사용하지 않게 하기위해서 어떤 말이 다른 말을 잡아먹었는 경우가 있는지 검사하는 for문안에서 생성했음
			//checkMate인지 검사함.
			if (chesses[i] != nullptr && i != 4 && i != 28 &&!(chesses[i]->isMoveing))
			{			
				if (i < 16)
				{
					/****************병사 끝에 도달했을때 체크****************/

					if (7 < i) //병사말에한하여서 체크함.끝에 도달하였을경우에 룩,비숍,퀸
					{
						if ( chesses[i]->isPawn && !(chesses[i]->isMoveing) && chesses[i]->locationNow > 55)
						{
							short j = ((rand() % 3) * 8);
							for (short k = 0; k < 8; k++)
							{
								if (toChangeHorse[k + j] != nullptr)
								{
									toChangeHorse[k + j]->locationNow = chesses[i]->locationNow;
									toChangeHorse[k + j]->setPosByIndex(chesses[i]->locationNow);
									toChangeHorse[k + j]->coolTime = 120;
									delete chesses[i];
									chesses[i] = toChangeHorse[k + j];
									toChangeHorse[k + j] = nullptr;
									break;
								}
							}
						}
					}
					/*****************************************************/

					if (chesses[i]->calCulateCanGo(chesses,chesses[28]->locationNow) && !(chesses[28]->isMoveing))
					{
						isWhiteCheckMate = true;
						isNotWhiteCheckmate = false;
					}
				}
				else
				{
					if (i < 25)
					{
						if (chesses[i]->isPawn && chesses[i]->locationNow < 8 && !(chesses[i]->isMoveing))
						{
							isBlackCrushWall = &chesses[i];
						}
					}

					if (chesses[i]->calCulateCanGo(chesses,chesses[4]->locationNow) && !(chesses[4]->isMoveing))
					{
						isBlackCHeckMate = true;
						isNotBlackCheckmate = false;
					}
				}
			}
		}

		if (isNotBlackCheckmate) //체크메이트 render를 멈추게 하는 부분
		{
			BlackCheckMateCount = 0;
			isBlackCHeckMate = false;
		}
		if (isNotWhiteCheckmate)
		{
			WhiteCheckMateCount = 0;
			isWhiteCheckMate = false;
		}

		// 현재 선택(클릭)된 말이갈수있는곳을 클릭한 경우에 그곳으로 움직이게하는 기능및 AttackHorsess 등록기능
		chessHorseMoveProgress(selected_horse, _clickIndexNow);

		computer->progress(chesses, this);

		for (int i = 0; i < 32; i++)
		{
			if (chesses[i] != nullptr)
			{
				chesses[i]->progress();

				if (chesses[i]->die)
				{
					// 체스말이 죽었다는 싸인인 경우에 처리함 (죽은말들 넣어두는 배열로 넘김)
					chessHorseDieProgress(chesses[i]);
					chesses[i] = nullptr;
				}
			}
		}

		for (int i = 0; i < 16; i++) //죽은 말들움직임 관리
		{
			if (DieWhiteHorsess[i] != nullptr)
			{
				if (DieWhiteHorsess[i]->isMoveing)
				{
					DieWhiteHorsess[i]->dieProgress();
				}
			}

			if (DieBlackHorsess[i] != nullptr)
			{
				if (DieBlackHorsess[i]->isMoveing)
				{
					DieBlackHorsess[i]->dieProgress();
				}
			}
		}

		checkGameOver();

		initialize_check_arr();//check_arr 초기화
	}
	else if(isBlackCrushWall != nullptr && !gameOver)
	{
		progressChangeHorse(isBlackCrushWall);
	}
}

void GameStart::render()
{
	renderMap();
	buttonRender(MouseManager::getX(),MouseManager::getY());

	if(isWhiteCheckMate)
		renderCheckMate(true);

	if(isBlackCHeckMate)
		renderCheckMate(false);

	/*************************화면에 수치표시용 (완성후삭제)*********************************/
	char buf[256];
	strcpy(buf, "X : ");
	int len = 4;
	len += sprintf(buf + len, "%d ", MouseManager::getX());
	puts(buf);
	TextOut(memDC, 0, 0, TEXT(buf), strlen(buf));

	char buf_2[256];
	strcpy(buf_2, "Y : ");
	int len_2 = 4;
	len_2 += sprintf(buf_2 + len_2, "%d ", MouseManager::getY());
	puts(buf_2);
	TextOut(memDC, 0, 20, TEXT(buf_2), strlen(buf_2));

	char buf_3[256];
	strcpy(buf_3, "test_click : ");
	int len_3 = 13;
	len_3 += sprintf(buf_3 + len_3, "%d ", test_click);
	puts(buf_3);

	TextOut(memDC, 0, 40, TEXT(buf_3), strlen(buf_3));


	//test_click
	/***************************************************************************************/
	if (isBlackCrushWall != nullptr && !gameOver)
	{
		renderChangeHorse(MouseManager::getX(), MouseManager::getY());
	}

	if(gameOver)
		gameOverRender();

}

void GameStart::initialize()
{
	release();

	for (short i = 0; i < 32; i++)
	{
		AttackHorsess[i] = nullptr;
	}

	for (short i = 0; i < 16; i++)
	{
		DieWhiteHorsess[i] = nullptr;
	}

	for (short i = 0; i < 16; i++)
	{
		DieBlackHorsess[i] = nullptr;
	}

	chesses[0] = new Look(0,true);chesses[1] = new Night(1,true);chesses[2] = new Bishop(2,true);chesses[3] = new Queen(3,true);
	chesses[4] = new King(4, true); chesses[5] = new Bishop(5, true); chesses[6] = new Night(6, true); chesses[7] = new Look(7, true);
	chesses[8] = new Pawn(8, true); chesses[9] = new Pawn(9, true); chesses[10] = new Pawn(10, true); chesses[11] = new Pawn(11, true);
	chesses[12] = new Pawn(12, true); chesses[13] = new Pawn(13, true); chesses[14] = new Pawn(14, true); chesses[15] = new Pawn(15, true);
	chesses[16] = new Pawn(48); chesses[17] = new Pawn(49); chesses[18] = new Pawn(50); chesses[19] = new Pawn(51); chesses[20] = new Pawn(52);
	chesses[21] = new Pawn(53); chesses[22] = new Pawn(54); chesses[23] = new Pawn(55), chesses[24] = new Look(56); chesses[25] = new Night(57);
	chesses[26] = new Bishop(58); chesses[27] = new Queen(59); chesses[28] = new King(60); chesses[29] = new Bishop(61); chesses[30] = new Night(62);
	chesses[31] = new Look(63);

	toChangeHorse[0] = new Queen(0,true);toChangeHorse[1] = new Queen(0,true);toChangeHorse[2] = new Queen(0,true);
	toChangeHorse[3] = new Queen(0,true);toChangeHorse[4] = new Queen(0,true);toChangeHorse[5] = new Queen(0,true);
	toChangeHorse[6] = new Queen(0,true);toChangeHorse[7] = new Queen(0,true);toChangeHorse[8] = new Look(0,true);
	toChangeHorse[9] = new Look(0,true);toChangeHorse[10] = new Look(0,true);toChangeHorse[11] = new Look(0,true);
	toChangeHorse[12] = new Look(0,true);toChangeHorse[13] = new Look(0,true);toChangeHorse[14] = new Look(0,true);
	toChangeHorse[15] = new Look(0,true);toChangeHorse[16] = new Bishop(0,true);toChangeHorse[17] = new Bishop(0,true);
	toChangeHorse[18] = new Bishop(0,true);toChangeHorse[19] = new Bishop(0,true);toChangeHorse[20] = new Bishop(0,true);
	toChangeHorse[21] = new Bishop(0,true);toChangeHorse[22] = new Bishop(0,true);toChangeHorse[23] = new Bishop(0,true);
	toChangeHorse[24] = new Queen(0);toChangeHorse[25] = new Queen(0);toChangeHorse[26] = new Queen(0);toChangeHorse[27] = new Queen(0);
	toChangeHorse[28] = new Queen(0);toChangeHorse[29] = new Queen(0);toChangeHorse[30] = new Queen(0);toChangeHorse[31] = new Queen(0);
	toChangeHorse[32] = new Look(0);toChangeHorse[33] = new Look(0);toChangeHorse[34] = new Look(0);toChangeHorse[35] = new Look(0);
	toChangeHorse[36] = new Look(0);toChangeHorse[37] = new Look(0);toChangeHorse[38] = new Look(0);toChangeHorse[39] = new Look(0);
	toChangeHorse[40] = new Bishop(0);toChangeHorse[41] = new Bishop(0);toChangeHorse[42] = new Bishop(0);toChangeHorse[43] = new Bishop(0);
	toChangeHorse[44] = new Bishop(0); toChangeHorse[45] = new Bishop(0); toChangeHorse[46] = new Bishop(0); toChangeHorse[47] = new Bishop(0);

	gameOver = false;
	selected_horse = nullptr;
	isStop = false;
	GameOverCount = 0;
	bottonCount = 0;
	isBlackCrushWall = nullptr;
}

inline void GameStart::release()
{
	for (int i = 0; i < 16; i++)
	{
		if (DieWhiteHorsess[i] != nullptr)
		{
			delete DieWhiteHorsess[i];
		}

		if (DieBlackHorsess[i] != nullptr)
		{
			delete DieBlackHorsess[i];
		}
	}

	for (int i = 0; i < 32; i++)
	{
		if (chesses[i] != nullptr)
		{
			delete chesses[i];
		}
	}

	for (int i = 0; i < 48; i++)
	{
		if (toChangeHorse[i] != nullptr)
		{
			delete toChangeHorse[i];
		}
	}
}

inline void GameStart::selectHorse(int MouseX,int MouseY)
{
	int _clickIndexNow = 0;
	if (MouseManager::left)
	{
		if (240 < MouseX && 737 > MouseX)
		{
			if (80 < MouseY && 577 > MouseY)
			{
				_clickIndexNow = clickIndexNow();

				for (int i = 16; i < 32; i++) //클릭에 의한 선택은 검은말만 할 수 있게끔 하는 코드
				{
					if (chesses[i] != nullptr && chesses[i]->locationNow == _clickIndexNow)
					{
						selected_horse = chesses[i];
						return;
					}
				}
				selected_horse = nullptr;
			}
		}
	}
}

void GameStart::renderMap()
{
	//체스판 그리기
	TransparentBlt(memDC, 240, 80, 497, 497, bitmapDC, 0, 0, 800, 800, RGB(255, 0, 255));

	//왼쪽 죽은말 보관소 그리기
	TransparentBlt(memDC, 116, 80, 124, 496, bitmapDC_killed, 0, 0, 124, 496, RGB(255, 0, 255));

	//오른쪽 죽은말 보관소 그리기
	TransparentBlt(memDC, 737, 80, 124, 496, bitmapDC_killed, 0, 0, 124, 496, RGB(255, 0, 255));

	//선택된 칸 파란색으로 표시
	if (selected_horse != nullptr)
	{
		TransparentBlt(memDC, selected_horse->X, selected_horse->Y, 62, 62, bitmpaDC_selected, 0, 0, 62, 62, RGB(255, 0, 255));
		selected_horse->renderCanGO(chesses);
	}
	
	//체스말 그리기
	for (int i = 0; i < 32; i++)
	{
		if (chesses[i] != nullptr)
		{
			chesses[i]->render();

			if (chesses[i]->count != 0) //쓸데없는 함수호출을 줄이기 위한 조건
			{
				chesses[i]->render_cool_time();
			}
		}
	}

	for (int i = 0; i < 16; i++) //죽은 말들움직임 관리
	{
		if (DieWhiteHorsess[i] != nullptr)
		{
			DieWhiteHorsess[i]->render();
		}

		if (DieBlackHorsess[i] != nullptr)
		{
			DieBlackHorsess[i]->render();
		}
	}
}

inline void GameStart::chessHorseMoveProgress(ChessHorse* chesseHorse,int _clickIndexNow)
{
		// 현재 선택(클릭)된 말이갈수있는곳을 클릭한 경우에 그곳으로 움직이게하는 기능및 AttackHorsess 등록기능
	if (chesseHorse != nullptr && !(chesseHorse->isMoveing) && chesseHorse->count == 0) 
	{

		//_clickIndexNow > -1 && _clickIndexNow < 65 이걸안넣으면 Queen 에서 0번째 칸으로 가면 calCulateCanGo에 -1 이 들어가서 에러남
		// calCulateCanGo 에 0 이하나 64 이상의 숫자가 들어가게 해선 안됌.
		if (_clickIndexNow > -1 && _clickIndexNow < 65 && chesseHorse->calCulateCanGo(chesses, _clickIndexNow))
		{
			chesseHorse->toGo = _clickIndexNow;			//클릭한 위치로 체스말의 목표 위치 설정
			chesseHorse->locationNow = _clickIndexNow;	//현재 위치를 클릭한 위치로 즉시 바꿔줌.(그래야지 체스말이 곂치는 경우가 없음.)
			chesseHorse->isMoveing = true;				//현재 말의 상태를 이동중으로 표시

			for (short i = 0; i < 32; i++)					//현재공격하고 있는 말들을 저장해놓는 배열에 현재 말을 등록 (AttackHorsess 등록)
			{
				if (AttackHorsess[i] == nullptr || AttackHorsess[i] == chesseHorse)
				{
					AttackHorsess[i] = chesseHorse;
					break;
				}
			}
		}

	}

}

inline void GameStart::chessHorseDieProgress(ChessHorse* chessHorse)
{
	ChessHorse** DieHorsessArrAddress = nullptr;
	
	if (chessHorse->isWhite)
	{
		DieHorsessArrAddress = DieWhiteHorsess;
	}
	else
	{
		DieHorsessArrAddress = DieBlackHorsess;
	}
	
	for (short i = 0; i < 16; i++)
	{
		if (*DieHorsessArrAddress == nullptr)
		{
			chessHorse->toGo = i;
			chessHorse->isMoveing = true;
			*DieHorsessArrAddress = chessHorse;
			break;
		}

		DieHorsessArrAddress++;//배열안의 주소를이용하여 index 이동
	}
}

void GameStart::renderCheckMate(bool isWhite)
{
	if (isWhite)
	{
		WhiteCheckMateCount++;

		if (WhiteCheckMateCount < 300)//TransparentBlt 의 쓸데없는 호출을 줄이기위한 render 시간제한
		{
			TransparentBlt(memDC, -700 + (WhiteCheckMateCount * 10), 0, 1000, 700, CheckMate_white_bitmapDC, 0, 0, 1000, 700, RGB(255, 0, 255));
		}

	}
	else
	{
		BlackCheckMateCount++;
		if (BlackCheckMateCount < 300) //TransparentBlt 의 쓸데없는 호출을 줄이기위한 render 시간제한
		{
			TransparentBlt(memDC, 700 - (BlackCheckMateCount * 10), 0, 1000, 700, CheckMate_black_bitmapDC, 0, 0, 1000, 700, RGB(255, 0, 255));
		}

	}

}

void GameStart::renderChangeHorse(int MouseX,int MouseY)
{
	Rectangle(memDC, 282, 223, 701, 473);
		
	if (MouseX > 307 && 407 > MouseX
		&& MouseY > 358 && 458 > MouseY)
	{
		TransparentBlt(memDC, 307, 358, 100, 100, bitmpaDC_selected, 0, 0, 62, 62, RGB(255, 0, 255));
	}
	else if (MouseX > 441 && 542 > MouseX
		&& MouseY > 358 && 458 > MouseY)
	{
		TransparentBlt(memDC, 441, 358, 100, 100, bitmpaDC_selected, 0, 0, 62, 62, RGB(255, 0, 255));
	}
	else if (MouseX > 576 && 676 > MouseX
		&& MouseY > 358 && 458 > MouseY)
	{
		TransparentBlt(memDC, 576, 358, 100, 100, bitmpaDC_selected, 0, 0, 62, 62, RGB(255, 0, 255));
	}

	//룩
	TransparentBlt(memDC, 307, 358, 160, 160, ChessHorse_bitmapDC, 128, 0, 128, 128, RGB(255, 0, 255));

	//퀸
	TransparentBlt(memDC, 441, 358, 160, 160, ChessHorse_bitmapDC, 384, 0, 128, 128, RGB(255, 0, 255));

	//비숍
	TransparentBlt(memDC, 576, 358, 160, 160, ChessHorse_bitmapDC, 256, 0, 128, 128, RGB(255, 0, 255));
}

void GameStart::progressChangeHorse(ChessHorse** pawn)
{
	if (MouseManager::left)
	{
		int MouseX = MouseManager::getX();
		int MouseY = MouseManager::getY();

		short j = 0;
		bool check = false;

		if (MouseX > 307 && 407 > MouseX
			&& MouseY > 358 && 458 > MouseY)
		{
			j = (2 * 8) + 24;
			check = true;
		}
		else if (MouseX > 441 && 542 > MouseX
			&& MouseY > 358 && 458 > MouseY)
		{
			j = (0 * 8) + 24;
			check = true;
		}
		else if (MouseX > 576 && 676 > MouseX
			&& MouseY > 358 && 458 > MouseY)
		{
			j = (1 * 8) + 24;
			check = true;
		}

		if (check)
		{
			for (short k = 0; k < 8; k++)
			{
				if (toChangeHorse[k + j] != nullptr)
				{
					//ChessHorse* tmp = pawn;
					toChangeHorse[k + j]->locationNow = (*pawn)->locationNow;
					toChangeHorse[k + j]->setPosByIndex((*pawn)->locationNow);
					toChangeHorse[k + j]->coolTime = 120;
					//pawn = nullptr;
					//delete *tmp;
					*pawn = toChangeHorse[k + j];
					toChangeHorse[k + j] = nullptr;
					isBlackCrushWall = nullptr;
					break;
				}
			}
		}
	}
}

inline void GameStart::buttonRender(int MouseX,int MouseY)
{
	//stopPlayButton
	if (MouseX > StopPlayButton.left && StopPlayButton.right > MouseX 
		&& MouseY > StopPlayButton.top && StopPlayButton.bottom > MouseY)
	{
		if (!isStop)
			TransparentBlt(memDC, 385, 606, 30, 30, Buttons_bitmapDC, 100, 0, 30, 30, RGB(255, 0, 255));
		else
			TransparentBlt(memDC, 385, 606, 30, 30, Buttons_bitmapDC, 130, 0, 30, 30, RGB(255, 0, 255));
	}
	else
	{
		if (!isStop)
			TransparentBlt(memDC, 385, 606, 30, 30, Buttons_bitmapDC, 0, 0, 30, 30, RGB(255, 0, 255));
		else
			TransparentBlt(memDC, 385, 606, 30, 30, Buttons_bitmapDC, 30, 0, 30, 30, RGB(255, 0, 255));
	}

	//RestartButton
	if (MouseX > RestartButton.left && RestartButton.right > MouseX
		&& MouseY > RestartButton.top && RestartButton.bottom > MouseY)
	{
		TransparentBlt(memDC, 558, 606, 30, 30, Buttons_bitmapDC, 160, 0, 30, 30, RGB(255, 0, 255));
	}
	else
	{
		TransparentBlt(memDC, 558, 606, 30, 30, Buttons_bitmapDC, 60, 0, 30, 30, RGB(255, 0, 255));
	}

	//GotoMainButton
	if (MouseX > GotoMainButton.left && GotoMainButton.right > MouseX
		&& MouseY > GotoMainButton.top && GotoMainButton.bottom > MouseY)
	{
		TransparentBlt(memDC, 867, 577, 100, 70, Buttons_bitmapDC, 100, 30, 100, 70, RGB(255, 0, 255));
	}
	else
	{
		TransparentBlt(memDC, 867, 577, 100, 70, Buttons_bitmapDC, 0, 30, 100, 70, RGB(255, 0, 255));
	}
}

inline void GameStart::buttonProgress(int MouseX, int MouseY)
{
	if (bottonCount > 0)
	{
		bottonCount--;
	}
	if (MouseManager::left)
	{
		if (bottonCount <= 0 
			&& MouseX > StopPlayButton.left && StopPlayButton.right > MouseX
			&& MouseY > StopPlayButton.top && StopPlayButton.bottom > MouseY)
		{
			isStop = !isStop;
			bottonCount = 50;
		}

		if (MouseX > RestartButton.left && RestartButton.right > MouseX
			&& MouseY > RestartButton.top && RestartButton.bottom > MouseY)
		{
			StateManager::getBeforGameStartState()->initialize();
			StateManager::setStateNow(BEFOR_GAME_START);
		}

		//GotoMainButton
		if (MouseX > GotoMainButton.left && GotoMainButton.right > MouseX
			&& MouseY > GotoMainButton.top && GotoMainButton.bottom > MouseY)
		{
			StateManager::setStateNow(MAIN);
		}

		if (gameOver && GameOverCount > 300)
		{
			if (MouseX > ClearButton.left && ClearButton.right > MouseX
				&& MouseY > ClearButton.top && ClearButton.bottom > MouseY)
			{
				StateManager::setStateNow(REGISTER);
			}
		}
	}
}

inline void GameStart::checkGameOver()
{
	if (chesses[4] == nullptr || chesses[28] == nullptr)
	{
		gameOver = true;
	}
}

inline void GameStart::gameOverRender()
{
	GameOverCount++;

	if (chesses[4] == nullptr)
	{
		int Y = 700 - (GameOverCount * 5);
		TransparentBlt(memDC, 0, (Y > 0) ? Y : 0, 1000, 700, Logo_clear_bitmapDC, 0, 0, 1000, 700, RGB(255, 0, 255));

		if(Y < 0)
			Rectangle(memDC, ClearButton.left, ClearButton.top, ClearButton.right, ClearButton.bottom);
	}
	else if(chesses[28] == nullptr)
	{
		int X1 = -1000 + (GameOverCount * 5);
		TransparentBlt(memDC, (X1 < 0) ? X1 : 0, 0, 1000, 700, Logo_you_bitmapDC, 0, 0, 1000, 700, RGB(255, 0, 255));
		int X2 = 1000 - (GameOverCount * 5);
		TransparentBlt(memDC, (X2 > 0) ? X2 : 0, 0, 1000, 700, Logo_loose_bitmapDC, 0, 0, 1000, 700, RGB(255, 0, 255));
	}
}

void GameStart::set_check_arr()
{
	for (int i = 0; i < 32; i++)
	{
		if (chesses[i] != nullptr)
		{
			check_arr[chesses[i]->locationNow] = chesses[i]->currentHorseNum;
		}
	}
}

void GameStart::initialize_check_arr()
{
	for (int i = 0; i < 64; i++)
	{
		check_arr[i] = 0;
	}
}

GameStart::GameStart(Computer* computer)
{
	this->computer = computer;
	bitmapDC = BitMapManager::getGameStart_bitmapDC();
	ChessHorse_bitmapDC = BitMapManager::getChessHorse_bitmapDC();
	bitmpaDC_selected = BitMapManager::getDisplay_bitmapDC();
	bitmapDC_killed = BitMapManager::getKilled_bitmapDC();
	Logo_clear_bitmapDC = BitMapManager::getLogo_clear_bitmapDC();
	Logo_you_bitmapDC = BitMapManager::getLogo_you_bitmapDC();
	Logo_loose_bitmapDC = BitMapManager::getLogo_loose_bitmapDC();
	Buttons_bitmapDC = BitMapManager::getButtons_bitmapDC();
	CheckMate_black_bitmapDC = BitMapManager::getCheckMate_black_bitmapDC();
	CheckMate_white_bitmapDC = BitMapManager::getCheckMate_white_bitmapDC();

	StopPlayButton = { 385,606,415,635 }; //가로세로 30
	RestartButton = { 558,606,588,636 }; //가로세로 30
	GotoMainButton = { 867,577,967,647 }; //가로 100 세로 70
	ClearButton = { 407, 403, 607, 453 };
	gameOver = false;
	selected_horse = nullptr;
	isStop = false;

	isWhiteCheckMate = false;
	isBlackCHeckMate = false;
	isBlackCrushWall = nullptr;
	WhiteCheckMateCount = 0;
	BlackCheckMateCount = 0;

	GameOverCount = 0;
	bottonCount = 0;
	test_click = false; //지우기
}

GameStart::~GameStart()
{
	release();
}
