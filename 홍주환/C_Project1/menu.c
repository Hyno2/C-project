#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "menu.h"

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

int import_menu()
{
	printf("=============================\n");
	printf("분류 항목 선택\n");
	printf("=============================\n");
	printf("1.카드\n");
	printf("2.현금\n");
	printf("3.나가기\n");
	printf("=============================\n");
	printf("입력 번호 :");
	int menu;
	scanf("%d", &menu);
	return menu;
}

int check_menu()
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
