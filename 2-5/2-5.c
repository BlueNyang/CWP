#include <stdio.h>

void main() {
	int i = 0, j = 1, su = 1, dan;
	while (i < 3) {

		dan = 3 * i + j; //i, j의 값에 따라 바뀌는 dan의 값을 지정

		if (j <3) { //3개 단씩 끊어서 2개는 tap
			printf("%d * %d = %2d\t", dan, su, dan * su);
			j++;
		}
		else { //3번째에서는 줄바꿈을 한다.
			printf("%d * %d = %2d\n", dan, su, dan * su);
			j = 1;
			su++;
		}

		if (su > 9) { //반복된 후, su가 9가 넘으면, 줄바꿈, su 초기화 및 i증가
			printf("\n");
			su = 1; i++;
		}
	}
}