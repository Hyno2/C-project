#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit()
#include <time.h>	// time()
#include <string.h>	// strcpy()
#include <conio.h>
#include <windows.h>// Sleep()
#include "menu.h"
#include "ui.h"
#include "file.h"
#include "func.h"



void check_input_msg(income in) {

	printf("┌─ 확인─────────────────────────────┐\n");
	printf("│  입력하신 금액은 %d원 입니다. ☜\n", in.money);
	printf("│\t\t(1.예  2.아니오)    │\n");
	printf("└───────────────────────────────────┘\n");
	printf("  선택: ");
}

void check_input_msg2(out ou) {

	printf("┌─ 확인─────────────────────────────┐\n");
	printf("│  입력하신 금액은 %d원 입니다. ☜\n", ou.money);
	printf("│\t\t(1.예  2.아니오)    │\n");
	printf("└───────────────────────────────────┘\n");
	printf("  선택: ");
	
}

void spend_catagory(out ou) {
	// 카테고리 메뉴 함수 변수에 선언
	int submenu0 = type_menu();
	if (submenu0 == 1) {
		strcpy(ou.type, "식비");
	}
	else if (submenu0 == 2) {
		strcpy(ou.type, "주거 / 통신");
	}
	else if (submenu0 == 3) {
		strcpy(ou.type, "의복 / 미용");
	}
	else if (submenu0 == 4) {
		strcpy(ou.type, "건강 / 문화");
	}
	else if (submenu0 == 5) {
		strcpy(ou.type, "교육 / 육아");
	}
	else if (submenu0 == 6) {
		strcpy(ou.type, "교통 / 차량");
	}
	else if (submenu0 == 7) {
		strcpy(ou.type, "기타");
	}
}

void pay_method(out ou) {
	int submenu1 = import_menu();
	if (submenu1 == 1) {
		strcpy(ou.pay, "카드");
	}
	else if (submenu1 == 2) {
		strcpy(ou.pay, "현금");
	}
}