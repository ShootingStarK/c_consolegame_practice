#include "main.h"

#ifndef KEY_CODE
#define KEY_CODE

// keyboard value
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

#endif

void GameLoop(int);
void move(int*, int*, int, int, int*, int*); // x, y, _x, _y, key, playing
int keyControl();
void drawtitle();
int drawmenu();
void drawinfo();
int drawmaplist();
void drawmap(int*, int*);
void drawUI(int*, int*, int*);