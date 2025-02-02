#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h>
#include <string.h>
#include <pthread.h>
#include "sign.h"
#include "temp.h"

time_t t_1;
time_t start_time_1;

//COORD spout = {111, 10};// notice for my self :because we in line 1 write the effects_1 so all coord_1.Y plus 1 
int _coin = 0;

COORD coord = {7, 11};
COORD time1_1 = {124, 14};

char valuecoin[27][65];
struct game *temp2;
char _map2[27][65];

int life1 = 3;
int score1 = 0;
int coin1 = 0;
int lose1 = 0;
int victory1 = 0;
int shild1 = 0;
int second1 = 0;
int minute1 = 0;

void maptwo(FILE *mp1)
{

    int i = 0;
    while(i<27 && fgets(_map2[i], 65, mp1) != NULL)
    {
        i++;
        //fseek(mp1, 1, SEEK_CUR);
    }
    for(int j = 0; j < 27; j++)
    {
        for(int k = 0; k < 63; k++)
        {
            if(_map2[j][k] == '8')
            {
                srand(time(0));
                valuecoin[j][k] = (rand() % 5) + 1;
            }
            else{
                valuecoin[j][k] = 0;
            }
        }
    }
    // for(i = 0; i < 14; i++)
    //     printf("%s", _map2[i]);


    SetConsoleOutputCP(CP_UTF8);
    
    for(i = 0; i < 27; i++)
    {
        for(int j = 0; j < 63; j++)
        {
            
            if(_map2[i][j] == ' ')
            {
                printf("  ");
            }
            else if(_map2[i][j] == '#')
            {
                printf("🧱");
            }
            else if(_map2[i][j] == '$')
            {
                printf("🪙");
            }
            else if(_map2[i][j] == '(')
            {
                printf("🐙");
            }
            else if(_map2[i][j] == '|')
            {
                printf("🟢");
            }
            else if(_map2[i][j] == '%')
            {
                printf("🟧");
            }
            else if(_map2[i][j] == '8')
            {
                printf("🟨");
            }
            else if(_map2[i][j] == '!')
            {
                printf("🦖");
            }
            else if(_map2[i][j] == 'S')
            {
                printf("🛡️");
            }
            else if(_map2[i][j] == '{')
            {
                printf("🚩");
            }
            else{
                printf(" ");
            }
            
        }
        printf("\n");
    }
    
    //printf("\nlife: %d victory: %d lose: %d score: %d coin: %d", life1, victory1, lose1, score1, coin1);
    fclose(mp1);    
    //move

    
}

// void findinfogame(char *name, FILE *fgame )
// {
//     struct infogame temp;
//     while(fwrite(&temp, sizeof(struct infogame), 1, fgame) == 1)
//     {
//         if(strcmp(temp.name, name) == 0)
//         {
//             temp2 = temp.pHead;
//             struct game *pNew = (struct game*)malloc(sizeof(struct game));
//             while(temp2 != NULL)
//                 temp2 = temp2 -> pNext;
//             temp2->pNext = NULL;
            
//         }

//     } 
// }

int is_alive1(int life1)
{
    if(life1 == 0)
    {

        
        system("cls");
        printf("GAME OVER");
        return 4;// mean you are game over
    }
    else{
        gotoxy(5, 11);
        return 1;
    }
}

