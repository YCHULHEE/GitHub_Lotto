#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include <windows.h>


/*확률이 높은 숫자를 출력하는 함수 */
void highcheck_print(int a);
/*번호가 높은 순서대로 출력하는 함수*/
void lowcheck_print(int a);
/*프로그램을 통해 나온 당첨횟수를 오름차순으로 나열해주는 함수*/
void count_check1();
/*프로그램을 통해 나온 당첨횟수를 오름차순으로 나열해주는 함수 */
void count_check2();
/*로또번호를 생성하는 함수*/
void user_lotto();
/*로또를 할껀지 여부를 선택하는 함수*/
void chance(int a);
/*a라는 변수 값을 받아 a 횟수 만큼 로또번호를 생성해서 출력하는 함수*/
void auto_print(int a);
/*수동입력할지 자동입력할지 여부를 결정하는 함수*/
void auto_lotto(int a, int b);
/*가중치를 가지고 로또 번호를 생성하는 함수*/
void change_lotto();
/*가중치를 가진 로또 번호를 출력해주는 함수*/
void change_print(int a);
/*경우의 수를 뽑고 출력해주는 함수*/
void  probaility_value();
/*가중치를 적용하여 확률순으로 정렬하여 출력하는 함수*/
void changecheck1_print(int a);
/*가중치를 적용하여 번호순으로 정렬하여 출력하는 함수*/
void changecheck2_print(int a);
/*가중치를 적용하여 홀수 짝수의 경우의 수를 카운트해주는 함수*/
void even_odd_result(int a, int b, int c);
/*홀수와 짝수의 비율에 따른 확률을 나타내는 함수 */
void odd_even_check_print(int a);
/*조합 함수*/
int comb(int n, int r);
/*짝수 홀수 경우의 수 출력*/
void even_odd_print(int c);
/*글자 위치 지정 해주는 함수*/
void gotoxy(int x, int y);