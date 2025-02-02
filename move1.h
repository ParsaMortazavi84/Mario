#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h>
#include <string.h>
#include <pthread.h>

struct distinction{
    int score;
    int coin;
    struct distinction *pNext2;
};

struct result{
    int victory;
    int lose;
    struct distinction *pWin;
    struct distinction *plose;
    struct result *pNext1;// part 1 
    
};

struct infogame{
    char name[100];
    struct result *pHead1;// part 1
    struct result *pHead2;
};
//struct game *pNext2;// part 2



void findinfogame1(char *name, FILE *fgame);
void reloadgame1(char *name, FILE *fgame);
int writeinfile1(FILE *fgame);
void showinfogame1(char name[], FILE *fgame);
int abilitygame1(char *name, FILE *fgame, SHORT X, SHORT Y, int result);
void mapone(FILE *mp1, char *name);
void setcursorposition1(SHORT x, SHORT y);
int whathappenX1(char ch);
int whathappenY1(int result);
int godown1();
int goleftorright1(char ch, int result);
int mariojump1();
void gotoxy1(int x, int y);
void updateresult1();
void timegame1();
int GAME1(char *name, int dicision);
