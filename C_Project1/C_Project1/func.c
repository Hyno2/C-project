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

void spend_error_msg(out ou) {
	
}