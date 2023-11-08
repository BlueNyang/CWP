#include <stdio.h>
#include <Windows.h>

void gotoxy(short x, short y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView(char show) {
	CONSOLE_CURSOR_INFO Console_Cursor;
	Console_Cursor.bVisible = show;
	Console_Cursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Console_Cursor);
}

int main(void) {
	printf("Press Enter to start: ");		
	getchar();

	CursorView(0);
	srand((unsigned int)time(NULL));
	while (1) {
		gotoxy((rand() % 300) / 2, rand() % 25);
		printf("*");
		Sleep(1);
	}
	
	return 0;
}