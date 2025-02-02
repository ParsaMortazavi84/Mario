#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <pthread.h>




void findinfogame1();
void reloadgame1();
int writeinfile1();
void showinfogame1();
int abilitygame1(SHORT X, SHORT Y, int result);
void mapone(FILE *mp1);
void setcursorposition1(SHORT x, SHORT y);
int whathappenX1(char ch);
int whathappenY1(int result);
int godown1();
int goleftorright1(char ch, int result);
int mariojump1();
void gotoxy1(int x, int y);
void updateresult1();
void timegame1();
int GAME1(int dicision);
