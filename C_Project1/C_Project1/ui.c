#include <stdio.h>
#include <windows.h>// win32 api 사용 (윈도우 환경에서만 사용 가능)
#include <conio.h>
#include "ui.h"


void title()
{
	printf("\t\t\t\t         v1.0\n");
	printf("\n");
	printf("\n");
	printf("\n");
	font_color(LIGHT_RED);
	printf("\t         (\\____/)\n");
	printf("\t         / @__@ \\\n");
	printf("\t        (  (oo)  )\n");
	printf("\t         `-.~~.-'\n");
	printf("\t          /    \\\n");
	printf("\t        @/      \\@\n");
	printf("\t       (/ /    \\ \\)\n");
	printf("\t        WW      WW\n");
	printf("\n");
	printf("\n");
	font_color(WHITE);
	printf("\t        로딩중");
	Sleep(400); printf(". ");
	Sleep(400); printf(". ");
	Sleep(400); printf(". ");
	printf("\n");
	printf("\n");
	Sleep(1000);
	printf("\t         로딩완료!");
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

void center() {// 230918 콘솔 실행 창 크기 및 화면 중앙 실행. by JANG
	HWND consoleWindow = GetConsoleWindow();

	if (consoleWindow != NULL) {
		// 콘솔창 크기 조정 
		RECT r;
		GetWindowRect(consoleWindow, &r);
		MoveWindow(consoleWindow, r.left, r.top, 400, 400, TRUE);

		// 현재 모니터의 해상도 정보를 얻어옴
		int screenX = GetSystemMetrics(SM_CXSCREEN);
		int screenY = GetSystemMetrics(SM_CYSCREEN);

		// 콘솔 창의 크기 정보를 얻어옴
		RECT consoleRect;
		GetWindowRect(consoleWindow, &consoleRect);
		int consoleWidth = consoleRect.right - consoleRect.left;
		int consoleHeight = consoleRect.bottom - consoleRect.top;

		// 콘솔 창을 화면 중앙으로 이동
		int newX = (screenX - consoleWidth) / 2;
		int newY = (screenY - consoleHeight) / 2;
		MoveWindow(consoleWindow, newX, newY, consoleWidth, consoleHeight, TRUE);
	}
}