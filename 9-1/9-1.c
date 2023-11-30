#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#define DINO_BOTTOM_Y 12
#define TREE_BOTTOM_Y 20
#define TREE_BOTTOM_X 45
#define FALSE 0
#define TRUE 1

enum {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VIOLET,
	DARK_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE
};

void CursorView(char show) {
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);
}
void SetConsoleView() {
	system("mod con : cols=100 lines=25");
	system("title 창의실무프로젝트 구글 공룡게임 [By. YongWun Kim] - 20202717");
	CursorView(FALSE);
}
void SetColor(unsigned short text) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

void GoToXY(int x, int y) {
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKeyDown() {
	if (_kbhit() != 0) return _getch();
	return FALSE;
}

int IsCollision(const int treeX, const int dinoY) {
	GoToXY(0, 0);
	printf("treeX : %d, dinoY : %d", treeX, dinoY);
	if (treeX <= 8 && treeX >= 4 && dinoY > 8) return TRUE;

	return FALSE;
}

void DrawDino(int dinoY) {
	SetColor(SKYBLUE);
	GoToXY(0, dinoY);
	static int legFlag = TRUE;
	printf("        $$$$$$$ \n");
	printf("       $$ $$$$$$\n");
	printf("       $$$$$$$$$\n");
	printf("$      $$$      \n");
	printf("$$     $$$$$$$  \n");
	printf("$$$   $$$$$     \n");
	printf(" $$  $$$$$$$$$$ \n");
	printf(" $$ ");
	SetColor(RED);
	printf("원광대");
	SetColor(SKYBLUE);
	printf("$$$    \n");
	printf("  $$$");
	SetColor(BLUE);
	printf("컴소공");
	SetColor(SKYBLUE);
	printf("$    \n");
	printf("    $$$$$$$$    \n");
	printf("     $$$$$$      \n");
	if (legFlag) {
		printf("     $    $$$   \n");
		printf("     $$         ");
		legFlag = FALSE;
	}
	else {
		printf("     $$$  $     \n");
		printf("          $$    ");
		legFlag = TRUE;
	}
}

void DrawTree(int treeX) {
	SetColor(GREEN);
	GoToXY(treeX, TREE_BOTTOM_Y);
	printf("$$$$");
	GoToXY(treeX, TREE_BOTTOM_Y + 1);
	printf("$$$$");
	GoToXY(treeX, TREE_BOTTOM_Y + 2);
	printf("$$$$");
	SetColor(DARK_YELLOW);
	GoToXY(treeX, TREE_BOTTOM_Y + 3);
	printf(" $$ ");
	GoToXY(treeX, TREE_BOTTOM_Y + 4);
	printf(" $$ ");
}

void DrawGameOver(const int score) {
	system("cls");
	SetColor(YELLOW);
	int x = 16, y = 6;
	GoToXY(x, y);
	printf("===================================");
	GoToXY(x, y + 1);
	printf("==========G A M E O V E R==========");
	GoToXY(x, y + 2);
	printf("===================================");
	GoToXY(x, y + 5);
	printf("SCORE : %d", score);
	GoToXY(x, y + 14);
	system("pause");
}

int main(void) {
	SetConsoleView();

	while (TRUE) {
		int isJumping = FALSE;
		int isBottom = TRUE;
		const gravity = 3;

		int dinoY = DINO_BOTTOM_Y;
		int treeX = TREE_BOTTOM_X;

		int score = 0;
		clock_t start, curr;
		start = clock();
		while (TRUE) {
			if (IsCollision(treeX, dinoY)) break;

			if (GetKeyDown() == ' ' && isBottom) {
				isJumping = TRUE;
				isBottom = FALSE;
			}

			if (isJumping) dinoY -= gravity;
			else dinoY += gravity;

			if (dinoY >= DINO_BOTTOM_Y) { dinoY = DINO_BOTTOM_Y; isBottom = TRUE; }	

			treeX -= 2;
			if (treeX <= 0) treeX = TREE_BOTTOM_X;

			if (dinoY <= 3) isJumping = FALSE;

			DrawDino(dinoY);
			DrawTree(treeX);

			curr = clock();
			if (((curr - start) / CLOCKS_PER_SEC) >= 1) {
				score++;
				start = clock();
			}

			Sleep(30);
			system("cls");

			SetColor(WHITE);

			GoToXY(22, 0);
			printf("SCORE : %d", score);

			GoToXY(2, 2);
			printf("JUMP : SPACE");
		}

		DrawGameOver(score);
	}

	return FALSE;
}