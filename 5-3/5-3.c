#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

void bubble(char*, int);

void main() {
	char str[80];

	printf("문자열입력 : ");
	gets(str);
	bubble(str, strlen(str));
	printf("문자열을 버블 정렬한 결과 : %s\n", str);
}

void bubble(char* str, int count) {
	int nPass = 0;
	int nChange = 1;
	char cTemp;

	printf("bubble 영역\n");
	while (nPass < count && nChange == 1) {
		nChange = 0;
		for (int i = 0; i < count - nPass - 1; i++) {
			if (str[i] > str[i + 1]) {
				nChange = 1;
				cTemp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = cTemp;
			}
		}
		nPass++;
	}

}