#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>

void user_lotto()
{
    int ary[7] = { 0 };
    int i;
    int j;

    for (i = 0; i < 7; i++)
    {
        ary[i] = rand() % 45 + 1;
        for (j = 0; j < i; j++)
        {
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