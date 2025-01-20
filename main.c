#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "sign.h"

int main()
{
    FILE *fp = fopen("sign.bin", "r+b");
    FILE *fgame = fopen("game.bin", "r+b");
    if(fp == NULL)
    {
        fp = fopen("sign.bin", "w+b");
    }
    if(fgame == NULL)
    {
        fgame = fopen("game.bin", "w+b");
    }
    int n;
    while(1)
    {
        printf("if you Enter 1 you can sign up:\nif you Enter 2 you can sign in:\n");
        printf("if you Enter 3 you can forget password:\nif you Enter 4 you can see your history:\n");
        printf("if you Enter 5 you can change your Data:\nif you Enter 5 you can exit:\n");

        printf("Enter your number: ");
        scanf("%d", &n);
        switch(n)
        {
            case 1:
                sign_up(fp);
                break;
            case 2:
                int result = 1;
                char nametmp[100];
                sign_in(fp, &result, nametmp);
                if(result == 0)
                {
                    continue;
                    printf("Error\n");
                }
                else
                {
                    showinfogame(nametmp, fgame);
                }
                break;  
            case 3:
                forgetpassword(fp);
                break;
            case 4:     
                showinfogame(nametmp, fgame);
                break;
            case 5:
                change_Data(fp);         
        }
    }
}