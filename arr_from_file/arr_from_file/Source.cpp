#include <windows.h>
#include <stdio.h>
void linetodxy(int dx, int dy);
int x, y;
int k,kk;
HDC hdc;
PAINTSTRUCT ps;
void a(int i, int u, int r, int t, int posX, int posY, int step);
void b(int i, int u, int r, int t, int posX, int posY, int step);
void c(int i, int u, int r, int t, int posX, int posY, int step);
void d(int i, int u, int r, int t, int posX, int posY, int step);
/*
HPEN red = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
HPEN green = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
HPEN blue = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
HPEN black = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
*/
HPEN red = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
HPEN green = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
HPEN blue = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
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
		FILE *file;
	 
		errno_t err;
		err = fopen_s(&file, "E:/123.txt", "r");

		for (int i = 0; i < 512; i++){
			for (int o = 0; o < 512; o++)
				arr[i][o] = fgetc(file);
			fgetc(file);
		}
		fclose(file);SelectObject(hdc, green);
	 /*	for (int i = 39; i<700; i+=4)
			{
				MoveToEx(hdc, i, 0, NULL); LineTo(hdc, i, 600);
			} */
		x = 40; y =40; SetPixel(hdc, 39, 40, RGB(0, 255, 0)); 
		SelectObject(hdc, red);MoveToEx(hdc, 550, 10, NULL); 
		LineTo(hdc, 601, 35); SelectObject(hdc, green); SetPixel(hdc, 602, 35, RGB(0, 255, 0)); LineTo(hdc, 600, 30);
		MoveToEx(hdc, x, y, NULL); 
		a(8, 8, 0, 0, 0, 0, 8);
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
	SetPixel(hdc, posX * 4 + 600, posY * 4 + 40, RGB(0, 0, 0));
	if ((check_white(posX, posY, pow2(i - 1))) && (k == 0) && (kk == 0)) {
		k = 1; a(i - 2, 8, l_bef, l_aft, posX, posY, i); k = 0; return;
	}
	if ((check_black(posX, posY, pow2(i - 1))) && (kk == 0)) {
		kk = 1; a(i, 2, l_bef, l_aft, posX, posY, i); kk = 0; return;
	}
	if (k==1)
	{	
		if ((2 > 1) && (l_bef == 1)){ SelectObject(hdc, green); x =posX * 4 + 39 ; y =posY * 4 + 39 + 4 ; LineTo(hdc,x ,y ); }
		if ((2 > 1) && (l_bef == 2)){SelectObject(hdc, green);  x = posX * 4 + 39 + 4 ; y =posY * 4 + 39 ; LineTo(hdc,x,y ); }
	}
	if (kk == 1)
	{
		if ((i > 1) && (l_bef == 0)){ SelectObject(hdc, green); x = posX * 4 + 39+1; y = posY * 4 + 39+1 ; LineTo(hdc, x, y); }
		if ((i > 1) && (l_bef == 1)){ SelectObject(hdc, green); x = posX * 4 + 39; y = posY * 4 + 39 + 1; LineTo(hdc, x, y); }
		if ((i > 1) && (l_bef == 2)){ SelectObject(hdc, green);  x = posX * 4 + 39 + 1; y = posY * 4 + 39; LineTo(hdc, x, y); }
	}
	 
	SelectObject(hdc, red);
	if (check_black(posX, posY, 1)){
		if (l_bef == 1) linetodxy(1, 0);
		if (l_bef == 2) linetodxy(0, 1);
	} else{if (l_bef == 1) linetodxy(u / 2, 0);
		if (l_bef == 2) linetodxy(0, u / 2);}
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

	SelectObject(hdc, red);
	if (check_black(posX, posY , 1)){
		if (l_aft == 1) linetodxy(0,1);
		if (l_aft == 2) linetodxy(-1, 0);
	} else{if (l_aft == 1) linetodxy(0, u / 2);
		if (l_aft == 2) linetodxy(-u / 2, 0);}
	SelectObject(hdc, black); 
}

