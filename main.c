#include <stdio.h>
#include <windows.h>

// keyboard value
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

int keyControl();
void init();
void drawtitle();
int drawmenu();
void gotoxy(int x, int y);

int main() {
	init();
	drawtitle();
	drawmenu();
	return 0;
}

int keyControl() {
	char temp = getch();

	if (temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 'a' || temp == 'A') {
		return LEFT;
	}
	else if (temp == 's' || temp == 'S') {
		return DOWN;
	}
	else if (temp == 'd' || temp == 'D') {
		return RIGHT;
	}
	else if (temp == ' ') {
		return SUBMIT;
	}
}

void init() {
	system("mode con cols=56 lines=20");
}

void drawtitle() {
	printf("\n\n\n\n");
	printf("        #####    ###    ###    #    ####   ##### \n");
	printf("        #       #      #      # #   #   #  #     \n");
	printf("        ####    ####   #     #####  ####   ####  \n");
	printf("        #           #  #     #   #  #      #     \n");
	printf("        #####   ####    ###  #   #  #      ##### \n");
}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int drawmenu() {
	int x = 24;
	int y = 12;
	gotoxy(24 - 2, 12);
	printf("> 게 임 시 작");
	gotoxy(24, 13);
	printf("게 임 정 보");
	gotoxy(24, 14);
	printf("   종  료  ");
	while (1)
	{
		int n = keyControl();
		switch (n)
		{
		case UP:
			if (y > 12)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;

		case DOWN:
			if (y < 14)
			{
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
			
		case SUBMIT:
			return y - 12;
		}
	}
}
