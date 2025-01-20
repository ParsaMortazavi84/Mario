#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct sign {
    char name[100];
    char gmail[200];
    char password[100];
};

struct game{
    int victory;
    int loss;
    int score;
    int coin;
    struct game *pNext;
};
struct infogame{
    char name[100];
    struct game *pHead;
};

void sign_up(FILE *fp);
void forgetpassword(FILE *fp);
void sign_in(FILE *fp, int *result, char nametmp[]);
int filegame(FILE *fgame, char name[]);
void showinfogame(char name[], FILE *fgame);
void change_Data(FILE *fp);