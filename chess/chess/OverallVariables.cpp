#include "OverallVariables.h"

HINSTANCE OverallVariables::hInst = nullptr;
HWND OverallVariables::hWnd = nullptr;
HDC OverallVariables::hdc = nullptr;
HDC OverallVariables::memDC = nullptr;
RECT OverallVariables::crt = { 0,0,0,0 };
HBITMAP OverallVariables::myBitMap = nullptr;
HBITMAP OverallVariables::oldBitMap = nullptr;
