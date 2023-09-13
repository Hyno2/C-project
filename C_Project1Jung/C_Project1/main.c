#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

typedef enum {
	NOCURSOR,		// 커서 없앰		0
	SOLID_CURSOR,	// solid 형태	1
	NORMAL_CURSOR	// 일반 형태		2
} CURSOR_TYPE;

typedef enum {
	BLACK,	// 0
	BLUE,	// 1
	GREEN,	// 2
	CYAN,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
	GRAY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_CYAN,
	LIGHT_RED,
	LIGHT_PURPLE,
	LIGHT_YELLOW,
	LIGHT_GRAY	// 15
} FONT_COLOR;

void title();
void gotoxy(int x, int y);
void set_cursor_type(CURSOR_TYPE type);
void font_color(FONT_COLOR color);


int main() {
	set_cursor_type(NOCURSOR);
	font_color(LIGHT_GREEN);
	title();
	_getch();

	system("cls");
	font_color(LIGHT_GRAY);
	set_cursor_type(NORMAL_CURSOR);
	while (1) {
		switch (main_menu()) {
		case 1:
			break;
		case 2: {
			system("cls");
			int submenu1 = search_menu();
		}
			break;
		case 3:
			system("cls");
			int submenu2 = sub_menu();
			break;
		case 4:
			printf("프로그램을 종료합니다.\n");
			printf("부자 되세요~");
			exit(0);
		}
		system("cls");
	}
}

int main_menu()
{
	printf("=============================\n");
	printf("         가 계 부\n");
	printf("=============================\n");
	printf("1.수입\n");
	printf("2.지출\n");
	printf("3.조회\n");
	printf("4.종료\n");
	printf("=============================\n");
	printf("메뉴 선택:");
	int menu;
	scanf("%d", &menu);
	return menu;
}

int search_menu()
{
	printf("=============================\n");
	printf("분류 항목 선택\n");
	printf("=============================\n");
	printf("1.식비\n");
	printf("2.주거 / 통신\n");
	printf("3.의복 / 미용\n");
	printf("4.건강 / 문화\n");
	printf("5.교육 / 육아\n");
	printf("6.교통 / 차량\n");
	printf("7.기타\n");
	printf("8.나가기\n");
	printf("=============================\n");
	printf("입력 번호 :");
	int menu;
	scanf("%d", &menu);
	return menu;
}

int sub_menu()
{
	printf("=============================\n");
	printf("1.일별로 조회\n");
	printf("2.월별로 조회\n");
	printf("3.전체내역 조회\n");
	printf("4.나가기\n");
	printf("=============================\n");
	int menu;
	scanf("%d", &menu);
	return menu;
}

void title()
{
	int x = 5;
	int y = 3;
	gotoxy(x, y + 0); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(x, y + 1); printf("■							     ■");
	gotoxy(x, y + 2); printf("■							     ■");
	gotoxy(x, y + 3); printf("■							     ■");
	gotoxy(x, y + 4); printf("■							     ■");
	gotoxy(x, y + 5); printf("■							     ■");
	gotoxy(x, y + 6); printf("■							     ■");
	gotoxy(x, y + 7); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	gotoxy(x + 12, y + 2); printf("가 계 부");
	gotoxy(x + 33, y + 4); printf("만든날짜	: 2023.09.13");
	gotoxy(x, y + 12); printf("메인화면 이동은 아무키나 누르세요!!!");
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