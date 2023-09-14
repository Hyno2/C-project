#include <stdio.h>
#include <windows.h>// win32 api 사용 (윈도우 환경에서만 사용 가능)
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
	// 윈도우 콘솔에서 커서 위치 이동
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
	// 커서 타입을 설정 (win32 API)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void font_color(FONT_COLOR color)
{
	// 폰트에 색생 적용
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}