#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit()
#include <time.h>	// time()
#include <string.h>	// strcpy()
#include <conio.h>
#include <windows.h>// Sleep()
#include "menu.h"
#include "ui.h"

typedef struct _income {
	int month;
	int day;
	int money;
	char memo[50];
} income;

typedef struct _out {
	int month;
	int day;
	int money;
	char type[20];
	char pay[20];
	char memo[50];
} out;

int main() {
	set_cursor_type(NOCURSOR);
	font_color(LIGHT_GREEN);
	title();
	_getch();
	system("cls");
	font_color(LIGHT_GRAY);
	set_cursor_type(NORMAL_CURSOR);
	
	while (1) {
		int totalincome = 0;
		int totalout = 0;
		income in = { 0 };
		out ou = { 0 };
		FILE* fp1 = fopen("income.bin", "rb");
		FILE* fp2 = fopen("out.bin", "rb");
		while (fread(&in, sizeof(income), 1, fp1) > 0) {
			totalincome += in.money;
		}
		while (fread(&ou, sizeof(out), 1, fp2) > 0) {
			totalout += ou.money;
		}
		font_color(RED);
		printf("지출 : % d원\n", totalout);
		font_color(WHITE);
		printf("수입 : %d원\n", totalincome);
		if (totalincome - totalout > 0) {
			font_color(GREEN);
			printf("현재 자산 : %d원\n", totalincome - totalout);
		}
		else if (totalincome - totalout <= 0) {
			font_color(RED);
			printf("현재 자산 : %d원\n", totalincome - totalout);
		}
		font_color(WHITE);
		switch (main_menu()) {
		case 1: {
			income in = { 0 };
			printf("날짜 입력 (9월 5일 일시 ex.9 5): ");
			scanf("%d %d", &in.month, &in.day);
			printf("금액 입력(원 단위): ");
			scanf("%d", &in.money);
			// 금액 확인 y or n
			printf("입력금액이 %d맞습니까?(Y/N)", in.money);
			char choice1;
			scanf(" %c", &choice1);
			if (choice1 == 'y' || choice1 == 'Y') {
				printf("메모 입력: ");
				scanf("%s", in.memo);

				FILE* fp = fopen("income.bin", "ab");
				fwrite(&in, sizeof(income), 1, fp);
				fclose(fp);
				printf("저장 완료!\n");
				system("pause");
			}
			else if (choice1 == 'n' || choice1 == 'N') {
				printf("금액 입력이 취소 되었습니다.\n");
				system("pause");
			}
			// else 오류남 else일경우 잘못입력하셨습니다 출력해야하는데
		}
			break;
		case 2: {
			out ou = { 0 };
			printf("날짜 입력 (9월 5일 일시 ex.9 5): ");
			scanf("%d %d", &ou.month, &ou.day);
			printf("지출 금액(원 단위): ");
			scanf("%d", &ou.money);
			// 금액확인
			printf("지출 금액이 %d 가 맞습니까? (Y/N)", ou.money);
			char choice2;
			scanf(" %c", &choice2);
			if(choice2 == 'y' || choice2 == 'Y'){
				system("cls");
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
				printf("메모 입력 (ex.주류비,통신비 등등): ");
				scanf("%s", ou.memo);
				system("cls");
				int submenu1 = import_menu();
				if (submenu1 == 1) {
					strcpy(ou.pay, "카드");
				}
				else if (submenu1 == 2) {
					strcpy(ou.pay, "현금");
				}
				FILE* fp = fopen("out.bin", "ab");
				fwrite(&ou, sizeof(out), 1, fp);
				fclose(fp);
				printf("저장 완료!\n");
				system("pause");
			}
			else if (choice2 == 'n' || choice2 == 'N') {
				printf("금액 입력이 취소 되었습니다.\n");
				system("pause");
			}
			// else 오류남 else일경우 잘못입력하셨습니다 출력해야하는데
			}
			
			break;
		case 3:
			system("cls");
			int submenu2 = check_menu();
			if (submenu2 == 1) {
				int count = 1;
				int cnt = 1;
				int totalincome = 0;
				int totalout = 0;
				income in = { 0 };
				out ou = { 0 };
				FILE* fp1 = fopen("income.bin", "rb");
				FILE* fp2 = fopen("out.bin", "rb");
				int day = 0;
				printf("궁금한 날을 입력해주세용 : ");
				scanf("%d", &day);
				while (fread(&in, sizeof(income), 1, fp1) > 0) {
					if (day == in.day) {
						totalincome += in.money;
						printf("수익내역 %d 번째\n", count++);
						printf("날짜: %d월 %d일\n", in.month, in.day);
						printf("금액: %d\n", in.money);
						printf("메모: %s\n", in.memo);
						printf("-----------------\n");
					}
				}
				while (fread(&ou, sizeof(out), 1, fp2) > 0) {
					if (day == ou.day) {
						totalout += ou.money;
						printf("지출내역 %d 번째\n", cnt++);
						printf("날짜: %d월 %d일\n", ou.month, ou.day);
						printf("금액: %d원\n", ou.money);
						printf("타입: %s\n", ou.type);
						printf("메모: %s\n", ou.memo);
						printf("결제수단: %s\n", ou.pay);
						printf("-----------------\n");
					}
				}
				fclose(fp1);
				fclose(fp2);
				printf("%d일 총 수익 금액: %d원, 총 지출 금액: %d원\n",day, totalincome, totalout);
				printf("%d일 총 합산 금액: %d원\n",day, totalincome - totalout);
				system("pause");
			}
			if (submenu2 == 2) {
				int count = 1;
				int cnt = 1;
				int totalincome = 0;
				int totalout = 0;
				income in = { 0 };
				out ou = { 0 };
				FILE* fp1 = fopen("income.bin", "rb");
				FILE* fp2 = fopen("out.bin", "rb");
				int month = 0;
				printf("몇월 내역을 출력하시겠습니까? : ");
				scanf("%d", &month);
				while (fread(&in, sizeof(income), 1, fp1) > 0) {
					if (month == in.month) {
						totalincome += in.money;
						printf("수익내역 %d 번째\n", count++);
						printf("날짜: %d월 %d일\n", in.month, in.day);
						printf("금액: %d\n", in.money);
						printf("메모: %s\n", in.memo);
						printf("-----------------\n");
					}
				}
				while (fread(&ou, sizeof(out), 1, fp2) > 0) {
					if (month == ou.month) {
						totalout += ou.money;
						printf("지출내역 %d 번째\n", cnt++);
						printf("날짜: %d월 %d일\n", ou.month, ou.day);
						printf("금액: %d원\n", ou.money);
						printf("타입: %s\n", ou.type);
						printf("메모: %s\n", ou.memo);
						printf("결제수단: %s\n", ou.pay);
						printf("-----------------\n");
					}
				}
				fclose(fp1);
				fclose(fp2);
				printf("%d달 총 수익 금액: %d원, 총 지출 금액: %d원\n", month, totalincome, totalout);
				printf("%d달 총 합산 금액: %d원\n", month, totalincome - totalout);
				system("pause");
			}

			if (submenu2 == 3) {
				int count = 1;
				int cnt = 1;
				int totalincome = 0;
				int totalout = 0;
				income in = { 0 };
				out ou = { 0 };
				FILE* fp1 = fopen("income.bin", "rb");
				FILE* fp2 = fopen("out.bin", "rb");
				while (fread(&in, sizeof(income), 1, fp1) > 0) {
					totalincome += in.money;
					printf("수익내역 %d 번째\n",count++);
					printf("날짜: %d월 %d일\n",in.month, in.day);
					printf("금액: %d원\n", in.money);
					printf("메모: %s\n", in.memo);
					printf("-----------------\n");
				}
				while (fread(&ou, sizeof(out), 1, fp2) > 0) {
					totalout += ou.money;
					printf("지출내역 %d 번째\n",cnt++);
					printf("날짜: %d월 %d일\n",ou.month, ou.day);
					printf("금액: %d원\n", ou.money);
					printf("타입: %s\n", ou.type);
					printf("메모: %s\n", ou.memo);
					printf("결제수단: %s\n", ou.pay);
					printf("-----------------\n");
				}
				fclose(fp1);
				fclose(fp2);
				printf("총 수익 금액: %d원, 총 지출 금액: %d원\n", totalincome, totalout);
				printf("총 합산 금액: %d원\n", totalincome - totalout);
				system("pause");
			}
			break;
		case 4: // 서브메뉴 더 받아서 전체내역 삭제할지, 검색해서 삭제?? , 아니면 수익내역만 삭제 , 지출내역만 삭제 이런거 해도될듯
			{
			char del;
			printf("삭제하시겟습니까? (Y/N)\n");
			scanf(" %c", &del);

			if (del == 'y' || del == 'Y') {
				FILE* fp1 = fopen("income.bin", "wb");
				FILE* fp2 = fopen("out.bin", "wb");
				fclose(fp1);
				fclose(fp2);
			}
			else if (del == 'n' || del == 'N') {
				printf("삭제 취소 하셨습니다.");
				system("pause");
			}
			// else 오류남 else일경우 잘못입력하셨습니다 출력해야하는데
			}
			break;
		case 5:
			printf("프로그램을 종료합니다.\n");
			printf("부자 되세요~");
			exit(0);
		}
		system("cls");
	}
}


