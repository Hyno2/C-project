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

char spend_catagory(out ou) { // ���� ��Ʈ��ī�ǰ� �����̾ȉ�
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
	return ou.type;
}

void pay_method(out ou) { // ����
	int submenu1 = import_menu();
	if (submenu1 == 1) {
		strcpy(ou.pay, "ī��");
	}
	else if (submenu1 == 2) {
		strcpy(ou.pay, "����");
	}
}

void day_check(char file1[],char file2[]) {

	// ��ȸ �޴� �Լ�ȣ��
	int submenu2 = check_menu();
	// �Ϻ� ��ȸ  ���⼭ �� ���� �Է¹ް� �Է¹��� ���� �ϼ��� ǥ���ϰ� �ؾ� �ҵ� 
	if (submenu2 == 1) {
		int count = 1;
		int cnt = 1;
		int totalincome = 0;
		int totalout = 0;
		int card = 0;
		int cash = 0;
		income in = { 0 };
		out ou = { 0 };

		// 230918 �� �Է¹ޱ����� ���� ����
		int month = 0;

		printf("���� �Է� ���ּ���.");
		scanf("%d", &month);

		rewind(stdin);
		// 230918 month������ 1~12������ �ްԲ� �Ϸ�. �ƴҽ� ���Է�
		while (month < 1 || month>12) {
			printf("�߸��� ��¥ �Է�!\n");
			printf("�ٽ� �Է��� �ּ���.\n");
			printf("���� �ٽ� �Է����ּ��� : ");
			scanf("%d", &month);
			rewind(stdin);
		}
		//�� �Է¹ޱ����� ���� ����
		int day = 0;

		printf("�ñ��� ���� �Է����ּ��� : ");
		scanf("%d", &day);
		rewind(stdin);
		printf("���� �ҷ�������......\n");
		Sleep(2000);

		while (day < 1 || day>31) {
			printf("�߸��� ��¥ �Է�!\n");
			printf("�ٽ� �Է��� �ּ���.\n");
			printf("�ñ��� ���� �ٽ� �Է����ּ��� : ");
			scanf("%d", &day);
			rewind(stdin);
		}
		FILE* fp1 = fopen(file1, "rb");
		FILE* fp2 = fopen(file2, "rb");

		while (fread(&in, sizeof(income), 1, fp1) > 0) {
			// ���� �Է¹�����¥�� ���� ����ü ���� month ���� day ���� ���ٸ�
			if (month == in.month && day == in.day) {
				totalincome += in.money;
				printf("-----------------\n");
				printf("���ͳ��� %d ��°\n", count++);
				printf("��¥ : %d�� %d��\n", in.month, in.day);
				printf("�ݾ� : %d\n", in.money);
				printf("�޸� : %s\n", in.memo);
				printf("-----------------\n");
			}
		}
		while (fread(&ou, sizeof(out), 1, fp2) > 0) {
			// ���� �Է� ���� ��¥�� ���� ����ü ���� month ���� month���� ���� day ���� ���ٸ�
			if (month == ou.month && day == ou.day) {
				totalout += ou.money;
				// 230915 ���ҹ���� ī���� ��� card������ ou.money �� ���� �ջ� by jung 
				if (strcmp(ou.pay, "ī��") == 0) {
					card += ou.money;
				}
				// 230915 ���ҹ���� ������ ��� cash������ ou.money �� ���� �ջ� by jung
				if (strcmp(ou.pay, "����") == 0) {
					cash += ou.money;
				}
				printf("-----------------\n");
				printf("���⳻�� %d ��°\n", cnt++);
				printf("��¥ : %d�� %d��\n", ou.month, ou.day);
				printf("�ݾ� : %d��\n", ou.money);
				printf("Ÿ�� : %s\n", ou.type);
				printf("�޸� : %s\n", ou.memo);
				printf("�������� : %s\n", ou.pay);
				printf("-----------------\n");
			}
		}
		fclose(fp1);
		fclose(fp2);

		// �Ϻ� ��ȸ ���
		// 230915 ī��, ���� �� ���ݾ� �߰� by jung
		printf("%d�� %d�� ī�� �� ��� �ݾ� : %d��\n", month, day, card);
		printf("%d�� %d�� ���� �� ��� �ݾ� : %d��\n", month, day, cash);
		printf("%d�� %d�� �� ���� �ݾ� : %d��\n", month, day, totalincome);
		printf("%d�� %d�� �� ���� �ݾ� : %d��\n", month, day, totalout);
		printf("%d�� %d�� �� �ջ� �ݾ� : %d��\n", month, day, totalincome - totalout);
		system("pause");
	}
}

