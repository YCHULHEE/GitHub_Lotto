#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include "lotto.h"


int main(void)
{
    static int number = 1; // �ζ� ȸ�� ��� ����
    static int total = 578422000; // �ζ� �� �ݾ� ��� ����
    int tn, mn; // �ζ� ����
    static int hm = 0; // ���� �ݾ� ��� ����
    char qs; // y/n �� �޴� ����
    int at_num; // ���� �ڵ� �����ϴ� ����
    int manual_aray[] = { 0, }; // ����Ǵ� ����

    srand((unsigned)time(NULL));  //�ð��� �̿��� �õ尪 �����ϴ� �Լ�

    while (1) {
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("---------- Lotto Program ----------\n");
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("---------------%dround--------------\n", number);
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("1�� 1000��. \n�ѹ��� �ִ� 10����� ���� �����մϴ�! \n");
        printf("���� �����Ͻðڽ��ϱ�?\n");
        scanf("%d", &tn); // Ƽ�� ���� Ƚ��
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("1.\t�ڵ� �Է�\n2.\t���� �Է�\n");
        scanf("%d", &at_num);
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
        total = total + 1000 * tn;
        chance(qs);
        auto_lotto(at_num, tn);



        printf("��÷�Ǹ� %d���� �����Ǽ��ֽ��ϴ�.\n", total);
        printf("%dȸ�� ��÷��ȣ��?\n", number);
        getch(); // ��� ���߰� ���ִ� �Լ�. �ƹ� Ű �Է½� �ڵ� ����
        count_check();
        printf("\n��÷��ȣ�� ");
        answer_lotto();
        printf("�Դϴ�.\n");
        
        getch(); // ��� ���α׷� ������ ���ߴ� �Լ�
        highcheck_print(tn);
        getch();
        lowcheck_print(tn);
        /*print_chance(void);*/
        auto_print1(10);
        getch();
        number++;
        hm = 0;
        qs = 'n';
        rewind(stdin); // scanf ���� �ʱ�ȭ!
        view_init();


    }

}
