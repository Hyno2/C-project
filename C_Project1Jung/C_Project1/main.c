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
		FILE* fp1 = fopen("income", "rb");
		FILE* fp2 = fopen("out", "rb");
		while (fread(&in, sizeof(income), 1, fp1) > 0) {
			totalincome += in.money;
		}
		while (fread(&ou, sizeof(out), 1, fp2) > 0) {
			totalout += ou.money;
		}
		printf("총 수입   : %d원\n", totalincome);
		font_color(RED);
		printf("총 지출   : %d원\n", totalout);
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
			// 230914 month변수는 1~12까지 , day변수는 1~31까지만 받게끔 완료. 
			while (in.month < 1 || in.month >= 13 || in.day < 1 || in.day >= 32) {
				printf("잘못된 날짜 입력!\n");
				printf("다시 입력해 주세요.\n");
				printf("날짜 입력 (9월 5일 일시 ex.9 5): ");
				scanf("%d %d", &in.month, &in.day);
			}
			printf("금액 입력(원 단위): ");
			scanf("%d", &in.money);
			// 230914 금액 확인메세지 추가 근디 뭔가 애매~ 한 느낌..
			printf("┌─ 확인─────────────────────────────┐\n");
			printf("│  입력하신 금액은 %d원 입니다. ☜\n", in.money);
			printf("│\t\t(1.예  2.아니오)    │\n");
			printf("└───────────────────────────────────┘\n");
			printf("  선택: ");
			int select;
			scanf("%d", &select);
			if (select == 1) {
				in.money;
			}
			else {
				printf("금액을 다시 입력해 주세요: ");
				scanf("%d", &in.money);
			}
			printf("메모 입력: ");
			scanf("%s", in.memo);
			
			FILE* fp = fopen("income", "ab");
			fwrite(&in, sizeof(income), 1, fp);
			fclose(fp);
			printf("저장 완료!\n");
			system("pause");
		}
			break;
		case 2: {
			out ou = { 0 };
			printf("날짜 입력 (9월 5일 일시 ex.9 5): ");
			scanf("%d %d", &ou.month, &ou.day);
			// 230914 month변수는 1~12까지 , day변수는 1~31까지만 받게끔 완료. 
			while (ou.month < 1 || ou.month >= 13 || ou.day < 1 || ou.day >= 32) {
				printf("잘못된 날짜 입력!\n");
				printf("다시 입력해 주세요.\n");
				printf("날짜 입력 (9월 5일 일시 ex.9 5): ");
				scanf("%d %d", &ou.month, &ou.day);
			}
			printf("지출 금액(원 단위): ");
			scanf("%d", &ou.money);
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
			FILE* fp = fopen("out", "ab");
			fwrite(&ou, sizeof(out), 1, fp);
			fclose(fp);
			printf("저장 완료!\n");
			system("pause");
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
				FILE* fp1 = fopen("income", "rb");
				FILE* fp2 = fopen("out", "rb");
				int day = 0;
				printf("궁금한 날을 입력해주세용 : ");
				scanf("%d", &day);
				// 230914 day변수는 1~31까지만 받게끔 완료.
				while (day < 1 || day>31) {
					printf("잘못된 날짜 입력!\n");
					printf("다시 입력해 주세요.\n");
					printf("궁금한 날을 다시 입력해주세용 : ");
					scanf("%d", &day);
				}
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
				FILE* fp1 = fopen("income", "rb");
				FILE* fp2 = fopen("out", "rb");
				int month = 0;
				printf("몇 월 내역을 출력하시겠습니까? : ");
				scanf("%d", &month);
				// 230914 month변수는 1~12까지만 받게끔 완료.
				while (month < 1 || month > 12) {
					printf("잘못된 날짜 입력!\n");
					printf("다시 입력해 주세요.\n");
					printf("몇 월 내역을 출력하시겠습니까? : ");
					scanf("%d", &month);
				}
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
				FILE* fp1 = fopen("income", "rb");
				FILE* fp2 = fopen("out", "rb");
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
				FILE* fp1 = fopen("income", "wb");
				FILE* fp2 = fopen("out", "wb");
				fclose(fp1);
				fclose(fp2);
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


