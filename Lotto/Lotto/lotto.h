#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>


/*확률이 높은 숫자를 출력하는 함수 */
void highcheck_print(int a);
/*확률이 낮은 숫자를 출력하는 함수*/
void lowcheck_print(int a);
/*프로그램을 통해 나온 당첨횟수를 오름차순으로 나열해주는 함수*/
void count_check();
/*로또번호를 생성하는 함수*/
void user_lotto();
/*당첨번호를 출력하는 함수*/
void answer_lotto();
/* 결제종류와 구매한 가격을 출력히는 함수*/
void buy_result(int a, int b);
/*로또를 할껀지 여부를 선택하는 함수*/
void chance(int a);
/*구매한 로또를 1개당 1000원으로 계산하여 총 가격을 추출하는 함수*/
int money_check(int tn);
/*화면 초기화 함수*/
void view_init();
/*a라는 변수 값을 받아 a 횟수 만큼 로또번호를 생성해서 출력하는 함수*/
void auto_print(int a);
/*수동 입력한 로또 번호 값을 출력해주는 함수*/
void manual_print(int a, int* b);
/*수동 입력을 했을 때 로또 번호 6자리를 받는 함수*/
void lotto_manual(int a, int* b);
/*수동입력할지 자동입력할지 여부를 결정하는 함수*/
void auto_lotto(int a, int b);

