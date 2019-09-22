//Headers
#include<Windows.h>

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
	TCHAR szAppName[] = TEXT("MyApp");

	MessageBox(NULL, TEXT("Starting Application"), TEXT("Message"), MB_OK | MB_ICONINFORMATION);

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
		TEXT("MyApplication"),
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
	TCHAR chString[255];
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CREATE:
		wsprintf(chString, TEXT("WM_CREATE message is arrived. \n This WM_CREATE comes first and only once"));
		MessageBox(hwnd, chString, TEXT("Message"), MB_OK | MB_ICONINFORMATION);
		break;

	case WM_KEYDOWN:
		wsprintf(chString, TEXT("WM_KEYDOWN message is arrived."));
		MessageBox(hwnd, chString, TEXT("Message"), MB_OK | MB_ICONINFORMATION);
		break;

	case WM_LBUTTONDOWN:
		wsprintf(chString, TEXT("WM_LBUTTONDOWN message is arrived."));
		MessageBox(hwnd, chString, TEXT("Message"), MB_OK | MB_ICONINFORMATION);
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
