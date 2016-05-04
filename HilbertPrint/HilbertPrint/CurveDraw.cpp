#include <windows.h>
#include <stdio.h>
#include "CurveDraw.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

void linetodxy(int dx, int dy);
void LineToPoint(int x, int y);

void a(int i, int u, int r, int t, int posX, int posY, int step);
void b(int i, int u, int r, int t, int posX, int posY, int step);
void c(int i, int u, int r, int t, int posX, int posY, int step);
void d(int i, int u, int r, int t, int posX, int posY, int step);

int pow2(int power);
bool check_black(int posX, int posY, int i);
bool check_white(int posX, int posY, int i);

void ReadBmp(int black, int white, String^ adress);
void Makearray(void);


int x = 0, y = 0;
int k, kk;
int ptsX[110000], ptsY[110000];
int num = 0;

char **arr;

int DrawCurve(System::Drawing::Graphics^ grr, System::Drawing::Pen^ my_pen, String^ adress, bool inverse){

	arr = (char**)malloc(512 * sizeof(char*));
	for (int i = 0; i < 512; i++){
		arr[i] = (char*)malloc(512 * sizeof(char));
	}

	if (inverse)
		ReadBmp(0, 1, adress);
	else
		ReadBmp(1, 0, adress);
	Makearray();
	//line building
	a(8, 4, 0, 0, 0, 0, 8);

	//draw to picturebox
	grr->DrawLine(my_pen, 0, 0, ptsX[0] - 39, ptsY[0] - 39);

	for (int i = 1; i < num; i++)
		grr->DrawLine(my_pen, ptsX[i - 1] - 39, ptsY[i - 1] - 39, ptsX[i] - 39, ptsY[i] - 39);

	for (int i = 0; i < 512; i++){
		free(arr[i]);
	}
	free(arr);

	for (int i = 0; i < num; i++)
	{
		ptsX[i] = 0;
		ptsY[i] = 0;
	}
	num = 0;
	return 0;
}


/*
*getting array of colors from bmp
*/
void ReadBmp(int black, int white, String^ adress)
{
	for (int i = 0; i < 512; i++)
	{
		Bitmap^ Bmp = gcnew Bitmap(adress);
		for (int o = 0; o < 512; o++)
		{
			Color c;
			c = Bmp->GetPixel(i, o);
			if (c == Color::FromArgb(0xFF000000))
				arr[i][o] = black;
			else
				arr[i][o] = white;
		}
	}
}

/*
*makes array for drawing
*/
void Makearray(void){

	for (int i = 0; i < 64; i++){
		for (int o = 0; o < 64; o++){
			int kount = 0;
			for (int ee = 0; ee < 8; ee++)
				for (int qq = 0; qq < 8; qq++)
					if (arr[i * 8 + ee][o * 8 + qq] == 1) kount++;

			if (kount > 32) {
				for (int ee = 0; ee < 2; ee++)
					for (int qq = 0; qq < 2; qq++)
						arr[i * 2 + ee][o * 2 + qq] = 1;
			}
			else
			{
				for (int ee = 0; ee < 2; ee++)
					for (int qq = 0; qq < 2; qq++)
						arr[i * 2 + ee][o * 2 + qq] = 0;
			}


		}
	}
}

/**
*  >___
*  	   |
*   ___|
*/
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
			LineToPoint(x, y);
		}
		if (l_bef == 1){
			x = posX * 4 + 39;
			y = posY * 4 + 39 + u / 2;
			LineToPoint(x, y);
		}
		if (l_bef == 2){
			x = posX * 4 + 39 + u / 2;
			y = posY * 4 + 39;
			LineToPoint(x, y);
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

}

/**
*   ___
*  |
*  |___<
*/
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
			LineToPoint(x, y);
		}
		if (l_bef == 1){
			x = (posX + pow2(step - 1)) * 4 + 39;
			y = (posY + pow2(step - 1)) * 4 + 39 - u / 2;;
			LineToPoint(x, y);
		}
		if (l_bef == 2){
			x = (posX + pow2(step - 1)) * 4 + 39 - u / 2;
			y = (posY + pow2(step - 1)) * 4 + 39;
			LineToPoint(x, y);
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

/**
*   ___
*  |   |
*  |   |
*      ^
*/
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
			LineToPoint(x, y);
		}
		if (l_bef == 1){
			x = (posX + pow2(step - 1)) * 4 + 39 - u / 2;
			y = (posY + pow2(step - 1)) * 4 + 39;
			LineToPoint(x, y);
		}
		if (l_bef == 2){
			x = (posX + pow2(step - 1)) * 4 + 39;
			y = (posY + pow2(step - 1)) * 4 + 39 - u / 2;
			LineToPoint(x, y);
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


/**
*  ,,
*  |   |
*  |___|
*/
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
			LineToPoint(x, y);
		}
		if (l_bef == 1){
			x = posX * 4 + 39 + u / 2;;
			y = posY * 4 + 39;
			LineToPoint(x, y);
		}
		if (l_bef == 2){
			x = posX * 4 + 39;
			y = posY * 4 + 39 + u / 2;
			LineToPoint(x, y);
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

int pow2(int power){
	int z = 1;
	if (power == -1)
		return 0;
	for (int i = 0; i < power; i++)
		z *= 2;
	return z;
}

bool check_black(int X, int Y, int i)
{
	for (int jj = X; jj < X + i; jj++)
		for (int oo = Y; oo < Y + i; oo++)
			if (!(arr[jj][oo] == 1))
				return false;
	return true;
}

bool check_white(int X, int Y, int i)
{
	for (int jj = X; jj < X + i; jj++)
		for (int oo = Y; oo < Y + i; oo++)
			if ((arr[jj][oo] == 1))
				return false;
	return true;
}

void linetodxy(int dx, int dy)
{
	x += dx;
	y += dy;
	if (num < 110000){
		ptsX[num] = x;
		ptsY[num] = y;
		num++;
	}
}

void LineToPoint(int dx, int dy)
{
	if (num < 110000){
		ptsX[num] = dx;
		ptsY[num] = dy;
		num++;
	}
}