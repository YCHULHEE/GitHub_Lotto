#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include "lotto.h"


int main(void)
{
   /*int ary[][7] = { 0, };
    

    for (int j = 0; j < 10; j++)
    {`
        ary[j][7] = lott_value(10);
        for (int i = 0; i < 7; i++) {
            if (i == 6) {
                printf("���ʽ� ��ȣ : [%d] ", ary[j][i]);
                break;
            }

            printf("[%d] ", ary[i]);
        }
    }
 }*/


    static int number = 1; // �ζ� ȸ�� ��� ����
    static int total = 578422000; // �ζ� �� �ݾ� ��� ����
    int tn, mn; // �ζ� ����
    static int hm = 0;
    char qs; 
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
        scanf("%d", &tn); // Ƽ�� ���� Ƚ��
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("���� �Ͻ� �ý����� �������ּ���. \n");
        printf(" 1��\t�ſ�ī�� ����\n 2��\t���� ����\n 3��\t�޴��� ����\n 4��\t��ȭ��ǰ�� ����\n");
        printf("-----------------------------------\n");
        scanf("%d", &mn);
        hm = money_check(tn); // ���� �̿��� �ݾ��� üũ�ؼ� hm �̶�� ������ �������ݴϴ�.
        buy_result(mn, hm); // ���� �����ϰ� �ݾ��� ������ �˷��ִ� �Լ�.
        printf("��Ȯõ���� ��ȸ�� �븮�ðڽ��ϱ�?(y/n)\n");
        scanf(" %c", &qs); // �ζ��� �ǻ縦 �޴� ����
        total = total + 1000*tn; 
        chance(qs); 
        lotto_print(tn);
        printf("��÷�Ǹ� %d���� �����Ǽ��ֽ��ϴ�.\n", total);
        printf("%dȸ�� ��÷��ȣ��?\n", number);
        getch(); // ��� ���߰� ���ִ� �Լ�. �ƹ� Ű �Է½� �ڵ� ����

        printf("\n��÷��ȣ�� ");
        user_lotto();
        printf("�Դϴ�. ");
        getch();
        number++;
        tn = 0;
        hm = 0;
        qs = 'n';
        rewind(stdin); // scanf ���� �ʱ�ȭ!
        view_init();

     
    }

}

