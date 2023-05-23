#include "MainGame.h"
#include "BitMapManager.h"
#include "OverallVariables.h"
#include "MouseManager.h"

//Gitignore 이 잘 생성되었는지 확인해보는 주석

LRESULT CALLBACK wndProc(HWND, UINT, WPARAM, LPARAM);
const char* lpszClass = "GAME";

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmpParam, int nCmdShow)
{
	HWND hWnd; // 윈도우 창 그 자체인 객체
	MSG message;
	WNDCLASS wndClass; // 윈도우 창과 관련된 값을 설정하고 관장하는 객체이다

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

	//CreateWindow 함수를 통해서 윈도우 창을 운영체제에 등록하는 과정을 한다 

	ShowWindow(hWnd, nCmdShow); 
	// 창을 화면에 표시하는 함수 두번째 매개변수 값은 
	// SW_HIDE, 창을 기본 상태로 표시하는 SW_SHOWNORMAL, 창을 최대화하는 SW_MAXIMIZE 등 다양한 값을 가질 수 있다.
	// 즉 두번째 매개변수 값으로 창을 숨길수도 있고 나타낼 수도 있다
	/************************************************************************************/
	DWORD dwTime = GetTickCount(); // DWORD -> unsigned long 이다
	srand(time(NULL)); 
	OverallVariables::InitializeOverallVariables(hWnd, hInstance);// 반드시 MainGame 생성자 호출 이전에
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
	case WM_DESTROY:				// 이 case 부분만 기본적으로 있는 부분이고 나머지는 적은부분임
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


