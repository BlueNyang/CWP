#include "Blocks.h"
#include "Controller.h"
#include "Screen.h"
#include "ConsoleCursor.h"

int main(void) {
	CursorView(false);
	system("mode con cols=76 lines=28 | title â�ǽǹ�������Ʈ_��Ʈ���� �ǽ�");


	while (true) {
		GameTitle();
		GameProcess();
	}
}