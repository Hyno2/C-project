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
	// 230914 month������ 1~12���� , day������ 1~31������ �ްԲ� �Ϸ�. 
			// month�� 1�̸� 13�̻��̰ų� day�� 1�̸� 32�̸��϶� �����޼��� �ٽ��Է¹ޱ�
	while (ou.month < 1 || ou.month >= 13 || ou.day < 1 || ou.day >= 32) {
		printf("�߸��� ��¥ �Է�!\n");
		printf("�ٽ� �Է��� �ּ���.\n");
		printf("��¥ �Է� ex 9/5 : ");
		scanf("%d/%d", &ou.month, &ou.day);
		
	}
}