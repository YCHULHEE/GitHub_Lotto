#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include "lotto.h"
#include <windows.h>


int main(void)
{
    static int number = 1; // �ζ� ȸ�� ��� ����
    static int total = 578422000; // �ζ� �� �ݾ� ��� ����
    int tn, mn; // �ζ� ����
    static int hm = 0; // ���� �ݾ� ��� ����
    char qs; // y/n �� �޴� ����
    int at_num; // ���� �ڵ� �����ϴ� ����
    int manual_aray[] = { 0, }; // ����Ǵ� ����
    int x = 23; //Ÿ��Ʋȭ���� ǥ�õǴ� x��ǥ 
    int y = 4; //Ÿ��Ʋȭ���� ǥ�õǴ� y��ǥ 
    int cnt; //Ÿ��Ʋ �������� ���� ����  
    srand((unsigned)time(NULL));  //�ð��� �̿��� �õ尪 �����ϴ� �Լ�
    while (1) {

        SetConsoleTitle("Lotto Program");
        system("mode con cols=120 lines=48");
        system("color E");
        gotoxy(x, y + 0); printf("����������������"); Sleep(100);
        gotoxy(x, y + 1); printf("�����  ����    ������"); Sleep(100);
        gotoxy(x, y + 2); printf("�����              ���  ��"); Sleep(100);
        gotoxy(x, y + 3); printf("������  ��  ��  ������"); Sleep(100);
        gotoxy(x, y + 4); printf("���  �������������"); Sleep(100);
        gotoxy(x, y + 5); printf("�����Lotto Program�����"); Sleep(100);
        gotoxy(x, y + 6); printf("����������������"); Sleep(100);
        gotoxy(x, y + 7); printf("�����  ����    ������"); Sleep(100);
        gotoxy(x, y + 8); printf("�����              ���  ��"); Sleep(100);
        gotoxy(x, y + 9); printf("������  ��  ��  ������"); Sleep(100);
        gotoxy(x, y + 10); printf("���  �������������\n"); Sleep(100);
        gotoxy(x, y + 11); printf("-----------%dround-------------\n", number); Sleep(100);
        gotoxy(x, y + 12); printf("----�ζ� 1�� ���� ���α׷�----\n"); Sleep(100);
        gotoxy(x, y + 13); printf("�ζ� ȸ���� �Է����ּ���.\n"); Sleep(100);
        gotoxy(x, y + 14); scanf("%d", &tn); // �ζ� ȸ��
  
        gotoxy(x, y + 15); printf("1.\t�ڵ� �Է�\n");
        gotoxy(x, y + 16); scanf("%d", &at_num);
        gotoxy(x, y + 17); printf("------------------------------\n");
        gotoxy(x, y + 18); printf("------------------------------\n");
        gotoxy(x, y + 19); printf("��Ȯõ���� ��ȸ�� �븮�ðڽ��ϱ�?(y/n)\n");
        gotoxy(x, y + 20); scanf(" %c", &qs); // �ζ��� �ǻ縦 �޴� ����
        chance(qs);
        gotoxy(x, y); auto_lotto(at_num, tn);
        getch();
        count_check1();
        getch(); // ��� ���α׷� ������ ���ߴ� �Լ�
        highcheck_print(tn);
        getch();
        lowcheck_print(tn);
        getch();
        
        /*print_chance(void);*/
        change_print(tn);
        count_check2();
        getch();
        changecheck1_print(tn);
        getch();
        changecheck2_print(tn);
        getch();
        printf("\n\n\n");
        probaility_value();
        getch();
        odd_even_check_print(tn);
        getch();
        even_odd_print(tn);
        getch();
        number++;
        hm = 0;
        qs = 'n';
        rewind(stdin); // scanf ���� �ʱ�ȭ!
        system("cls");
    }
}
