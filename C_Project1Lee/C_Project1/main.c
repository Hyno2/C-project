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
	// title���� Ŀ���� �ȶߴ� �Լ�
	set_cursor_type(NOCURSOR);
	// ��Ʈ �÷��� �ٲٴ� �Լ�
	font_color(LIGHT_GREEN);
	// title�� �ҷ��´�
	title();
	_getch();

	// �ý��� Ŭ����
	system("cls");
	
	font_color(LIGHT_GRAY);
	set_cursor_type(NORMAL_CURSOR);

	// ���ϸ��� �Ű������� ����ϱ����� ����file[] ����
	char file[] = "data.bin";

	
	while (1) {
		
		switch (main_menu()) {
			
		case 1: {
			system("cls");
			//���� �Լ��� ������ submenu1���� ����
			int submenu1 = import_menu();
			break;
		}
		case 2: {
			system("cls");
			//���� �Լ��� ������ submenu2���� ����
			int submenu2 = spend_menu();
		}
			break;
		case 3:
			system("cls");
			//��ȸ �Լ��� ������ submenu3���� ����
			int submenu3 = check_menu();
			break;
		case 4:
			printf("���α׷��� �����մϴ�.\n");
			printf("���� �Ǽ���~");
			exit(0);
		}
		system("cls");
	}
}