void month_check(char file1[], char file2[]) {

	// ��ȸ �޴� �Լ�ȣ��
	int submenu2 = check_menu();
	// ���� ��ȸ
	if (submenu2 == 2) {
		int count = 1;
		int cnt = 1;
		int totalincome = 0;
		int totalout = 0;
		// 230915 ī�庯�� �߰� by jung
		int card = 0;
		// 230915 ���ݺ��� �߰� by jung
		int cash = 0;
		income in = { 0 };
		out ou = { 0 };

		FILE* fp1 = fopen(file1, "rb");
		FILE* fp2 = fopen(file2, "rb");
		int month = 0;
		printf("�� �� ������ ����Ͻðڽ��ϱ�? : ");
		scanf("%d", &month);
		// 230916 �Է¹��� ����(���ѷ��� ����) by Jung
		rewind(stdin);
		// ������ �ֱ� 23.09.16 by Lee
		printf("���� �ҷ�������......\n");
		Sleep(2000);

		// 230914 month������ 1~12������ �ްԲ� �Ϸ�. by jung
		while (month < 1 || month > 12) {
			printf("�߸��� ��¥ �Է�!\n");
			printf("�ٽ� �Է��� �ּ���.\n");
			printf("�� �� ������ ����Ͻðڽ��ϱ�? : ");
			scanf("%d", &month);
			// 230916 �Է¹��� ����(���ѷ��� ����) by Jung
			rewind(stdin);
		}
		while (fread(&in, sizeof(income), 1, fp1) > 0) {
			if (month == in.month) {
				totalincome += in.money;
				printf("���ͳ��� %d ��°\n", count++);
				printf("��¥ : %d�� %d��\n", in.month, in.day);
				printf("�ݾ� : %d\n", in.money);
				printf("�޸� : %s\n", in.memo);
				printf("-----------------\n");
			}
		}
		while (fread(&ou, sizeof(out), 1, fp2) > 0) {
			if (month == ou.month) {
				totalout += ou.money;
				// 230915 ���ҹ���� ī���� ��� card������ ou.money �� ���� �ջ� by jung
				if (strcmp(ou.pay, "ī��") == 0) {
					card += ou.money;
				}
				// 230915 ���ҹ���� ������ ��� cash������ ou.money �� ���� �ջ� by jung
				if (strcmp(ou.pay, "����") == 0) {
					cash += ou.money;
				}
				printf("���⳻�� %d ��°\n", cnt++);
				printf("��¥ : %d�� %d��\n", ou.month, ou.day);
				printf("�ݾ� : %d��\n", ou.money);
				printf("Ÿ�� : %s\n", ou.type);
				printf("�޸� : %s\n", ou.memo);
				printf("�������� : %s\n", ou.pay);
				printf("-----------------\n");
			}
		}
		fclose(fp1);
		fclose(fp2);
		printf("%d�� ī�� �� ���ݾ� : %d��\n", month, card);
		printf("%d�� ���� �� ���ݾ� : %d��\n", month, cash);
		printf("%d�� �� ���� �ݾ�: %d��\n", month, totalincome);
		printf("%d�� �� ���� �ݾ� : %d��\n", month, totalout);
		printf("%d�� �� �ջ� �ݾ� : %d��\n", month, totalincome - totalout);
		system("pause");
	}
}

void all_check(char file1[], char file2[]) {

	// ��ȸ �޴� �Լ�ȣ��
	int submenu2 = check_menu();

	// ��ü ���� ��ȸ
	if (submenu2 == 3) {
		int count = 1;
		int cnt = 1;
		int totalincome = 0;
		int totalout = 0;
		int card = 0;
		int cash = 0;
		income in = { 0 };
		out ou = { 0 };
		printf("���� �ҷ�������......\n");
		Sleep(2000);
		FILE* fp1 = fopen(file1, "rb");
		FILE* fp2 = fopen(file2, "rb");
		while (fread(&in, sizeof(income), 1, fp1) > 0) {
			totalincome += in.money;

			printf("���ͳ��� %d ��°\n", count++);
			printf("��¥ : %d�� %d��\n", in.month, in.day);
			printf("�ݾ� : %d��\n", in.money);
			printf("�޸� : %s\n", in.memo);
			printf("-----------------\n");
		}
		while (fread(&ou, sizeof(out), 1, fp2) > 0) {
			totalout += ou.money;
			if (strcmp(ou.pay, "ī��") == 0) {
				card += ou.money;
			}
			if (strcmp(ou.pay, "����") == 0) {
				cash += ou.money;
			}
			printf("���⳻�� %d ��°\n", cnt++);
			printf("��¥ : %d�� %d��\n", ou.month, ou.day);
			printf("�ݾ� : %d��\n", ou.money);
			printf("Ÿ�� : %s\n", ou.type);
			printf("�޸� : %s\n", ou.memo);
			printf("�������� : %s\n", ou.pay);
			printf("-----------------\n");
		}
		fclose(fp1);
		fclose(fp2);
		printf("ī�� �� ��� �ݾ�: %d��\n", card);
		printf("���� �� ��� �ݾ�: %d��\n", cash);
		printf("�� ���� �ݾ�: %d��\n", totalincome);
		printf("�� ���� �ݾ�: %d��\n", totalout);
		printf("�� �ջ� �ݾ�: %d��\n", totalincome - totalout);
		system("pause");
	}
}

void delete_all(char file1[],char file2[]) {
	char del;
	printf("�����Ͻðٽ��ϱ� Y/N\n");
	while (1) {
		scanf(" %c", &del);
		rewind(stdin);
		if (del == 'y' || del == 'Y') {
			FILE* fp1 = fopen(file1, "wb");
			FILE* fp2 = fopen(file2, "wb");
			fclose(fp1);
			fclose(fp2);

			printf("������ ������......\n");
			Sleep(2000);
			printf("�����Ϸ�!\n");
			system("pause");
		}
		else if (del == 'n' || del == 'N') {
			printf("���� ��� �ϼ̽��ϴ�.");
			system("pause");
		}
		else {
			printf("�߸��� �Է�!\n");
			continue;
		}
		break;
	}
}