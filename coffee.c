#include <stdio.h>
#include <stdlib.h>	// exit()
#include <time.h>	// time()
#include <string.h>	// strcpy()
#include <windows.h>// win32 api ��� (������ ȯ�濡���� ��� ����)
#include <conio.h>
void title();
void gotoxy(int x, int y);

int  main(void)
{
	title();
};
void title()
{
	int x = 5;
	int y = 3;
	gotoxy(x, y + 0); printf("	�����������������������");
	gotoxy(x + 8, y + 1); printf("��			���� ��������������������");
	gotoxy(x + 3, y + 2); printf("��							��");
	gotoxy(x+3,y + 1); printf("��						��");
	gotoxy(x + 3, y + 4); printf("��							��");
	gotoxy(x + 4, y + 5); printf("��						��������");
	gotoxy(x+	4 , y + 2); printf("		��			��������");
	gotoxy(x + 5, y + 2); printf("	��				�����");
	gotoxy(x + 10, y + 2); printf("	������������				��");
	
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	// ������ �ֿܼ��� Ŀ�� ��ġ �̵�
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


