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
        printf("[%d] ", ary[i]);
    }
}

void check_lotto()
{

}



int main(void)
{
    static int number = 1; // �ζ� ȸ�� ��� ����
    static int total = 583900000; // �ζ� �� �ݾ� ��� ����
    int tn, mn; // 
    int hm = 0;
    int i, j, o;
    char qs;
    int value[7] = { 1, 2, 3, 4, 5, 6, 7 };
    srand((unsigned)time(NULL));
    while (1) {
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("---------- �ζ� ���α׷� ----------\n");
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("---------------%dȸ��---------------\n", number);
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("1�� 1000��. \n�ѹ��� �ִ� 100����� ���� �����մϴ�! \n");
        printf("���� �����Ͻðڽ��ϱ�?\n");
        scanf("%d", &tn);
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("���� �Ͻ� �ý����� �������ּ���. \n");
        printf(" 1��\t�ſ�ī�� ����\n 2��\t���� ����\n 3��\t�޴��� ����\n 4��\t��ȭ��ǰ�� ����\n");
        printf("-----------------------------------\n");
        scanf("%d", &mn);

        for (i = 1; i < 101; i++)
        {
            if (tn >= i)
                hm += 1000;
        }


        switch (mn) {
        case 1:
            printf("�ſ�ī�� %d�� ������ �Ǿ����ϴ�.\n", hm);
            break;
        case 2:
            printf("���� %d�� ������ �Ǿ����ϴ�.\n", hm);
            break;
        case 3:
            printf("�޴��� %d�� ������ �Ǿ����ϴ�.\n", hm);
            break;
        case 4:
            printf("��ȭ��ǰ�� %d�� ������ �Ǿ����ϴ�.\n", hm);
            break;
        }

        printf("��Ȯõ���� ��ȸ�� �븮�ðڽ��ϱ�?(y/n)\n");
        scanf("%d", &qs);
        switch (qs) {
        case 'y':
            break;
        case 'n':
            break;
        }




        for (i = 1; i < 101; i++)
        {
            if (tn >= i) {
                printf("%d��°: ", i);
                user_lotto();
                printf("\n");
                total += 1000;
            }

        }

        printf("��÷�Ǹ� %d���� �����Ǽ��ֽ��ϴ�.\n", total);
        printf("%dȸ�� ��÷��ȣ��?\n", number);

        getch(); // ��� ���߰� ���ִ� �Լ�. �ƹ� Ű �Է½� �ڵ� ����


        printf("\n��÷��ȣ�� ");
        user_lotto();
        printf("�Դϴ�. ");
        getch();
        number++;
    }

}

