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



void findinfogame2(char *name, FILE *fgame);
void reloadgame2(char *name, FILE *fgame);
int writeinfile2(FILE *fgame);
void showinfogame2(char name[], FILE *fgame);
int abilitygame2(char *name, FILE *fgame, SHORT X, SHORT Y, int result);
void maptwo(FILE *mp1, char *name);
void setcursorposition2(SHORT x, SHORT y);
int whathappenX2(char ch);
int whathappenY2(int result);
int godown2();
int goleftorright2(char ch, int result);
void mariojump2();
void gotoxy2(int x, int y);
void updateresult2();
void timegame2();
int GAME2(char *name, int dicision);
