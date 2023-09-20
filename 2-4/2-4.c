#include <stdio.h>

void main() {

	int i, j, su, dan;

	for (i = 0; i <= 2; i++) { //행에서 단이 넘어가는 for문
		for (su = 1; su <= 9; su++) { //단에서 1~9까지 곱하는 행을 담당
			for (j = 1; j <= 3; j++) { //열에서 단이 넘어가는 걸 담당
				dan = 3 * i + j; //매 행에서 출력될 단을 지정
				printf("%d * %d = %2d\t", dan, su, dan * su);
			}
			printf("\n");
		}
		printf("\n");
	}
}