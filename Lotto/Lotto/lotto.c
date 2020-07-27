#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include "lotto.h"
#include <windows.h>

int ary[6] = { 0, };  // �ζǹ�ȣ 6���� ǥ���� �� ���������� ���Ǵ� ����.

int manual_aray[] = { 0, }; // ���� �Է��� �ζǹ�ȣ�� ��� ����
int lotto_number[45] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 ,15 ,16 ,17, 18, 19, 20, 21, 22, 23, 24, 25,
    26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 }; //�ζ� ��ȣ�� �����ϴ� ����.
int x = 23; //Ÿ��Ʋȭ���� ǥ�õǴ� x��ǥ 
int y = 4; //Ÿ��Ʋȭ���� ǥ�õǴ� y��ǥ 
/*��÷Ƚ���� �ζǹ�ȣ�� ��� ����ü*/
struct Lotto {
    int count1; // ��÷Ƚ���� ������ ����
    int count2; // ��÷Ƚ���� �������ķ� �����Ͽ� ������ ����
    int number1; // ��÷Ƚ���� ����Ű�� �ζǹ�ȣ�� �ּ�
    int number2; // �������ķ� ������ ��÷Ƚ���� ����Ű�� �ζǹ�ȣ�� �ּ�
    int sp_num;
};
/* Ȧ�� ¦�� ����ġ ��� ����ü  ¦��_Ȧ��_ī��Ʈ ��) six_zero �� ��� ¦�� 6 Ȧ�� 0  */
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
struct Weight weight[1]; // ����ġ ����ü�� �����Ͽ� weight �̸����� ����ü ���� ����

struct Lotto list[45]; /* �ζǹ�ȣ�� ��÷Ƚ���� ��� ����ü�� list �̸����� 45���� ����ü ���� ���� 
                       45���� ������ ������ �ζǹ�ȣ 1���� 45���� ���� ����ü�� ����� ���ؼ��̴�.*/
struct Lotto list2[45];

void highcheck_print(int a) // Ȯ���� ���� ���ڸ� ����ϴ� �Լ�
{
    int j = 5;  
    /*gotoxy(x, y + 4);*/ printf("\nȮ�� ������ ����\n");
    for (int i = 44; i >= 0; i--) {
        /*gotoxy(x, y + j);*/ printf("��ȣ: %d��\t ��÷Ƚ�� : %d \t��÷Ȯ�� : %.2f%% \n", list[i].number2, list[i].count2, (double)list[i].count2 / (a * 6) * 100);
        j++;
    }
}

void lowcheck_print(int a) // �ζ� ��ȣ ������ ����ϴ� �Լ�
{
    printf("\n�ζ� ��ȣ������ ����\n");
    for (int i = 0; i < 45; i++)
        printf("��ȣ: %d��\t ��÷Ƚ�� : %d \t��÷Ȯ�� : %.2f%%  \n", list[i].number1, list[i].count1,(double)list[i].count1 / (a * 6) * 100);
}

void changecheck1_print(int a) // Ȯ���� ���� ���ڸ� ����ϴ� �Լ�
{
    printf("\nȮ�� ������ ����\n\t����ġ�� �����ؼ� 1ȸ �ݺ��� �󵵿� Ȯ��\t\t\t�ζ� ��÷ ��ȣ�� �󵵿� Ȯ��\n");
    for (int i = 44; i >= 0; i--)
        printf("��ȣ: %d��\t ��÷Ƚ�� : %d \t��÷Ȯ�� : %.2f%%  ��ȣ: %d��\t ��÷Ƚ�� : %d \t��÷Ȯ�� : %.2f%%\n",
            list2[i].number2, list2[i].count2, (double)list2[i].count2 / (a * 6) * 100, list[i].number2, list[i].count2, (double)list[i].count2 / (a * 6) * 100);
}

