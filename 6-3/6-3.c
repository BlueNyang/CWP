#include <stdio.h>

struct student {
	int number;
	char name[10];
	double grade;
	struct student* next;
};

int main(void) {
	struct student s1 = { 20231111, "Kim", 4.3, NULL };
	struct student s2 = { 20232222,"Park", 3.7, NULL };
	struct student* first;
	struct student* current;

	first = &s1;
	s1.next = &s2;
	s2.next = NULL;

	current = first;
	while (current != NULL) {
		printf("학번 : %d,\t이름 : %s,\t평점 : %.2f\n",
			current->number, current->name, current->grade);
		current = current->next;
	}

	return 0;	
}