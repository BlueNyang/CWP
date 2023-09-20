#include <stdio.h>

void main() {
	int s = 0;
	for (int i = 1; i <= 50; i++) { //for문 블럭 안에서만 사용한 i를 선언 후 반복 마다 값을 늘리도록 설정
		s += i; //s에 i를 더해서 저장
	}

	printf("Sum from 1 to 50 = %d\n\n", s);
}