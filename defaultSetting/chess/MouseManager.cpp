#include "MouseManager.h"
#include "OverallVariables.h"

bool MouseManager::left = false;
bool MouseManager::right = false;
POINT MouseManager::mouse = { 0,0 };
POINT* const MouseManager::mousePointer = &mouse;

void MouseManager::progress()
{
	GetCursorPos(&mouse);
	ScreenToClient(OverallVariables::getHWnd(), &mouse);  // �̰��� OS ������ ���콺����Ʈ�� ������â �������� �ٲ��ش�
}

int MouseManager::getX()
{
	return mouse.x;
}

int MouseManager::getY()
{
	return mouse.y;
}
