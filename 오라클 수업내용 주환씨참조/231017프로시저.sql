-- 프로시저 : 함수와 유사한 형태, DB에서 실행할 수 있는 코드 블럭
--       프로그래밍 논리 수행 가능 (복잡하니 구체적으로 다루진 않겠다)

-- 프로시저 선언 방식
-- OR REPLACE 안 쓰면, 동일한 이름의 프로시저 사용이 불가능하다
--CREATE OR REPLACE PROCEDURE 프로시저명
--(
--    매개변수 (IN, OUT, INOUT)
--)
--IS
--    변수선언
--BEGIN
--    프로시저 본문
--END 프로시저명;

-- 사원 테이블 생성
CREATE TABLE EMPLOYEE(
    NUM VARCHAR2(10) PRIMARY KEY, -- 기본키 설정
    NAME VARCHAR(20),
    AGE INT,
    DEPART VARCHAR2(5)
);

-- 부서 테이블 생성
CREATE TABLE DEPART(
    DEPART_NUM VARCHAR2(5), -- 외래키 설정
    NAME VARCHAR2(20),
    ----제약조건 PK_NUM으로 인해 DEPART_NUM이 기본키가 되었다.
    CONSTRAINT PK_NUM PRIMARY KEY(DEPART_NUM)
);
-- EMPLOYEE의 DEPART-> DEPART의 DEPART_NUM으로 참조
ALTER TABLE EMPLOYEE ADD CONSTRAINT FK_CODE 
FOREIGN KEY(DEPART) REFERENCES DEPART(DEPART_NUM);

-- 사원에 대한 데이터 추가
-- INSERT문으로 데이터 추가해왔지만, 프로시저를 구현해서 데이터 추가해보기
-- 프로시저 호출 -> EXEC 프로시저명(정보1,정보2, ...);
EXEC ADD_DEPART('1','교무부');
EXEC ADD_DEPART('2','경영지원부');
EXEC ADD_DEPART('3','취업지원부');
EXEC ADD_DEPART('4','행정부');

EXEC add_emplo('525','이현오',32,'1');
EXEC add_emplo('497','박지영',30,'4');
EXEC add_emplo('490','박준현',40,'3');
EXEC add_emplo('500','곽태원',30,'2');
EXEC add_emplo('450','정효미',35,'2');
EXEC add_emplo('499','정제원',27,'1');
EXEC add_emplo('511','박준현',40,'4');

-- JOIN : 2개이상의 테이블을 공통된 열로 묶음
-- JOIN ON 
SELECT *
FROM EMPLOYEE E JOIN DEPART D
ON E.DEPART =D.DEPART_NUM;

-- FROM 묶인 테이블명 WHERE 공통된칼럼1 = 공통된칼럼2
SELECT NUM 부서번호, EMPLOYEE.NAME 이름, AGE 나이, DEPART.NAME 부서명 
FROM DEPART, EMPLOYEE WHERE DEPART_NUM = EMPLOYEE.DEPART;


