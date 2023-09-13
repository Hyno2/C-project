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
#include "id.h"



int main() {
	// title에서 커서를 안뜨는 함수
	set_cursor_type(NOCURSOR);
	// 폰트 컬러를 바꾸는 함수
	font_color(LIGHT_GREEN);
	// title을 불러온다
	title();
	_getch();

	// 시스템 클리어
	system("cls");
	
	font_color(LIGHT_GRAY);
	set_cursor_type(NORMAL_CURSOR);

	// 파일명을 매개변수로 사용하기위해 변수file[] 선언
	char file[] = "data.bin";

	
	while (1) {
		
		switch (main_menu()) {
			
		case 1: {
			system("cls");
			//수입 함수를 대입할 submenu1변수 생성
			int submenu1 = import_menu();
			break;
		}
		case 2: {
			system("cls");
			//지출 함수를 대입할 submenu2변수 생성
			int submenu2 = spend_menu();
		}
			break;
		case 3:
			system("cls");
			//조회 함수를 대입할 submenu3변수 생성
			int submenu3 = check_menu();
			break;
		case 4:
			printf("프로그램을 종료합니다.\n");
			printf("부자 되세요~");
			exit(0);
		}
		system("cls");
	}
}





