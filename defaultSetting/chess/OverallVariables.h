#pragma once
#include "Include.h"
class OverallVariables
{
private:
	static HINSTANCE hInst; // private 맴버로 전역에서 접근 가능하게끔 디자인 // getter 로만 접근 가능하게끔 해놓았음
	static HWND hWnd;
	static HDC hdc, memDC;
	static RECT crt;
	static HBITMAP myBitMap, oldBitMap;

public:
	static void InitializeOverallVariables(HWND _hWnd, HINSTANCE _hInst)
	{
		hWnd = _hWnd; // 윈도우 창 그 자체인 객체
		hInst = _hInst;
		hdc = GetDC(hWnd);

		//더블버퍼를 구현하기 위한 memDC, RECT를 만들기위한 GetClientRect
		memDC = CreateCompatibleDC(hdc);
		GetClientRect(hWnd, &crt);

		//더블버퍼를 구현하기 위한 요소(?)
		myBitMap = CreateCompatibleBitmap(hdc, crt.right, crt.bottom);
		oldBitMap = (HBITMAP)SelectObject(memDC, myBitMap);
	};

	static HWND getHWnd() { return hWnd; }; // getter 로만 접근 가능하게끔 해놓았음
	static HINSTANCE getHInst() { return hInst; };
	static HDC getMemDC() { return memDC; };
	static RECT getCrt() { return crt; };
	static HDC getHdc() { return hdc; };
	static HBITMAP getMyBitMap() { return myBitMap; };
	static HBITMAP getOldBitMap() { return oldBitMap; };
};



