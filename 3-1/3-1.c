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

	//변환
	for (i = 0; i < len; i++) {
		out[i] = "";
		if (in[i] >= 'A' && in[i] <= 'Z') out[i] = in[i] + idff;
		else if (in[i] >= 'a' && in[i] <= 'z') out[i] = in[i] - idff;
		else out[i] = in[i];	
	}
	///문자열의 마지막에 NULL이 나오는 순간 문자열이 끝났다고 인식한다.
	//즉, 문자열이 끝나는 index에만 NULL(\0)을 넣어주면 된다.
	out[len] = NULL;

	printf("변환된 문자 => %s\n", out);
}