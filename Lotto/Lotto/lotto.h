#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
int ary[7] = { 0, };
int manual_aray[] = { 0, }; // ����Ǵ� ����
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
            printf("���ʽ� ��ȣ : [%d] ", ary[i]);
            break;
        }

        printf("[%d] ", ary[i]);
    }
}




//void winner_print()
//{
//    int ary[6] = { 1, 2, 3, 4, 5, 6 };
//    printf("1���� %d �Դϴ�.\n");
//    printf("2���� %d �Դϴ�.\n");
//    printf("3���� %d �Դϴ�.\n");
//}


void buy_result(int a, int b)
{
    switch (a) {
    case 1:
        printf("�ſ�ī�� %d�� ������ �Ǿ����ϴ�.\n", b);
        break;
    case 2:
        printf("���� %d�� ������ �Ǿ����ϴ�.\n", b);
        break;
    case 3:
        printf("�޴��� %d�� ������ �Ǿ����ϴ�.\n", b);
        break;
    case 4:
        printf("��ȭ��ǰ�� %d�� ������ �Ǿ����ϴ�.\n", b);
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
            printf("%d��°: ", i);
            user_lotto();
            printf("\n");
        }

    }
}

void manual_print(int a, int* b)
{
    printf("�ζǹ�ȣ: ");
    for (int i = 0; i < 7; i++)
    {
        printf("[%d] ", b[i]);
    }
    printf("\n");
}
    

void lotto_manual(int a, int* b)
{
    int temp;
    printf("���ڸ� �Է����ּ���");
    for (int i = 0; i < 7; i++)
    {
        printf("%d��° ��:", i + 1);
        
        scanf("%d", &b[i]);
        

        for (int j = 0; j < i; j++)
        {
            if (b[i] > 45) {
                i--;
                printf("1 ~ 45 ������ ���� �Է��Ͻÿ�.\n");
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

