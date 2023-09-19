#define __MENU_H__
// 한번만 사용하겟다 . 헤더파일 꼬임(중복)방지
				// 윈도우전용 표준형태 
				// #ifndef __MENU_H__ 
				// #define __MENU_H__
				// ~~~ #endif
typedef enum {
	MAIN_INCOME = 1,	// 수입 메뉴
	MAIN_SPEND,			// 지출 메뉴
	MAIN_CHECK,			// 조회 메뉴
	MAIN_DELETE,		// 삭제 메뉴
	MAIN_EXIT			// 종료
} MAIN_MENU;


extern int main_menu();// extern은 생략가능
extern int import_menu(); 
extern int check_menu();

