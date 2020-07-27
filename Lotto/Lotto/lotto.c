#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include "lotto.h"
#include <windows.h>

int ary[6] = { 0, };  // 로또번호 6개를 표현할 때 공통적으로 사용되는 변수.

int manual_aray[] = { 0, }; // 수동 입력의 로또번호를 담는 변수
int lotto_number[45] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 ,15 ,16 ,17, 18, 19, 20, 21, 22, 23, 24, 25,
    26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 }; //로또 번호를 저장하는 변수.
int x = 23; //타이틀화면이 표시되는 x좌표 
int y = 4; //타이틀화면이 표시되는 y좌표 
/*당첨횟수와 로또번호를 담는 구조체*/
struct Lotto {
    int count1; // 당첨횟수를 저장한 변수
    int count2; // 당첨횟수를 선택정렬로 정리하여 저장한 변수
    int number1; // 당첨횟수를 가르키는 로또번호의 주소
    int number2; // 선택정렬로 정리한 당첨횟수를 가르키는 로또번호의 주소
    int sp_num;
};
/* 홀수 짝수 가중치 담는 구조체  짝수_홀수_카운트 예) six_zero 일 경우 짝수 6 홀수 0  */
struct Weight {
    int six_zero_count; 
    int five_one_count;
    int four_two_count;
    int three_three_count;
    int two_four_count;
    int one_five_count;
    int zero_six_count;
    int total_count;
};
struct Weight weight[1]; // 가중치 구조체를 선언하여 weight 이름으로 구조체 변수 선언

struct Lotto list[45]; /* 로또번호와 당첨횟수를 담는 구조체를 list 이름으로 45개의 구조체 변수 선언 
                       45개로 선언한 이유는 로또번호 1에서 45까지 담을 구조체를 만들기 위해서이다.*/
struct Lotto list2[45];

void highcheck_print(int a) // 확률이 높은 숫자를 출력하는 함수
{
    int j = 5;  
    /*gotoxy(x, y + 4);*/ printf("\n확률 순으로 정렬\n");
    for (int i = 44; i >= 0; i--) {
        /*gotoxy(x, y + j);*/ printf("번호: %d번\t 당첨횟수 : %d \t당첨확률 : %.2f%% \n", list[i].number2, list[i].count2, (double)list[i].count2 / (a * 6) * 100);
        j++;
    }
}

void lowcheck_print(int a) // 로또 번호 순으로 출력하는 함수
{
    printf("\n로또 번호순으로 정렬\n");
    for (int i = 0; i < 45; i++)
        printf("번호: %d번\t 당첨횟수 : %d \t당첨확률 : %.2f%%  \n", list[i].number1, list[i].count1,(double)list[i].count1 / (a * 6) * 100);
}

void changecheck1_print(int a) // 확률이 높은 숫자를 출력하는 함수
{
    printf("\n확률 순으로 정렬\n\t가중치를 적용해서 1회 반복한 빈도와 확률\t\t\t로또 당첨 번호의 빈도와 확률\n");
    for (int i = 44; i >= 0; i--)
        printf("번호: %d번\t 당첨횟수 : %d \t당첨확률 : %.2f%%  번호: %d번\t 당첨횟수 : %d \t당첨확률 : %.2f%%\n",
            list2[i].number2, list2[i].count2, (double)list2[i].count2 / (a * 6) * 100, list[i].number2, list[i].count2, (double)list[i].count2 / (a * 6) * 100);
}

void changecheck2_print(int a) // 로또 숫자 대로 출력
{
    printf("\n번호 순으로 정렬\n\t가중치를 적용해서 1회 반복한 빈도와 확률\t\t\t로또 당첨 번호의 빈도와 확률\n");
    for (int i = 0; i < 45; i++)
        printf("번호: %d번\t 당첨횟수 : %d \t당첨확률 : %.2f%%  번호: %d번\t 당첨횟수 : %d \t당첨확률 : %.2f%%\n", 
            list2[i].number1, list2[i].count1, (double)list2[i].count1 / (a * 6) * 100, list[i].number1, list[i].count1, (double)list[i].count1 / (a * 6) * 100);
            
}   

