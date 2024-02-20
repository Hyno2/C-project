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

void file_write_income(char file1[],income in) {
	// 파일오픈 income.bin에 이어서저장 ab
	FILE* fp = fopen(file1, "ab");
	// fwrite 변수in내용을 income구조체크기만큼 한덩어리 쓴다
	fwrite(&in, sizeof(income), 1, fp);
	fclose(fp);
}

void file_write_spend(char file2[], out ou) {
	FILE* fp = fopen(file2, "ab");
	fwrite(&ou, sizeof(out), 1, fp);
	fclose(fp);
}

void show_total_money(char file1[], char file2[], int totalincome, int totalspend)
{
	//파일 읽기
	//구조체 income 에 변수 in 초기화
	income in = { 0 };
	//구조체 out에 변수 ou 초기화
	out ou = { 0 };

	FILE* fp1 = fopen(file1, "rb");
	FILE* fp2 = fopen(file2, "rb");
	while (fread(&in, sizeof(income), 1, fp1) > 0) {
		// 총수입 = 총수입 + 구조체 income.money
		totalincome += in.money;
	}
	while (fread(&ou, sizeof(out), 1, fp2) > 0) {
		// 총지출 = 총지출 + 구조체 income.money
		totalspend += ou.money;
	}
	fclose(fp1);
	fclose(fp2);

	font_color(WHITE);
	printf("총 수입 : %d원\n", totalincome);

	font_color(RED);
	printf("총 지출 : %d원\n", totalspend);

	// 만약 총수입 - 총지출 0보다 클시
		//-폰트는 초록색, 현재 자산 출력
	if (totalincome - totalspend > 0) {
		font_color(GREEN);
		printf("현재 자산 : %d원\n", totalincome - totalspend);
	}
	// 아니고 0이거나 작을시 
	//-폰트 빨강, 현재 자산출력
	else if (totalincome - totalspend <= 0) {
		font_color(RED);
		printf("현재 자산 : %d원\n", totalincome - totalspend);
	}
}





