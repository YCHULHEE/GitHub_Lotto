#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
int ary[7] = { 0, };
int manual_aray[] = { 0, }; // 저장되는 변수
/*int ary[][7] = { 0, };
int lotto_value(int a)
{
    int ary[][7] = { 0, };
    int i, j, o;
    int ary1[][7] = { 0, };

    for (o = 0; o < a; o++)
    {
        for (i = 0; i < 7; i++)
        {
            ary[o][i] = rand() % 45 + 1;
            return ary[o][i];
            for (j = 0; j < i; j++)

                    if (ary[i] == ary[j])
                        i--;
            }
        }
    }*/

   

    void user_lotto()
{
    int i;
    int j;
    int temp;

    for (i = 0; i < 7; i++)
    {
        ary[i] = rand() % 45 + 1;
        for (j = 0; j < i; j++)
        {
            if (ary[i] < ary[j])
            {
                if (ary[i] == ary[6])
                    break;
                temp = ary[i];
                ary[i] = ary[j];
                ary[j] = temp;
            }

            if (ary[i] == ary[j])
                i--;
        }
    }

    for (int i = 0; i < 7; i++) {
        if (i == 6) {
            printf("보너스 번호 : [%d] ", ary[i]);
            break;
        }

        printf("[%d] ", ary[i]);
    }
}




//void winner_print()
//{
//    int ary[6] = { 1, 2, 3, 4, 5, 6 };
//    printf("1등은 %d 입니다.\n");
//    printf("2등은 %d 입니다.\n");
//    printf("3등은 %d 입니다.\n");
//}


void buy_result(int a, int b)
{
    switch (a) {
    case 1:
        printf("신용카드 %d원 결제가 되었습니다.\n", b);
        break;
    case 2:
        printf("현금 %d원 결제가 되었습니다.\n", b);
        break;
    case 3:
        printf("휴대폰 %d원 결제가 되었습니다.\n", b);
        break;
    case 4:
        printf("문화상품권 %d원 결제가 되었습니다.\n", b);
        break;
    }
}

void chance(int a) {
    switch (a) {
    case 'y':
        break;
    case 'n':
        break;
    }
}

int money_check(int tn) {
    int i;
    int value = 0;
    for (i = 1; i < 101; i++)
    {
        if (tn >= i)
            value += 1000
            ;
        if (tn == i)
            return value;
    }
}

void view_init()
{
    for (int i = 0; i < 20; i++)
        printf("\n");
}

void auto_print(int a){
    for (int i = 1; i < 101; i++)
    {
        if (a >= i) {
            printf("%d번째: ", i);
            user_lotto();
            printf("\n");
        }

    }
}

void manual_print(int a, int* b)
{
    printf("로또번호: ");
    for (int i = 0; i < 7; i++)
    {
        printf("[%d] ", b[i]);
    }
    printf("\n");
}
    

void lotto_manual(int a, int* b)
{
    int temp;
    printf("숫자를 입력해주세요");
    for (int i = 0; i < 7; i++)
    {
        printf("%d번째 수:", i + 1);
        
        scanf("%d", &b[i]);
        

        for (int j = 0; j < i; j++)
        {
            if (b[i] > 45) {
                i--;
                printf("1 ~ 45 사이의 값을 입력하시오.\n");
                break;
            }

            if (b[i] < b[j])
            {
                if (b[i] == b[6])
                    break;
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }

            if (b[i] == b[j])
                i--;
        }
    }
}

void auto_lotto(int a, int b)
{
    switch (a) {
    case 1:
        auto_print(b);
        break;
    case 2:
        lotto_manual(b, manual_aray);
        manual_print(manual_aray);
        break;
    }
}

