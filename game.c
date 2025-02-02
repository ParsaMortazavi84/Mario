#include "common.h"


int maingame()
{
    
    int t = 1;
    int d = GAME1(t);
    while(1)
    {
        if(d == 4)
        {
            system("cls");
            printf("\033[32m");
            printf("if you want to start new game please enter 1\n");
            printf("if you want to play again please enter 2\n");
            printf("if you want to quit the game please enter 3\n");
            printf("please inter your number: ");
            printf("\033[0m");
            scanf("%d", &t);
            if(t == 3)
            {
                exit(0); 
            }
            else{
                d = GAME1(t);
                continue;
            }

        }
        else if( d == 5 )
        {
            system("cls");
            printf("\033[32m");
            printf("if you want to go to part 2 please enter 1\n");
            printf("if you want play again part 1 please enter 2\n");
            printf("if you want to quit the game please enter 3\n");
            printf("please inter your number: ");
            printf("\033[0m");
            scanf("%d", &t);

            if(t == 3)
            {
                exit(0);
            }
            else if( t == 1){
                break;
            }
            else if( t == 2){
                d = GAME1(t);
                continue;
            }
        }
    }
    t = 1;
    d = GAME2(t);
    while(1)
    {
        if(d == 4)
        {
            system("cls");
            printf("\033[32m");
            printf("if you want to play again please enter 2\n");
            printf("if you want to quit the game please enter 3\n");
            printf("please inter your number: ");
            printf("\033[0m");
            scanf("%d", &t);
            if(t == 3)
            {
                exit(0);
            }
            else{
                d = GAME2(t);
                continue;
            }
        }
        else if( d == 5 )
        {
            system("cls");
            printf("\033[32m");
            printf("if you want play again part 2 please enter 2\n");
            printf("if you want to quit the game please enter 3\n");
            printf("please inter your number: ");
            printf("\033[0m");
            scanf("%d", &t);

            if(t == 3)
            {
                exit(0);
            }
            else if( t == 1){
                break;
            }
            else if( t == 2){
                d = GAME2(t);
                continue;
            }
        }
    }
    

    return 0;
}