void clear1(int x, int y)
{
    COORD bloke;
    bloke.X = x;
    bloke.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bloke);
    printf(" ");
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void abilitygame(SHORT X, SHORT Y, int result)//result mean the mario go up or down or left and right// result 0 up // result 1 down // result 2 left and  right
{
    // the comments in this func is a idea but i don't use them yet
    time_t t2;
    if(_map2[Y][X] == '$'){
        coin1 += 1;
        //updateresult1();
        _map2[Y][X] = ' ';
    }
    else if(_map2[Y][X] == 'S' )// shild1 i plus one life1 
    {
        shild1 = 1;
    }  
    else if(_map2[Y][X] == '(' && shild1 == 0)// simple enemy in _map2 becase it is an array X+1 -> X all of them minese 1 (plus -1) Y -> Y-1
    {
        life1 -= 1;
        //updateresult1();
        int d = is_alive1(life1);
        if(d == 4)
        {
            return;
        }

    }
    else if(_map2[Y][X] == '(' && shild1 == 1)
    {
        shild1 = 0;
        gotoxy(5, 12);
    }
    else if(_map2[Y+1][X] == '(' && result == 1)// simple enemy  X->X-1  Y+1 -> Y
    {
        //static int i = 100;
        static int i = 0;
        if(i == 0){
            time(&t_1);
            score1 += 100;// give score1 
            //updateresult1();

            _map2[Y+1][X] = ' ';
            

        }
        else{
            time(&t2);
            if(difftime(t2, t_1) <= 5)
            {
                i *= 2; 
                if(i > 400)
                    i = 400;
                score1 += i;
                //updateresult1();
                _map2[Y+1][X] = ' ';
                t_1 = t2;
            }
            else{
                i = 100;
                score1 += i;
                //updateresult1();
                _map2[Y+1][X] = ' ';
                t_1 = t2;
            }
        }
    }
    else if(result == 2 && _map2[Y][X+1] == '!' && shild1 == 0)// X & Y -> X-1 & Y-1  X+1 -> X
    {
        life1 -= 1;
        //updateresult1();
        int d = is_alive1(life1);
        if(d == 4)
        {
            exit(0);
        }
        gotoxy(5, 12);
        
    }
    else if(_map2[Y][X] == '!' || _map2[Y][X+1] == '!' && shild1 == 1)
    {
        shild1 = 0;
        gotoxy(5, 12);
    }
    else if(_map2[Y-1][X] == '8' && result == 0)// X & Y-1 -> X-1 & Y-2
    {
        valuecoin[Y-1][X] -= 1;// X & Y-1 -> X-1 & Y-2
        coin1 += 1;
        //updateresult1();
        if(valuecoin[Y-1][X] == 0)// X & Y-1 -> X-1 & Y-2
        {
            clear1(X, Y-1);//that meen the coin1 is over//that's correct it work on map
            _map2[Y][X] == ' ';// X & Y -> X-1 & Y-1
        }
    }
    else if(_map2[Y-1][X] == '%' && result == 0)// X & Y-1 -> X-1 & Y-1
    {
        if(valuecoin[Y-1][X] == 1)
        {
            coin1 += 1;
            //updateresult1();
            clear1(X, Y-1);
            _map2[Y-1][X] = ' ';
            valuecoin[Y-1][X] -= 1;
        } 
    }
    else if(_map2[Y][X] == '{')// when mario catch the flat
    {
        victory1 += 1;
        //return 5;
        system ("cls");
        printf("you won this part 1");
        //return 2;// 2 mean you can go to part two or again play this time
    }
    else if(coord.X == 110 && coord.Y == 9)
    {
        gotoxy(49, 5);
        godown();
        
    }

    //return 0;
}

void setcursorposition(SHORT x, SHORT y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(hConsole, pos);
}

int whathappenX(char ch)//move in the X way
{
    // mp1 = fopen("map1.txt", "r+");
    // char _map2[14][130];
    // int i = 0;
    // while(i < 14 && fgets(_map2[i], 130, mp1) != NULL)
    // {
    //     i++;
    //     //fseek(mp1, 1, SEEK_CUR);
    // }
    if(ch == 'a' || ch == 'A')
    {
        if(_map2[coord.Y][coord.X - 1] == '#' || _map2[coord.Y][coord.X - 1] == '|')
        {
            return 0;
        }
    }
    else if(ch == 'd' || ch == 'D')
    {
        if(_map2[coord.Y][coord.X + 1] == '#' || _map2[coord.Y][coord.X + 1] == '|')
        {
            return 0;
        }
    }
    abilitygame(coord.X, coord.Y, 2);
    // fclose(mp1);
    return 1;
}

