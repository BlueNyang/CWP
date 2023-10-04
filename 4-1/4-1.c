#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void size_add(int* s, int** arr);

void main() {
	int i = 0;
	int nSize = 3;

	int* nP = (int*)malloc(sizeof(int) * nSize);

	scanf("%d", &nP[0]);

	if (nP[0] != -1) {
		do {
			i++;
			scanf("%d", &nP[i]);
			if (nP[i] == -1) break;
			if (i + 1 >= nSize) size_add(&nSize, &nP);
		} while (i < 20);
		
		for (int j = 0; j <= i; j++)
			printf("%d ", nP[j]);
	}

	free(nP);
}

void size_add(int* s, int** arr) {
	int newSize = *s + 3;
	int* temp = (int*)malloc(sizeof(int) * newSize);
	for (int i = 0; i < *s; i++) temp[i] = (*arr)[i];
	
	free(*arr);

	*arr = temp;
	*s = newSize;
}