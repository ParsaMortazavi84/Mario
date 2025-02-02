#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h>
#include <string.h>
#include <pthread.h>

extern char Name[100];


struct sign {
    char name[100];
    char gmail[200];
    char password[100];
};

struct distinction{
    int score;
    int coin;
    
};

struct result{
    int victory;
    int lose;
    struct distinction pWin[10];
    struct distinction plose[10];
    
    
};

struct infogame{
    char name[100];
    int count1;
    int count2;
    struct result gameResults1[20];// part 1
    struct result gameResults2[20];// part 2 
};


//sign or part 0
void sign_up(FILE *fp, FILE *fgame);
void forgetpassword(FILE *fp, int *result);
void sign_in(FILE *fp, int *result);

void change_Data(FILE *fp, FILE *fgame);

int SIGN();


// game
int maingame();


// move1 or part1

void findinfogame1(FILE *fgame);

void reloadgame1(FILE *fgame);
int writeinfile1(FILE *fgame);
void showinfogame1(FILE *fgame);
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


// move3 or part2
void findinfogame2(FILE *fgame);
void reloadgame2(FILE *fgame);
int writeinfile2(FILE *fgame);
void showinfogame2(FILE *fgame);
int abilitygame2(SHORT X, SHORT Y, int result);
void maptwo(FILE *mp1);
void setcursorposition2(SHORT x, SHORT y);
int whathappenX2(char ch);
int whathappenY2(int result);
int godown2();
int goleftorright2(char ch, int result);
int mariojump2();
void gotoxy2(int x, int y);
void updateresult2();
void timegame2();
int GAME2(int dicision);