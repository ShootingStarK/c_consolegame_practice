#include "game.h"
#include "util.h"

char tempmap[14][56]; // �� �ӽ������� �迭

char map1[14][56] = { // �����
	{"11111111111111111111111111111111111111111111111111111111"}, // 0 ����� 1 �� k ���� l ��� �� q Ż�ⱸ
	{"10000000100000000000000000000000000000000000000000000001"},
	{"10000000100000000000000000000000000000000000000000000001"},
	{"10001000100000000000000000000000000000000000000000000001"},
	{"10001000100000000000000000000000000000000000000000000001"},
	{"10001000100000000000000000000000000000000000000000000001"},
	{"10001000111111000000000000000000000000000000000000000001"},
	{"10001000000001000000000000000000000000000000000000000001"},
	{"10001000100001000000000000000000000000000000000000000001"},
	{"10001000100k01000000000000000000000000000000000001111111"},
	{"10001000100001000000000000000000000000000000000001000001"},
	{"10s0100011111111111111111111111111111111111111111100q001"},
	{"10001000l00000000000000000000000000000000000000000000001"},
	{"11111111111111111111111111111111111111111111111111111111"}
};

char map2[14][56] = { // �����
	{"11111111111111111111111111111111111111111111111111111111"},
	{"10000000000000000000000000000000000000000000000000000001"},
	{"10000000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000001"},
	{"10s01000000000000000000000000000000000000000000000000001"},
	{"10001000000000000000000000000000000000000000000000000001"},
	{"11111111111111111111111111111111111111111111111111111111"}
};


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

void drawtitle() {
	printf("\n\n\n\n");
	printf("        #####    ###    ###    #    ####   ##### \n");
	printf("        #       #      #      # #   #   #  #     \n");
	printf("        ####    ####   #     #####  ####   ####  \n");
	printf("        #           #  #     #   #  #      #     \n");
	printf("        #####   ####    ###  #   #  #      ##### \n");
}

int drawmenu() {
	int x = 24;
	int y = 12;
	gotoxy(24 - 2, 12);
	printf("> Game Start");
	gotoxy(24, 13);
	printf("Game Information");
	gotoxy(24, 14);
	printf("Exit");
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

void drawinfo()
{
	system("cls");
	printf("\n\n");
	printf("[ �� �� �� ]\n\n");
	printf(" �̵� : W, A, S, D\n");
	printf(" ���� : SPACE BAR\n\n\n\n\n\n\n");
	printf(" ������: someone\n\n");
	printf(" �����̽��ٸ� ������ ����ȭ������ �̵��մϴ�.");

	while (1)
	{
		if (keyControl() == SUBMIT)
		{
			break;
		}
	}
}

int drawmaplist() {
	int x = 24;
	int y = 6;
	system("cls");
	printf("\n\n");
	printf("                  [ �� ���� ]\n\n");

	gotoxy(x - 2, y);
	printf("> �� ��");
	gotoxy(x, y + 1);
	printf("�� �� ��");
	gotoxy(x, y + 2);
	printf("�� ��");

	while (1) {
		int n = keyControl();
		switch (n) {
		case UP:
			if (y > 6) {
				gotoxy(x - 2 , y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		case DOWN:
			if (y < 8) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		case SUBMIT:
			return y - 6;
		}
	}
}

void drawmap(int* x, int* y) {
	system("cls");

	for (int h = 0; h < 14; h++) {
		for (int w = 0; w < 56; w++) {
			char temp = tempmap[h][w];
			if (temp == '0') { // �� ����
				setColor(black, black);
				printf(" ");
			} else if (temp == '1') { // ��
				setColor(white, white);
				printf("#");
			} else if (temp == 's') { // �÷��̾�(@)
				*x = w;
				*y = h;
				setColor(cyan, black);
				printf("@");
			} else if (temp == 'q') { // ������(destonation)(O)
				setColor(lightgreen, black);
				printf("O");
			} else if (temp == 'k') { // ����(*)
				setColor(yellow, black);
				printf("*");
			} else if (temp == 'l') { // ��� ��(X)
				setColor(brown, black);
				printf("X");
			}
		}
		printf("\n");
	}
	setColor(white, black);
}

void GameLoop(int level) {
	int x, y; // �÷��̾� ��ǥ ���� ���� ���� (x, y)
	int key = 0; // ���� ���� ���� ����

	int playing = 1; // 1 �̸� ������, 0 �̸� ���� ����
	
	// level 0 �����, level 1 ������
	if (level == 0) {
		memcpy(tempmap, map1, sizeof(tempmap));
	} else if (level == 1) {
		memcpy(tempmap, map2, sizeof(tempmap));
	}

	drawmap(&x, &y);

	while (playing) {
		drawUI(&x, &y, &key);

		switch (keyControl()) {
		case UP:
			move(&x, &y, 0, -1, &key, &playing);
			break;
		case DOWN:
			move(&x, &y, 0, 1, &key, &playing);
			break;
		case RIGHT:
			move(&x, &y, 1, 0, &key, &playing);
			break;
		case LEFT:
			move(&x, &y, -1, 0, &key, &playing);
			break;
		case SUBMIT:
			playing = 0;
		}
	}
	gotoxy(22, 8);
	printf("Game Clear!");
	Sleep(1500);
}

void move(int* x, int* y, int _x, int _y, int* key, int* playing) { // _x, _y x������ �󸶳� �̵�����, y������ �󸶳� �̵������� ���� ��
	// �̵��� ��ġ�� �ִ� �� �迭�� ���� �ӽ�����
	char mapObject = tempmap[*y + _y][*x + _x];
	setColor(white, black);
	
	if (mapObject == '0') {
		gotoxy(*x, *y);
		printf(" ");

		setColor(cyan, black);
		gotoxy(*x + _x, *y + _y);
		printf("@");

		*x += _x;
		*y += _y;
	} else if (mapObject == 'k') {
		*key += 1;
		tempmap[*y + _y][*x + _x] = '0'; // ȹ���ϸ� ������ k�� 0���� ����
		gotoxy(*x + _x, *y + _y);
		printf(" ");
	} else if (mapObject == 'l') { 
		if (*key > 0) {
			*key -= 1;
			tempmap[*y + _y][*x + _x] = '0';
			setColor(white, black);
			gotoxy(*x + _x, *y + _y);
			printf(" ");
		}
	} else if (mapObject == 'q') {
			*playing = 0;
		}
	}

void drawUI(int* x, int* y, int* key) {
	setColor(white, black);
	gotoxy(3, 16);
	printf("�� ġ : %02d, %02d", *x, *y);

	setColor(yellow, black);
	gotoxy(34, 16);
	printf("���� : %d��", *key);
}