void odd_even_check_print(int a) // 가중치를 적용한 홀짝의 확률과 갯수 출력하는 함수
{
    printf("\n가중치 적용후 나온 홀짝 확률\n");
    printf("홀수 6 짝수 0 : %.2f%%\t%d개 \n홀수 5 짝수 1 : %.2f%%\t%d개\n홀수 4 짝수 2 : %.2f%%\t%d개\n홀수 3 짝수 3 : %.2f%%\t%d개\n홀수 2 짝수 4 : %.2f%%\t%d개\n홀수 1 짝수 5 : %.2f%%\t%d개\n홀수 0 짝수 6 : %.2f%%\t%d개\n전체 횟수 : %d \n",
        ((double)weight[0].zero_six_count / weight[0].total_count) * 100, weight[0].zero_six_count, ((double)weight[0].one_five_count / weight[0].total_count) * 100,
        weight[0].one_five_count, ((double)weight[0].two_four_count / weight[0].total_count) * 100, weight[0].two_four_count,
            ((double)weight[0].three_three_count / weight[0].total_count) * 100, weight[0].three_three_count, ((double)weight[0].four_two_count / weight[0].total_count) * 100,
                weight[0].four_two_count, ((double)weight[0].five_one_count / weight[0].total_count) * 100, weight[0].five_one_count,
                    ((double)weight[0].six_zero_count / weight[0].total_count) * 100, weight[0].six_zero_count, weight[0].total_count);

}

void count_check1() // 프로그램을 통해 나온 당첨횟수를 오름차순으로 나열해주는 함수
{
    int i, j;
    int temp;
    for (i = 0; i < 45; i++) // 로또번호와 당첨횟수를 count1에서 count2로 옴기는 반복문
    {
        list[i].count2 = list[i].count1;
        list[i].number2 = list[i].number1;
        for (j = 0; j < i; j++) // 당첨횟수를 비교하여 오름차순으로 나열한다.
        {
            if (list[i].count2 <= list[j].count2) 
            {
                temp = list[i].count2;
                list[i].count2 = list[j].count2;
                list[j].count2 = temp;
                temp = list[i].number2;
                list[i].number2 = list[j].number2;
                list[j].number2 = temp;
            }
        }
    }
}

void count_check2() // 프로그램을 통해 나온 당첨횟수를 오름차순으로 나열해주는 함수
{
    int i, j;
    int temp;
    for (i = 0; i < 45; i++) // 로또번호와 당첨횟수를 count1에서 count2로 옴기는 반복문
    {
        list2[i].count2 = list2[i].count1;
        list2[i].number2 = list2[i].number1;
        for (j = 0; j < i; j++) // 당첨횟수를 비교하여 오름차순으로 나열한다.
        {
            if (list2[i].count2 <= list2[j].count2)
            {
                temp = list2[i].count2;
                list2[i].count2 = list2[j].count2;
                list2[j].count2 = temp;
                temp = list2[i].number2;
                list2[i].number2 = list2[j].number2;
                list2[j].number2 = temp;
            }
        }
    }
}

void user_lotto() //로또번호를 생성하는 함수
{
    int i, j, o;
    int temp;
    int ary[6] = { 0, };
    for (i = 0; i < 6; i++) // 로또 번호 6개를 뽑고 뽑을 때마다 짝수인지 홀수인지 비교하여 변수에 저장한다.
    {
        ary[i] = rand() % 45 + 1;
        /*if (ary[i] % 2 == 0)
            even_number++;
        else if (ary[i] % 2 == 1)
            odd_number++;*/

        for (o = 0; o < 45; o++) // 로또번호의 당첨횟수를 증가시키는 반복문
        {
            list[o].number1 = o + 1;
            if (ary[i] == list[o].number1)
                list[o].count1++;
        }

        for (j = 0; j < i; j++) // 로또 번호가 나왔을 때 오름차순으로 정렬시켜주는 반복문
        {
            if (ary[i] < ary[j])
            {
                temp = ary[i];
                ary[i] = ary[j];
                ary[j] = temp;
            }

            if (ary[i] == ary[j]) // 중복일시 당첨횟수를 줄이고 짝수 홀수 카운팅횟수를 줄이는 조건문
            {
                for (o = 0; o < 45; o++)
                {
                    if (ary[i] == list[o].number1) {
                        list[o].count1--;
                        /*if (ary[i] % 2 == 0)
                            even_number--;
                        else if (ary[i] % 2 == 1)
                            odd_number--;*/
                    }
                }
                i--;
            }
        }
    }

    for (int i = 0; i < 6; i++) // 생성된 로또번호를  출력하는 반복문
    {
        printf("[%d] ", ary[i]);
        if (i == 6) {
            printf("\n");
            break;
        }
    }
}

void even_odd_print(int c)
{
    int on = 0; // 홀수 변수
    int en = 0; // 짝수 변수
    int sum;
    while (1) {
        printf("\n짝수 홀수를 대입하여 로또번호를 추출\n");
        printf("짝수 홀수의 합이 6여야 합니다.\n");
        printf("짝수를 입력해주세요.");
        scanf("%d", &en);
        printf("\n홀수를 입력해주세요.");
        scanf("%d", &on);
        sum = en + on;
        if (sum == 6) {
            printf("로또번호는 ");
            even_odd_result(en, on, c);
            printf("입니다. \n");
        }
    }
}

