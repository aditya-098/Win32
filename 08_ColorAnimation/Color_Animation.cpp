#include<windows.h>
#include<stdio.h>

#define MYTIMER 100

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpszCmdLine,int iCmdShow) {
	WNDCLASSEX wndclass;
	MSG msg;
	HWND hwnd;
	TCHAR szAppName[] = TEXT("Color_Animation");

	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbWndExtra = 0;
	wndclass.cbClsExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hInstance = hInstance;
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName,
		TEXT("Color_Animation"),
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

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;
	RECT rctmp;
	static int iPointFlag = 0;
	HBRUSH hbr;

	static FILE *fp;

	switch (iMsg) {

	case WM_CREATE:
		SetTimer(hwnd, MYTIMER, 2000, NULL);
		break;

	case WM_TIMER:
		KillTimer(hwnd, MYTIMER);
		
		fopen_s(&fp,"MyFile.txt", "a");

		iPointFlag++;
		if (iPointFlag > 8) {
			iPointFlag = 1;
			InvalidateRect(hwnd, NULL, TRUE);
		}
		else {
			InvalidateRect(hwnd, NULL, FALSE);
		}
		SetTimer(hwnd, MYTIMER, 1000, NULL);
		break;

	case WM_PAINT:
		
		GetClientRect(hwnd, &rc);
	
		hdc = BeginPaint(hwnd, &ps);

		switch (iPointFlag) {

		case 1:
			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 1;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);
			fclose(fp);
			break;

		case 2:
			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 1;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 2;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);
			fclose(fp);
			break;

		case 3:
			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 1;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 2;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 3;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);
			fclose(fp);
			break;

		case 4:
			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 1;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 2;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 3;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 4;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 255, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);
			fclose(fp);
			break;

		case 5:
			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 1;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 2;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 3;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 4;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 255, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 5;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(255, 0, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);
			fclose(fp);
			break;

		case 6:
			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 1;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 2;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 3;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 4;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 255, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 5;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(255, 0, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 6;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(255, 255, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);
			fclose(fp);
			break;

		case 7:
			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 1;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 2;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 3;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 4;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 255, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 5;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(255, 0, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 6;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(255, 255, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 7;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(255, 255, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);
			fclose(fp);
			break;

		case 8:
			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 1;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(255, 0, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 2;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 3;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 0, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 4;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 255, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 5;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(255, 0, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 6;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(255, 255, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 7;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(255, 255, 255));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);

			rctmp.top = rc.top;
			rctmp.left = rc.left + (rc.right / 8) * 8;
			rctmp.bottom = rc.bottom;
			rctmp.right = rctmp.left + rc.right / 8;
			hbr = CreateSolidBrush(RGB(0, 0, 0));
			SelectObject(hdc, hbr);
			FillRect(hdc, &rctmp, hbr);
			fclose(fp);
			break;
		}
		EndPaint(hwnd, &ps);
		
		break;



	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

