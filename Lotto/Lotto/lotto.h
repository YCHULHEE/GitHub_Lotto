#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include <windows.h>


/*Ȯ���� ���� ���ڸ� ����ϴ� �Լ� */
void highcheck_print(int a);
/*��ȣ�� ���� ������� ����ϴ� �Լ�*/
void lowcheck_print(int a);
/*���α׷��� ���� ���� ��÷Ƚ���� ������������ �������ִ� �Լ�*/
void count_check1();
/*���α׷��� ���� ���� ��÷Ƚ���� ������������ �������ִ� �Լ� */
void count_check2();
/*�ζǹ�ȣ�� �����ϴ� �Լ�*/
void user_lotto();
/*�ζǸ� �Ҳ��� ���θ� �����ϴ� �Լ�*/
void chance(int a);
/*a��� ���� ���� �޾� a Ƚ�� ��ŭ �ζǹ�ȣ�� �����ؼ� ����ϴ� �Լ�*/
void auto_print(int a);
/*�����Է����� �ڵ��Է����� ���θ� �����ϴ� �Լ�*/
void auto_lotto(int a, int b);
/*����ġ�� ������ �ζ� ��ȣ�� �����ϴ� �Լ�*/
void change_lotto();
/*����ġ�� ���� �ζ� ��ȣ�� ������ִ� �Լ�*/
void change_print(int a);
/*����� ���� �̰� ������ִ� �Լ�*/
void  probaility_value();
/*����ġ�� �����Ͽ� Ȯ�������� �����Ͽ� ����ϴ� �Լ�*/
void changecheck1_print(int a);
/*����ġ�� �����Ͽ� ��ȣ������ �����Ͽ� ����ϴ� �Լ�*/
void changecheck2_print(int a);
/*����ġ�� �����Ͽ� Ȧ�� ¦���� ����� ���� ī��Ʈ���ִ� �Լ�*/
void even_odd_result(int a, int b, int c);
/*Ȧ���� ¦���� ������ ���� Ȯ���� ��Ÿ���� �Լ� */
void odd_even_check_print(int a);
/*���� �Լ�*/
int comb(int n, int r);
/*¦�� Ȧ�� ����� �� ���*/
void even_odd_print(int c);
/*���� ��ġ ���� ���ִ� �Լ�*/
void gotoxy(int x, int y);