void changecheck2_print(int a) // �ζ� ���� ��� ���
{
    printf("\n��ȣ ������ ����\n\t����ġ�� �����ؼ� 1ȸ �ݺ��� �󵵿� Ȯ��\t\t\t�ζ� ��÷ ��ȣ�� �󵵿� Ȯ��\n");
    for (int i = 0; i < 45; i++)
        printf("��ȣ: %d��\t ��÷Ƚ�� : %d \t��÷Ȯ�� : %.2f%%  ��ȣ: %d��\t ��÷Ƚ�� : %d \t��÷Ȯ�� : %.2f%%\n", 
            list2[i].number1, list2[i].count1, (double)list2[i].count1 / (a * 6) * 100, list[i].number1, list[i].count1, (double)list[i].count1 / (a * 6) * 100);
            
}   

void odd_even_check_print(int a) // ����ġ�� ������ Ȧ¦�� Ȯ���� ���� ����ϴ� �Լ�
{
    printf("\n����ġ ������ ���� Ȧ¦ Ȯ��\n");
    printf("Ȧ�� 6 ¦�� 0 : %.2f%%\t%d�� \nȦ�� 5 ¦�� 1 : %.2f%%\t%d��\nȦ�� 4 ¦�� 2 : %.2f%%\t%d��\nȦ�� 3 ¦�� 3 : %.2f%%\t%d��\nȦ�� 2 ¦�� 4 : %.2f%%\t%d��\nȦ�� 1 ¦�� 5 : %.2f%%\t%d��\nȦ�� 0 ¦�� 6 : %.2f%%\t%d��\n��ü Ƚ�� : %d \n",
        ((double)weight[0].zero_six_count / weight[0].total_count) * 100, weight[0].zero_six_count, ((double)weight[0].one_five_count / weight[0].total_count) * 100,
        weight[0].one_five_count, ((double)weight[0].two_four_count / weight[0].total_count) * 100, weight[0].two_four_count,
            ((double)weight[0].three_three_count / weight[0].total_count) * 100, weight[0].three_three_count, ((double)weight[0].four_two_count / weight[0].total_count) * 100,
                weight[0].four_two_count, ((double)weight[0].five_one_count / weight[0].total_count) * 100, weight[0].five_one_count,
                    ((double)weight[0].six_zero_count / weight[0].total_count) * 100, weight[0].six_zero_count, weight[0].total_count);

}

