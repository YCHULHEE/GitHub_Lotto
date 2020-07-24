#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include "lotto.h"
#include <windows.h>


int main(void)
{
    static int number = 1; // 로또 회차 담는 변수
    static int total = 578422000; // 로또 총 금액 담는 변수
    int tn, mn; // 로또 변수
    static int hm = 0; // 결제 금액 담는 변수
    char qs; // y/n 값 받는 변수
    int at_num; // 수동 자동 저장하는 변수
    int manual_aray[] = { 0, }; // 저장되는 변수
    int x = 23; //타이틀화면이 표시되는 x좌표 
    int y = 4; //타이틀화면이 표시되는 y좌표 
    int cnt; //타이틀 프레임을 세는 변수  
    srand((unsigned)time(NULL));  //시간을 이용한 시드값 설정하는 함수
    while (1) {

        SetConsoleTitle("Lotto Program");
        system("mode con cols=120 lines=48");
        system("color E");
        gotoxy(x, y + 0); printf("■□□□■■■□□■■□□■■"); Sleep(100);
        gotoxy(x, y + 1); printf("■■■□  ■□□    ■■□□■"); Sleep(100);
        gotoxy(x, y + 2); printf("□□□■              □■  ■"); Sleep(100);
        gotoxy(x, y + 3); printf("■■□■■  □  ■  □□■□□"); Sleep(100);
        gotoxy(x, y + 4); printf("■■  ■□□□■■■□■■□□"); Sleep(100);
        gotoxy(x, y + 5); printf("■■■■Lotto Program■■■■"); Sleep(100);
        gotoxy(x, y + 6); printf("■□□□■■■□□■■□□■■"); Sleep(100);
        gotoxy(x, y + 7); printf("■■■□  ■□□    ■■□□■"); Sleep(100);
        gotoxy(x, y + 8); printf("□□□■              □■  ■"); Sleep(100);
        gotoxy(x, y + 9); printf("■■□■■  □  ■  □□■□□"); Sleep(100);
        gotoxy(x, y + 10); printf("■■  ■□□□■■■□■■□□\n"); Sleep(100);
        gotoxy(x, y + 11); printf("-----------%dround-------------\n", number); Sleep(100);
        gotoxy(x, y + 12); printf("----로또 1등 산출 프로그램----\n"); Sleep(100);
        gotoxy(x, y + 13); printf("로또 회차를 입력해주세요.\n"); Sleep(100);
        gotoxy(x, y + 14); scanf("%d", &tn); // 로또 회차
  
        gotoxy(x, y + 15); printf("1.\t자동 입력\n");
        gotoxy(x, y + 16); scanf("%d", &at_num);
        gotoxy(x, y + 17); printf("------------------------------\n");
        gotoxy(x, y + 18); printf("------------------------------\n");
        gotoxy(x, y + 19); printf("일확천금의 기회를 노리시겠습니까?(y/n)\n");
        gotoxy(x, y + 20); scanf(" %c", &qs); // 로또할 의사를 받는 변수
        chance(qs);
        gotoxy(x, y); auto_lotto(at_num, tn);
        getch();
        count_check1();
        getch(); // 잠시 프로그램 동작을 멈추는 함수
        highcheck_print(tn);
        getch();
        lowcheck_print(tn);
        getch();
        
        /*print_chance(void);*/
        change_print(tn);
        count_check2();
        getch();
        changecheck1_print(tn);
        getch();
        changecheck2_print(tn);
        getch();
        printf("\n\n\n");
        probaility_value();
        getch();
        odd_even_check_print(tn);
        getch();
        even_odd_print(tn);
        getch();
        number++;
        hm = 0;
        qs = 'n';
        rewind(stdin); // scanf 버퍼 초기화!
        system("cls");
    }
}
