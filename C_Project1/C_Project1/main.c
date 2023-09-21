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

int main() {
	// 콘솔창 제목표시줄 내용바꾸기
	SetConsoleTitle(TEXT("가.계.부 v1.0"));
	// 콘솔창이 모니터 중앙으로
	center();
	// 커서 없앰
	set_cursor_type(NOCURSOR);
	// 폰트색상 
	font_color(LIGHT_GREEN);
	// 타이틀 함수 호출
	title();
	// 딜레이 1초
	Sleep(1000);
	//타이틀 종료 시스템클리어
	system("cls");
	font_color(LIGHT_GRAY);
	set_cursor_type(NORMAL_CURSOR);

	// 파일명 매개변수로 던져 주기 위한 선언
	char file_in[]= "income.bin";
	char file_sp[] = "out.bin";
	
	while (1) {
		// 총 수입 변수 
		int totalincome = 0;
		// 총 지출 변수
		int totalout = 0;

		// goto문 돌아가는 위치
		com:

		// 타이틀 위에 총수입 총지출 현자산 츨력하는 함수 호출
		show_total_money(file_in,file_sp, totalincome, totalout);
		font_color(WHITE);

		// 메인메뉴 시작 
		switch (main_menu()) {

		// 1번 수입
		case MAIN_INCOME : 
		{
			//구조체 income 에 변수 in 선언,초기화
			income in = { 0 };

			// 230918 q, Q입력시 메인메뉴로 가기 변수 선언
			char ch;

			printf(" 메인메뉴로 돌아가시려면 (q or Q)\n");
			printf(" ▶ 날짜 입력 ex 9/5 : ");
			if (scanf("%d/%d", &in.month, &in.day)) {}
			else if (scanf("%c", &ch) && ch == 'q'|| ch=='Q') {
				break;
			}
			rewind(stdin);

			// 230914 month변수는 1~12까지 , day변수는 1~31까지만 받게끔 완료. 
			// month는 1미만 13이상이거나 day는 1미만 32미만일때 오류메세지 다시입력받기
			while (in.month < 1 || in.month >= 13 || in.day < 1 || in.day >= 32) {
				printf(" 잘못된 날짜 입력!\n");
				printf(" 다시 입력해 주세요.\n");
				printf(" ▶ 날짜 입력 ex 9/5 : ");
				scanf("%d/%d", &in.month, &in.day);

			// 230918 while반복문 안에서 q누르면 탈출.
			if (scanf("%c", &ch) && ch == 'q' || ch == 'Q') {
				system("cls");
				goto com;	
			}	rewind(stdin);
			}
						
			printf(" ▶ 금액 입력 : ");
			scanf("%d", &in.money);
			rewind(stdin);

			// 입력금액 확인을 입력받기위한 변수 select
			int select = 0;

			// 금액입력확인메세지 함수 호출
			while (1) {
			check_input_msg(in);
			
			scanf("%d", &select);
			rewind(stdin);
				// 입력값이 1일경우 입력받은 금액
				if (select == 1) {
					in.money;
					break;
				}// 2일경우 다시입력 받기
				else if (select == 2) {
					printf(" 금액을 다시 입력해 주세요 : ");
					scanf("%d", &in.money);
					rewind(stdin);
					continue;
				}
				else {
					printf(" 잘못된 입력입니다.\n");
					printf(" 다시 입력해주세요.\n");
				}
			}
			// 메모 입력 
			printf(" ▶ 메모 입력 : ");
			scanf("%s", in.memo);
		
			// 수입 파일 쓰기 함수 호출
			file_write_income(file_in,in);
			printf(" 수입내역 저장중");
			Sleep(400); printf(".");
			Sleep(400); printf(".");
			Sleep(400); printf(".\n");
			Sleep(400);
			printf(" 저장 완료!\n");
			system("pause");
		}  break;

		// 2번 지출
		case MAIN_SPEND :
		{
			char ch;
			out ou = { 0 };
			printf(" 메인메뉴로 돌아가시려면 (q or Q)\n");
			printf(" ▶ 날짜 입력 ex 9/5 : ");
			if (scanf("%d/%d", &ou.month, &ou.day)) {}
			else if (scanf("%c", &ch) && ch == 'q' || ch == 'Q') {
				break;
			}rewind(stdin);
		
			while (ou.month < 1 || ou.month >= 13 || ou.day < 1 || ou.day >= 32) {
				printf(" 잘못된 날짜 입력!\n");
				printf(" 다시 입력해 주세요.\n");
				printf(" ▶ 날짜 입력 ex 9/5 : ");
				scanf("%d/%d", &ou.month, &ou.day);

				// 230918 while반복문 안에서 q누르면 탈출.
				if (scanf("%c", &ch) && ch == 'q' || ch == 'Q') {
					system("cls");
					goto com;
				}	rewind(stdin);
			}
			printf(" ▶ 지출 금액 : ");
			scanf("%d", &ou.money);			
			rewind(stdin);

			// 금액확인 메세지 변수 선언
			int select = 0;

			// 금액입력확인메세지 함수 호출
			while (1) {
			check_input_msg2(ou);

			// 조건 체크
				scanf("%d", &select);
				rewind(stdin);
				if (select == 1) {
					ou.money;
					break;
				}
				else if (select == 2) {
					printf(" 금액을 다시 입력해 주세요 : ");
					scanf("%d", &ou.money);
					rewind(stdin);
					continue;
				}
				else {
					printf(" 잘못된 입력입니다.\n");
					printf(" 다시 입력해주세요.\n");
				}
			}
			// 지출 카테고리 함수 호출 
			// 작동 안됌 오류 발견 빈칸이 들어감!
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
			printf(" ▶ 메모 입력 : ");
			scanf("%s", ou.memo);

			// 결재 수단 메뉴 함수 호출 
			// 작동안됌 오류 발견 빈칸이들어감
			int submenu1 = import_menu();
			if (submenu1 == 1) {
				strcpy(ou.pay, "카드");
			}
			else if (submenu1 == 2) {
				strcpy(ou.pay, "현금");
			}

			// 지출 파일 쓰기 함수 호출
			file_write_spend(file_sp, ou);
			printf(" 지출내역 저장중");
			Sleep(400); printf(".");
			Sleep(400); printf(".");
			Sleep(400); printf(".\n");
			Sleep(400);
			printf(" 저장 완료!\n");
			system("pause");
		}  break;
			
		// 3번 조회 
		case MAIN_CHECK :
		{
			// 조회 메뉴 함수호출
			system("cls");
			int submenu2 = check_menu();	

			// 일 조회 함수 호출
			day_check(submenu2, file_in, file_sp);

			// 월 조회 함수 호출
			month_check(submenu2, file_in, file_sp);

			// 전체 내역 조회 함수 호출
			all_check(submenu2, file_in, file_sp);
		} break;

		// 4번 삭제
		case MAIN_DELETE :	// 서브메뉴 더 받아서 전체내역 삭제할지, 검색해서 삭제?? , 				
		{					// 아니면 수익내역만 삭제 , 지출내역만 삭제 이런거 해도될듯
			delete_all(file_in,file_sp);
		}break;

		case MAIN_EXIT :
		{
			printf(" 프로그램을 종료합니다.\n");
			printf(" 부자 되세요~");
			exit(0);
		}
			} // switch 문 닫는 중괄호
		system("cls");
	} // while문 닫는 중괄호

} // main문 닫는 중괄호


