#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "menu.h"

int main_menu()
{
	printf("=============================\n");
	printf("         �� �� ��\n");
	printf("=============================\n");
	printf("1.����\n");
	printf("2.����\n");
	printf("3.��ȸ\n");
	printf("4.����\n");
	printf("=============================\n");
	printf("�޴� ����:");
	int menu;
	scanf("%d", &menu);
	return menu;
}

int import_menu()
{
	printf("=============================\n");
	printf("�з� �׸� ����\n");
	printf("=============================\n");
	printf("1.ī��\n");
	printf("2.����\n");
	printf("3.������\n");
	printf("=============================\n");
	printf("�Է� ��ȣ :");
	int menu;
	scanf("%d", &menu);
	return menu;
}

int check_menu()
{
	printf("=============================\n");
	printf("1.�Ϻ��� ��ȸ\n");
	printf("2.������ ��ȸ\n");
	printf("3.��ü���� ��ȸ\n");
	printf("4.������\n");
	printf("=============================\n");
	int menu;
	scanf("%d", &menu);
	return menu;
}