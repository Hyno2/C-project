#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit()
#include <time.h>	// time()
#include <string.h>	// strcpy()
#include <conio.h>
#include <windows.h>// Sleep()
#include "menu.h"
#include "ui.h"

// ����ü ���� income ����
typedef struct _income {
	int month;
	int day;
	int money;
	char memo[50];
} income;

// ����ü ���� out ����
typedef struct _out {
	int month;
	int day;
	int money;
	char type[20];
	char pay[20];
	char memo[50];
} out;

int main() {
	// �ܼ�â ũ�� ���� 
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 500, 500, TRUE);

	// Ŀ�� ����
	set_cursor_type(NOCURSOR);

	// ��Ʈ���� 
	font_color(LIGHT_GREEN);
	title();
	_getch();
	//Ÿ��Ʋ ���� �ý���Ŭ����
	system("cls");
	
	
	font_color(LIGHT_GRAY);
	set_cursor_type(NORMAL_CURSOR);
	//idc();
	
	while (1) {
		// �� ���� ���� 
		int totalincome = 0;
		// �� ���� ����
		int totalout = 0;
		//����ü income �� ���� in �ʱ�ȭ
		income in = { 0 };
		//����ü out�� ���� ou �ʱ�ȭ
		out ou = { 0 };

	// ���θ޴� ���� ������ ����
		//���� �б�
		FILE* fp1 = fopen("income.bin", "rb");
		FILE* fp2 = fopen("out.bin", "rb");
		while (fread(&in, sizeof(income), 1, fp1) > 0) {
			// �Ѽ��� = �Ѽ��� + ����ü income.money
			totalincome += in.money;
		}
		while (fread(&ou, sizeof(out), 1, fp2) > 0) {
			// ������ = ������ + ����ü income.money
			totalout += ou.money;
		}
		font_color(WHITE);
		printf("�� ���� : %d��\n", totalincome);
		font_color(RED);
		printf("�� ���� : %d��\n", totalout);
		// ���� �Ѽ��� - ������ 0���� Ŭ��
		//-��Ʈ�� �ʷϻ�, ���� �ڻ� ���
		if (totalincome - totalout > 0) {
			font_color(GREEN);
			printf("���� �ڻ� : %d��\n", totalincome - totalout);
		}
		// �ƴϰ� 0�̰ų� ������ 
		//-��Ʈ ����, ���� �ڻ����
		else if (totalincome - totalout <= 0) {
			font_color(RED);
			printf("���� �ڻ� : %d��\n", totalincome - totalout);
		}
		
		// ���θ޴� ���� 
		font_color(WHITE);
		switch (main_menu()) {
			// 1�� ���� ���ý�
		case 1: {
			//����ü income �� ���� in �ʱ�ȭ
			income in = { 0 };
			printf("��¥ �Է� (9�� 5�� �Ͻ� ex.9 5) : ");
			scanf("%d %d", &in.month, &in.day);
			// 230916 �Է¹��� ����(���ѷ��� ����) by Jung
			rewind(stdin);
			// 230914 month������ 1~12���� , day������ 1~31������ �ްԲ� �Ϸ�. 
			// month�� 1�̸� 13�̻��̰ų� day�� 1�̸� 32�̸��϶� �����޼��� �ٽ��Է¹ޱ�
			while (in.month < 1 || in.month >= 13 || in.day < 1 || in.day >= 32) {
				// 230916 �Է¹��� ����(���ѷ��� ����) by Jung
				rewind(stdin);
				printf("�߸��� ��¥ �Է�!\n");
				printf("�ٽ� �Է��� �ּ���.\n");
				printf("��¥ �Է� (9�� 5�� �Ͻ� ex.9 5) : ");
				scanf("%d %d", &in.month, &in.day);				
			}
			
			// �Է±ݾ� Ȯ���� �Է¹ޱ����� ���� select
			int select = 0;

			// Ȯ�� �޼��� �߰� 
			// 23.09.16 while�� ������ �ݾ��Է� ������ �ű�  by Lee
				printf("�ݾ� �Է� : ");
				scanf("%d", &in.money);
				// 230916 �Է¹��� ����(���ѷ��� ����) by Jung
				rewind(stdin);
				while (select != 1) {
				printf("���� Ȯ�Φ�����������������������������������������������������������\n");
				printf("��  �Է��Ͻ� �ݾ��� %d�� �Դϴ�. ��\n", in.money);
				printf("��\t\t(1.��  2.�ƴϿ�)    ��\n");
				printf("��������������������������������������������������������������������������\n");
				printf("  ����: ");
				scanf("%d", &select);
				// 230916 �Է¹��� ����(���ѷ��� ����) by Jung
				rewind(stdin);	
				// �Է°��� 1�ϰ�� �Է¹��� �ݾ�
				if (select == 1) {
					in.money;
				}// 2�ϰ�� �ٽ��Է� �ޱ�
				else if (select == 2) {
					printf("�ݾ��� �ٽ� �Է��� �ּ��� : ");
					scanf("%d", &in.money);
					// 230916 �Է¹��� ����(���ѷ��� ����) by Jung
					rewind(stdin);
				}
				else {
					printf("�߸��� �Է��Դϴ�.\n");
					printf("�ٽ� �Է����ּ���\n");
				}
			}
			//�޸� �Է� 
			printf("�޸� �Է� : ");
			scanf("%s", in.memo);

			// ���Ͽ��� income.bin�� �̾���� ab
			FILE* fp = fopen("income.bin", "ab");
			// fwrite ����in������ income����üũ�⸸ŭ �ѵ�� ����
			fwrite(&in, sizeof(income), 1, fp);
			fclose(fp);
			printf("���Գ��� ������......\n");
			// 23.09.16 ������ �ش� 1000�� 1sec   by Lee
			Sleep(2000);
			printf("���� �Ϸ�!\n");
			system("pause");
		}
			  break;
		case 2: {
			out ou = { 0 };
			printf("��¥ �Է� (9�� 5�� �Ͻ� ex.9 5): ");
			scanf("%d %d", &ou.month, &ou.day);
			// 230916 �Է¹��� ����(���ѷ��� ����) by Jung
			rewind(stdin);
			// 230914 month������ 1~12���� , day������ 1~31������ �ްԲ� �Ϸ�. 
			// month�� 1�̸� 13�̻��̰ų� day�� 1�̸� 32�̸��϶� �����޼��� �ٽ��Է¹ޱ�
			while (ou.month < 1 || ou.month >= 13 || ou.day < 1 || ou.day >= 32) {
				printf("�߸��� ��¥ �Է�!\n");
				printf("�ٽ� �Է��� �ּ���.\n");
				printf("��¥ �Է� (9�� 5�� �Ͻ� ex.9 5): ");
				scanf("%d %d", &ou.month, &ou.day);
			}
			// �ݾ�Ȯ�� �޼��� ���� ����
			int select = 0;
			
			printf("���� �ݾ� : ");
			scanf("%d", &ou.money);
			// 230916 �Է¹��� ����(���ѷ��� ����) by Jung
			rewind(stdin);
			while (select != 1) {
				//  23.09.16 ����ݾ� Ȯ�� �޼��� �߰� by Lee
				printf("���� Ȯ�Φ�����������������������������������������������������������\n");
				printf("��  �Է��Ͻ� �ݾ��� %d�� �Դϴ�. ��\n", ou.money);
				printf("��\t\t(1.��  2.�ƴϿ�)    ��\n");
				printf("��������������������������������������������������������������������������\n");
				printf("  ����: ");
				scanf("%d", &select);
				// 230916 �Է¹��� ����(���ѷ��� ����) by Jung
				rewind(stdin);
				// �Է°��� 1�ϰ�� �Է¹��� �ݾ�
				if (select == 1) {
					ou.money;
				}// 2�ϰ�� �ٽ��Է� �ޱ�
				else if (select == 2) {
					printf("�ݾ��� �ٽ� �Է��� �ּ��� : ");
					scanf("%d", &ou.money);
					// 230916 �Է¹��� ����(���ѷ��� ����) by Jung
					rewind(stdin);
				}
				else {
					printf("�߸��� �Է��Դϴ�.\n");
				}
			}
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
			// �޸��Է�
			printf("�޸� �Է� (ex.�ַ���,��ź� ���): ");
			scanf("%s", ou.memo);

			// ���� ���� �޴� ���� ����
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
			printf("���⳻�� ������......\n");
			// ������ �ֱ� 23.09.16 by Lee
			Sleep(2000);
			printf("���� �Ϸ�!\n");
			system("pause");
		}
			  break;
		case 3:
			system("cls");
			int submenu2 = check_menu();

			// �Ϻ� ��ȸ  ���⼭ �� ���� �Է¹ް� �Է¹��� ���� �ϼ��� ǥ���ϰ� �ؾ� �ҵ� 
			if (submenu2 == 1) {
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

				FILE* fp1 = fopen("income.bin", "rb");
				FILE* fp2 = fopen("out.bin", "rb");

				//�� �Է¹ޱ����� ���� ����
				int day = 0;
				printf("�ñ��� ���� �Է����ּ��� : ");
				scanf("%d", &day);
				// 230916 �Է¹��� ����(���ѷ��� ����) by Jung
				rewind(stdin);
				// ������ �ֱ� 23.09.16 by Lee
				printf("���� �ҷ�������......\n");
				Sleep(2000);

				// 230914 day������ 1~31������ �ްԲ� �Ϸ�. �ƴҽ� ���Է� by jung
				while (day < 1 || day>31) {
					printf("�߸��� ��¥ �Է�!\n");
					printf("�ٽ� �Է��� �ּ���.\n");
					printf("�ñ��� ���� �ٽ� �Է����ּ��� : ");
					scanf("%d", &day);
					// 230916 �Է¹��� ����(���ѷ��� ����) by Jung
					rewind(stdin);
				}

				while (fread(&in, sizeof(income), 1, fp1) > 0) {
					// ���� �Է¹�����¥�� ���� ����ü ���� day ���� ���ٸ�
					if (day == in.day) {
						totalincome += in.money;
						printf("���ͳ��� %d ��°\n", count++);
						printf("��¥ : %d�� %d��\n", in.month, in.day);
						printf("�ݾ� : %d\n", in.money);
						printf("�޸� : %s\n", in.memo);
						printf("-----------------\n");
					}
				}
				while (fread(&ou, sizeof(out), 1, fp2) > 0) {
					if (day == ou.day) {
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

				// �Ϻ� ��ȸ ���
				// 230915 ī��, ���� �� ���ݾ� �߰� by jung
				printf("%d�� ī�� �� ��� �ݾ� : %d��\n", day, card);
				printf("%d�� ���� �� ��� �ݾ� : %d��\n", day, cash);
				printf("%d�� �� ���� �ݾ� : %d��\n", day, totalincome);
				printf("%d�� �� ���� �ݾ� : %d��\n", day, totalout);
				printf("%d�� �� �ջ� �ݾ� : %d��\n", day, totalincome - totalout);
				system("pause");
			}
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
				
				FILE* fp1 = fopen("income.bin", "rb");
				FILE* fp2 = fopen("out.bin", "rb");
				int month = 0;
				printf("�� �� ������ ����Ͻðڽ��ϱ�? : ");
				scanf("%d", &month);
				// 230916 �Է¹��� ����(���ѷ��� ����) by Jung
				rewind(stdin);
				// ������ �ֱ� 23.09.16 by Lee
				printf("���� �ҷ�������......\n");
				Sleep(2000);

				// 230914 month������ 1~12������ �ްԲ� �Ϸ�. by jung
				while (month < 1 || month > 12 ) {
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
			
			// ��ü ���� ��ȸ
			if (submenu2 == 3) {
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
				// ������ �ֱ� 23.09.16 by Lee
				printf("���� �ҷ�������......\n");
				Sleep(2000);
				FILE* fp1 = fopen("income.bin", "rb");
				FILE* fp2 = fopen("out.bin", "rb");
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
				fclose(fp1);
				fclose(fp2);
				// 230915 ī��, ���� �� ���ݾ� �߰� by jung
				printf("ī�� �� ��� �ݾ�: %d��\n", card);
				printf("���� �� ��� �ݾ�: %d��\n", cash);
				printf("�� ���� �ݾ�: %d��\n", totalincome);
				printf("�� ���� �ݾ�: %d��\n", totalout);
				printf("�� �ջ� �ݾ�: %d��\n", totalincome - totalout);
				system("pause");
			}
			break;
		case 4: // ����޴� �� �޾Ƽ� ��ü���� ��������, �˻��ؼ� ����?? , 
				// �ƴϸ� ���ͳ����� ���� , ���⳻���� ���� �̷��� �ص��ɵ�
			{
			char del;
			printf("�����Ͻðٽ��ϱ� Y/N\n");
			scanf(" %c", &del);

			if (del == 'y' || del == 'Y') {
				FILE* fp1 = fopen("income.bin", "wb");
				FILE* fp2 = fopen("out.bin", "wb");
				fclose(fp1);
				fclose(fp2);
				// ������ �ֱ� 23.09.16 by Lee
				printf("������ ������......\n");
				Sleep(2000);
				printf("�����Ϸ�!\n");
				// 23.09.16 by Lee
				system("pause");
			}
			else if (del == 'n' || del == 'N') {
				printf("���� ��� �ϼ̽��ϴ�.");
				// �߰� 23.09.16 by Lee
				system("pause");
			}
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


