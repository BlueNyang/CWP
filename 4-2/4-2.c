#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void delete_middle(int* s, int** arr);

void main() {
	int n = 0;
	while (n % 2 != 1)
		scanf("%d", &n);
	printf("\n");
	int* nP = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &nP[i]);

	delete_middle(&n, &nP);
	printf("\n");

	for (int i = 0; i < n; i++)
		printf("%d ", nP[i]);

	free(nP);
}

void delete_middle(int* s, int** arr) {
	int newSize = *s - 1;
	int* temp = (int*)malloc(sizeof(int) * newSize);
	int j = 0;
	for (int i = 0; i < *s; i++) {
		if (j == *s / 2) i++;
		temp[j] = (*arr)[i];
		j++;
	}

	free(*arr);

	*arr = temp;
	*s = newSize;
}