void count_check1() // ���α׷��� ���� ���� ��÷Ƚ���� ������������ �������ִ� �Լ�
{
    int i, j;
    int temp;
    for (i = 0; i < 45; i++) // �ζǹ�ȣ�� ��÷Ƚ���� count1���� count2�� �ȱ�� �ݺ���
    {
        list[i].count2 = list[i].count1;
        list[i].number2 = list[i].number1;
        for (j = 0; j < i; j++) // ��÷Ƚ���� ���Ͽ� ������������ �����Ѵ�.
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

void count_check2() // ���α׷��� ���� ���� ��÷Ƚ���� ������������ �������ִ� �Լ�
{
    int i, j;
    int temp;
    for (i = 0; i < 45; i++) // �ζǹ�ȣ�� ��÷Ƚ���� count1���� count2�� �ȱ�� �ݺ���
    {
        list2[i].count2 = list2[i].count1;
        list2[i].number2 = list2[i].number1;
        for (j = 0; j < i; j++) // ��÷Ƚ���� ���Ͽ� ������������ �����Ѵ�.
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

void user_lotto() //�ζǹ�ȣ�� �����ϴ� �Լ�
{
    int i, j, o;
    int temp;
    int ary[6] = { 0, };
    for (i = 0; i < 6; i++) // �ζ� ��ȣ 6���� �̰� ���� ������ ¦������ Ȧ������ ���Ͽ� ������ �����Ѵ�.
    {
        ary[i] = rand() % 45 + 1;
        /*if (ary[i] % 2 == 0)
            even_number++;
        else if (ary[i] % 2 == 1)
            odd_number++;*/

        for (o = 0; o < 45; o++) // �ζǹ�ȣ�� ��÷Ƚ���� ������Ű�� �ݺ���
        {
            list[o].number1 = o + 1;
            if (ary[i] == list[o].number1)
                list[o].count1++;
        }

        for (j = 0; j < i; j++) // �ζ� ��ȣ�� ������ �� ������������ ���Ľ����ִ� �ݺ���
        {
            if (ary[i] < ary[j])
            {
                temp = ary[i];
                ary[i] = ary[j];
                ary[j] = temp;
            }

            if (ary[i] == ary[j]) // �ߺ��Ͻ� ��÷Ƚ���� ���̰� ¦�� Ȧ�� ī����Ƚ���� ���̴� ���ǹ�
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

    for (int i = 0; i < 6; i++) // ������ �ζǹ�ȣ��  ����ϴ� �ݺ���
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
    int on = 0; // Ȧ�� ����
    int en = 0; // ¦�� ����
    int sum;
    while (1) {
        printf("\n¦�� Ȧ���� �����Ͽ� �ζǹ�ȣ�� ����\n");
        printf("¦�� Ȧ���� ���� 6���� �մϴ�.\n");
        printf("¦���� �Է����ּ���.");
        scanf("%d", &en);
        printf("\nȦ���� �Է����ּ���.");
        scanf("%d", &on);
        sum = en + on;
        if (sum == 6) {
            printf("�ζǹ�ȣ�� ");
            even_odd_result(en, on, c);
            printf("�Դϴ�. \n");
        }
    }
}

void even_odd_result(int a, int b, int c) {
        

    int i, j, o, value, num =0;
    int temp;
    int even_number = a; // ¦�� ����
    int odd_number = b; // Ȧ�� ����
    int ary[6] = { 0, };
    int sum;

    sum = even_number + odd_number;

    for (i = 0; i < even_number; i++) // �ζ� ��ȣ 6���� �̰� ���� ������ ¦������ Ȧ������ ���Ͽ� ������ �����Ѵ�.
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

            for (o = 0; o < 45; o++) // �ζǹ�ȣ�� ��÷Ƚ���� ������Ű�� �ݺ���
            {
                list[o].number1 = o + 1;
                if (ary[i] == list[o].number1)
                    list[o].count1++;
            }

            for (j = 0; j < i; j++) // �ζ� ��ȣ�� ������ �� ������������ ���Ľ����ִ� �ݺ���
            {
                if (ary[i] < ary[j])
                {
                    temp = ary[i];
                    ary[i] = ary[j];
                    ary[j] = temp;
                }

                if (ary[i] == ary[j]) // �ߺ��Ͻ� ��÷Ƚ���� ���̰� ¦�� Ȧ�� ī����Ƚ���� ���̴� ���ǹ�
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

    for (i=even_number; i < 6; i++) // �ζ� ��ȣ 6���� �̰� ���� ������ ¦������ Ȧ������ ���Ͽ� ������ �����Ѵ�.
    {
        if (sum == 6) {
            ary[i] = rand() % 45 + 1;
            if ((ary[i] % 2) == 0) {
                i--;
                continue;
            }

            for (o = 0; o < 45; o++) // �ζǹ�ȣ�� ��÷Ƚ���� ������Ű�� �ݺ���
            {
                list[o].number1 = o + 1;
                if (ary[i] == list[o].number1)
                    list[o].count1++;
            }

            for (j = 0; j < i; j++) // �ζ� ��ȣ�� ������ �� ������������ ���Ľ����ִ� �ݺ���
            {
                if (ary[i] < ary[j])
                {
                    temp = ary[i];
                    ary[i] = ary[j];
                    ary[j] = temp;
                }

                if (ary[i] == ary[j]) // �ߺ��Ͻ� ��÷Ƚ���� ���̰� ¦�� Ȧ�� ī����Ƚ���� ���̴� ���ǹ�
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
    for (int i = 0; i < 6; i++) // ������ �ζǹ�ȣ��  ����ϴ� �ݺ���
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

void change_lotto(int a) //�ζǹ�ȣ�� �����ϴ� �Լ�
{
    int i, j, o, num = 0;
    int value;
    int temp;
    int odd_number = 0; // Ȧ�� ����
    int even_number = 0; // ¦�� ����
    int ary[6] = { 0, };
    for (i = 0; i < 6; i++) // �ζ� ��ȣ 6���� �̰� ���� ������ ¦������ Ȧ������ ���Ͽ� ������ �����Ѵ�.
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

        for (o = 0; o < 45; o++) // �ζǹ�ȣ�� ��÷Ƚ���� ������Ű�� �ݺ���
        {
            list2[o].number1 = o + 1;
            if (ary[i] == list2[o].number1)
                list2[o].count1++;
        }

        for (j = 0; j < i; j++) // �ζ� ��ȣ�� ������ �� ������������ ���Ľ����ִ� �ݺ���
        {
            if (ary[i] < ary[j])
            {
                temp = ary[i];
                ary[i] = ary[j];
                ary[j] = temp;
            }

            if (ary[i] == ary[j]) // �ߺ��Ͻ� ��÷Ƚ���� ���̰� ¦�� Ȧ�� ī����Ƚ���� ���̴� ���ǹ�
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
        if (i == 5) // ¦�� Ȧ�� ������ Ƚ���� ������ ����� ���� �����ϴ� ���ǹ�
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
        weight[0].three_three_count + weight[0].two_four_count + weight[0].one_five_count + weight[0].zero_six_count; //Ȧ ¦ ����� �� ī����

    for (int i = 0; i < 6; i++) // ������ �ζǹ�ȣ��  ����ϴ� �ݺ���
    {
        printf("[%d] ", ary[i]);
        if (i == 6) {
            printf("\n");
            break;
        }
    }
}

void chance(int a) // �ζǸ� �Ҳ��� ���θ� �����ϴ� �Լ�
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

void auto_print(int a) // a��� ���� ���� �޾� a Ƚ�� ��ŭ �ζǹ�ȣ�� �����ؼ� ����ϴ� �Լ�
{
    for (int i = 1; i < 10001; i++)
    {
        if (a >= i) {
            printf("[%d]��° �ζǹ�ȣ: ", i);
            user_lotto(); //�ζ� �����ϴ� �Լ�
            printf("\n");
        }
    }
}

void change_print(int a) // a��� ���� ���� �޾� a Ƚ�� ��ŭ �ζǹ�ȣ�� �����ؼ� ����ϴ� �Լ�
{
    for (int i = 1; i < a+1; i++)
    {
        if (a >= i) {
            printf("[%d]��° �ζǹ�ȣ: ", i);
            change_lotto(a); //�ζ� �����ϴ� �Լ�
            printf("\n");
        }
    }

}

void auto_lotto(int a, int b) // �����Է����� �ڵ��Է����� ���θ� �����ϴ� �Լ�
{
    switch (a) {
    case 1:
        auto_print(b);
        break;
    default :
        printf("���� �ٽ� �Ͻÿ�.");
        main();
        break;
    }
}

int comb(int n, int r)//���� �Լ�
{
    if (n == r || r == 0)
        return 1;
    return comb(n - 1, r - 1) + comb(n - 1, r);//n-1Cr-1+n-1Cr=nCr
}

void probaility_value() // ����Ǽ� �����ϴ� �Լ�
{
    int value;
    value = comb(45, 6);//�ζǴ�÷Ȯ��(45�߿��� 6���� ���ڸ� ���� ������� �����ϴ� ����� ��)
    printf("������ Ȧ¦ ���ڿ� ���� Ȯ��\n");
    printf("�ζ� ��÷Ȯ��:%d\n", value);
    int com[7] = { 0, };
    for (int k = 0; k < 7; k++) {
        com[k] = comb(23, 6 - k) * comb(22, k);
    }
    for (int r = 0; r < 7; r++) {
        printf("Ȧ�� %d�� ¦�� %d���� Ȯ��: %.2f%%   %d��\n", 6 - r, r, ((double)com[r]/value)*100, com[r]);
    }
}

void gotoxy(int x, int y) { //gotoxy�Լ� 
    COORD pos = { 2 * x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void screen_reset() {
    for (int i = 0; i < 30; i++)
        printf("\n\n");
}
