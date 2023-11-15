#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ARROW 224
#define A 97
#define D 100
#define S 115
#define W 119
#define CMD_H 114
#define CMD_V 27

//별이 돌아다니면서 총알을 쏘는 게임
//구조체+멀티쓰레드+CMD 조작

struct Point {
	int X;
	int Y;
};
struct Point star = { 30, 7 };

void GoToXY(struct Point point) {
	COORD Pos;
	Pos.X = point.X;
	Pos.Y = point.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void CursorView(char show) {
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}
void SetColor(unsigned short text, unsigned short back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

void Shooting(int nkey) {
	struct Point bullet = { star.X, star.Y };
	int end = 0;
	for (int i = 0; i < 10; i++) {
		if (bullet.X != star.X || bullet.Y != star.Y) { GoToXY(bullet); printf(" "); }
		switch (nkey) {
		case A:
			if (bullet.X == 0) { end = 1; break; }
			bullet.X -= 2; break;
		case D:
			if (bullet.X == CMD_H) { end = 1; break; }
			bullet.X += 2; break;
		case W:
			if (bullet.Y == 0) { end = 1; break; }
			--bullet.Y; break;
		case S:
			if (bullet.Y == CMD_V) { end = 1; break; }
			++bullet.Y; break;
		}
		if (end) break;
		GoToXY(bullet);
		printf("ㆍ");
		Sleep(100);
	}
	if (bullet.X != star.X || bullet.Y != star.Y) { GoToXY(bullet); printf(" "); }
}

CRITICAL_SECTION cs1;
void MoveStar(int nkey) {
	GoToXY(star); printf(" ");
	switch (nkey) {
	case UP:
		if(star.Y != 0) --star.Y; break;
	case DOWN:
		if(star.Y != CMD_V) ++star.Y; break;
	case LEFT:
		if(star.X != 0) star.X -= 2; break;
	case RIGHT:
		if(star.X != CMD_H) star.X += 2; break;
	}
	GoToXY(star); printf("★");
}

int main(void) {
	CursorView(0); SetColor(6, 0);
	system("mod con: cols=%d lines=%d", CMD_H, CMD_V);
	while (1) {
		system("cls"); GoToXY(star);  printf("★");
		HANDLE Thread1 = NULL;
		HANDLE Thread2 = NULL;
		int nkey = _getch();
		if (nkey == ARROW) {
			nkey = _getch();
			Thread1 = _beginthreadex(NULL, 0, (_beginthreadex_proc_type)MoveStar, (void*)nkey, 0, NULL);
		}
		if (nkey == A || nkey == D || nkey == W || nkey == S) {
			Thread2 = _beginthreadex(NULL, 0, (_beginthreadex_proc_type)Shooting, (void*)nkey, 0, NULL);
		}
		if (Thread1 != NULL) {
			WaitForSingleObject(Thread1, INFINITE);
			DeleteCriticalSection(&cs1);
		}
		Sleep(10);
	}
	return 0;
}