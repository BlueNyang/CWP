#include<string.h>
#include <stdio.h>
#pragma warning(disable:4996)

void main() {
	char in[50], out[50];
	int i, len;
	int idff = 'a' - 'A';

	printf(" 문자입력 : ");
	gets(in);

	len = strlen(in);

	//out 초기화
	for (i = 0; i < 50; i++) out[i] = NULL;
	//변환
	for (i = 0; i < len; i++) {
		out[i] = "";
		if (in[i] >= 'A' && in[i] <= 'Z') out[i] = in[i] + idff;
		else if (in[i] >= 'a' && in[i] <= 'z') out[i] = in[i] - idff;
		else out[i] = in[i];	
	}

	printf("변환된 문자 => %s\n", out);
}