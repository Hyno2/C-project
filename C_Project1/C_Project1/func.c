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

void check_input_msg2(out ou) {

	printf("���� Ȯ�Φ�����������������������������������������������������������\n");
	printf("��  �Է��Ͻ� �ݾ��� %d�� �Դϴ�. ��\n", ou.money);
	printf("��\t\t(1.��  2.�ƴϿ�)    ��\n");
	printf("��������������������������������������������������������������������������\n");
	printf("  ����: ");
	
}

void spend_catagory(out ou) {
	// ī�װ� �޴� �Լ� ������ ����
	int submenu0 = type_menu();
	if (submenu0 == 1) {
		strcpy(ou.type, "�ĺ�");
	}
	else if (submenu0 == 2) {
		strcpy(ou.type, "�ְ� / ���");
	}
	else if (submenu0 == 3) {
		strcpy(ou.type, "�Ǻ� / �̿�");
	}
	else if (submenu0 == 4) {
		strcpy(ou.type, "�ǰ� / ��ȭ");
	}
	else if (submenu0 == 5) {
		strcpy(ou.type, "���� / ����");
	}
	else if (submenu0 == 6) {
		strcpy(ou.type, "���� / ����");
	}
	else if (submenu0 == 7) {
		strcpy(ou.type, "��Ÿ");
	}
}

void pay_method(out ou) {
	int submenu1 = import_menu();
	if (submenu1 == 1) {
		strcpy(ou.pay, "ī��");
	}
	else if (submenu1 == 2) {
		strcpy(ou.pay, "����");
	}
}