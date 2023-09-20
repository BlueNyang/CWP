#pragma warning(disable:4996)
#include <stdio.h>

void main() {

	while (1) { //결과를 반복해서 확인하기 위한 while
		int x = 0, y = 0;
		char xy = NULL;
		//반복하는 동안 값을 초기화, 가독성을 위해 반복문 내에 선언

		printf("**** result *****\n\n");
		printf("input X xy Y == ? ");
		scanf("%d %c %d", &x, & xy, &y);

		rewind(stdin); //입력후 스트림 초기화용(반복문 때문에 넣은 구문)

		//예제 실습 내용
		if (xy == '*')
			printf("%d * %d = %d\n\n", x, y, x * y);
		else if (xy == '/')
			printf("%d / %d = %d\n\n", x, y, x / y);
		else if (xy == '+')
			printf("%d + %d = %d\n\n", x, y, x + y);
		else if (xy == '-')
			printf("%d - %d = %d\n\n", x, y, x - y);

		else { //아무글자나 넣으면 반복문 탈출
			printf("올바르지 않은 기호\n\n");
			break;
		}
	};
}
