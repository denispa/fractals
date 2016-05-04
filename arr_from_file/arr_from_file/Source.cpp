#include <windows.h>
#include <stdio.h>
void linetodxy(int dx, int dy);
int x, y;
int k, kk;
HDC hdc;
PAINTSTRUCT ps;
static HDC memBit;
static HBITMAP hBitmap;
void a(int i, int u, int r, int t, int posX, int posY, int step);
void b(int i, int u, int r, int t, int posX, int posY, int step);
void c(int i, int u, int r, int t, int posX, int posY, int step);
void d(int i, int u, int r, int t, int posX, int posY, int step);

HPEN black = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));

int pow2(int power);
bool check_black(int posX, int posY, int i);
bool check_white(int posX, int posY, int i);

int **arr = (int**)malloc(512 * sizeof(int*));

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
	wincl.hbrBackground = CreateSolidBrush(RGB(140, 140, 140));

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
	while (GetMessage(&messages, NULL, 0, 0)){
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


		for (int i = 0; i<512; i++){
			arr[i] = (int*)malloc(512 * sizeof(int));
		}
		/*FILE *file;

		errno_t err;
		err = fopen_s(&file, "E:/123.txt", "r");

		for (int i = 0; i < 512; i++){
		for (int o = 0; o < 512; o++)
		arr[i][o] = fgetc(file);
		fgetc(file);
		}*/
		hBitmap = (HBITMAP)LoadImage(NULL, TEXT("e:\\qwqqr.bmp"), IMAGE_BITMAP,
			0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		memBit = CreateCompatibleDC(hdc);
		SelectObject(memBit, hBitmap);

		//	BitBlt(hdc, 100, 100, 512, 512, memBit, 0, 0, SRCCOPY);

		unsigned int t;
		int num;
		for (int i = 0; i < 512; i++) {
			for (int o = 0; o < 512; o++){
				t = GetPixel(memBit, i, o);
				if (t == 16777215) num = 49; else num = 40;

				arr[i][o] = num;
			}
		}


		for (int i = 0; i < 64; i++){
			for (int o = 0; o < 64; o++){
				int kount = 0;
				for (int ee = 0; ee < 8; ee++)
					for (int qq = 0; qq < 8; qq++)
						if (arr[i * 8 + ee][o * 8 + qq] == 49) kount++;

				if (kount > 32) {
					for (int ee = 0; ee < 2; ee++)
						for (int qq = 0; qq < 2; qq++)
							arr[i * 2 + ee][o * 2 + qq] = 49;
				}
				else
				{
					for (int ee = 0; ee < 2; ee++)
						for (int qq = 0; qq < 2; qq++)
							arr[i * 2 + ee][o * 2 + qq] = 40;
				}


			}
		}


		/*fclose(file);*/

		x = 0; y = 0;

		MoveToEx(hdc, x, y, NULL);
		a(8, 4, 0, 0, 0, 0, 8);
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


void a(int i, int u, int l_bef, int l_aft, int posX, int posY, int step) {

	if ((check_white(posX, posY, pow2(i - 1))) && (k == 0) && (kk == 0)) {
		k = 1;
		a(i - 1, 4, l_bef, l_aft, posX, posY, i);
		k = 0;
		return;
	}
	if ((check_black(posX, posY, pow2(i - 1))) && (kk == 0)) {
		kk = 1;
		a(i, 2, l_bef, l_aft, posX, posY, i);
		kk = 0;
		return;
	}

	if ((kk == 1) || (k == 1))
	{
		if (l_bef == 0){
			x = posX * 4 + 39 + u / 2;
			y = posY * 4 + 39 + u / 2;
			LineTo(hdc, x, y);
		}
		if (l_bef == 1){
			x = posX * 4 + 39;
			y = posY * 4 + 39 + u / 2;
			LineTo(hdc, x, y);
		}
		if (l_bef == 2){
			x = posX * 4 + 39 + u / 2;
			y = posY * 4 + 39;
			LineTo(hdc, x, y);
		}
	}

	if (check_black(posX, posY, 1)){
		if (l_bef == 1)
			linetodxy(1, 0);
		if (l_bef == 2)
			linetodxy(0, 1);
	}
	else{
		if (l_bef == 1)
			linetodxy(u / 2, 0);
		if (l_bef == 2)
			linetodxy(0, u / 2);
	}
	SelectObject(hdc, black);
	if (i > 1){
		d(i - 1, u, 0, 1, posX, posY, step - 1);
		posX += pow2(step - 2);
		a(i - 1, u, 1, 1, posX, posY, step - 1);
		posY += pow2(step - 2);
		a(i - 1, u, 2, 2, posX, posY, step - 1);
		posX -= pow2(step - 2);
		c(i - 1, u, 2, 0, posX, posY, step - 1);
	}

	if (i == 1){
		linetodxy(u, 0);
		linetodxy(0, u);
		linetodxy(-u, 0);
	}


	if (check_black(posX, posY, 1)){
		if (l_aft == 1)
			linetodxy(0, 1);
		if (l_aft == 2)
			linetodxy(-1, 0);
	}
	else{
		if (l_aft == 1)
			linetodxy(0, u / 2);
		if (l_aft == 2)
			linetodxy(-u / 2, 0);
	}
	SelectObject(hdc, black);
}

void b(int i, int  u, int l_bef, int l_aft, int posX, int posY, int step) {

	if ((check_white(posX, posY, pow2(i - 1))) && (k == 0) && (kk == 0)){
		k = 1;
		b(i - 1, 4, l_bef, l_aft, posX, posY, i);
		k = 0;
		return;
	}
	if ((check_black(posX, posY, pow2(i - 1))) && (kk == 0)){
		kk = 1;
		b(i, 2, l_bef, l_aft, posX, posY, i);
		kk = 0;
		return;
	}

	if ((kk == 1) || (k == 1))
	{
		if (l_bef == 0){
			x = (posX + pow2(step - 1)) * 4 + 39 - u / 2;
			y = (posY + pow2(step - 1)) * 4 + 39 - u / 2;
			LineTo(hdc, x, y);
		}
		if (l_bef == 1){
			x = (posX + pow2(step - 1)) * 4 + 39;
			y = (posY + pow2(step - 1)) * 4 + 39 - u / 2;;
			LineTo(hdc, x, y);
		}
		if (l_bef == 2){
			x = (posX + pow2(step - 1)) * 4 + 39 - u / 2;
			y = (posY + pow2(step - 1)) * 4 + 39;
			LineTo(hdc, x, y);
		}
	}


	if (check_black(posX + pow2(step - 2), posY + pow2(step - 2), 1)){
		if (l_bef == 1)
			linetodxy(-1, 0);
		if (l_bef == 2)
			linetodxy(0, -1);
	}
	else {
		if (l_bef == 1)
			linetodxy(-u / 2, 0);
		if (l_bef == 2)
			linetodxy(0, -u / 2);
	}

	if (i > 1) {
		posX += pow2(step - 2);
		posY += pow2(step - 2);
		c(i - 1, u, 0, 1, posX, posY, step - 1);
		posX -= pow2(step - 2);
		b(i - 1, u, 1, 1, posX, posY, step - 1);
		posY -= pow2(step - 2);
		b(i - 1, u, 2, 2, posX, posY, step - 1);
		posX += pow2(step - 2);
		d(i - 1, u, 2, 0, posX, posY, step - 1);
	}
	if (i == 1) {
		linetodxy(-u, 0);
		linetodxy(0, -u);
		linetodxy(u, 0);
	}

	if (check_black(posX, posY, 1)){
		if (l_aft == 1)
			linetodxy(0, -1);
		if (l_aft == 2)
			linetodxy(1, 0);
	}
	else{
		if (l_aft == 1)
			linetodxy(0, -u / 2);
		if (l_aft == 2)
			linetodxy(u / 2, 0);
	}
}

void c(int i, int u, int l_bef, int l_aft, int posX, int posY, int step) {

	if ((check_white(posX, posY, pow2(i - 1))) && (k == 0) && (kk == 0)){
		k = 1;
		c(i - 1, 4, l_bef, l_aft, posX, posY, i);
		k = 0;
		return;
	}
	if ((check_black(posX, posY, pow2(i - 1))) && (kk == 0)){
		kk = 1;
		c(i, 2, l_bef, l_aft, posX, posY, i);
		kk = 0;
		return;
	}

	if ((kk == 1) || (k == 1))
	{
		if (l_bef == 0){
			x = (posX + pow2(step - 1)) * 4 + 39 - u / 2;
			y = (posY + pow2(step - 1)) * 4 + 39 - u / 2;
			LineTo(hdc, x, y);
		}
		if (l_bef == 1){
			x = (posX + pow2(step - 1)) * 4 + 39 - u / 2;
			y = (posY + pow2(step - 1)) * 4 + 39;
			LineTo(hdc, x, y);
		}
		if (l_bef == 2){
			x = (posX + pow2(step - 1)) * 4 + 39;
			y = (posY + pow2(step - 1)) * 4 + 39 - u / 2;
			LineTo(hdc, x, y);
		}
	}

	if (check_black(posX + pow2(step - 2), posY + pow2(step - 2), 1)){
		if (l_bef == 1)
			linetodxy(0, -1);
		if (l_bef == 2)
			linetodxy(-1, 0);
	}
	else{
		if (l_bef == 1)
			linetodxy(0, -u / 2);
		if (l_bef == 2)
			linetodxy(-u / 2, 0);
	}

	if (i > 1) {
		posY += pow2(step - 2);
		posX += pow2(step - 2);
		b(i - 1, u, 0, 1, posX, posY, step - 1);
		posY -= pow2(step - 2);
		c(i - 1, u, 1, 1, posX, posY, step - 1);
		posX -= pow2(step - 2);
		c(i - 1, u, 2, 2, posX, posY, step - 1);
		posY += pow2(step - 2);
		a(i - 1, u, 2, 0, posX, posY, step - 1);
	}
	if (i == 1) {
		linetodxy(0, -u);
		linetodxy(-u, 0);
		linetodxy(0, u);
	}
	if (check_black(posX, posY, 1)){
		if (l_aft == 1)
			linetodxy(-1, 0);
		if (l_aft == 2)
			linetodxy(0, 1);
	}
	else{
		if (l_aft == 1)
			linetodxy(-u / 2, 0);
		if (l_aft == 2)
			linetodxy(0, u / 2);
	}
}

void d(int i, int u, int l_bef, int l_aft, int posX, int posY, int step) {

	if ((check_white(posX, posY, pow2(i - 1))) && (k == 0) && (kk == 0)){
		k = 1;
		d(i - 1, 4, l_bef, l_aft, posX, posY, i);
		k = 0;
		return;
	}
	if ((check_black(posX, posY, pow2(i - 1))) && (kk == 0)) {
		kk = 1;
		d(i, 2, l_bef, l_aft, posX, posY, i);
		kk = 0;
		return;
	}

	if ((kk == 1) || (k == 1))
	{
		if (l_bef == 0){
			x = posX * 4 + 39 + u / 2;
			y = posY * 4 + 39 + u / 2;
			LineTo(hdc, x, y);
		}
		if (l_bef == 1){
			x = posX * 4 + 39 + u / 2;;
			y = posY * 4 + 39;
			LineTo(hdc, x, y);
		}
		if (l_bef == 2){
			x = posX * 4 + 39;
			y = posY * 4 + 39 + u / 2;
			LineTo(hdc, x, y);
		}
	}

	if (check_black(posX, posY, 1)){
		if (l_bef == 1)
			linetodxy(0, 1);
		if (l_bef == 2)
			linetodxy(1, 0);
	}
	else{
		if (l_bef == 1)
			linetodxy(0, u / 2);
		if (l_bef == 2)
			linetodxy(u / 2, 0);
	}

	if (i > 1) {
		a(i - 1, u, 0, 1, posX, posY, step - 1);
		posY += pow2(step - 2);
		d(i - 1, u, 1, 1, posX, posY, step - 1);
		posX += pow2(step - 2);
		d(i - 1, u, 2, 2, posX, posY, step - 1);
		posY -= pow2(step - 2);
		b(i - 1, u, 2, 0, posX, posY, step - 1);
	}
	if (i == 1) {
		linetodxy(0, u);
		linetodxy(u, 0);
		linetodxy(0, -u);
	}

	if (check_black(posX, posY, 1)){
		if (l_aft == 1)
			linetodxy(1, 0);
		if (l_aft == 2)
			linetodxy(0, -1);
	}
	else{
		if (l_aft == 1)
			linetodxy(u / 2, 0);
		if (l_aft == 2)
			linetodxy(0, -u / 2);
	}
}

void linetodxy(int dx, int dy)
{
	x += dx;
	y += dy;
	LineTo(hdc, x, y);
}

int pow2(int power){
	int z = 1;
	if (power == -1)
		return 0;
	if (power == 0)
		return 1;
	for (int i = 0; i < power; i++)
		z *= 2;
	return z;
}

bool check_black(int X, int Y, int i)
{
	for (int jj = X; jj < X + i; jj++)
		for (int oo = Y; oo < Y + i; oo++)
			if (!(arr[jj][oo] == 49))
				return false;
	return true;
}

bool check_white(int X, int Y, int i)
{
	for (int jj = X; jj < X + i; jj++)
		for (int oo = Y; oo < Y + i; oo++)
			if ((arr[jj][oo] == 49))
				return false;
	return true;
}