void even_odd_result(int a, int b, int c) {
        

    int i, j, o, value, num =0;
    int temp;
    int even_number = a; // 짝수 변수
    int odd_number = b; // 홀수 변수
    int ary[6] = { 0, };
    int sum;

    sum = even_number + odd_number;

    for (i = 0; i < even_number; i++) // 로또 번호 6개를 뽑고 뽑을 때마다 짝수인지 홀수인지 비교하여 변수에 저장한다.
    {
        if (sum == 6) {
            ary[i] = rand() % (c * 6) + 1;
            value = ary[i];
            int temp = 0;
            for (int i = 0; i < 45; i++) {
                temp += list[i].count1;
                list[i].sp_num = temp;
            }

            if (value <= list[0].count1) {
                num = 1;
            }
            for (int p = 1; p < 45; p++) {
                if (list[p - 1].sp_num < value && value <= list[p].sp_num) {
                    num = p + 1;
                    break;
                }
            }
            ary[i] = num;

            if ((ary[i] % 2) == 1) {
                i--;
                continue;
            }

            for (o = 0; o < 45; o++) // 로또번호의 당첨횟수를 증가시키는 반복문
            {
                list[o].number1 = o + 1;
                if (ary[i] == list[o].number1)
                    list[o].count1++;
            }

            for (j = 0; j < i; j++) // 로또 번호가 나왔을 때 오름차순으로 정렬시켜주는 반복문
            {
                if (ary[i] < ary[j])
                {
                    temp = ary[i];
                    ary[i] = ary[j];
                    ary[j] = temp;
                }

                if (ary[i] == ary[j]) // 중복일시 당첨횟수를 줄이고 짝수 홀수 카운팅횟수를 줄이는 조건문
                {
                    for (o = 0; o < 45; o++)
                    {
                        if (ary[i] == list[o].number1) {
                            list[o].count1--;
                            /*if (ary[i] % 2 == 0)
                                even_number--;
                            else if (ary[i] % 2 == 1)
                                odd_number--;*/
                        }
                    }
                    i--;
                }
            }
        }
    }

    for (i=even_number; i < 6; i++) // 로또 번호 6개를 뽑고 뽑을 때마다 짝수인지 홀수인지 비교하여 변수에 저장한다.
    {
        if (sum == 6) {
            ary[i] = rand() % 45 + 1;
            if ((ary[i] % 2) == 0) {
                i--;
                continue;
            }

            for (o = 0; o < 45; o++) // 로또번호의 당첨횟수를 증가시키는 반복문
            {
                list[o].number1 = o + 1;
                if (ary[i] == list[o].number1)
                    list[o].count1++;
            }

            for (j = 0; j < i; j++) // 로또 번호가 나왔을 때 오름차순으로 정렬시켜주는 반복문
            {
                if (ary[i] < ary[j])
                {
                    temp = ary[i];
                    ary[i] = ary[j];
                    ary[j] = temp;
                }

                if (ary[i] == ary[j]) // 중복일시 당첨횟수를 줄이고 짝수 홀수 카운팅횟수를 줄이는 조건문
                {
                    for (o = 0; o < 45; o++)
                    {
                        if (ary[i] == list[o].number1) {
                            list[o].count1--;
                            /*if (ary[i] % 2 == 0)
                                even_number--;
                            else if (ary[i] % 2 == 1)
                                odd_number--;*/
                        }
                    }
                    i--;
                }
            }
        }
    }
    for (int i = 0; i < 6; i++) // 생성된 로또번호를  출력하는 반복문
    {
        if (sum == 6) {
            printf("[%d] ", ary[i]);
            if (i == 6) {
                printf("\n");
                break;
            }
        }
    }       
}

