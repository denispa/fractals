#pragma once
#include <windows.h>
#include <stdio.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

Bitmap^ DrawCurve(System::Drawing::Graphics^, Color  Linecolor, Color  Fontcolor, System::String^ adress, bool inverse, bool animate);

void linetodxy(int dx, int dy);
void LineToPoint(int x, int y);

void a(int i, int u, int r, int t, int posX, int posY, int step);
void b(int i, int u, int r, int t, int posX, int posY, int step);
void c(int i, int u, int r, int t, int posX, int posY, int step);
void d(int i, int u, int r, int t, int posX, int posY, int step);

int pow2(int power);
bool check_black(int posX, int posY, int i);
bool check_white(int posX, int posY, int i);

void Makearray(void);
void ReadBmp(int black, int white, String^ adress);

static char **arr;
static int x = 0, y = 0;
static int num = 0;
static int k, kk;
static int ptsX[110000], ptsY[110000];
