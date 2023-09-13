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


// 수입 메뉴 파일을 불러오고 쓰는 함수
void file_import(char filename[]) {
	FILE* fp = fopen(filename, "ab");
	if (fp == NULL) {
		printf("파일 오픈 실패!\n");
		return;
	}
	//fwrite 사용해 쓰기
	fclose(fp);
}
// 지출 메뉴 파일 불러오고 쓰는 함수

// 조회 메뉴 파일 불러오고 쓰는 함수
