//Headers
#include<Windows.h>

#define ID_MY_TIMER		101

//Global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine,
	int iCmdShow)
{
	//variable declarations
	WNDCLASSEX wndClass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("TimerClass");

	//code
	//initialization of WNDCLASSEX
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hInstance = hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.lpszClassName = szAppName;
	wndClass.lpszMenuName = NULL;
	wndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//Register Above class
	ATOM ob = RegisterClassEx(&wndClass);

	//create window in Memory
	hwnd = CreateWindow(szAppName,
		TEXT("Timer Color Change"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);

	UpdateWindow(hwnd);

	//Message LOOP
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hDc;
	PAINTSTRUCT ps;
	RECT rcRect;

	static RECT rcTempRect;

	static int iPaintIndex = 0;
	HBRUSH hBrush;

	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CREATE:
		SetTimer(hwnd, ID_MY_TIMER, 2000 , NULL);
		break;

	case WM_TIMER:
		KillTimer(hwnd, ID_MY_TIMER);

		iPaintIndex++;

		if (iPaintIndex > 7)
			iPaintIndex = 0;

		GetClientRect(hwnd, &rcRect);
		InvalidateRect(hwnd, &rcRect, TRUE);

		SetTimer(hwnd, ID_MY_TIMER, 2000, NULL);
		break;
	
	case WM_PAINT:

		hDc = BeginPaint(hwnd, &ps);

		GetClientRect(hwnd, &rcRect);

		rcTempRect.top = rcRect.top;
		rcTempRect.bottom = rcRect.bottom;

		if (iPaintIndex == 0)
		{
			rcTempRect.left = rcRect.left;
			rcTempRect.right = rcTempRect.left + (LONG)((rcRect.right - rcRect.left) / 8);
		}
		else
		{
			rcTempRect.left = rcTempRect.right;
			rcTempRect.right = rcTempRect.left + (LONG)((rcRect.right - rcRect.left) / 8);
		}


		switch (iPaintIndex)
		{
		case 1:
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hDc, hBrush);
			FillRect(hDc, &rcTempRect, hBrush);
			break;

		case 2:
			hBrush = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hDc, hBrush);
			FillRect(hDc, &rcTempRect, hBrush);
			break;

		case 3:
			hBrush = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hDc, hBrush);
			FillRect(hDc, &rcTempRect, hBrush);
			break;

		case 4:
			hBrush = CreateSolidBrush(RGB(0, 255, 255));
			SelectObject(hDc, hBrush);
			FillRect(hDc, &rcTempRect, hBrush);
			break;

		case 5:
			hBrush = CreateSolidBrush(RGB(255, 0, 255));
			SelectObject(hDc, hBrush);
			FillRect(hDc, &rcTempRect, hBrush);
			break;

		case 6:
			hBrush = CreateSolidBrush(RGB(255, 255, 0));
			SelectObject(hDc, hBrush);
			FillRect(hDc, &rcTempRect, hBrush);
			break;

		case 7:
			hBrush = CreateSolidBrush(RGB(255, 255, 255));
			SelectObject(hDc, hBrush);
			FillRect(hDc, &rcTempRect, hBrush);
			break;

		case 8:
			hBrush = CreateSolidBrush(RGB(0, 0, 0));
			SelectObject(hDc, hBrush);
			FillRect(hDc, &rcTempRect, hBrush);
			break;

		default:
			hBrush = CreateSolidBrush(RGB(0, 0, 0));
			SelectObject(hDc, hBrush);
			FillRect(hDc, &rcTempRect, hBrush);
			break;
		}

		EndPaint(hwnd, &ps);
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

