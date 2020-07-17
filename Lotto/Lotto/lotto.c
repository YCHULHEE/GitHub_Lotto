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
    static int total = 583900000;
    int tn, mn;
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
        printf("1ȸ�� 1000��. \n�ѹ��� �ִ� 100����� ���� �����մϴ�! \n");
        printf("�� ȸ �Ͻðڽ��ϱ�?\n");
        scanf("%d", &tn);
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("���� �Ͻ� �ý����� �������ּ���. \n");
        printf(" 1��\t�ſ�ī�� ����\n 2��\t���� ����\n 3��\t�޴��� ����\n 4��\t��ȭ��ǰ�� ����\n");
        printf("-----------------------------------\n");
        scanf("%d", &mn);


        if (tn == 1)
            hm = 1000;
        else if (tn == 3)
            hm = 3000;
        else if (tn == 5)
            hm = 5000;
        else if (tn == 10)
            hm = 10000;
        else {
            printf("���Ű����� ���ڸ� �Է��ϼ���.");
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

        printf("������ �ǰ��� �� �����ϴ�. ��� �Ͻ� �̴ϱ�? y/n\n");
        scanf("%d", &qs);
        switch (qs) {
        case 'y':
            break;
        case 'n':
            break;
        }




        switch (tn) {
        case 1:
            printf("1��°: ");
            user_lotto();
            total += 1000;
            break;
        case 3:
            for (i = 0; i < 3; i++) {
                printf("%d��°: ", i + 1);
                user_lotto();
                printf("\n");
                total += 1000;
            }
            break;
        case 5:
            for (i = 0; i < 5; i++) {
                printf("%d��°: ", i + 1);
                user_lotto();
                printf("\n");
                total += 1000;
            }
            break;
        case 10:
            for (i = 0; i < 10; i++) {
                printf("%d��°: ", i + 1);
                user_lotto();
                printf("\n");
                total += 1000;
            }
            break;
        }

        printf("��÷�Ǹ� %d���� �����Ǽ��ֽ��ϴ�.", total);

        getch(); // ��� ���߰� ���ִ� �Լ�. �ƹ� Ű �Է½� �ڵ� ����


        printf("\n��÷��ȣ�� ");
        user_lotto();
        printf("�Դϴ�. ");
        getch();

    }

}

