#include <stdio.h>
#include <stdlib.h>	// exit()
#include <time.h>	// time()
#include <string.h>	// strcpy()
#include <windows.h>// win32 api 사용 (윈도우 환경에서만 사용 가능)
#include <conio.h>
void title();
void gotoxy(int x, int y);

int  main(void)
{
	title();
};
void title()
{
	int x = 5;
	int y = 3;
	gotoxy(x, y + 0); printf("	■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(x + 8, y + 1); printf("■			■■■ ■■■■■■■■■■■■■■■■■■■");
	gotoxy(x + 3, y + 2); printf("■							■");
	gotoxy(x+3,y + 1); printf("■						■");
	gotoxy(x + 3, y + 4); printf("■							■");
	gotoxy(x + 4, y + 5); printf("■						■■■■■■■");
	gotoxy(x+	4 , y + 2); printf("		■			■■■■■■■");
	gotoxy(x + 5, y + 2); printf("	■				■■■■");
	gotoxy(x + 10, y + 2); printf("	■■■■■■■■■■■				■");
	
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	// 윈도우 콘솔에서 커서 위치 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


