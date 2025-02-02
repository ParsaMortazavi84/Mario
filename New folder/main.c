#include "common.h"

int main()
{
    Name[0] = '\0';
    // FILE *fp = fopen("sign.bin", "r+b");
    // FILE *fgame = fopen("game.bin", "r+b");
    // if(fp == NULL)
    // {
    //     fp = fopen("sign.bin", "w+b");
    // }
    // if(fgame == NULL)
    // {
    //     fgame = fopen("game.bin", "w+b");
    // }
    int n;
    int d = 0;
    while(1)
    {
        
        system("cls");
        if(d == 1){
            printf("if you want to do some thing about sign again inter 1\n");
            printf("if you want to play or show you history game inter number 2\n");

        }
        else if( d == 0){
            printf("\033[32m");
            printf("if you want to do some thing about sign inter 1\n");

        }
        

        printf("\033[34m");
        printf("Enter your number: ");
        printf("\033[0m");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
                d = SIGN();
                break;
            case 2:   
                maingame();    
                break;  
        }
    }
}