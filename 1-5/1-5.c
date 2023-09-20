#pragma warning(disable:4996)
#include <stdio.h>

void main() {
		

	for (int month = 0; month != 404;) { //결과를 반복하여 확인하기 위한 for문(404로 빠져나가기)
		int days = 0; //계속 초기화

		printf("달을 입력하시오: ");
		scanf("%d", &month);

		//실습 내용
		if (month > 12 || month < 1) //1~12 사이의 값만 받기
			printf("달의 값은 1~12사이의 정수입니다 \n\n");
		else if (month == 2) //2월은 예외
			days = 28;
		else if ((month <= 7 && month % 2 == 0) || (month > 7 && month % 2 == 1)) //나머지 달의 조건, if의 장점. 복잡한 '조건'을 지정할 수 있음
			days = 30;
		else
			days = 31;


		if (days) //초기화 후 값이 입력되지 않으면 (month가 1~12 사이가 아니면) 출력되지 않게끔 조정.
			printf("%d월의 일수는 %d일입니다.\n\n", month, days);
	};
}