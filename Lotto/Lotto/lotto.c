#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>

int ary[7] = { 0, };  // 로또번호 7개를 표현할 때 공통적으로 사용되는 변수.

int manual_aray[] = { 0, }; // 수동 입력의 로또번호를 담는 변수
int lotto_number[45] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 ,15 ,16 ,17, 18, 19, 20, 21, 22, 23, 24, 25,
    26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45 }; //로또 번호를 저장하는 변수.
/*당첨횟수와 로또번호를 담는 구조체*/
struct Lotto {
    int count1; // 당첨횟수를 저장한 변수
    int count2; // 당첨횟수를 선택정렬로 정리하여 저장한 변수
    int number1; // 당첨횟수를 가르키는 로또번호의 주소
    int number2; // 선택정렬로 정리한 당첨횟수를 가르키는 로또번호의 주소
};
/* 홀수 짝수 가중치 담는 구조체  짝수_홀수_카운트 예) six_zero 일 경우 짝수 6 홀수 0  */
struct Weight {
    int six_zero_count; 
    int five_one_count;
    int four_two_count;
    int three_three_count;
    int two_four_count;
    int one_five_count;
    int zero_six_count;
};

struct Weight weight[1]; // 가중치 구조체를 선언하여 weight 이름으로 구조체 변수 선언


struct Lotto list[45]; /* 로또번호와 당첨횟수를 담는 구조체를 list 이름으로 45개의 구조체 변수 선언 
                       45개로 선언한 이유는 로또번호 1에서 45까지 담을 구조체를 만들기 위해서이다.*/


//void file_read() {
//    char ch;
//    FILE* fp;
//    fp = fopen("C:\\Users\\User\\Source\\Repos\\GitHub_Lotto\\Lotto\\Lotto\\db.txt", "rt");
//    // 파일의 경로가 컴파일 된 프로그램 위치에 존재하지 않는경우 전체 경로 입력 역슬래쉬 두번입력
//    // ex) fopen("C:\\Users\\user\\Documents\\test.txt", "rt"); 
//
//    if (fp == NULL) { // fopen함수가 정상적으로 작동되지 않는다면 NULL값 반환
//        printf("파일 읽기 오류");
//        return -1; // 에러 발생을 알리는 값 -1 리턴
//    }
//
//    while ((ch = fgetc(fp)) != EOF) { // fgetc()함수로 fp가 가리키는 파일에 문자를 가져와서 ch에 저장. 그 값이 EOF(-1)가 아닐 때 까지 반복  
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
//    fputs(arr, fp); // 배열 arr에 있는 문자열을 fp가 가리키는 파일에 출력
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
//    fputs(arr, fp); // 배열 arr에 있는 문자열을 fp가 가리키는 파일에 출력
//
//    fclose(fp);
//}


void highcheck_print(int a) // 확률이 높은 숫자를 출력하는 함수
{
    printf("\n확률이 높은 숫자 10개\n");
    for (int i = 44; i > 34; i--)
        printf("번호: %d번 당첨 횟수: %d\n", list[i].number2, list[i].count2);
}

void lowcheck_print(int a) // 확률이 낮은 숫자를 출력하는 함수
{
    printf("\n확률이 낮은 숫자 5개\n");
    for (int i = 0; i < 5; i++)
        printf("번호: %d번 당첨 횟수: %d\n", list[i].number2, list[i].count2);
}

//void recommend_lottonum()
//{
//    for (int i = 44; i > 34; i--)
//    {
//        
//    }
//}

