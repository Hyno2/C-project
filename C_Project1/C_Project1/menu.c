#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "menu.h"


int menuInput(int start, int end)
{
	int menu;
	scanf("%d", &menu);
	while (1)
	{
		if (menu < start || menu>end)
		{
			// �Է� ���� ���� 
			rewind(stdin);
			printf("�ٽ� �Է����ּ���.");
			scanf("%d", &menu);
			continue;
		}
		break;

	}
	return menu;
}
void printMenu()
{
	printf("=============================\n");
	printf("         �� �� ��\n");
	printf("=============================\n");
	printf("1.����\n");
	printf("2.����\n");
	printf("3.��ȸ\n");
	printf("4.����\n");
	printf("5.����\n");
	printf("=============================\n");
	printf("�޴� ����:");
}
int main_menu()
{
	printMenu();
//	menuInput(1, 5);
	//int menu;
	//scanf("%d", &menu);
	//while (1)
	//{
	//	if (menu < 1 || menu>5)
	//	{
	//		// �Է� ���� ���� 
	//		rewind(stdin);
	//		printf("�ٽ� �Է����ּ���.");
	//		scanf("%d", &menu);
	//		continue;
	//	}
	//	break;

	//}
	return menuInput(1, 5);
}

int type_menu()
{
	printf("=============================\n");
	printf("�з� �׸� ����\n");
	printf("=============================\n");
	printf("1.�ĺ�\n");
	printf("2.�ְ� / ���\n");
	printf("3.�Ǻ� / �̿�\n");
	printf("4.�ǰ� / ��ȭ\n");
	printf("5.���� / ����\n");
	printf("6.���� / ����\n");
	printf("7.��Ÿ\n");
	printf("=============================\n");
	printf("�Է� ��ȣ :");
//	int menu;
//	scanf("%d", &menu);
//	return menu;
	return menuInput(1, 7);
}

int import_menu()
{
	printf("=============================\n");
	printf("���� ���� ����\n");
	printf("=============================\n");
	printf("1.ī��\n");
	printf("2.����\n");
	printf("=============================\n");
	printf("�Է� ��ȣ :");
//	int menu;
//	scanf("%d", &menu);
//	return menu;
	return menuInput(1, 2);
}

int check_menu()
{
	printf("=============================\n");
	printf("1.�Ϻ��� ��ȸ\n");
	printf("2.������ ��ȸ\n");
	printf("3.��ü���� ��ȸ\n");
	printf("4.������\n");
	printf("=============================\n");
//	int menu;
//	scanf("%d", &menu);
//	return menu;
	return menuInput(1, 4);
}

