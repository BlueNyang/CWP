#include<stdio.h>
#pragma warning(disable:4996)
#define ROWS 3
#define COLS 3

void main() {
	int A[ROWS][COLS] = { {1,0,0},{0,1,0},{0,0,1} };
	int B[ROWS][COLS] = { {1,0,0},{0,1,0},{0,0,1} };
	int C[ROWS][COLS];

	//2°³ÀÇ Çà·Ä µ¡¼À
	for (int i = 0, j; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
			C[i][j] = A[i][j] + B[i][j];
			printf("  %d  ", C[i][j]);
		}
		printf("\n");
	}
}