void count_check() // 프로그램을 통해 나온 당첨횟수를 오름차순으로 나열해주는 함수
{
    int i, j;
    int temp;
    for (i = 0; i < 45; i++) // 로또번호와 당첨횟수를 count1에서 count2로 옴기는 반복문
    {
        list[i].count2 = list[i].count1;
        list[i].number2 = list[i].number1;
        for (j = 0; j < i; j++) // 당첨횟수를 비교하여 오름차순으로 나열한다.
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

void user_lotto() //로또번호를 생성하는 함수
{
    int i, j, o;
    int temp;
    int odd_number = 0; // 홀수 변수
    int even_number = 0; // 짝수 변수

    for (i = 0; i < 6; i++) // 로또 번호 6개를 뽑고 뽑을 때마다 짝수인지 홀수인지 비교하여 변수에 저장한다.
    {
        ary[i] = rand() % 45 + 1;
        if (ary[i] % 2 == 0)
            even_number++;
        else if (ary[i] % 2 == 1)
            odd_number++;

        for (o = 0; o < 45; o++) // 로또번호의 당첨횟수를 증가시키는 반복문
        {
            list[o].number1 = o + 1;
            if (ary[i] == list[o].number1)
                list[o].count1++;
        }

        for (j = 0; j < i; j++) // 로또 번호가 나왔을 때 오름차순으로 정렬시켜주는 반복문
        {
            if (ary[i] < ary[j])
            {
                temp = ary[i];
                ary[i] = ary[j];
                ary[j] = temp;


            }


            if (ary[i] == ary[j]) // 중복일시 당첨횟수를 줄이고 짝수 홀수 카운팅횟수를 줄이는 조건문
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
        if (i == 5) // 짝수 홀수 나오는 횟수를 가지고 경우의 수를 구별하는 조건문
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

    for (int i = 0; i < 6; i++) // 생성된 로또번호를  출력하는 반복문
    {
        printf("[%d] ", ary[i]);
        if (i == 6) {
            printf("\n");
            break;
        }
    }
}

void answer_lotto() // 당첨번호를 출력하는 함수
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
            printf("보너스 번호 : [%d] ", ary[i]);
            break;
        }

        printf("[%d] ", ary[i]);
    }
}

//void winner_print()
//{
//    int ary[6] = { 1, 2, 3, 4, 5, 6 };
//    printf("1등은 %d 입니다.\n");
//    printf("2등은 %d 입니다.\n");
//    printf("3등은 %d 입니다.\n");
//}

void buy_result(int a, int b) // 결제종류와 구매한 가격을 출력히는 함수
{
    switch (a) {
    case 1:
        printf("신용카드 %d원 결제가 되었습니다.\n", b);
        break;
    case 2:
        printf("현금 %d원 결제가 되었습니다.\n", b);
        break;
    case 3:
        printf("휴대폰 %d원 결제가 되었습니다.\n", b);
        break;
    case 4:
        printf("문화상품권 %d원 결제가 되었습니다.\n", b);
        break;
    }
}

void chance(int a) // 로또를 할껀지 여부를 선택하는 함수
{
    switch (a) {
    case 'y':
        break;
    case 'n':
        break;
    }
}

int money_check(int tn) // 구매한 로또를 1개당 1000원으로 계산하여 총 가격을 추출하는 함수
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

void view_init() // 화면 초기화 함수
{
    for (int i = 0; i < 20; i++)
        printf("\n");
}

void auto_print(int a) // a라는 변수 값을 받아 a 횟수 만큼 로또번호를 생성해서 출력하는 함수
{
    for (int i = 1; i < 10001; i++)
    {
        if (a >= i) {
            printf("[%d]번째 로또번호: ", i);
            user_lotto(); //로또 생성하는 함수
            printf("\n");
        }

    }
}

void manual_print(int a, int* b) // 수동 입력한 로또 번호 값을 출력해주는 함수
{
    for (int o = 0; o < a; o++)
    {
        printf("로또번호: ");
        for (int i = 0; i < 7; i++)
        {
            printf("[%d] ", b[i]);
        }
        printf("\n");
    }
}

void lotto_manual(int a, int* b) // 수동 입력을 했을 때 로또 번호 6자리를 받는 함수
{
    int temp;
    printf("숫자를 입력해주세요\n");
    for (int o = 0; o < a; o++)
    {
        printf("%d번째 로또\n", o + 1);
        for (int i = 0; i < 6; i++)
        {
            printf("%d번째 수:", i + 1);

            scanf("%d", &b[i]);


            for (int j = 0; j < i; j++)
            {
                if (b[i] > 45) {
                    i--;
                    printf("1 ~ 45 사이의 값을 입력하시오.\n");
                    break;
                }

                if (b[i] < b[j])
                {
                    temp = b[i];
                    b[i] = b[j];
                    b[j] = temp;
                }

                if (b[i] == b[j]) {
                    printf("중복된 값은 안됩니다.\n");
                    i--;
                }
            }
        }
    }
}

void auto_lotto(int a, int b) // 수동입력할지 자동입력할지 여부를 결정하는 함수
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
        printf("오류 다시 하시오.");
        break;
    }
}

