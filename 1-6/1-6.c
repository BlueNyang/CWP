#pragma warning(disable:4996)
#include <stdio.h>

void main() {


	for (int month = 0; month != 404;) { //결과를 반복하여 확인하기 위한 for문(404로 빠져나가기)
		int days = 0; //계속 초기화

		printf("달을 입력하시오: ");
		scanf("%d", &month);

		//실습 내용
		switch (month) { //switch의 단점: case에서 관계연산자의 사용이 불가능하다.
		case 2:
			days = 28;
			break;
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: {
			days = 31;
			break;
		}
		case 4: case 6: case 9: case 11: {
			days = 30;
			break;
		}
		default:
			printf("달의 값은 1~12 사이의 정수 입니다\n\n");
		};
	
		if (days) //초기화 후 값이 입력되지 않으면 (month가 1~12 사이가 아니면) 출력되지 않게끔 조정.
			printf("%d월의 일수는 %d일입니다.\n\n", month, days);
	};
}