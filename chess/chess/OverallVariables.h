#pragma once
#include "Include.h"
class OverallVariables
{
private:
	static HINSTANCE hInst; // private �ɹ��� �������� ���� �����ϰԲ� ������ // getter �θ� ���� �����ϰԲ� �س�����
	static HWND hWnd;
	static HDC hdc, memDC;
	static RECT crt;
	static HBITMAP myBitMap, oldBitMap;

public:
	static void InitializeOverallVariables(HWND _hWnd, HINSTANCE _hInst)
	{
		hWnd = _hWnd; // ������ â �� ��ü�� ��ü
		hInst = _hInst;
		hdc = GetDC(hWnd);

		//������۸� �����ϱ� ���� memDC, RECT�� ��������� GetClientRect
		memDC = CreateCompatibleDC(hdc);
		GetClientRect(hWnd, &crt);

		//������۸� �����ϱ� ���� ���(?)
		myBitMap = CreateCompatibleBitmap(hdc, crt.right, crt.bottom);
		oldBitMap = (HBITMAP)SelectObject(memDC, myBitMap);
	};

	static HWND getHWnd() { return hWnd; }; // getter �θ� ���� �����ϰԲ� �س�����
	static HINSTANCE getHInst() { return hInst; };
	static HDC getMemDC() { return memDC; };
	static RECT getCrt() { return crt; };
	static HDC getHdc() { return hdc; };
	static HBITMAP getMyBitMap() { return myBitMap; };
	static HBITMAP getOldBitMap() { return oldBitMap; };
};



