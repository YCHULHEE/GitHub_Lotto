#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include "lotto.h"


int main(void)
{
    static int number = 1; // 로또 회차 담는 변수
    static int total = 578422000; // 로또 총 금액 담는 변수
    int tn, mn; // 
    static int hm = 0;
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

        hm = money_check(tn); // 현재 이용한 금액을 체크해서 hm 이라는 변수에 저장해줍니다.

        buy_result(mn, hm); // 구매한 
        printf("일확천금의 기회를 노리시겠습니까?(y/n)\n");
        scanf("%d", &qs);
        chance(qs);



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
        tn = 0;
        hm = 0;
        qs = 'n';

        rewind(stdin); // scanf 버퍼 초기화!
        view_init();
    }

}

