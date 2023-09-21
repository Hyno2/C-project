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
			// 입력 버퍼 비우기 
			rewind(stdin);
			printf(" 다시 입력해주세요 : ");
			scanf("%d", &menu);
			continue;
		}
		break;

	}
	return menu;
}

void printMenu()
{
	printf("┌────────────────────────────┐\n");
	printf("│          가 계 부          │\n");
	printf("├────────────────────────────┤\n");
	printf("│ ① 수입                    │\n");
	printf("│ ② 지출                    │\n");
	printf("│ ③ 조회                    │\n");
	printf("│ ④ 삭제                    │\n");
	printf("│ ⑤ 종료                    │\n");
	printf("└────────────────────────────┘\n");
	printf(" ▶ 메뉴 선택 : ");
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
	//		// 입력 버퍼 비우기 
	//		rewind(stdin);
	//		printf("다시 입력해주세요.");
	//		scanf("%d", &menu);
	//		continue;
	//	}
	//	break;

	//}
	return menuInput(1, 5);
}

int type_menu()
{
	printf("┌────────────────────────────┐\n");
	printf("│        분류 항목 선택      │\n");
	printf("├────────────────────────────┤\n");
	printf("│ ① 식비 \t");
	printf("② 주거, 통신│\n");
	printf("│ ③ 의복, 미용\t");
	printf("④ 건강, 문화│\n");
	printf("│ ⑤ 교육, 육아\t");
	printf("⑥ 교통, 차량│\n");
	printf("│ ⑦ 기타 \t\t     │\n");
	printf("└────────────────────────────┘\n");
	printf(" ▶ 입력 번호 : ");
//	int menu;
//	scanf("%d", &menu);
//	return menu;
	return menuInput(1, 7);
}

int import_menu()
{
	printf("┌────────────────────────────┐\n");
	printf("│      지불 수단 선택        │ \n");
	printf("├────────────────────────────┤\n");
	printf("│ ① 카드                    │\n");
	printf("│ ② 현금                    │\n");
	printf("└────────────────────────────┘\n");
	printf(" ▶ 입력 번호 :");
//	int menu;
//	scanf("%d", &menu);
//	return menu;
	return menuInput(1, 2);
}

int check_menu()
{
	printf("┌────────────────────────────┐\n");
	printf("│ ① 일별로 조회             │\n");
	printf("│ ② 월별로 조회             │\n");
	printf("│ ③ 전체내역 조회           │\n");
	printf("│ ④ 나가기                  │\n");
	printf("└────────────────────────────┘\n");
	printf(" ▶ 입력 번호 : ");
//	int menu;
//	scanf("%d", &menu);
//	return menu;
	return menuInput(1, 4);
}

