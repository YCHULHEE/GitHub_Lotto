#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>


/*Ȯ���� ���� ���ڸ� ����ϴ� �Լ� */
void highcheck_print(int a);
/*Ȯ���� ���� ���ڸ� ����ϴ� �Լ�*/
void lowcheck_print(int a);
/*���α׷��� ���� ���� ��÷Ƚ���� ������������ �������ִ� �Լ�*/
void count_check();
/*�ζǹ�ȣ�� �����ϴ� �Լ�*/
void user_lotto();
/*��÷��ȣ�� ����ϴ� �Լ�*/
void answer_lotto();
/* ���������� ������ ������ ������� �Լ�*/
void buy_result(int a, int b);
/*�ζǸ� �Ҳ��� ���θ� �����ϴ� �Լ�*/
void chance(int a);
/*������ �ζǸ� 1���� 1000������ ����Ͽ� �� ������ �����ϴ� �Լ�*/
int money_check(int tn);
/*ȭ�� �ʱ�ȭ �Լ�*/
void view_init();
/*a��� ���� ���� �޾� a Ƚ�� ��ŭ �ζǹ�ȣ�� �����ؼ� ����ϴ� �Լ�*/
void auto_print(int a);
/*���� �Է��� �ζ� ��ȣ ���� ������ִ� �Լ�*/
void manual_print(int a, int* b);
/*���� �Է��� ���� �� �ζ� ��ȣ 6�ڸ��� �޴� �Լ�*/
void lotto_manual(int a, int* b);
/*�����Է����� �ڵ��Է����� ���θ� �����ϴ� �Լ�*/
void auto_lotto(int a, int b);

