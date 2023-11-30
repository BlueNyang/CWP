#include "Blocks.h"
#include "Controller.h"
#include "Screen.h"
#include "ConsoleCursor.h"

int main(void) {
	CursorView(false);
	system("mode con cols=76 lines=28 | title 창의실무프로젝트_테트리스 실습");

	//PlaySound(Text(BGM), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	while (true) {
		GameTitle();
		GameProcess();
	}
}