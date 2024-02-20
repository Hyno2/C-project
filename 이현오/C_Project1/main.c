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
		printf("���� : % d��\n", totalout);
		font_color(WHITE);
		printf("���� : %d��\n", totalincome);
		if (totalincome - totalout > 0) {
			font_color(GREEN);
			printf("���� �ڻ� : %d��\n", totalincome - totalout);
		}
		else if (totalincome - totalout <= 0) {
			font_color(RED);
			printf("���� �ڻ� : %d��\n", totalincome - totalout);
		}
		font_color(WHITE);
		switch (main_menu()) {
		case 1: {
			income in = { 0 };
			printf("��¥ �Է� (9�� 5�� �Ͻ� ex.9 5): ");
			scanf("%d %d", &in.month, &in.day);
			printf("�ݾ� �Է�(�� ����): ");
			scanf("%d", &in.money);
			// �ݾ� Ȯ�� y or n
			printf("�Է±ݾ��� %d�½��ϱ�?(Y/N)", in.money);
			char choice1;
			scanf(" %c", &choice1);
			if (choice1 == 'y' || choice1 == 'Y') {
				printf("�޸� �Է�: ");
				scanf("%s", in.memo);

				FILE* fp = fopen("income.bin", "ab");
				fwrite(&in, sizeof(income), 1, fp);
				fclose(fp);
				printf("���� �Ϸ�!\n");
				system("pause");
			}
			else if (choice1 == 'n' || choice1 == 'N') {
				printf("�ݾ� �Է��� ��� �Ǿ����ϴ�.\n");
				system("pause");
			}
			// else ������ else�ϰ�� �߸��Է��ϼ̽��ϴ� ����ؾ��ϴµ�
		}
			break;
		case 2: {
			out ou = { 0 };
			printf("��¥ �Է� (9�� 5�� �Ͻ� ex.9 5): ");
			scanf("%d %d", &ou.month, &ou.day);
			printf("���� �ݾ�(�� ����): ");
			scanf("%d", &ou.money);
			// �ݾ�Ȯ��
			printf("���� �ݾ��� %d �� �½��ϱ�? (Y/N)", ou.money);
			char choice2;
			scanf(" %c", &choice2);
			if(choice2 == 'y' || choice2 == 'Y'){
				system("cls");
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
				printf("�޸� �Է� (ex.�ַ���,��ź� ���): ");
				scanf("%s", ou.memo);
				system("cls");
				int submenu1 = import_menu();
				if (submenu1 == 1) {
					strcpy(ou.pay, "ī��");
				}
				else if (submenu1 == 2) {
					strcpy(ou.pay, "����");
				}
				FILE* fp = fopen("out.bin", "ab");
				fwrite(&ou, sizeof(out), 1, fp);
				fclose(fp);
				printf("���� �Ϸ�!\n");
				system("pause");
			}
			else if (choice2 == 'n' || choice2 == 'N') {
				printf("�ݾ� �Է��� ��� �Ǿ����ϴ�.\n");
				system("pause");
			}
			// else ������ else�ϰ�� �߸��Է��ϼ̽��ϴ� ����ؾ��ϴµ�
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
				printf("�ñ��� ���� �Է����ּ��� : ");
				scanf("%d", &day);
				while (fread(&in, sizeof(income), 1, fp1) > 0) {
					if (day == in.day) {
						totalincome += in.money;
						printf("���ͳ��� %d ��°\n", count++);
						printf("��¥: %d�� %d��\n", in.month, in.day);
						printf("�ݾ�: %d\n", in.money);
						printf("�޸�: %s\n", in.memo);
						printf("-----------------\n");
					}
				}
				while (fread(&ou, sizeof(out), 1, fp2) > 0) {
					if (day == ou.day) {
						totalout += ou.money;
						printf("���⳻�� %d ��°\n", cnt++);
						printf("��¥: %d�� %d��\n", ou.month, ou.day);
						printf("�ݾ�: %d��\n", ou.money);
						printf("Ÿ��: %s\n", ou.type);
						printf("�޸�: %s\n", ou.memo);
						printf("��������: %s\n", ou.pay);
						printf("-----------------\n");
					}
				}
				fclose(fp1);
				fclose(fp2);
				printf("%d�� �� ���� �ݾ�: %d��, �� ���� �ݾ�: %d��\n",day, totalincome, totalout);
				printf("%d�� �� �ջ� �ݾ�: %d��\n",day, totalincome - totalout);
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
				printf("��� ������ ����Ͻðڽ��ϱ�? : ");
				scanf("%d", &month);
				while (fread(&in, sizeof(income), 1, fp1) > 0) {
					if (month == in.month) {
						totalincome += in.money;
						printf("���ͳ��� %d ��°\n", count++);
						printf("��¥: %d�� %d��\n", in.month, in.day);
						printf("�ݾ�: %d\n", in.money);
						printf("�޸�: %s\n", in.memo);
						printf("-----------------\n");
					}
				}
				while (fread(&ou, sizeof(out), 1, fp2) > 0) {
					if (month == ou.month) {
						totalout += ou.money;
						printf("���⳻�� %d ��°\n", cnt++);
						printf("��¥: %d�� %d��\n", ou.month, ou.day);
						printf("�ݾ�: %d��\n", ou.money);
						printf("Ÿ��: %s\n", ou.type);
						printf("�޸�: %s\n", ou.memo);
						printf("��������: %s\n", ou.pay);
						printf("-----------------\n");
					}
				}
				fclose(fp1);
				fclose(fp2);
				printf("%d�� �� ���� �ݾ�: %d��, �� ���� �ݾ�: %d��\n", month, totalincome, totalout);
				printf("%d�� �� �ջ� �ݾ�: %d��\n", month, totalincome - totalout);
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
					printf("���ͳ��� %d ��°\n",count++);
					printf("��¥: %d�� %d��\n",in.month, in.day);
					printf("�ݾ�: %d��\n", in.money);
					printf("�޸�: %s\n", in.memo);
					printf("-----------------\n");
				}
				while (fread(&ou, sizeof(out), 1, fp2) > 0) {
					totalout += ou.money;
					printf("���⳻�� %d ��°\n",cnt++);
					printf("��¥: %d�� %d��\n",ou.month, ou.day);
					printf("�ݾ�: %d��\n", ou.money);
					printf("Ÿ��: %s\n", ou.type);
					printf("�޸�: %s\n", ou.memo);
					printf("��������: %s\n", ou.pay);
					printf("-----------------\n");
				}
				fclose(fp1);
				fclose(fp2);
				printf("�� ���� �ݾ�: %d��, �� ���� �ݾ�: %d��\n", totalincome, totalout);
				printf("�� �ջ� �ݾ�: %d��\n", totalincome - totalout);
				system("pause");
			}
			break;
		case 4: // ����޴� �� �޾Ƽ� ��ü���� ��������, �˻��ؼ� ����?? , �ƴϸ� ���ͳ����� ���� , ���⳻���� ���� �̷��� �ص��ɵ�
			{
			char del;
			printf("�����Ͻðٽ��ϱ�? (Y/N)\n");
			scanf(" %c", &del);

			if (del == 'y' || del == 'Y') {
				FILE* fp1 = fopen("income.bin", "wb");
				FILE* fp2 = fopen("out.bin", "wb");
				fclose(fp1);
				fclose(fp2);
			}
			else if (del == 'n' || del == 'N') {
				printf("���� ��� �ϼ̽��ϴ�.");
				system("pause");
			}
			// else ������ else�ϰ�� �߸��Է��ϼ̽��ϴ� ����ؾ��ϴµ�
			}
			break;
		case 5:
			printf("���α׷��� �����մϴ�.\n");
			printf("���� �Ǽ���~");
			exit(0);
		}
		system("cls");
	}
}


