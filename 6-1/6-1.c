#include <stdio.h>

struct student {
	int number;
	char name[20];
	double grade;
};

struct student list[] = {
	{20230001, "홍길동", 4.2},
	{20230002, "김철수", 3.2},
	{20230002, "김영희", 3.9}
};

int main(void) {
	struct student super_stu;

	int size = sizeof(list) / sizeof(list[0]);
	super_stu = list[0];

	for (int i = 0; i < size; i++)
		if (list[i].grade > super_stu.grade) super_stu = list[i];

	printf("평점이 가장 높은 학생은 (이름: %s, 학번: %d, 평점: %.2f) 입니다.\n",
		super_stu.name, super_stu.number, super_stu.grade);

	return 0;
}