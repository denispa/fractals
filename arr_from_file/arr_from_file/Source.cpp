#include <windows.h>
#include <stdio.h>
void linetodxy(int dx, int dy);
int x, y;
HDC hdc;
PAINTSTRUCT ps;
void a(int i, int u);
void b(int i, int u);
void c(int i, int u);
void d(int i, int u);
HPEN red = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
HPEN green = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
HPEN blue = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
HPEN black = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
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
		x = 50; y = 50;
		MoveToEx(hdc, x, y, NULL);


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

		//a(5, 10);
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


void a(int i, int u) {

	if (i>0){
		d(i - 1, u);
		SelectObject(hdc, red); linetodxy(u, 0);
		a(i - 1, u);
		SelectObject(hdc, red); linetodxy(0, u);
		a(i - 1, u);
		SelectObject(hdc, red); linetodxy(-u, 0);
		c(i - 1, u);
	}
}

void b(int i, int u) {

	if (i>0) {
		c(i - 1, u);
		SelectObject(hdc, blue); linetodxy(-u, 0);
		b(i - 1, u);
		SelectObject(hdc, blue); linetodxy(0, -u);
		b(i - 1, u);
		SelectObject(hdc, blue); linetodxy(u, 0);
		d(i - 1, u);
	}
}

void c(int i, int u) {

	if (i>0) {
		b(i - 1, u);
		SelectObject(hdc, green); linetodxy(0, -u);
		c(i - 1, u);
		SelectObject(hdc, green); linetodxy(-u, 0);
		c(i - 1, u);
		SelectObject(hdc, green); linetodxy(0, u);
		a(i - 1, u);
	}
}

void d(int i, int u) {
	if (i>0) {
		a(i - 1, u);
		SelectObject(hdc, black); linetodxy(0, u);
		d(i - 1, u);
		SelectObject(hdc, black); linetodxy(u, 0);
		d(i - 1, u);
		SelectObject(hdc, black); linetodxy(0, -u);
		b(i - 1, u);
	}
}

void linetodxy(int dx, int dy)
{
	x += dx;
	y += dy;
	LineTo(hdc, x, y);
}