int whathappenY(int result)
{
    
    if(result == 0)
    {
        if(_map2[coord.Y - 1][coord.X] == '#' || _map2[coord.Y - 1][coord.X] == '|' || coord.Y <= 0 )
        {
            return 0;
        }
        else{
            abilitygame(coord.X, coord.Y, 0);
            return 1;
        }
        //abilitygame1(name, fgame, )
    }
    else if(result == 1)
    {
        if((coord.Y + 1) >= 13 || _map2[coord.Y + 1][coord.X] == '#' || _map2[coord.Y + 1][coord.X] == '|' || _map2[coord.Y + 1][coord.X] == '8' || _map2[coord.Y + 1][coord.X] == '%')
        {
            return 0;
        }
        else{
            abilitygame(coord.X, coord.Y, 1); 
            return 1;
        }
        
    }
    //abilitygame1
    // fclose1(mp);

}

void godown()// gravity
{
    // mp = fopen("map1.txt", "r+");
    // char _map2[14][130];
    // int i = 0;
    // while(i < 14 && fgets(_map2[i], 130, mp) != NULL)
    // {
    //     i++;
    //     //fseek(mp1, 1, SEEK_CUR); 
    // }
    
    while(coord.Y < 13 && _map2[coord.X][coord.Y+1] != '#' && _map2[coord.X][coord.Y+1] != '|' && _map2[coord.X][coord.Y+1] != ' ') //going to fall
    {
        if((GetAsyncKeyState('D') & 0x8000))
        {
            // char ch = 'd'; 
            goleftorright('d', 1);
        }
        else if((GetAsyncKeyState('A') & 0x8000))
        {
            // char ch = 'd';
            goleftorright('a', 1);
        }
        int j = whathappenY(1);
        if(j == 0)
        {
            break;
        }
        gotoxy(coord.X, coord.Y + 1);
        Sleep(100);
    }
}

void goleftorright(char ch, int result)
{
    FILE *mp;
    if(result == 2)// don't going to jump 
    {
        if(ch == 'a' || ch == 'A')
        {
            int i = whathappenX(ch);
            int j = whathappenY(1);
            if(i == 0 )
            {
                return;
            }
            if(j != 0)
            {
                godown();
            }
            Sleep(100);
            gotoxy(coord.X - 1, coord.Y);
        }
        else if(ch == 'd' || ch == 'D')
        {
            int i = whathappenX(ch);
            int j = whathappenY(ch);
            if(i == 0)
            {
                return;
            }
            if(j != 0)
            {
                godown();
            }
            Sleep(100);
            gotoxy(coord.X + 1, coord.Y);   
        }
    }
    else if(result == 0)// that mine mario during a jump
    {
        if(ch == 'a' || ch == 'A')
        {
            int i = whathappenX(ch);
            int j = whathappenY(0);
            if(i == 0 || j ==0)
            {
                return;
            }
            Sleep(100);
            gotoxy(coord.X - 1, coord.Y);
        }
        else if(ch == 'd' || ch == 'D')
        {
            int i = whathappenX(ch);
            int j = whathappenY(0);
            if(i == 0 || j == 0)
            {
                return;
            }
            Sleep(100);
            gotoxy(coord.X + 1, coord.Y);   
        }
    }
    else if(result == 1)// that mine mario going to fall
    {
        if(ch == 'a' || ch == 'A')
        {
            int i = whathappenX(ch);
            int j = whathappenY(1);
            if(i == 0 || j ==0)
            {
                return;
            }
            Sleep(100);
            gotoxy(coord.X - 1, coord.Y);
        }
        else if(ch == 'd' || ch == 'D')
        {
            int i = whathappenX(ch);
            int j = whathappenY(1);
            if(i == 0 || j == 0)
            {
                return;
            }
            Sleep(100);
            gotoxy(coord.X + 1, coord.Y);   
        }
    }
}

