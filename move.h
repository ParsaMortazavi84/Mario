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
char valuecoin[14][130];
void findgame(char *name, FILE *fgame);
void abilitygame(char *name, FILE *fgame, SHORT X, SHORT Y);
void mapone(FILE *mp1);
void setcursorposition(SHORT x, SHORT y);
int whathappenX(char ch);
int whathappenY(int result);
void godown();
void goleftorright(char ch, int result);
void mariojump();
void gotoxy(int x, int y);
