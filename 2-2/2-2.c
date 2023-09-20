#include <stdio.h>

void main() {
	int i = 1, s = 0; //for문 처럼 i를 선언할 수 없으므로 미리 선언 및 초기화
	while (i <= 50) {
		s += i; i++;
	}
	printf("Sum from 1 to 50 = %d\n", s);
}