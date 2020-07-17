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
    static int number = 1; // 로또 회차 담는 변수
    static int total = 583900000; // 로또 총 금액 담는 변수
    int tn, mn; // 
    int hm = 0;
    int i, j, o;
    char qs;
    int value[7] = { 1, 2, 3, 4, 5, 6, 7 };
    srand((unsigned)time(NULL));
    while (1) {
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("---------- 로또 프로그램 ----------\n");
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("---------------%d회차---------------\n", number);
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("1장 1000원. \n한번에 최대 100장까지 구매 가능합니다! \n");
        printf("몇장 구매하시겠습니까?\n");
        scanf("%d", &tn);
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("결제 하실 시스템을 선택해주세요. \n");
        printf(" 1번\t신용카드 결제\n 2번\t현금 결제\n 3번\t휴대폰 결제\n 4번\t문화상품권 결제\n");
        printf("-----------------------------------\n");
        scanf("%d", &mn);

        for (i = 1; i < 101; i++)
        {
            if (tn >= i)
                hm += 1000;
        }


        switch (mn) {
        case 1:
            printf("신용카드 %d원 결제가 되었습니다.\n", hm);
            break;
        case 2:
            printf("현금 %d원 결제가 되었습니다.\n", hm);
            break;
        case 3:
            printf("휴대폰 %d원 결제가 되었습니다.\n", hm);
            break;
        case 4:
            printf("문화상품권 %d원 결제가 되었습니다.\n", hm);
            break;
        }

        printf("일확천금의 기회를 노리시겠습니까?(y/n)\n");
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
                printf("%d번째: ", i);
                user_lotto();
                printf("\n");
                total += 1000;
            }

        }

        printf("당첨되면 %d원을 얻으실수있습니다.\n", total);
        printf("%d회차 당첨번호는?\n", number);

        getch(); // 잠시 멈추게 해주는 함수. 아무 키 입력시 코드 진행


        printf("\n당첨번호는 ");
        user_lotto();
        printf("입니다. ");
        getch();
        number++;
    }

}