void b(int i, int  u, int l_bef, int l_aft, int posX, int posY, int step) {
	SetPixel(hdc, posX * 4 + 600, posY * 4 + 40, RGB(0, 0, 0));
	if ((check_white(posX, posY, pow2(i - 1))) && (k == 0) && (kk == 0)){ 
		k = 1; b(i - 2, 8, l_bef, l_aft, posX, posY, i); k = 0; return;
	}
	if ((check_black(posX, posY, pow2(i - 1))) && (kk == 0)){ 
		kk = 1; b(i, 2, l_bef, l_aft, posX, posY, i); kk = 0; return;
	}
	
	 if (k == 1)
	{
		if ((i > 1) && (l_bef == 1)){ SelectObject(hdc, green); x = (posX + pow2(step-1)) * 4 + 39 ; y = (posY + pow2(step - 1)) * 4 + 39- 4; 
										LineTo(hdc, x, y); }
		if ((i > 1) && (l_bef == 2)){ SelectObject(hdc, green);  x = (posX + pow2(step-1)) * 4 + 39-4; y = (posY + pow2(step - 1)) * 4 + 39 ;  
										LineTo(hdc, x, y); }
	} 
	 if (kk == 1)
	 {
		 if ((i > 1) && (l_bef == 1)){
			 SelectObject(hdc, green); x = (posX + pow2(step - 1)) * 4 + 39; y = (posY + pow2(step - 1)) * 4 + 39 - 1;
			 LineTo(hdc, x, y);
		 }
		 if ((i > 1) && (l_bef == 2)){
			 SelectObject(hdc, green);  x = (posX + pow2(step - 1)) * 4 + 39-1  ; y = (posY + pow2(step - 1)) * 4 + 39;
			 LineTo(hdc, x, y);
		 }
	 }



	 SelectObject(hdc, green);
	 if (check_black(posX + pow2(step - 2), posY + pow2(step -2), 1)){
		 if (l_bef == 1)linetodxy(-1, 0);
		 if (l_bef == 2) linetodxy(0, -1);
	 } else{ if (l_bef == 1)linetodxy(-u / 2, 0);
		 if (l_bef == 2) linetodxy(0, -u / 2);}
	SelectObject(hdc, black);

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
	}SelectObject(hdc, green);
	if (check_black(posX, posY, 1)){
		if (l_aft == 1)linetodxy(0, -1);
		if (l_aft == 2) linetodxy(1, 0);
	} else{	if (l_aft == 1)linetodxy(0, -u / 2);
		if (l_aft == 2) linetodxy(u / 2, 0);}SelectObject(hdc, black);
}

void c(int i, int u, int l_bef, int l_aft, int posX, int posY, int step) {
	SetPixel(hdc, posX * 4 + 600, posY * 4 + 40, RGB(0, 0, 0));
	if ((check_white(posX, posY, pow2(i - 1))) && (k == 0) && (kk == 0)){  
		k = 1; c(i - 2, 8, l_bef, l_aft, posX, posY, i); k = 0; return;
	}
	if ((check_black(posX, posY, pow2(i - 1))) && (kk == 0)){ 
		kk = 1; c(i, 2, l_bef, l_aft, posX, posY, i); kk = 0; return;
	}

 	 if (k==1)
	{
		if ((i > 1) && (l_bef == 1)){ SelectObject(hdc, green); x = (posX + pow2(step-1)) * 4 + 39 - 4; y = (posY + pow2(step-1)) * 4 + 39; LineTo(hdc, x, y); }
		if ((i > 1) && (l_bef == 2)){ SelectObject(hdc, green);  x = (posX + pow2(step - 1)) * 4 + 39; y = (posY + pow2(step - 1)) * 4 + 39 - 4;  LineTo(hdc, x, y); }
	} 

	 if (kk == 1)
	 {
		 if ((i > 1) && (l_bef == 1)){ SelectObject(hdc, green); x = (posX + pow2(step - 1)) * 4 + 39 - 1; y = (posY + pow2(step - 1)) * 4 + 39; LineTo(hdc, x, y); }
		 if ((i > 1) && (l_bef == 2)){ SelectObject(hdc, green);  x = (posX + pow2(step - 1)) * 4 + 39; y = (posY + pow2(step - 1)) * 4 + 39 - 1;  LineTo(hdc, x, y); }
	 }

SelectObject(hdc, blue);
if (check_black(posX+pow2(step - 2), posY+pow2(step - 2), 1)){
	if (l_bef == 1)linetodxy(0, -1);
	if (l_bef == 2)linetodxy(-1, 0);
} else{if (l_bef == 1)linetodxy(0, -u / 2);
	if (l_bef == 2)linetodxy(-u / 2, 0);}
SelectObject(hdc, black);	

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
	if (check_black(posX , posY , 1)){
		if (l_aft == 1) linetodxy(-1, 0);
		if (l_aft == 2) linetodxy(0, 1);
	}
	else{
		if (l_aft == 1) linetodxy(-u / 2, 0);
		if (l_aft == 2) linetodxy(0, u / 2);
	}
}

