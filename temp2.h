#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h>
#include <string.h>
#include <pthread.h>

int coin = 0;
COORD coord;
char valuecoin[14][67];
//void findgame(char *name, FILE *fgame);
int is_alive1(int life1);

void abilitygame(SHORT X, SHORT Y, int result);
void mapone(FILE *mp1);
void setcursorposition(SHORT x, SHORT y);
int whathappenX(char ch);
int whathappenY(int result);
void godown();
void goleftorright(char ch, int result);
void mariojump();
void updateresult1();
void gotoxy(int x, int y);
void timegame1();