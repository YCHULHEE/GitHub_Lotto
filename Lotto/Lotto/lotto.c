#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>

int ary[7] = { 0, };  // �ζǹ�ȣ 7���� ǥ���� �� ���������� ���Ǵ� ����.

int manual_aray[] = { 0, }; // ���� �Է��� �ζǹ�ȣ�� ��� ����
int lotto_number[45] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 ,15 ,16 ,17, 18, 19, 20, 21, 22, 23, 24, 25,
    26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 }; //�ζ� ��ȣ�� �����ϴ� ����.
/*��÷Ƚ���� �ζǹ�ȣ�� ��� ����ü*/
struct Lotto {
    int count1; // ��÷Ƚ���� ������ ����
    int count2; // ��÷Ƚ���� �������ķ� �����Ͽ� ������ ����
    int number1; // ��÷Ƚ���� ����Ű�� �ζǹ�ȣ�� �ּ�
    int number2; // �������ķ� ������ ��÷Ƚ���� ����Ű�� �ζǹ�ȣ�� �ּ�
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
};

struct Weight weight[1]; // ����ġ ����ü�� �����Ͽ� weight �̸����� ����ü ���� ����


struct Lotto list[45]; /* �ζǹ�ȣ�� ��÷Ƚ���� ��� ����ü�� list �̸����� 45���� ����ü ���� ���� 
                       45���� ������ ������ �ζǹ�ȣ 1���� 45���� ���� ����ü�� ����� ���ؼ��̴�.*/


//void file_read() {
//    char ch;
//    FILE* fp;
//    fp = fopen("C:\\Users\\User\\Source\\Repos\\GitHub_Lotto\\Lotto\\Lotto\\db.txt", "rt");
//    // ������ ��ΰ� ������ �� ���α׷� ��ġ�� �������� �ʴ°�� ��ü ��� �Է� �������� �ι��Է�
//    // ex) fopen("C:\\Users\\user\\Documents\\test.txt", "rt"); 
//
//    if (fp == NULL) { // fopen�Լ��� ���������� �۵����� �ʴ´ٸ� NULL�� ��ȯ
//        printf("���� �б� ����");
//        return -1; // ���� �߻��� �˸��� �� -1 ����
//    }
//
//    while ((ch = fgetc(fp)) != EOF) { // fgetc()�Լ��� fp�� ����Ű�� ���Ͽ� ���ڸ� �����ͼ� ch�� ����. �� ���� EOF(-1)�� �ƴ� �� ���� �ݺ�  
//        printf("%c", ch);
//    }
//    fclose(fp);
//}
//void file_write() {
//    int num = 45;
//    char arr[] = "m";
//    *arr = (char)num;
//    FILE* fp;
//    fp = fopen("C:\\Users\\User\\Source\\Repos\\GitHub_Lotto\\Lotto\\Lotto\\db.txt", "a");
//
//    fputs(arr, fp); // �迭 arr�� �ִ� ���ڿ��� fp�� ����Ű�� ���Ͽ� ���
//
//    fclose(fp);
//}


//void file_write(*char a) {
//
//    char arr[] = "ganadara";
//    *arr = a;
//    FILE* fp;
//    fp = fopen("C:\\Users\\User\\Source\\Repos\\GitHub_Lotto\\Lotto\\Lotto\\db.txt", "wt");
//
//    fputs(arr, fp); // �迭 arr�� �ִ� ���ڿ��� fp�� ����Ű�� ���Ͽ� ���
//
//    fclose(fp);
//}


void highcheck_print(int a) // Ȯ���� ���� ���ڸ� ����ϴ� �Լ�
{
    printf("\nȮ���� ���� ���� 10��\n");
    for (int i = 44; i > 34; i--)
        printf("��ȣ: %d�� ��÷ Ƚ��: %d\n", list[i].number2, list[i].count2);
}

void lowcheck_print(int a) // Ȯ���� ���� ���ڸ� ����ϴ� �Լ�
{
    printf("\nȮ���� ���� ���� 5��\n");
    for (int i = 0; i < 5; i++)
        printf("��ȣ: %d�� ��÷ Ƚ��: %d\n", list[i].number2, list[i].count2);
}

//void recommend_lottonum()
//{
//    for (int i = 44; i > 34; i--)
//    {
//        
//    }
//}

void count_check() // ���α׷��� ���� ���� ��÷Ƚ���� ������������ �������ִ� �Լ�
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

void user_lotto() //�ζǹ�ȣ�� �����ϴ� �Լ�
{
    int i, j, o;
    int temp;
    int odd_number = 0; // Ȧ�� ����
    int even_number = 0; // ¦�� ����

    for (i = 0; i < 6; i++) // �ζ� ��ȣ 6���� �̰� ���� ������ ¦������ Ȧ������ ���Ͽ� ������ �����Ѵ�.
    {
        ary[i] = rand() % 45 + 1;
        if (ary[i] % 2 == 0)
            even_number++;
        else if (ary[i] % 2 == 1)
            odd_number++;

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

    for (int i = 0; i < 6; i++) // ������ �ζǹ�ȣ��  ����ϴ� �ݺ���
    {
        printf("[%d] ", ary[i]);
        if (i == 6) {
            printf("\n");
            break;
        }
    }
}

void answer_lotto() // ��÷��ȣ�� ����ϴ� �Լ�
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

void buy_result(int a, int b) // ���������� ������ ������ ������� �Լ�
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

void chance(int a) // �ζǸ� �Ҳ��� ���θ� �����ϴ� �Լ�
{
    switch (a) {
    case 'y':
        break;
    case 'n':
        break;
    }
}

int money_check(int tn) // ������ �ζǸ� 1���� 1000������ ����Ͽ� �� ������ �����ϴ� �Լ�
{
    int i;
    int value = 0;
    for (i = 1; i < 10001; i++)
    {
        if (tn >= i)
            value += 1000
            ;
        if (tn == i)
            return value;
    }
}

void view_init() // ȭ�� �ʱ�ȭ �Լ�
{
    for (int i = 0; i < 20; i++)
        printf("\n");
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

void manual_print(int a, int* b) // ���� �Է��� �ζ� ��ȣ ���� ������ִ� �Լ�
{
    for (int o = 0; o < a; o++)
    {
        printf("�ζǹ�ȣ: ");
        for (int i = 0; i < 7; i++)
        {
            printf("[%d] ", b[i]);
        }
        printf("\n");
    }
}

void lotto_manual(int a, int* b) // ���� �Է��� ���� �� �ζ� ��ȣ 6�ڸ��� �޴� �Լ�
{
    int temp;
    printf("���ڸ� �Է����ּ���\n");
    for (int o = 0; o < a; o++)
    {
        printf("%d��° �ζ�\n", o + 1);
        for (int i = 0; i < 6; i++)
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
                    temp = b[i];
                    b[i] = b[j];
                    b[j] = temp;
                }

                if (b[i] == b[j]) {
                    printf("�ߺ��� ���� �ȵ˴ϴ�.\n");
                    i--;
                }
            }
        }
    }
}

void auto_lotto(int a, int b) // �����Է����� �ڵ��Է����� ���θ� �����ϴ� �Լ�
{
    switch (a) {
    case 1:
        auto_print(b);
        break;
    case 2:
        lotto_manual(b, manual_aray);
        manual_print(b, manual_aray);
        break;
    default :
        printf("���� �ٽ� �Ͻÿ�.");
        break;
    }
}

