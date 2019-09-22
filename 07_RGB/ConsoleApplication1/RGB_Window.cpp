#include<windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow) {
	WNDCLASSEX wndclass;
	TCHAR szAppName[] = TEXT("Color App");
	HWND hwnd;
	MSG msg;


	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.lpszClassName = szAppName;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hInstance = hInstance;
	wndclass.lpszMenuName = NULL;

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName, TEXT("RGB Window"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, HWND_DESKTOP, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return ((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	static int iFlagPoint = 0;
	RECT rc;
	HBRUSH hbr;
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMsg) {

	case WM_CHAR:
		switch(LOWORD(wParam)) {
		case 'R':
		case 'r':
			iFlagPoint = 1;
			InvalidateRect(hwnd,NULL, TRUE);
			break;

		case 'G':
		case 'g':
			iFlagPoint = 2;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'B':
		case 'b':
			iFlagPoint = 3;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'C':
		case 'c':
			iFlagPoint = 4;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'M':
		case 'm':
			iFlagPoint = 5;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'Y':
		case 'y':
			iFlagPoint = 6;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'W':
		case 'w':
			iFlagPoint = 7;
			InvalidateRect(hwnd, NULL, TRUE);
			break;

		case 'K':
		case 'k':
		default:
			iFlagPoint = 0;
			InvalidateRect(hwnd, NULL, TRUE);
			break;
		}
		break;


	case WM_PAINT:
		GetClientRect(hwnd, &rc);
		hdc = BeginPaint(hwnd, &ps);
		switch (iFlagPoint) {
		case 0:
			hbr = CreateSolidBrush(RGB(0, 0, 0));
			SelectObject(hdc,hbr);
			FillRect(hdc, &rc, hbr);
			break;

		case 1:
			hbr = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rc, hbr);
			break;

		case 2:
			hbr = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rc, hbr);
			break;

		case 3:
			hbr = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rc, hbr);
			break;

		case 4:
			hbr = CreateSolidBrush(RGB(0, 255,255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rc, hbr);
			break;

		case 5:
			hbr = CreateSolidBrush(RGB(255, 0,255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rc, hbr);
			break;

		case 6:
			hbr = CreateSolidBrush(RGB(255,255 ,0 ));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rc, hbr);
			break;

		case 7:
			hbr = CreateSolidBrush(RGB(255, 255, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rc, hbr);
			break;
		}
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}