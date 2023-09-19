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
	// 230914 month변수는 1~12까지 , day변수는 1~31까지만 받게끔 완료. 
			// month는 1미만 13이상이거나 day는 1미만 32미만일때 오류메세지 다시입력받기
	while (ou.month < 1 || ou.month >= 13 || ou.day < 1 || ou.day >= 32) {
		printf("잘못된 날짜 입력!\n");
		printf("다시 입력해 주세요.\n");
		printf("날짜 입력 ex 9/5 : ");
		scanf("%d/%d", &ou.month, &ou.day);
		
	}
}