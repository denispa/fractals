#include <windows.h>
void linetodxy(int dx, int dy);
int x, y;
HDC hdc;
PAINTSTRUCT ps;
void a(int i, int u);
void b(int i, int u);
void c(int i, int u);
void d(int i, int u);
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
	wincl.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));



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

		a(5, 10);
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
		linetodxy(u, 0);
		a(i - 1, u);
		linetodxy(0, u);
		a(i - 1, u);
		linetodxy(-u, 0);
		c(i - 1, u);
	}
}

void b(int i, int u) {

	if (i>0) {
		c(i - 1, u);
		linetodxy(-u, 0);
		b(i - 1, u);
		linetodxy(0, -u);
		b(i - 1, u);
		linetodxy(u, 0);
		d(i - 1, u);
	}
}

void c(int i, int u) {

	if (i>0) {
		b(i - 1, u);
		linetodxy(0, -u);
		c(i - 1, u);
		linetodxy(-u, 0);
		c(i - 1, u);
		linetodxy(0, u);
		a(i - 1, u);
	}
}

void d(int i, int u) {
	if (i>0) {
		a(i - 1, u);
		linetodxy(0, u);
		d(i - 1, u);
		linetodxy(u, 0);
		d(i - 1, u);
		linetodxy(0, -u);
		b(i - 1, u);
	}
}

void linetodxy(int dx, int dy)
{
	x += dx;
	y += dy;
	LineTo(hdc, x, y);
}