void mariojump()
{
    // FILE *mp = fopen("map1.txt", "r+");
    // char _map2[14][130];
    // int i = 0;
    // while(i < 14 && fgets(_map2[i], 130, mp) != NULL)
    // {
    //     i++;
    //     //fseek(mp1, 1, SEEK_CUR);
    // }
    int result = 0;
    for(int i = 0; i < 4; i++)//going to jump
    {
        if((GetAsyncKeyState('D') & 0x8000))
        {
            // ch = 'd';
            int z = whathappenX('d');
            if(z != 0)
                goleftorright('d', 0);
        }
        else if((GetAsyncKeyState('A') & 0x8000))
        {
            // char ch = 'd';
            int z = whathappenX('a');
            if(z != 0)
                goleftorright('a', 1);
        }
        
        int j = whathappenY(result);
        if(j == 0)
        {
            break;
        }
        
        gotoxy(coord.X, coord.Y - 1);
        Sleep(100);
    }
    result = 1;
    while(coord.Y < 13 || _map2[coord.X][coord.Y+1] != '#' || _map2[coord.X][coord.Y+1] != '|' || _map2[coord.X][coord.Y+1] != ' ') //going to fall
    {
        if((GetAsyncKeyState('D') & 0x8000))
        {
            // char ch = 'd';
            int z = whathappenX('a');
            if(z != 0)
                goleftorright('d', 1);
        }
        else if((GetAsyncKeyState('A') & 0x8000))
        {
            // char ch = 'd';
            int z = whathappenX('a');
            if(z != 0)
                goleftorright('a', 1);
        }
        int j = whathappenY(result);
        if(j == 0)
        {
            break;
        }
        gotoxy(coord.X, coord.Y + 1);
        Sleep(100);
    }
}

void updateresult1()
{
    COORD effects_1 = {0, 15};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), effects_1);
    char space[70] = {                                                                      };
    
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), effects_1);
    printf("life: %d victory: %d lose: %d score: %d coin: %d", life1, victory1, lose1, score1, coin1);

}

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf(" ");
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("M");

}

void timegame1()
{
    
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), time1_1);
    char space[20] = {                    };
    
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), time1_1);
    //printf("time: %d:%2d", minute1 ,second1);
}

int main() {
    time_t t3;
    time_t t4;
    int t_first = 0;
    FILE *mp1 = fopen("map2.txt", "r+");
    system("cls");
    maptwo(mp1);
    //gotoxy(128, 13);
    //printf("\n");

    gotoxy(7, 11);    

    // remove cursuer
    CONSOLE_CURSOR_INFO cursurInfo;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hConsole, &cursurInfo);
    cursurInfo.bVisible = false;
    SetConsoleCursorInfo (hConsole, &cursurInfo);

    while(1){
        char ch;
        if((GetAsyncKeyState('D') & 0x8000))
        {
            ch = 'd';
            goleftorright(ch, 2);
        }
        if((GetAsyncKeyState('A') & 0x8000))
        {   
            ch = 'a';
            goleftorright(ch, 2);
        }
        if(GetAsyncKeyState(VK_SPACE) & 0x8000){
            mariojump();
        }
                //time
        //time
        if(t_first == 0){
            time(&t3);
            time_t dif = difftime(t3, start_time_1);
            if(dif >= 1)
            {
                second1 += 1;
                if(second1 == 60)
                {
                    minute1 += 1;
                    second1 = 0;
                    timegame1();
                }
                else{
                    timegame1();
                }
                t4 = t3;
                t_first++;
            }
            else{
                continue;
            }
            t4 = t3;
            t_first++; 
        }
        else{
            time(&t3);
            time_t dif = difftime(t3, t4);
            if(dif >= 1)
            {

                second1 += 1;
                if(second1 == 60)
                {
                    minute1 += 1;
                    second1 = 0;
                    //timegame1();
                }
                else{
                    if(second1 % 10 == 0)
                        //timegame1();
                    t4 = t3;    
                }
            }
            else{
                continue;
            }
            
        }
    
    }
    return 0;
}