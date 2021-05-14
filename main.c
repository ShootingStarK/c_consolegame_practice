#include "main.h"
#include "util.h"

int main() {
	init();
	while (1)
	{
		drawtitle();
		int menuCode = drawmenu();
		if (menuCode == 0){
			int n = drawmaplist();

			if (n == 0) {
				GameLoop(0);
			}
			else if (n == 1) {
				GameLoop(1);
			}
		} else if (menuCode == 1) {
			drawinfo();
		} else if (menuCode == 2) {
			return 0;
		}
		system("cls");
		setColor(white, black);
	}
	return 0;
}