void change_lotto(int a) //로또번호를 생성하는 함수
{
    int i, j, o, num = 0;
    int value;
    int temp;
    int odd_number = 0; // 홀수 변수
    int even_number = 0; // 짝수 변수
    int ary[6] = { 0, };
    for (i = 0; i < 6; i++) // 로또 번호 6개를 뽑고 뽑을 때마다 짝수인지 홀수인지 비교하여 변수에 저장한다.
    {
        ary[i] = rand() % (a*6) + 1;
        value = ary[i];
        int temp = 0;
        for (int i = 0; i < 45; i++) {
            temp += list[i].count1;
            list[i].sp_num = temp;
        }

        if (value <= list[0].count1) {
            num = 1;
        }
        for (int p = 1; p < 45; p++) {
            if (list[p - 1].sp_num < value && value <= list[p].sp_num) {
                num = p + 1;
                break;
            }
        }
        ary[i] = num;

        if (ary[i] % 2 == 0)
            even_number++;
        else if (ary[i] % 2 == 1)
            odd_number++;

        for (o = 0; o < 45; o++) // 로또번호의 당첨횟수를 증가시키는 반복문
        {
            list2[o].number1 = o + 1;
            if (ary[i] == list2[o].number1)
                list2[o].count1++;
        }

        for (j = 0; j < i; j++) // 로또 번호가 나왔을 때 오름차순으로 정렬시켜주는 반복문
        {
            if (ary[i] < ary[j])
            {
                temp = ary[i];
                ary[i] = ary[j];
                ary[j] = temp;
            }

            if (ary[i] == ary[j]) // 중복일시 당첨횟수를 줄이고 짝수 홀수 카운팅횟수를 줄이는 조건문
            {
                for (o = 0; o < 45; o++)
                {
                    if (ary[i] == list2[o].number1) {
                        list2[o].count1--;
                        if (ary[i] % 2 == 0)
                            even_number--;
                        else if (ary[i] % 2 == 1)
                            odd_number--;
                    }
                }
                i--;
            }
        }
        if (i == 5) // 짝수 홀수 나오는 횟수를 가지고 경우의 수를 구별하는 조건문
        {
            if (even_number == 6 && odd_number == 0)
                weight[0].six_zero_count++;
            else if (even_number == 5 && odd_number == 1)
                weight[0].five_one_count++;
            else if (even_number == 4 && odd_number == 2)
                weight[0].four_two_count++;
            else if (even_number == 3 && odd_number == 3)
                weight[0].three_three_count++;
            else if (even_number == 2 && odd_number == 4)
                weight[0].two_four_count++;
            else if (even_number == 1 && odd_number == 5)
                weight[0].one_five_count++;
            else if (even_number == 0 && odd_number == 6)
                weight[0].zero_six_count++;
        }
    }
    weight[0].total_count = weight[0].six_zero_count + weight[0].five_one_count + weight[0].four_two_count +
        weight[0].three_three_count + weight[0].two_four_count + weight[0].one_five_count + weight[0].zero_six_count; //홀 짝 경우의 수 카운팅

    for (int i = 0; i < 6; i++) // 생성된 로또번호를  출력하는 반복문
    {
        printf("[%d] ", ary[i]);
        if (i == 6) {
            printf("\n");
            break;
        }
    }
}

void chance(int a) // 로또를 할껀지 여부를 선택하는 함수
{
    switch (a) {
    case 'y':
        break;
    case 'n':
        main();
        break;
    default:
        main();
        break;
    }
}

void auto_print(int a) // a라는 변수 값을 받아 a 횟수 만큼 로또번호를 생성해서 출력하는 함수
{
    for (int i = 1; i < 10001; i++)
    {
        if (a >= i) {
            printf("[%d]번째 로또번호: ", i);
            user_lotto(); //로또 생성하는 함수
            printf("\n");
        }
    }
}

void change_print(int a) // a라는 변수 값을 받아 a 횟수 만큼 로또번호를 생성해서 출력하는 함수
{
    for (int i = 1; i < a+1; i++)
    {
        if (a >= i) {
            printf("[%d]번째 로또번호: ", i);
            change_lotto(a); //로또 생성하는 함수
            printf("\n");
        }
    }

}

void auto_lotto(int a, int b) // 수동입력할지 자동입력할지 여부를 결정하는 함수
{
    switch (a) {
    case 1:
        auto_print(b);
        break;
    default :
        printf("오류 다시 하시오.");
        main();
        break;
    }
}

int comb(int n, int r)//조합 함수
{
    if (n == r || r == 0)
        return 1;
    return comb(n - 1, r - 1) + comb(n - 1, r);//n-1Cr-1+n-1Cr=nCr
}

void probaility_value() // 경우의수 추출하는 함수
{
    int value;
    value = comb(45, 6);//로또당첨확률(45중에서 6개의 숫자를 순서 상관없이 추출하는 경우의 수)
    printf("수학적 홀짝 숫자에 따른 확률\n");
    printf("로또 당첨확률:%d\n", value);
    int com[7] = { 0, };
    for (int k = 0; k < 7; k++) {
        com[k] = comb(23, 6 - k) * comb(22, k);
    }
    for (int r = 0; r < 7; r++) {
        printf("홀수 %d개 짝수 %d개의 확률: %.2f%%   %d개\n", 6 - r, r, ((double)com[r]/value)*100, com[r]);
    }
}

void gotoxy(int x, int y) { //gotoxy함수 
    COORD pos = { 2 * x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void screen_reset() {
    for (int i = 0; i < 30; i++)
        printf("\n\n");
}
