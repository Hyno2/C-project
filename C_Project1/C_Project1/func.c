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


	printf("���� Ȯ�Φ�����������������������������������������������������������\n");
	printf("��  �Է��Ͻ� �ݾ��� %d�� �Դϴ�. ��\n", in.money);
	printf("��\t\t(1.��  2.�ƴϿ�)    ��\n");
	printf("��������������������������������������������������������������������������\n");
	printf("  ����: ");
}

void spend_error_msg(out ou) {
	
}