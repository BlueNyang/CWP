#pragma warning(disable:4996)
#include <stdio.h>

void main() {
	
	//조건문에 관한 내용이나, 실행 후 결과를 한번에 확인하기 위해 반복문을 사용

	for (int num = 0; num != 404;) { //404(임의 값)를 넣기 전까지 반복해서 결과를 확인하기 위한 while문
		printf("enter a number: ");
		scanf("%d", &num);

		//실습내용
		switch (num >> 31)
		{
		case 404: //임의값 입력시 다른 동작 없이 반복문을 빠져 나가기 위해 추가
			break;
		case -1:
			printf("number is negative\n");
			break;
		default:
			printf("number is positive\n");
			break;
		}
	 }
};