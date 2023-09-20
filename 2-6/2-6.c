#include <stdio.h>

void main() {

	int i, j, su, dan;

	for (i = 0; i < 3; i++) {
		for (su = 1; su < 10; su++) {
			for (j = 1; j < 4; j++) {
				dan = 3 * i + j;
				if (dan % 2 == 1) printf("%d * %d = %2d\t", dan, su, dan * su);
				else printf("\t\t");
			}
			printf("\n");
		}
		printf("\n");
	}
}