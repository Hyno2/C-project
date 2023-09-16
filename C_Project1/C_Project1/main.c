#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit()
#include <time.h>	// time()
#include <string.h>	// strcpy()
#include <conio.h>
#include <windows.h>// Sleep()
#include "menu.h"
#include "ui.h"

// 구조체 수입 income 선언
typedef struct _income {
	int month;
	int day;
	int money;
	char memo[50];
} income;

// 구조체 지출 out 선언
typedef struct _out {
	int month;
	int day;
	int money;
	char type[20];
	char pay[20];
	char memo[50];
} out;

int main() {
	// 콘솔창 크기 조정 
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 500, 500, TRUE);

	// 커서 없앰
	set_cursor_type(NOCURSOR);

	// 폰트색상 
	font_color(LIGHT_GREEN);
	title();
	_getch();
	//타이틀 종료 시스템클리어
	system("cls");
	
	
	font_color(LIGHT_GRAY);
	set_cursor_type(NORMAL_CURSOR);
	//idc();
	
	while (1) {
		// 총 수입 변수 
		int totalincome = 0;
		// 총 지출 변수
		int totalout = 0;
		//구조체 income 에 변수 in 초기화
		income in = { 0 };
		//구조체 out에 변수 ou 초기화
		out ou = { 0 };

	// 메인메뉴 위에 내역들 띄우기
		//파일 읽기
		FILE* fp1 = fopen("income.bin", "rb");
		FILE* fp2 = fopen("out.bin", "rb");
		while (fread(&in, sizeof(income), 1, fp1) > 0) {
			// 총수입 = 총수입 + 구조체 income.money
			totalincome += in.money;
		}
		while (fread(&ou, sizeof(out), 1, fp2) > 0) {
			// 총지출 = 총지출 + 구조체 income.money
			totalout += ou.money;
		}
		font_color(WHITE);
		printf("총 수입 : %d원\n", totalincome);
		font_color(RED);
		printf("총 지출 : %d원\n", totalout);
		// 만약 총수입 - 총지출 0보다 클시
		//-폰트는 초록색, 현재 자산 출력
		if (totalincome - totalout > 0) {
			font_color(GREEN);
			printf("현재 자산 : %d원\n", totalincome - totalout);
		}
		// 아니고 0이거나 작을시 
		//-폰트 빨강, 현재 자산출력
		else if (totalincome - totalout <= 0) {
			font_color(RED);
			printf("현재 자산 : %d원\n", totalincome - totalout);
		}
		
		// 메인메뉴 시작 
		font_color(WHITE);
		switch (main_menu()) {
			// 1번 수입 선택시
		case 1: {
			//구조체 income 에 변수 in 초기화
			income in = { 0 };
			printf("날짜 입력 (9월 5일 일시 ex.9 5) : ");
			scanf("%d %d", &in.month, &in.day);
			// 230916 입력버퍼 비우기(무한루프 방지) by Jung
			rewind(stdin);
			// 230914 month변수는 1~12까지 , day변수는 1~31까지만 받게끔 완료. 
			// month는 1미만 13이상이거나 day는 1미만 32미만일때 오류메세지 다시입력받기
			while (in.month < 1 || in.month >= 13 || in.day < 1 || in.day >= 32) {
				// 230916 입력버퍼 비우기(무한루프 방지) by Jung
				rewind(stdin);
				printf("잘못된 날짜 입력!\n");
				printf("다시 입력해 주세요.\n");
				printf("날짜 입력 (9월 5일 일시 ex.9 5) : ");
				scanf("%d %d", &in.month, &in.day);				
			}
			
			// 입력금액 확인을 입력받기위한 변수 select
			int select = 0;

			// 확인 메세지 추가 
			// 23.09.16 while문 조건을 금액입력 밑으로 옮김  by Lee
				printf("금액 입력 : ");
				scanf("%d", &in.money);
				// 230916 입력버퍼 비우기(무한루프 방지) by Jung
				rewind(stdin);
				while (select != 1) {
				printf("┌─ 확인─────────────────────────────┐\n");
				printf("│  입력하신 금액은 %d원 입니다. ☜\n", in.money);
				printf("│\t\t(1.예  2.아니오)    │\n");
				printf("└───────────────────────────────────┘\n");
				printf("  선택: ");
				scanf("%d", &select);
				// 230916 입력버퍼 비우기(무한루프 방지) by Jung
				rewind(stdin);	
				// 입력값이 1일경우 입력받은 금액
				if (select == 1) {
					in.money;
				}// 2일경우 다시입력 받기
				else if (select == 2) {
					printf("금액을 다시 입력해 주세요 : ");
					scanf("%d", &in.money);
					// 230916 입력버퍼 비우기(무한루프 방지) by Jung
					rewind(stdin);
				}
				else {
					printf("잘못된 입력입니다.\n");
					printf("다시 입력해주세요\n");
				}
			}
			//메모 입력 
			printf("메모 입력 : ");
			scanf("%s", in.memo);

			// 파일오픈 income.bin에 이어서저장 ab
			FILE* fp = fopen("income.bin", "ab");
			// fwrite 변수in내용을 income구조체크기만큼 한덩어리 쓴다
			fwrite(&in, sizeof(income), 1, fp);
			fclose(fp);
			printf("수입내역 저장중......\n");
			// 23.09.16 딜레이 준다 1000이 1sec   by Lee
			Sleep(2000);
			printf("저장 완료!\n");
			system("pause");
		}
			  break;
		case 2: {
			out ou = { 0 };
			printf("날짜 입력 (9월 5일 일시 ex.9 5): ");
			scanf("%d %d", &ou.month, &ou.day);
			// 230916 입력버퍼 비우기(무한루프 방지) by Jung
			rewind(stdin);
			// 230914 month변수는 1~12까지 , day변수는 1~31까지만 받게끔 완료. 
			// month는 1미만 13이상이거나 day는 1미만 32미만일때 오류메세지 다시입력받기
			while (ou.month < 1 || ou.month >= 13 || ou.day < 1 || ou.day >= 32) {
				printf("잘못된 날짜 입력!\n");
				printf("다시 입력해 주세요.\n");
				printf("날짜 입력 (9월 5일 일시 ex.9 5): ");
				scanf("%d %d", &ou.month, &ou.day);
			}
			// 금액확인 메세지 변수 선언
			int select = 0;
			
			printf("지출 금액 : ");
			scanf("%d", &ou.money);
			// 230916 입력버퍼 비우기(무한루프 방지) by Jung
			rewind(stdin);
			while (select != 1) {
				//  23.09.16 지출금액 확인 메세지 추가 by Lee
				printf("┌─ 확인─────────────────────────────┐\n");
				printf("│  입력하신 금액은 %d원 입니다. ☜\n", ou.money);
				printf("│\t\t(1.예  2.아니오)    │\n");
				printf("└───────────────────────────────────┘\n");
				printf("  선택: ");
				scanf("%d", &select);
				// 230916 입력버퍼 비우기(무한루프 방지) by Jung
				rewind(stdin);
				// 입력값이 1일경우 입력받은 금액
				if (select == 1) {
					ou.money;
				}// 2일경우 다시입력 받기
				else if (select == 2) {
					printf("금액을 다시 입력해 주세요 : ");
					scanf("%d", &ou.money);
					// 230916 입력버퍼 비우기(무한루프 방지) by Jung
					rewind(stdin);
				}
				else {
					printf("잘못된 입력입니다.\n");
				}
			}
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
			// 메모입력
			printf("메모 입력 (ex.주류비,통신비 등등): ");
			scanf("%s", ou.memo);

			// 결재 수단 메뉴 변수 선언
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
			printf("지출내역 저장중......\n");
			// 딜레이 주기 23.09.16 by Lee
			Sleep(2000);
			printf("저장 완료!\n");
			system("pause");
		}
			  break;
		case 3:
			system("cls");
			int submenu2 = check_menu();

			// 일별 조회  여기서 월 먼저 입력받고 입력받은 달의 일수만 표시하게 해야 할듯 
			if (submenu2 == 1) {
				int count = 1;
				int cnt = 1;
				int totalincome = 0;
				int totalout = 0;
				// 230915 카드변수 추가 by jung
				int card = 0; 
				// 230915 현금변수 추가 by jung
				int cash = 0; 
				income in = { 0 };
				out ou = { 0 };

				FILE* fp1 = fopen("income.bin", "rb");
				FILE* fp2 = fopen("out.bin", "rb");

				//일 입력받기위한 변수 선언
				int day = 0;
				printf("궁금한 날을 입력해주세용 : ");
				scanf("%d", &day);
				// 230916 입력버퍼 비우기(무한루프 방지) by Jung
				rewind(stdin);
				// 딜레이 주기 23.09.16 by Lee
				printf("내역 불러오는중......\n");
				Sleep(2000);

				// 230914 day변수는 1~31까지만 받게끔 완료. 아닐시 재입력 by jung
				while (day < 1 || day>31) {
					printf("잘못된 날짜 입력!\n");
					printf("다시 입력해 주세요.\n");
					printf("궁금한 날을 다시 입력해주세용 : ");
					scanf("%d", &day);
					// 230916 입력버퍼 비우기(무한루프 방지) by Jung
					rewind(stdin);
				}

				while (fread(&in, sizeof(income), 1, fp1) > 0) {
					// 만약 입력받은날짜와 수입 구조체 변수 day 값이 같다면
					if (day == in.day) {
						totalincome += in.money;
						printf("수익내역 %d 번째\n", count++);
						printf("날짜 : %d월 %d일\n", in.month, in.day);
						printf("금액 : %d\n", in.money);
						printf("메모 : %s\n", in.memo);
						printf("-----------------\n");
					}
				}
				while (fread(&ou, sizeof(out), 1, fp2) > 0) {
					if (day == ou.day) {
						totalout += ou.money;
						// 230915 지불방식이 카드인 경우 card변수에 ou.money 값 누적 합산 by jung 
						if (strcmp(ou.pay, "카드") == 0) {    
							card += ou.money;
						}
						// 230915 지불방식이 현금인 경우 cash변수에 ou.money 값 누적 합산 by jung
						if (strcmp(ou.pay, "현금") == 0) {    
							cash += ou.money;
						}
						printf("지출내역 %d 번째\n", cnt++);
						printf("날짜 : %d월 %d일\n", ou.month, ou.day);
						printf("금액 : %d원\n", ou.money);
						printf("타입 : %s\n", ou.type);
						printf("메모 : %s\n", ou.memo);
						printf("결제수단 : %s\n", ou.pay);
						printf("-----------------\n");
					}
				}
				fclose(fp1);
				fclose(fp2);

				// 일별 조회 결과
				// 230915 카드, 현금 총 사용금액 추가 by jung
				printf("%d일 카드 총 사용 금액 : %d원\n", day, card);
				printf("%d일 현금 총 사용 금액 : %d원\n", day, cash);
				printf("%d일 총 수익 금액 : %d원\n", day, totalincome);
				printf("%d일 총 지출 금액 : %d원\n", day, totalout);
				printf("%d일 총 합산 금액 : %d원\n", day, totalincome - totalout);
				system("pause");
			}
			// 월별 조회
			if (submenu2 == 2) {
				int count = 1;
				int cnt = 1;
				int totalincome = 0;
				int totalout = 0;
				// 230915 카드변수 추가 by jung
				int card = 0;
				// 230915 현금변수 추가 by jung
				int cash = 0; 
				income in = { 0 };
				out ou = { 0 };
				
				FILE* fp1 = fopen("income.bin", "rb");
				FILE* fp2 = fopen("out.bin", "rb");
				int month = 0;
				printf("몇 월 내역을 출력하시겠습니까? : ");
				scanf("%d", &month);
				// 230916 입력버퍼 비우기(무한루프 방지) by Jung
				rewind(stdin);
				// 딜레이 주기 23.09.16 by Lee
				printf("내역 불러오는중......\n");
				Sleep(2000);

				// 230914 month변수는 1~12까지만 받게끔 완료. by jung
				while (month < 1 || month > 12 ) {
					printf("잘못된 날짜 입력!\n");
					printf("다시 입력해 주세요.\n");
					printf("몇 월 내역을 출력하시겠습니까? : ");
					scanf("%d", &month);
					// 230916 입력버퍼 비우기(무한루프 방지) by Jung
					rewind(stdin);
				}
				while (fread(&in, sizeof(income), 1, fp1) > 0) {
					if (month == in.month) {
						totalincome += in.money;
						printf("수익내역 %d 번째\n", count++);
						printf("날짜 : %d월 %d일\n", in.month, in.day);
						printf("금액 : %d\n", in.money);
						printf("메모 : %s\n", in.memo);
						printf("-----------------\n");
					}
				}
				while (fread(&ou, sizeof(out), 1, fp2) > 0) {
					if (month == ou.month) {
						totalout += ou.money;
						// 230915 지불방식이 카드인 경우 card변수에 ou.money 값 누적 합산 by jung
						if (strcmp(ou.pay, "카드") == 0) {     
							card += ou.money;
						}
						// 230915 지불방식이 현금인 경우 cash변수에 ou.money 값 누적 합산 by jung
						if (strcmp(ou.pay, "현금") == 0) {    
							cash += ou.money;
						}
						printf("지출내역 %d 번째\n", cnt++);
						printf("날짜 : %d월 %d일\n", ou.month, ou.day);
						printf("금액 : %d원\n", ou.money);
						printf("타입 : %s\n", ou.type);
						printf("메모 : %s\n", ou.memo);
						printf("결제수단 : %s\n", ou.pay);
						printf("-----------------\n");
					}
				}
				fclose(fp1);
				fclose(fp2);
				printf("%d월 카드 총 사용금액 : %d원\n", month, card);
				printf("%d월 현금 총 사용금액 : %d원\n", month, cash);
				printf("%d월 총 수익 금액: %d원\n", month, totalincome);
				printf("%d월 총 지출 금액 : %d원\n", month, totalout);
				printf("%d월 총 합산 금액 : %d원\n", month, totalincome - totalout);
				system("pause");
			}
			
			// 전체 내역 조회
			if (submenu2 == 3) {
				int count = 1;
				int cnt = 1;
				int totalincome = 0;
				int totalout = 0;
				// 230915 카드변수 추가 by jung
				int card = 0; 
				// 230915 현금변수 추가 by jung
				int cash = 0; 
				income in = { 0 };
				out ou = { 0 };
				// 딜레이 주기 23.09.16 by Lee
				printf("내역 불러오는중......\n");
				Sleep(2000);
				FILE* fp1 = fopen("income.bin", "rb");
				FILE* fp2 = fopen("out.bin", "rb");
				while (fread(&in, sizeof(income), 1, fp1) > 0) {
					totalincome += in.money;

					printf("수익내역 %d 번째\n", count++);
					printf("날짜 : %d월 %d일\n", in.month, in.day);
					printf("금액 : %d원\n", in.money);
					printf("메모 : %s\n", in.memo);
					printf("-----------------\n");
				}
				while (fread(&ou, sizeof(out), 1, fp2) > 0) {
					totalout += ou.money;
					// 230915 지불방식이 카드인 경우 card변수에 ou.money 값 누적 합산 by jung
					if (strcmp(ou.pay, "카드") == 0) {     
						card += ou.money;
					}
					// 230915 지불방식이 현금인 경우 cash변수에 ou.money 값 누적 합산 by jung
					if (strcmp(ou.pay, "현금") == 0) {    
						cash += ou.money;
					}
					printf("지출내역 %d 번째\n", cnt++);
					printf("날짜 : %d월 %d일\n", ou.month, ou.day);
					printf("금액 : %d원\n", ou.money);
					printf("타입 : %s\n", ou.type);
					printf("메모 : %s\n", ou.memo);
					printf("결제수단 : %s\n", ou.pay);
					printf("-----------------\n");
				}
				fclose(fp1);
				fclose(fp2);
				// 230915 카드, 현금 총 사용금액 추가 by jung
				printf("카드 총 사용 금액: %d원\n", card);
				printf("현금 총 사용 금액: %d원\n", cash);
				printf("총 수익 금액: %d원\n", totalincome);
				printf("총 지출 금액: %d원\n", totalout);
				printf("총 합산 금액: %d원\n", totalincome - totalout);
				system("pause");
			}
			break;
		case 4: // 서브메뉴 더 받아서 전체내역 삭제할지, 검색해서 삭제?? , 
				// 아니면 수익내역만 삭제 , 지출내역만 삭제 이런거 해도될듯
			{
			char del;
			printf("삭제하시겟습니까 Y/N\n");
			scanf(" %c", &del);

			if (del == 'y' || del == 'Y') {
				FILE* fp1 = fopen("income.bin", "wb");
				FILE* fp2 = fopen("out.bin", "wb");
				fclose(fp1);
				fclose(fp2);
				// 딜레이 주기 23.09.16 by Lee
				printf("데이터 삭제중......\n");
				Sleep(2000);
				printf("삭제완료!\n");
				// 23.09.16 by Lee
				system("pause");
			}
			else if (del == 'n' || del == 'N') {
				printf("삭제 취소 하셨습니다.");
				// 추가 23.09.16 by Lee
				system("pause");
			}
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


