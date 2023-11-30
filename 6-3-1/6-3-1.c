#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

#define NEW_S 1
#define MOD_S 0

//실패작...

struct student {
	int sNum;
	char name[12];
	double grade;
	struct student* next;
};

static struct student* list = NULL;

static struct Meta {
	int count;
	int size;
	struct student* index0;
	struct student** start;
}m1;

int get_student(int index);
void add_student(struct student** s, int index);
void remove_student(int index);
void modify_student(int index, struct student s);
void print_student(int index);
void print_all();
void gets_student();

int main(void) {

	list = malloc(sizeof(struct student));
	m1.count = 0;
	m1.size = 1;
	m1.index0 = list;
	m1.start = &m1.index0;
	int select;
	int chosen_index;

	int loop = 1;

	while (loop) {
		printf("1. add, 2. remove, 3 modify, 4. find, 5.print all, 6. exit\n");
		printf("항목 선택: ");
		scanf("%d", &select);
		switch (select) {
		case 1:
			gets_student(NEW_S);
			break;
		case 2:
			printf("\n--------------------------------------\n");
			printf("삭제할 인덱스 선택(음수 입력시 취소: ");
			scanf("%d", &chosen_index);
			remove_student(chosen_index);
			break;
		case 3:
			gets_student(MOD_S);
			break;
		case 4:
			printf("인덱스를 입력 : ");
			scanf("%d", &chosen_index);
			print_student(chosen_index);
			break;
		case 5:
			print_all();
			break;
		case 6:
			loop = 0;
			break;
		default:
			printf("올바르지 않은 항목\n\n");
			break;
		}
	}
	return 0;
}

int get_student(int index, struct student** temp) {
	if (index == -1) index = m1.count;
	if (index >= 0 && index <= m1.count) {
		(*temp) = m1.start;
		int i = 0;
		while (i < index)
		{
			if (i == 0)
				(*temp) = *m1.start;
			else
				(*temp) = (*temp)->next;
			i++;
		}
		return 1;
	}
	else return 0;
}

void add_student(struct student* s, int index) {
	struct student* temp;
	int result = get_student(index, &temp);
	if (result) {
		if (index == 0) {
			(*m1.start) = &s;
			(*s).next = temp;
		}
		else {
			(*s).next = temp->next;
			temp->next = &s;
		}
		m1.count++;
	}
	else
		printf("\n올바르지 않은 인덱스\n");
}

void remove_student(int index) {
	struct student* temp;
	int result = get_student(index, &temp);
	if (result) {
		struct student* temp2;
		temp2 = temp->next;
		temp->next = temp2->next;
		temp2->sNum = NULL;
		temp2->next = NULL;
		m1.count--;
	}
	else
		printf("\n올바르지 않은 인덱스\n");
}

void modify_student(int index, struct student* s) {
	remove_student(index);
	add_student(s, index);
}

void print_student(int index) {
	struct student* s;
	int result = get_student(index, &s);
	if (result) {
		s = s->next;
		printf("학번: %d\n", s->sNum);
		printf("이름: %s\n", s->name);
		printf("성적: %.2f\n\n", s->grade);
	}
	else
		printf("\n올바르지 않은 인덱스\n");
}

void print_all() {
	int count = m1.count;
	for (int i = 0; i < count; i++) {
		print_student(i);
	}
}

void gets_student(int mode) {
	int index;
	struct student* temp;


	if (m1.size <= m1.count + 1) {
		int newSize = m1.size + 1;
		temp = (struct student*)malloc(sizeof(struct student) * newSize);
		for (int i = 0; i < m1.size; i++) temp[i] = list[i];
		free(list);
		list = temp;
		free(temp);
		temp = &list[m1.size];
		m1.size = newSize;
	}
	else {
		int i = 0;
		while (list[i].sNum != NULL) {
			i++;
		}
		temp = &list[--i];
	}

	printf("\n--------------------------------------\n");
	printf("인덱스를 입력(-1 입력 시, 마지막에 자동 배치):");
	scanf("%d", &index);
	printf("학번을 입력: ");
	scanf("%d", &temp->sNum);
	printf("이름을 입력: ");
	getchar();
	gets(temp->name);
	printf("학점을 입력: ");
	scanf("%.2f", &temp->grade);

	if (mode)
		add_student(temp, index);
	else
		modify_student(index, temp);
	printf("\n\n");
}