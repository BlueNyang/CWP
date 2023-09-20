#pragma warning(disable:4996)
#include <stdio.h>

void main() {
	for (int i = 0; i == 0;) { //결과를 반복해서 확인하기 위한 while
		int x = 0, y = 0;
		char xy = NULL;
		//반복하는 동안 값을 계속 초기화, 가독성 면에서 반복문 내 선언

		printf("**** result *****\n\n");
		printf("input X xy Y == ? ");
		scanf("%d %c %d", &x, & xy, &y);

		rewind(stdin); //입력후 스트림 초기화용(반복문 때문에 넣은 구문)

		//예제 1-4 실습 내용
		switch (xy)
		{
		case '*':
			printf("%d * %d = %d\n\n", x, y, x * y);
			break;
		case '/':
			printf("%d / %d = %d\n\n", x, y, x / y);
			break;
		case '+':
			printf("%d + %d = %d\n\n", x, y, x + y);
			break;
		case '-':
			printf("%d - %d = %d\n\n", x, y, x - y);
			break;

		default:
			printf("잘못된 기호\n\n"); //아무거나 적으면 종료
			i = 1;
			break;
		} 
	}
}
