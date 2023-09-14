#include <stdio.h>
#include <windows.h>// win32 api ��� (������ ȯ�濡���� ��� ����)
#include "ui.h"



void title()
{
	printf("           (\\____/)\n");
	printf("           / @__@ \\\n");
	printf("          (  (oo)  )\n");
	printf("           `-.~~.-'\n");
	printf("            /    \\\n");
	printf("          @/      \\@\n");
	printf("         (/ /    \\ \\)\n");
	printf("          WW      WW\n");
}


void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	// ������ �ֿܼ��� Ŀ�� ��ġ �̵�
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void set_cursor_type(CURSOR_TYPE type)
{
	CONSOLE_CURSOR_INFO info = { 0 };
	switch (type) {
	case NOCURSOR:
		info.dwSize = 1;
		info.bVisible = FALSE;
		break;
	case SOLID_CURSOR:
		info.dwSize = 100;
		info.bVisible = TRUE;
		break;
	case NORMAL_CURSOR:
		info.dwSize = 20;
		info.bVisible = TRUE;
		break;
	}
	// Ŀ�� Ÿ���� ���� (win32 API)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void font_color(FONT_COLOR color)
{
	// ��Ʈ�� ���� ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}