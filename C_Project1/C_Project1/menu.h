#define __MENU_H__
// 한번만 사용하겟다 . 헤더파일 꼬임(중복)방지
				// 윈도우전용 표준형태 
				// #ifndef __MENU_H__ 
				// #define __MENU_H__
				// ~~~ #endif
typedef enum {
	MAIN_RAND_INS = 1,	// 랜덤 생성 메뉴
	MAIN_DIR_INS,		// 직접 입력 메뉴
	MAIN_ALL_DEL,		// 전체 삭제
	MAIN_VIEW,			// 전체 보기
	MAIN_SEARCH,		// 검색
	MAIN_DELETE,		// 삭제
	MAIN_UPDATE,		// 수정
	MAIN_EXIT			// 종료
} MAIN_MENU;

extern int main_menu();// extern은 생략가능
extern int import_menu(); 
extern int check_menu();

