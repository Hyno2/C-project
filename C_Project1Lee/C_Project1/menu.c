#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "menu.h"
#include "file.h"
// ���� �޴�
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
// ���θ޴� 1�� ����
int import_menu(char filename) {
	FILE* fp = fopen(filename, "wb");
	if (fp == NULL) {
		printf("���� ���� ����!\n");
		return;
	}
	printf("")
}
//�޴� 2�� ���� �޴�
int spend_menu()
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
//�޴� 3�� ��ȸ �޴�
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

