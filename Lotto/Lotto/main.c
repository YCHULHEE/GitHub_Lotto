#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include "lotto.h"


int main(void)
{
    static int number = 1; // 로또 회차 담는 변수
    static int total = 578422000; // 로또 총 금액 담는 변수
    int tn, mn; // 로또 변수
    static int hm = 0; // 결제 금액 담는 변수
    char qs; // y/n 값 받는 변수
    int at_num; // 수동 자동 저장하는 변수
    int manual_aray[] = { 0, }; // 저장되는 변수

    srand((unsigned)time(NULL));  //시간을 이용한 시드값 설정하는 함수

    while (1) {
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("---------- Lotto Program ----------\n");
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("---------------%dround--------------\n", number);
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("1장 1000원. \n한번에 최대 10장까지 구매 가능합니다! \n");
        printf("몇장 구매하시겠습니까?\n");
        scanf("%d", &tn); // 티켓 구매 횟수
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("1.\t자동 입력\n2.\t수동 입력\n");
        scanf("%d", &at_num);
        printf("-----------------------------------\n");
        printf("-----------------------------------\n");
        printf("결제 하실 시스템을 선택해주세요. \n");
        printf(" 1번\t신용카드 결제\n 2번\t현금 결제\n 3번\t휴대폰 결제\n 4번\t문화상품권 결제\n");
        printf("-----------------------------------\n");
        scanf("%d", &mn);
        hm = money_check(tn); // 현재 이용한 금액을 체크해서 hm 이라는 변수에 저장해줍니다.
        buy_result(mn, hm); // 뭐로 결제하고 금액은 얼마인지 알려주는 함수.
        printf("일확천금의 기회를 노리시겠습니까?(y/n)\n");
        scanf(" %c", &qs); // 로또할 의사를 받는 변수
        total = total + 1000 * tn;
        chance(qs);
        auto_lotto(at_num, tn);



        printf("당첨되면 %d원을 얻으실수있습니다.\n", total);
        printf("%d회차 당첨번호는?\n", number);
        getch(); // 잠시 멈추게 해주는 함수. 아무 키 입력시 코드 진행
        count_check();
        printf("\n당첨번호는 ");
        answer_lotto();
        printf("입니다.\n");
        
        getch(); // 잠시 프로그램 동작을 멈추는 함수
        highcheck_print(tn);
        getch();
        lowcheck_print(tn);
        /*print_chance(void);*/
        auto_print1(10);
        getch();
        number++;
        hm = 0;
        qs = 'n';
        rewind(stdin); // scanf 버퍼 초기화!
        view_init();


    }

}
