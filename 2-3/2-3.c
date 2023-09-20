#include <stdio.h>

void main() {
	int i = 1, s = 0;
	do {
		s += i; i++;
	} while (i <= 50); //do구문 내 실행 후 판단

	printf("Sum from 1 to 50 = %d\n\n", s);

}