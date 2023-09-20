#pragma warning(disable:4996)
#include <stdio.h>

void main() {
    int num;

    printf("enter a number: ");
        scanf("%d", &num);

    if (num < 0) printf("number is negative\n");
    else printf("numver is positive\n");
};