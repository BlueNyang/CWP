#include <stdio.h>

int Add(int a, int b);
int Sub(int a, int b);

void main() {
	int nResult;
	int(* p)(int, int);
	printf("100°ú 200ÀÇ µ¡¼À°ú –E¼À ¿¬»ê\n");
	 
	p =Add;
	nResult = p(100, 200);
	printf("µ¡¼À°á°ú : %d\n", nResult);

	p = Sub;
	nResult = p(100, 200);
	printf("»¬¼À°á°ú : %d\n", nResult);
}

int Add(int a, int b) {
	printf("\nAdd ÇÔ¼ö\n");
	return a + b;
}

int Sub(int a, int b) {
	printf("\nSub ÇÔ¼ö\n");
	return a - b;
}