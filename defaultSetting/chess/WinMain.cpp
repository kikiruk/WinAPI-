#include "MainGame.h"
#include "BitMapManager.h"
#include "OverallVariables.h"
#include "MouseManager.h"

//Gitignore �� �� �����Ǿ����� Ȯ���غ��� �ּ�

LRESULT CALLBACK wndProc(HWND, UINT, WPARAM, LPARAM);
const char* lpszClass = "GAME";

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmpParam, int nCmdShow)
{
	HWND hWnd; // ������ â �� ��ü�� ��ü
	MSG message;
	WNDCLASS wndClass; // ������ â�� ���õ� ���� �����ϰ� �����ϴ� ��ü�̴�

	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = (WNDPROC)wndProc;
	wndClass.lpszClassName = lpszClass;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW || CS_VREDRAW;

	RegisterClass(&wndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		0, 0, BUFFER_WIDTH, BUFFER_HEIGHT,
		NULL, (HMENU)NULL, hInstance, NULL);

	//CreateWindow �Լ��� ���ؼ� ������ â�� �ü���� ����ϴ� ������ �Ѵ� 

	ShowWindow(hWnd, nCmdShow); 
	// â�� ȭ�鿡 ǥ���ϴ� �Լ� �ι�° �Ű����� ���� 
	// SW_HIDE, â�� �⺻ ���·� ǥ���ϴ� SW_SHOWNORMAL, â�� �ִ�ȭ�ϴ� SW_MAXIMIZE �� �پ��� ���� ���� �� �ִ�.
	// �� �ι�° �Ű����� ������ â�� ������� �ְ� ��Ÿ�� ���� �ִ�
	/************************************************************************************/
	DWORD dwTime = GetTickCount(); // DWORD -> unsigned long �̴�
	srand(time(NULL)); 
	OverallVariables::InitializeOverallVariables(hWnd, hInstance);// �ݵ�� MainGame ������ ȣ�� ������
	BitMapManager::initialize();

	MainGame game;


	while (true)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
			{
				PostQuitMessage(0);
				break;
			}
			else
			{
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
		}
		else
		{
			if (dwTime + 10 < GetTickCount())
			{
				MouseManager::progress();
				game.Progress();
				game.Render();
				dwTime = GetTickCount();
			}
		}
	}

	return message.wParam;
}

LRESULT CALLBACK wndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_DESTROY:				// �� case �κи� �⺻������ �ִ� �κ��̰� �������� �����κ���
		PostQuitMessage(0);
		break;

	case WM_LBUTTONDOWN:
		MouseManager::left = true;
		break;

	case WM_RBUTTONDOWN:
		MouseManager::right = true;
		break;

	case WM_LBUTTONUP:
		MouseManager::left = false;
		break;

	case WM_RBUTTONUP:
		MouseManager::right = false;
		break;
	default:
		break;
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}


