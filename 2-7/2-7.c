
#include <stdio.h>

void main() {

	int i, j, su, dan;

	for (i = 0; i < 3 ; i++) {
		for (su = 1; su < 10; su++) {
			for (j = 1; j < 4; j++) {
				dan = 3 * i + j;
				if (su % 2 == 1) printf("%d * %d = %2d\t", dan, su, dan * su);
				else printf("\t\t");
			}
			//if 문을 이용하여 su가 짝수인 경우를 건너 뛸 수도 있지만,
			//출력결과만을 보고 코드를 짠다고 한다면, su를 홀수로 만들고 줄바꿈을 2번 하거나
			//su의 홀짝 값에 따라서 j에 대한 for문의 실행 여부를 판단하는 것이 더 좋을 것 같다.
			//(2-7-1, 2-7-2)
			printf("\n");
		}
		printf("\n");
	}
}