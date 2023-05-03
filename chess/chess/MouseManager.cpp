#include "MouseManager.h"
#include "OverallVariables.h"

bool MouseManager::left = false;
bool MouseManager::right = false;
POINT MouseManager::mouse = { 0,0 };
POINT* const MouseManager::mousePointer = &mouse;

void MouseManager::progress()
{
	GetCursorPos(&mouse);
	ScreenToClient(OverallVariables::getHWnd(), &mouse);  // 이것이 OS 기준인 마우스포인트를 윈도우창 기준으로 바꿔준다
}

int MouseManager::getX()
{
	return mouse.x;
}

int MouseManager::getY()
{
	return mouse.y;
}