void d(int i, int u, int l_bef, int l_aft, int posX, int posY, int step) {
	SetPixel(hdc, posX * 4 + 600, posY * 4 + 40, RGB(0, 0, 0));
	if ((check_white(posX, posY, pow2(i - 1))) && (k == 0) && (kk == 0)){ 
		k = 1; d(i - 2, 8, l_bef, l_aft, posX, posY, i); k = 0; return;
	}
	if ((check_black(posX, posY, pow2(i - 1))) && (kk == 0)) {
		kk = 1; d(i, 2, l_bef, l_aft, posX, posY, i); kk = 0; return;
	}


 	if (k == 1)
	{
		if ((2 > 1) && (l_bef == 1)){ SelectObject(hdc, green); x = posX * 4 +39 + 4; y = posY * 4 + 39;LineTo(hdc, x, y); }
		if ((2 > 1) && (l_bef == 2)){ SelectObject(hdc, green);  x = posX * 4 +39; y = posY * 4 + 39 + 4;  LineTo(hdc, x, y); }
	}
	if (kk == 1)
	{
		if ((i > 1) && (l_bef == 1)){ SelectObject(hdc, green); x = posX * 4 + 39 + 1; y = posY * 4 + 39; LineTo(hdc, x, y); }
		if ((i > 1) && (l_bef == 2)){ SelectObject(hdc, green);  x = posX * 4 + 39; y = posY * 4 + 39 + 1;  LineTo(hdc, x, y); }
	}
 SelectObject(hdc, blue);
if (check_black(posX, posY, 1)){
	if (l_bef == 1) linetodxy(0,1);
	if (l_bef == 2)linetodxy(1, 0);
}
else{
	if (l_bef == 1) linetodxy(0, u / 2);
	if (l_bef == 2)linetodxy(u / 2, 0);
}SelectObject(hdc, black);
	
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

	SelectObject(hdc, blue);
	if (check_black(posX, posY, 1)){
		if (l_aft == 1) linetodxy(1, 0);
		if (l_aft == 2) linetodxy(0, -1);
	} else{	if (l_aft == 1) linetodxy(u / 2, 0);
		if (l_aft == 2) linetodxy(0, -u / 2);}SelectObject(hdc, black);
}

void linetodxy(int dx, int dy)
{
	x += dx;
	y += dy;
	LineTo(hdc, x, y);
}

int pow2(int power){
	int z=1;
	if (power == -1) return 0;
	if (power == 0) return 1;
	for (int i = 0; i < power; i++)
		z *= 2;
	return z;
}

bool check_black(int X, int Y, int i)
{
 	for (int jj = X*4; jj < X*4+i*4; jj++)
	 	for (int oo = Y*4; oo < Y*4+i*4 ; oo++)
			if (!(arr[jj][oo] == 49)) return false;
	 return true; 
}

bool check_white(int X, int Y, int i)
{
 	for (int jj = X*4; jj < X*4+i*4; jj++)
	 	for (int oo = Y*4; oo < Y*4+i*4 ; oo++)
			if ((arr[jj][oo] == 49)) return false;
	 return true; 
}