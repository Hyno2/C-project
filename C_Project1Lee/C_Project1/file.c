#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// exit()
#include <time.h>	// time()
#include <string.h>	// strcpy()
#include <conio.h>
#include <windows.h>// Sleep()
#include "menu.h"
#include "ui.h"
#include "id.h"


// ���� �޴� ������ �ҷ����� ���� �Լ�
void file_import(char filename[]) {
	FILE* fp = fopen(filename, "ab");
	if (fp == NULL) {
		printf("���� ���� ����!\n");
		return;
	}
	//fwrite ����� ����
	fclose(fp);
}
// ���� �޴� ���� �ҷ����� ���� �Լ�

// ��ȸ �޴� ���� �ҷ����� ���� �Լ�
