#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ARROW 224

void GoToXY(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void CursorView(char show) {
	CONSOLE_CURSOR_INFO console_cursor = { show, 1 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &console_cursor);
}
void SetColor(unsigned int text, unsigned int back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
int x = 30, y = 7;
int main(void) {
	CursorView(0); GoToXY(x, y); SetColor(6, 0); printf("¡Ú");
	while (1) {
		int nkey = _getch();
		if (nkey == ARROW) {
			nkey = _getch();
			switch (nkey) {
			case UP:
				system("cls"); GoToXY(x, --y); printf("¡Ú"); break;
			case DOWN:
				system("cls"); GoToXY(x, ++y); printf("¡Ú"); break;
			case LEFT:
				system("cls"); GoToXY(x = x - 2, y); printf("¡Ú"); break;
			case RIGHT:
				system("cls"); GoToXY(x = x + 2, y); printf("¡Ú"); break;
			}
		}
	}
}