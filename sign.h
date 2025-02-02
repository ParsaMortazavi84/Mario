#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

struct sign {
    char name[100];
    char gmail[200];
    char password[100];
};
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
    struct result *pNext1;
    
};

struct infogame{
    char name[100];
    struct result *pHead1;// part 1
    struct result *pHead2;// part2
};




void sign_up(FILE *fp, FILE *fgame, char *name);
void forgetpassword(FILE *fp, int *result, char *nametmp);
void sign_in(FILE *fp, int *result, char *nametmp);
//int writeinfile(FILE *fgame, char name[]);
//void showinfogame(char name[], FILE *fgame);
void change_Data(FILE *fp, FILE *fgame, char *name);

int SIGN(char *NAME);