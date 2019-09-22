#include"MySplashScreen.h"

#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow) {
	WNDCLASSEX wndclass;
	TCHAR szAppName[] = TEXT("MySplashScreen");
	HWND hwnd;
	MSG msg;

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szAppName;
	wndclass.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(MYICON));
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hInstance = hInstance;
	wndclass.lpszMenuName = NULL;

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName, TEXT("Icon App"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, HWND_DESKTOP, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return ((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	static HBITMAP hbt;
	RECT rc;
	PAINTSTRUCT ps;
	HDC hdc1;
	HDC hdc2;
	HANDLE h1;
	BITMAP bmt;

	switch (iMsg) {
	case WM_CREATE:
		
		hbt = LoadBitmap(GetModuleHandle(NULL),MAKEINTRESOURCE(MYBITMAP));
		break;

	case WM_PAINT:
		GetClientRect(hwnd,&rc);
		hdc1 = BeginPaint(hwnd, &ps);
		hdc2 = CreateCompatibleDC(NULL);
		h1 = SelectObject(hdc2, hbt);
		GetObject(hbt, sizeof(BITMAP), &bmt);
		StretchBlt(hdc1, rc.left, rc.top, rc.right-rc.left, rc.bottom-rc.top, hdc2, 0, 0, bmt.bmWidth, bmt.bmHeight, SRCCOPY);
		DeleteObject(hdc2);
		EndPaint(hwnd,&ps); 
		break;
		

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hwnd, iMsg, wParam, lParam));


}