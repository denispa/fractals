#include <windows.h>
#include <stdio.h>
void linetodxy(int dx, int dy);
int x, y;
int k;
HDC hdc;
PAINTSTRUCT ps;
void a(int i, int u, int r);
void b(int i, int u, int r);
void c(int i, int u, int r);
void d(int i, int u, int r);
HPEN red = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
HPEN green = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
HPEN blue = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
HPEN black = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
HPEN yellow = CreatePen(PS_SOLID, 1, RGB(255, 255, 224));
LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
char szClassName[] = "Krivaia Gil'berta";

int WINAPI WinMain(HINSTANCE hThisInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpszArgument,
	int nFunsterStil)

{
	HWND hwnd;
	MSG messages;
	WNDCLASSEX wincl;
	wincl.hInstance = hThisInstance;
	wincl.lpszClassName = szClassName;
	wincl.lpfnWndProc = WindowProcedure;
	wincl.style = CS_DBLCLKS;
	wincl.cbSize = sizeof(WNDCLASSEX);

	wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL;
	wincl.cbClsExtra = 0;
	wincl.cbWndExtra = 0;
	wincl.hbrBackground = CreateSolidBrush(RGB(150, 150, 150));



	if (!RegisterClassEx(&wincl))
		return 0;
	hwnd = CreateWindowEx(
		0,
		szClassName,
		"Krivaia Gil'berta",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		800,
		600,
		HWND_DESKTOP,
		NULL,
		hThisInstance,
		NULL
		);
	ShowWindow(hwnd, nFunsterStil);

	while (GetMessage(&messages, NULL, 0, 0))
	{
		TranslateMessage(&messages);
		DispatchMessage(&messages);
	}
	return messages.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{


	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		x = 40; y = 40;
		MoveToEx(hdc, x, y, NULL);
		/*

		int **arr;
		arr = (int**)malloc(512 * sizeof(int*));
		for (int i = 0; i<512; i++){
		arr[i] = (int*)malloc(512 * sizeof(int));
		}
		FILE *file;
		char u;
		errno_t err;
		err = fopen_s(&file, "E:/123.txt", "r");

		for (int i = 0; i<512; i++){
		for (int o = 0; o<512; o++){
		u = fgetc(file);
		arr[i][o] = u;
		}
		u = fgetc(file);
		}

		for (int i = 0; i<512; i++){
		for (int o = 0; o<512; o++)	{
		if (arr[i][o] == 49) SetPixel(hdc, i + 5, o + 5, RGB(0, 0, 0));
		else SetPixel(hdc, i + 5, o + 5, RGB(255, 0, 0));
		}
		}

		fclose(file);
		*/

		a(8, 40, 0);
		ValidateRect(hwnd, NULL);
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}


void a(int i, int u, int r) {

	if ((i < 6) && (k == 0)) { k = 1; a(1, 40, r); k = 0; return; }
	if ((i < 7) && (k == 0) && (y < 370)) { k = 1; a(3, 20, r); k = 0; return; }
	if (i > 1){

		d(i - 1, u, 1);
		SelectObject(hdc, yellow); if (i > 6) linetodxy(u / 4, 0); else linetodxy(u / 2, 0);
		a(i - 1, u, 1);
		SelectObject(hdc, yellow); if (i > 6) linetodxy(0, u / 4); else linetodxy(0, u / 2);
		a(i - 1, u, 2);
		SelectObject(hdc, yellow); if (i > 6) linetodxy(-u / 4, 0); else linetodxy(-u / 2, 0);
		c(i - 1, u, 0);
	}
	if (i == 1){
		SelectObject(hdc, red); linetodxy(u, 0);
		SelectObject(hdc, red); linetodxy(0, u);
		SelectObject(hdc, red); linetodxy(-u, 0);
	}

	if (r == 1)linetodxy(0, u / 2);
	if (r == 2)linetodxy(-u / 2, 0);
}

void b(int i, int  u, int r) {

	if ((i < 6) && (k == 0)) { k = 1; b(1, 40, r); k = 0; return; }
	if ((i < 7) && (k == 0) && (y < 370)) { k = 1; b(3, 20, r); k = 0; return; }
	if (i > 1) {
		c(i - 1, u, 1);
		SelectObject(hdc, yellow); if (i > 6)linetodxy(-u / 4, 0); else linetodxy(-u / 2, 0);
		b(i - 1, u, 1);
		SelectObject(hdc, yellow); if (i > 6)linetodxy(0, -u / 4); else  linetodxy(0, -u / 2);
		b(i - 1, u, 2);
		SelectObject(hdc, yellow); if (i > 6) linetodxy(u / 4, 0); else linetodxy(u / 2, 0);
		d(i - 1, u, 0);
	}
	if (i == 1) {
		SelectObject(hdc, blue); linetodxy(-u, 0);
		SelectObject(hdc, blue); linetodxy(0, -u);
		SelectObject(hdc, blue); linetodxy(u, 0);
	}
	
	if (r == 1)linetodxy(0, -u / 2);
	if (r == 2) linetodxy(u / 2, 0);
}

void c(int i, int u, int r) {

	if ((i < 6) && (k == 0)) { k = 1; c(1, 40, r); k = 0; return; }
	if ((i < 7) && (k == 0) && (y < 370)) { k = 1; c(3, 20, r); k = 0; return; }
	if (i > 1) {
		b(i - 1, u, 1);
		SelectObject(hdc, yellow); if (i > 6)linetodxy(0, -u / 4); else linetodxy(0, -u / 2);
		c(i - 1, u, 1);
		SelectObject(hdc, yellow); if (i > 6) linetodxy(-u / 4, 0); else linetodxy(-u / 2, 0);
		c(i - 1, u, 2);
		SelectObject(hdc, yellow); if (i > 6) linetodxy(0, u / 4); else linetodxy(0, u / 2);
		a(i - 1, u, 0);
	}
	if (i == 1) {
		SelectObject(hdc, green); linetodxy(0, -u);
		SelectObject(hdc, green); linetodxy(-u, 0);
		SelectObject(hdc, green); linetodxy(0, u);
	}
	
	if (r == 1)linetodxy(-u / 2, 0);
	if (r == 2)linetodxy(0, u / 2);
}

void d(int i, int u, int r) {

	if ((i < 6) && (k == 0)) { k = 1; d(1, 40, r); k = 0; return; }
	if ((i < 7) && (k == 0) && (y < 370)) { k = 1; d(3, 20, r); k = 0; return; }
	if (i > 1) {

		a(i - 1, u, 1);
		SelectObject(hdc, yellow); if (i > 6) linetodxy(0, u / 4); else linetodxy(0, u / 2);
		d(i - 1, u, 1);
		SelectObject(hdc, yellow); if (i > 6) linetodxy(u / 4, 0); else linetodxy(u / 2, 0);
		d(i - 1, u, 2);
		SelectObject(hdc, yellow); if (i > 6)linetodxy(0, -u / 4); else linetodxy(0, -u / 2);
		b(i - 1, u, 0);
	}
	if (i == 1) {
		SelectObject(hdc, black); linetodxy(0, u);
		SelectObject(hdc, black); linetodxy(u, 0);
		SelectObject(hdc, black); linetodxy(0, -u);
	} 	
	
	if (r == 1) linetodxy(u / 2, 0);
	if (r == 2)linetodxy(0, -u / 2);
}

void linetodxy(int dx, int dy)
{
	x += dx;
	y += dy;
	LineTo(hdc, x, y);
}